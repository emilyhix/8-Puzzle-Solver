#ifndef NODE_H
#define NODE_H
#include "../header/problem.h"

enum Operations {UP, DOWN, LEFT, RIGHT};

class Node{
    private:
        int initial_state[9];
        int goal_state[9] = {1, 2, 3,
                             4, 5, 6,
                             7, 8, 0};
        int current_state[9];
        int hN;
        int gN;
        Operations operation;

    public:
        Node(int, int setInitial[9]);
        Node(int, Operations, Node);
        bool Valid();
        int getInitial(int);
        int getgN();

};

Node::Node(int algorithm, int initialArray[9]) {
    gN = 0;
    
    // determine h(N)
        if (algorithm == 1) {
                    //UniformCostSearch
                    hN = 0;
        }
        if (algorithm == 2) {
                    //A* Euclidean
                    //hN = something
        }
        if (algorithm == 3) {
                    //A* Missing Tile
                    //hN = something
        }
    
    // set initial
    for (int i = 0; i < 9; ++i) {
        initial_state[i] = initialArray[i];
    }

    operation = UP;
}

Node::Node(int algorithm, Operations inputOp, Node parent) {
        
        //set gN
        gN = parent.getgN() + 1;

        // set operation
        operation = inputOp;

        // determine h(N)
        if (algorithm == 1) {
                    //UniformCostSearch
                    hN = 0;
        }
        if (algorithm == 2) {
                    //A* Euclidean
                    //hN = something
        }
        if (algorithm == 3) {
                    //A* Missing Tile
                    //hN = something
        }

        // keep initial state
        for (int i = 0; i < 9; ++i) {
            initial_state[i] = parent.getInitial(i);
        }
}

bool Node::Valid() {
    int index;

    if 
}

int Node::getInitial (int index) {
    return initial_state[index];
}

int Node::getgN() {
    return gN;
}

#endif NODE_H