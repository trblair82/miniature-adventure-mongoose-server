/* 
 * File:   main.cpp
 * Author: thomas
 *
 * Created on November 19, 2012, 5:23 PM
 */
#include <stdlib.h>
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
            numTriangles = value/3/3;
            
        }else{
            triangles[floatCount-1] = value;
            
            
        }
        floatCount++;
    }
    BASE_GEOMETRY testGeometry;
    testGeometry = getBaseGeometry(triangles,numTriangles);
    
    for(int j = 0;j<testGeometry.numVerts; j++){
        Point_3 vert1 = testGeometry.vertices[j];
        float x1 = vert1.x();
        float y1 = vert1.y();
        float z1 = vert1.z();
        
        int test = 0;
    }
    
    for(int i = 0;i<testGeometry.numTriangles*3;i+=3){
        
        int index1 = testGeometry.triangleIndex[i];
        Point_3 vert1 = testGeometry.vertices[index1];
        float x1 = vert1.x();
        float y1 = vert1.y();
        float z1 = vert1.z();
        int index2 = testGeometry.triangleIndex[i + 1];
        Point_3 vert2 = testGeometry.vertices[index2];
        float x2 = vert2.x();
        float y2 = vert2.y();
        float z2 = vert2.z();
        int index3 = testGeometry.triangleIndex[i + 2];
        Point_3 vert3 = testGeometry.vertices[index3];
        float x3 = vert3.x();
        float y3 = vert3.y();
        float z3 = vert3.z();
        
        int test1 = 0;
        
    }
    freeBaseGeometry();
    return 0; 
    
}

