//
//  main.cpp
//  Interlocker
//
//  Created by Grover Chen on 3/10/17.
//  Copyright © 2017 Grover Chen. All rights reserved.
//


#include "parts_graph.h"

#include <iostream>

int main(int argc, const char * argv[]) {
    // create furniture model of Figure 3 in the paper
    Graph chair(6);
    
    chair.setName("chair");
    chair.addEdge(0, 1, Y);
    chair.addEdge(0, 3, Y);
    chair.addEdge(1, 2, X);
    chair.addEdge(1, 4, X);
    chair.addEdge(1, 5, X);
    chair.addEdge(2, 3, Z);
    chair.addEdge(3, 4, Z);
    chair.addEdge(4, 5, Y);
    
    std::vector<int> tmp;
    tmp.push_back(0);tmp.push_back(1);tmp.push_back(2);tmp.push_back(3);
    chair.setLIGs(tmp);
    tmp.clear();
    tmp.push_back(1);tmp.push_back(2);tmp.push_back(3);tmp.push_back(4);
    chair.setLIGs(tmp);
    tmp.clear();
    tmp.push_back(1);tmp.push_back(4);tmp.push_back(5);
    chair.setLIGs(tmp);
    tmp.clear();
    
    chair.printLIGs();
    
    Graph bookShelf(12);
    
    bookShelf.setName("bookShelf");
    bookShelf.addEdge(0, 1, Z);
    bookShelf.addEdge(0, 2, Z);
    bookShelf.addEdge(0, 7, Z);
    bookShelf.addEdge(1, 3, X);
    bookShelf.addEdge(1, 4, Y);
    bookShelf.addEdge(1, 6, Z);
    bookShelf.addEdge(1, 12, X);
    bookShelf.addEdge(2, 3, Z);
    bookShelf.addEdge(2, 4, Z);
    bookShelf.addEdge(2, 5, Y);
    bookShelf.addEdge(2, 11, Z);
    bookShelf.addEdge(3, 9, Y);
    bookShelf.addEdge(4, 8, X);
    bookShelf.addEdge(4, 10, Y);
    bookShelf.addEdge(5, 7, X);
    bookShelf.addEdge(5, 8, Y);
    bookShelf.addEdge(6, 7, X);
    bookShelf.addEdge(6, 8, Z);
    bookShelf.addEdge(9, 11, X);
    bookShelf.addEdge(9, 12, Z);
    bookShelf.addEdge(10, 11, Y);
    bookShelf.addEdge(10, 12, Z);
    
    
    
    
    
    
    return 0;
}
