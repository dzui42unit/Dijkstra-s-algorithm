#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <climits>
#include <iomanip>

class Graph
{
private:
	
	// wight matrix
	std::vector<std::vector<int>>		links;
	// vector of visited nodes
	std::vector<int>					visited;
	// vector of distances from start to the point
	std::vector<int>					distances;
	// vector of path
	std::vector<int>					path;
	// number of nodes in the graph
	int									nodes;
public:
		Graph() = delete;
		~Graph();
		Graph(int nodes);
		Graph(const Graph &graph);
Graph	&operator=(const Graph &graph);

void	print_links(void);
void	assign_links(void);
void	print_distance(void);
void	dejkstra(void);
void	restore_path(void);
void	print_visited(void);
bool	is_visited(void);
void	print_path(void);

class NodesException : public std::exception
{
public:
	const char	*what() const throw() override
	{
		return ("Nodes number exception.");
	}
};

class WeightException : public std::exception
{
public:
	const char *what() const throw() override
	{
		return ("Weight value exception.");
	}
};

};

