#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

void	ft_process_inv_inp(std::string message);

int main()
{
	Graph	*example;
	int		nodes;

	try
	{
		std::cout << "Enter a number of NODES in the graph: ";
		while (!(std::cin >> nodes))
		{
			std::cout << "Please use positive integer numbers for a number of NODES in a graph" << std::endl;
			ft_process_inv_inp("Enter a number of NODES in the graph: ");
		}
		example = new Graph(nodes);
		example->assign_links();
		example->print_links();
		example->print_distance();
		example->dejkstra();
		example->print_distance();
		example->restore_path();
		example->print_path();
	}
	catch (const Graph::NodesException &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (const Graph::WeightException &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cin.get();
	while (1)
		;
	delete(example);
	return (0);
}

void	ft_process_inv_inp(std::string message)
{
	std::cin.clear();
	std::cout << message;
	while (std::cin.get() != '\n')
		continue;
}
