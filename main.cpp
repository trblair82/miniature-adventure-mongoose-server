/* 
 * File:   main.cpp
 * Author: thomas
 *
 * Created on November 19, 2012, 5:23 PM
 */

#include <fstream>
#include "CGAL_JNA_Utils.h"
#include "JNA_CGAL_Geometry_Simplifier.h"








 
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
//    BASE_GEOMETRY testGeometry;
//    testGeometry = deserializeBaseGeometry(triangles,numTriangles);
//    PolyhedralSurface poly = buildPolyhedron(testGeometry);
    
    SERIALIZED_BASE_GEOMETRY geometry = JNA_CGAL_Simplify_Geometry(triangles, numTriangles);
    for(int i = 0;i<geometry.numTriangles*3;i++){
        int test = geometry.triangleIndex[i];
        int ball = 0;
    }
    for(int i = 0;i<geometry.numVerts*3;i++){
        int test1 = geometry.vertices[i];
        int ball2 = 0;
    }
    
    
    
    
    int balls = 0;
        
    
    free_CGAL_JNA_Utils();
    return 0; 
    
}

