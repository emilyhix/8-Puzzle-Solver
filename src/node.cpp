#include "../header/node.h"

Node::Node(int algorithm, int initialArray[9]) { // initial node constructor
    this->gN = 0;
    
    // determine h(N)
    if (algorithm == 1) { //UniformCostSearch
        this->hN = 0;
    }
    if (algorithm == 2) { //A* Misplaced Tile
        this->hN = 0;
        for(int i = 0; i < 9; i++){
            if(initialArray[i] == (i + 1)){
                this->hN += 1;
            }
        }
    }
    if (algorithm == 3) { //A* Euclidean
        //hN = something
    }

    this->fN = this->gN + this->hN;
    
    // set initial
    for (int i = 0; i < 9; ++i) {
        initial_state[i] = initialArray[i];
        current_state[i] = initialArray[i];
    }

    operation = UP;
}

Node::Node(int algorithm, Operations inputOp, Node parent) { // children node constructor
        
    //set gN
    this->gN = parent.getgN() + 1;

    // set operation
    operation = inputOp;
    
    // determine h(N)
    if (algorithm == 1) { //UniformCostSearch
        this->hN = 0;
    }
    if (algorithm == 2) { //A* Misplaced Tile
        for(int i = 0; i < 9; i++){
            if(current_state[i] == (i + 1)){
                this->hN += 1;
            }
        }
    }
    if (algorithm == 3) { //A* Euclidean
        //hN = something
    }

    // keep initial state
    for (int i = 0; i < 9; ++i) {
        initial_state[i] = parent.initial_state[i];
        current_state[i] = parent.current_state[i];
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
    return true;
}

void Node::updateState() {
    int zeroIndex = 0;

    //find location of zero
    for (int i = 0; i < 9; i++) {
        if (current_state[i] == 0) {
            zeroIndex = i;
        }
    }

    // move tiles
    if (operation == UP) {
        int temp = current_state[zeroIndex - 3];
        current_state[zeroIndex - 3] = 0;
        current_state[zeroIndex] = temp;
    }
    else if (operation == DOWN) {
        int temp = current_state[zeroIndex + 3];
        current_state[zeroIndex + 3] = 0;
        current_state[zeroIndex] = temp;
    }
    else if (operation == LEFT) {
        int temp = current_state[zeroIndex - 1];
        current_state[zeroIndex - 1] = 0;
        current_state[zeroIndex] = temp;
    }
    else if (operation == RIGHT) {
        int temp = current_state[zeroIndex + 1];
        current_state[zeroIndex + 1] = 0;
        current_state[zeroIndex] = temp;
    }
}

bool Node::operator<(const Node & N) const {
    return ((gN + hN) > (N.gN + N.hN));
}

Node& Node::operator=(const Node & N) {
    for (int i = 0; i < 9; ++i) {
        initial_state[i] = N.initial_state[i];
        current_state[i] = N.current_state[i];
        goal_state[i] = N.goal_state[i];
    }
    hN = N.hN;
    gN = N.gN;
    operation = N.operation;
    return *this;
}

void Node::printNode() {
    int count3 = 0;
    cout << endl;
    for (int i = 0; i < 9; i++) {
        if (count3 > 2) {
            cout << endl;
            count3 = 0;
        }
        cout << current_state[i] << " ";
        ++count3;
    }
    cout << endl;
}

bool Node::checkFinal() {
    bool temp = true;
    
    for (int i = 0; i < 9; ++i) {
        if (current_state[i] != goal_state[i]) {
            temp = false;
        }
    }
    return temp;
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