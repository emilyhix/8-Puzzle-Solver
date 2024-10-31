#include "../header/node.h"

Node::Node(int algorithm, int initialArray[9]) {
    gN = 0;
    
    // determine h(N)
        if (algorithm == 1) {
                    //UniformCostSearch
                    hN = 0;
        }
        if (algorithm == 2) {
                    //A* Misplaced Tile
                    //hN = something
        }
        if (algorithm == 3) {
                    //A* Euclidean
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

    if (operation == UP) {
        if (current_state[0] == 0 || current_state[1] == 0 || current_state[2] == 0)
            return false;
    }
    else if (operation == DOWN) {
        if (current_state[6] == 0 || current_state[7] == 0 || current_state[8] == 0)
            return false;
    }
    else if (operation == LEFT) {
        if (current_state[0] == 0 || current_state[3] == 0 || current_state[6] == 0)
            return false;
    }
    else if (operation == RIGHT) {
        if (current_state[2] == 0 || current_state[5] == 0 || current_state[8] == 0)
            return false;
    }
    else return true;
}

int Node::getInitial (int index) {
    return initial_state[index];
}

int Node::getgN() {
    return gN;
}

int Node::gethN() {
    return hN;
}