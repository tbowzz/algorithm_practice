#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include <stdio.h>
#include <fstream>
#include "LinkedList.h"

int main(int argc, char **argv)
{
	VS_MEM_CHECK;
	if (argc != 3)
	{
		printf("USAGE: ./LinkedList <inputfile> <outputfile>\n");
		return -1;
	}

	printf("Parsing input file \"%s\"\n", argv[1]);
	std::fstream in;
	in.open(argv[1], std::ios::in);
	if (!in.is_open())
	{
		printf("Failed to parse file.\n");
		return -1;
	}

	std::fstream out;
	out.open(argv[2], std::ios::out);
	if (!out.is_open())
	{
		printf("Failed to open out file.\n");
		return -1;
	}

	LinkedListInterface<std::string> *linkedList = new LinkedList<std::string>();

	// process input strings
	for (std::string line; getline(in, line);)
	{
		std::string command, parameters;
		if (line.empty()) continue;
		std::istringstream iss(line);
		iss >> command;
		if (command == "Insert")
		{
			while (iss >> parameters)
			{
				linkedList->push_front(parameters);
			}
			out << line << "\n";
		}
		else if (command == "PrintList")
		{
			out << command;
			std::string output = linkedList->toString();
			if (output.empty())
			{
				out << " Empty!" << "\n";
			}
			else
			{
				out << output << "\n";
			}
		}
		else if (command == "Clear")
		{
			linkedList->clear();
			out << command << " " << "OK" << "\n";
		}
		else if (command == "Size")
		{
			out << command << " " << linkedList->size() << "\n";
		}
		else if (command == "Empty")
		{
			out << command;
			if (linkedList->empty())
			{
				out << " true" << "\n";
			}
			else
			{
				out << " false" << "\n";
			}
		}
		else if (command == "First")
		{
			out << command << " " << linkedList->front() << "\n";
		}
		else if (command == "Delete")
		{

		}
		else if (command == "Remove")
		{

		}
		else if (command == "Append")
		{

		}
		else if (command == "Last")
		{

		}
		else if (command == "Drop")
		{

		}
	}

	in.close();
	out.close();

	printf("Cleaning up\n");
	delete linkedList;
	printf("Exiting\n");
	return 0;
}
