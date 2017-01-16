#include <iostream>
#include "mygooglemap.h"
#include <fstream>
#include <boost/algorithm/string.hpp>

/*
 * Function signatures
 */
std::ifstream openFile(std::string filename);
UndirectedGraph initiateMapFromFile(std::ifstream& map);
void addEdge(std::vector<std::string>& splitVec, UndirectedGraph& graph);
void testGraph(UndirectedGraph& graph);


// Instantiate the graph object from the file
void MyGoogleMap::createMapFromFile(std::string filename) {
    // Open the file
    std::ifstream mapfile;
    mapfile = openFile(filename);

    // Call the function to initialize the graph object from mapfile
    this->graph = initiateMapFromFile(mapfile);

    // Try traversing the graph

}

UndirectedGraph initiateMapFromFile(std::ifstream& map) {
    // Read in each line from the map
//    std::string line;
//    getline(map, line);
//    int SIZE = std::stoi(line); // Get the size of the map (number of vertices)
//    UndirectedGraph graph(SIZE);
    UndirectedGraph graph;

    for (std::string line; getline(map,line);){
        // Perform splitting
        std::vector<std::string> splitVec;
        boost::split(splitVec, line, boost::is_any_of(" "), boost::token_compress_on);
        addEdge(splitVec, graph);
    }
    std::cout << "Hello" << std::endl;
    testGraph(graph);
    return graph;
}

void addEdge(std::vector<std::string>& splitVec, UndirectedGraph& graph){
    // TODO: handle exception
    int source_id = std::stoi(splitVec[0]);
    int dest_id = std::stoi(splitVec[1]);
    float distance = std::stof(splitVec[2]);

    // Check if source_id is already in graph
    boost::graph_traits<UndirectedGraph>::vertex_descriptor s,d;
    s = boost::vertex(source_id, graph);
    d = boost::vertex(dest_id, graph);

    boost::add_edge(s, d, Weight(distance), graph);
}


std::ifstream openFile(std::string filename) {
    std::ifstream file;
    try {
        file.open(filename);
    } catch (std::exception e){
        exit(1);
    }
    return file;
}


void testGraph(UndirectedGraph& graph){
    boost::graph_traits<UndirectedGraph>::vertex_descriptor s, d;
    typename boost::property_map < UndirectedGraph, boost::edge_weight_t >::type
            weight = get(boost::edge_weight, graph);
    typename boost::graph_traits < UndirectedGraph >::edge_descriptor edge;
    bool found;

    s = boost::vertex(0,graph);
    d = boost::vertex(1,graph);
    std::cout << "Reach here" << std::endl;
    boost::tie(edge, found) = boost::edge(s, d, graph);
    std::cout << boost::num_edges(graph) << " " << boost::num_vertices(graph) << std::endl;
    std::cout << found << std::endl;
//    std::cout << boost::get(weight, edge) << std::endl;
}