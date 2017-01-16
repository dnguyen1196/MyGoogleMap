/*
 * Google map class that basically builds upon a boost graph object
 */

#ifndef BOOSTED_MYGOOGLEMAP_H
#define BOOSTED_MYGOOGLEMAP_H

#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <string>
#include <vector>

/*
 * Initialize edge type with weight and undirected graph type
 */
typedef boost::property < boost::edge_weight_t, double >Weight;
typedef boost::adjacency_list < boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, Weight > UndirectedGraph;

//typedef boost::adjacency_matrix<boost::undirectedS, boost::no_property, Weight> UndirectedGraph;

class MyGoogleMap {
public:
    // Instantiate the graph object from file name
    void createMapFromFile(std::string filename);

    // Find the shortest path point id1 to point id2
    // Return the sequence of points to traverse to get from source
    // to destination
    std::vector<int> findShortestPath(int source, int destination);

private:
    UndirectedGraph graph;

};

#endif //BOOSTED_MYGOOGLEMAP_H
