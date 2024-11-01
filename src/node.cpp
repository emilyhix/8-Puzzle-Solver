#include "../header/node.h"

Node::Node(int algorithm, int initialArray[9]) { // initial node constructor
    gN = 0;
    
    // determine h(N)
    if (algorithm == 1) { //UniformCostSearch
        hN = 0;
    }
    if (algorithm == 2) { //A* Misplaced Tile
        hN = AStarMTHeuristic(initialArray);
    }
    if (algorithm == 3) { //A* Euclidean
        hN = AStarEDHeuristic(initialArray);
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
    gN = parent.getgN() + 1;

    // set operation
    operation = inputOp;
    
    // determine h(N)
    if (algorithm == 1) { //UniformCostSearch
        hN = 0;
    }
    if (algorithm == 2) { //A* Misplaced Tile
        hN = AStarMTHeuristic(current_state);
    }
    if (algorithm == 3) { //A* Euclidean
        hN = AStarEDHeuristic(current_state);
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

void Node::updateState(int algorithm) {
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

    if (algorithm == 1) { //UniformCostSearch
        //updateState();
        hN = 0;
    }
    if (algorithm == 2) { //A* Misplaced Tile
        hN = AStarMTHeuristic(current_state);
    }
    if (algorithm == 3) { //A* Euclidean
        hN = AStarEDHeuristic(current_state);
    }

}

bool Node::operator<(const Node & N) const {
    return ((gN + hN) > (N.gN + N.hN));
}

bool Node::operator>(const Node & N) const {
    return ((gN + hN) < (N.gN + N.hN));
}

bool Node::operator== (const Node &N) {
    bool result = true;

    for (int i = 0; i < 9; i++) {
        if (current_state[i] != N.current_state[i]) {
            result = false;
        }
    }
    if (gN != N.gN) {
        result = false;
    }
    if (hN != N.hN) {
        result = false;
    }
    return result;
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

double Node::gethN() {
    return hN;
}

int Node::getGoalMatrix(int i, int j){
    return goal_matrix[i][j];
}

int Node::AStarMTHeuristic(int board[9]){
    int hN = 0;

    int matrix[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int count = 0;

    for(int i = 0; i < 3; i++){ // populate matrix
        for(int j = 0; j < 3; j++){
            matrix[i][j] = board[count];
            count++;
        }
    }
    for(int i = 0; i < 3; i++){ // compare matrix at point i,j to final solution i,j
        for(int j = 0; j < 3; j++){
            if(matrix[i][j] != getGoalMatrix(i, j)) {
                ++hN;
            }
        }
    }
    return hN;
}

double Node::AStarEDHeuristic(int array[9]){
    int matrix[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int count = 0;

    for(int i = 0; i < 3; i++){ // populate matrix
        for(int j = 0; j < 3; j++){
            matrix[i][j] = array[count];
            count++;
        }
    }

    int distX = 0;
    int distY = 0;
    double distance = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(matrix[i][j] != getGoalMatrix(i,j)){ // if curr matrix != goal matrix
                for(int m = 0; m < 3; m++){ // find goal matrix location
                    for(int n = 0; n < 3; n++){
                        if(getGoalMatrix(m,n) == matrix[i][j]){ // found goal matrix location
                            distX = m - i; // calculate 
                            distY = n - j;

                            distance += sqrt((distX * distX)+(distY * distY)); // find the heuristic
                        }
                    }
                }
            }
        }
    }

    return distance;
}