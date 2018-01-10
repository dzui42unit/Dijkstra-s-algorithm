#include "Graph.h"

Graph::Graph(int nodes)
{
	if (nodes <= 0)
		throw(Graph::NodesException());
	this->nodes = nodes;
	for (int i = 0; i < this->nodes; i++)
	{
		links.push_back(std::vector<int>(this->nodes, 0));
		distances.push_back(INT_MAX);
		visited.push_back(0);
	}
}

Graph::~Graph()
{

}

Graph	&Graph::operator=(const Graph &graph)
{
	nodes = graph.nodes;
	links = graph.links;
	return (*this);
}

Graph::Graph(const Graph &graph)
{
	nodes = graph.nodes;
	links = graph.links;
}

void	Graph::print_links(void)
{
	std::cout << std::endl << "Number of nodes: " << nodes << std::endl;
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
		{
			std::cout << std::setw(3);
			std::cout << links[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	Graph::assign_links(void)
{
	int temp_weight;

	for (int i = 0; i < nodes; i++)
	{
		for (int j = i + 1; j < nodes; j++)
		{
			std::cout << "Enter a distance from " << i + 1 << " node to " << j + 1 << " node: ";
			if (!(std::cin >> temp_weight))
				throw(Graph::WeightException());
			links[i][j] = temp_weight;
			links[j][i] = temp_weight;
		}
	}
}

void	Graph::print_distance(void)
{
	for (int i = 1; i < nodes; i++)
		std::cout << "Distance from 1 node to " << i + 1 << " is: " << distances[i] << std::endl;
}

bool	Graph::is_visited(void)
{
	for (int i = 0; i < nodes; i++)
	{
		if (visited[i] == 0)
			return (0);
	}
	return (1);
}

void	Graph::dejkstra(void)
{
	int		min_node_index;
	int		min_path;
	int		temp_path;
	bool	finish;

	distances[0] = 0;
	finish = false;
	while (!finish)
	{
		min_node_index = INT_MAX;
		min_path = INT_MAX;
		print_visited();
		for (int i = 0; i < nodes; i++)
		{
			if (!visited[i] && distances[i] < min_path)
			{
				min_path = distances[i];
				min_node_index = i;
			}
		}
		if (min_node_index != INT_MAX)
		{
			for (int j = 0; j < nodes; j++)
			{
				if (links[min_node_index][j] > 0)
				{
					temp_path = min_path + links[min_node_index][j];
					if (temp_path < distances[j])
						distances[j] = temp_path;
				}
			}
			visited[min_node_index] = 1;
		}
		else
			finish = true;
	}
}

void	Graph::print_visited(void)
{
	for (int i = 0; i < nodes; i++)
	{
		std::cout << visited[i] << " ";
	}
	std::cout << std::endl;
}

void	Graph::restore_path(void)
{
	int					end_point;
	int					weight;
	int					temp_weight;

	end_point = nodes - 1;
	weight = distances[end_point];
	path.push_back(end_point + 1);
	while (end_point > 0)
	{
		for (int i = 0; i < nodes; i++)
		{
			if (links[end_point][i] > 0)
			{
				temp_weight = weight - links[end_point][i];
				if (temp_weight == distances[i])
				{
					weight = temp_weight;
					end_point = i;
					path.push_back(end_point + 1);
				}
			}
		}
	}
}

void	Graph::print_path(void)
{
	for (int i = path.size() - 1; i >= 0; i--)
	{
		std::cout << path[i] << " ";
	}
	std::cout << std::endl;
}