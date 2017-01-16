#include <iostream>
#include "mygooglemap.h"
int main(int argc, char** arg) {
    MyGoogleMap map;
    char* s = (char *) "Hello world";
    map.createMapFromFile(s);
}


