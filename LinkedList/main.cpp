#include <stdio.h>
#include <fstream>
#include "LinkedList.h"

int main(int argc, char **argv)
{
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
			out << line << std::endl;
		}
		else if (command == "PrintList")
		{
			out << command << " ";
			out << linkedList->toString() << std::endl;
		}
		else if (command == "Clear")
		{
			linkedList->clear();
			out << command << " " << "OK" << std::endl;
		}
		else if (command == "Size")
		{

		}
		else if (command == "Empty")
		{

		}
		else if (command == "First")
		{

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
