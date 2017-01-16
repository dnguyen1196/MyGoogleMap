/*
 * Google map class that basically builds upon a boost graph object
 */

#ifndef BOOSTED_MYGOOGLEMAP_H
#define BOOSTED_MYGOOGLEMAP_H

#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>


/*
 * Initialize edge type with weight and undirected graph type
 */
using namespace boost;
typedef property < edge_weight_t, double >Weight;
typedef adjacency_list < vecS, vecS, undirectedS, no_property, Weight > UndirectedGraph;

class MyGoogleMap {
public:
    void createMapFromFile(char* filename);

private:
    UndirectedGraph graph;

};

#endif //BOOSTED_MYGOOGLEMAP_H
