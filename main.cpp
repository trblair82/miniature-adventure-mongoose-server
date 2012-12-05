/* 
 * File:   main.cpp
 * Author: thomas
 *
 * Created on November 19, 2012, 5:23 PM
 */

#include <cstdlib>
#include <fstream>
#include "CGAL_JNA_Utils.h"

//#include <CGAL/Simple_cartesian.h>
//#include <CGAL/Polyhedron_3.h>
//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>





 
/*
 * 
 */
int main(int argc, char** argv) {
    
    std::ifstream input("triangles.txt");
    int floatCount = 0;
    float* triangles;
    float value;
    int numTriangles;
    while(!input.eof()){
        input >> value;
            
        if(floatCount == 0){
            
            triangles = (float*) malloc (value * sizeof(float));
            numTriangles = value;
            
        }else{
            triangles[floatCount-1] = value;
            
            
        }
        floatCount++;
    }
    std::map<std::string,Point_3*> testMap;
    int x = getBaseGeometry(triangles,numTriangles);
    return 0;
}

