#include <iostream>
#include "mygooglemap.h"
int main(int argc, char** arg) {
    MyGoogleMap map;
    map.createMapFromFile("map/testmap.txt"); // Open the test map file
    std::cout << "Hi, done" << std::endl;
}


