#include "..\header\Search.h"

Node Search(int algorithm, Node initialNode) {
    
    priority_queue<Node> frontier;
    vector<Node> explored;

    frontier.push(initialNode);

    while (!frontier.empty()) {
        
        Node temp = frontier.top();
        temp.printNode();
        if (temp.checkFinal()) {
            return temp;
        }
        else {
            frontier.pop();
            explored.push_back(temp);
            expand(1, temp, frontier, explored);
        }
    }
    return initialNode; //ERROR - SHOULD NOT REACH  
}

// temporary function so that Baipon doesn't get confused
// void AStarMisplacedTilesSearch(Node initialNode){
//     priority_queue<Node> frontier;
//     priority_queue<Node> explored;

//     if(frontier.empty()){
//         return;
//     }

//     return;
// }

void expand(int algorithm, Node parent, priority_queue<Node> &frontier, vector<Node> explored) {
    Node up(algorithm, UP, parent);
    Node down(algorithm, DOWN, parent);
    Node left(algorithm, LEFT, parent);
    Node right(algorithm, RIGHT, parent);
    up.updateState();
    down.updateState();
    left.updateState();
    right.updateState();

    bool upPresent = false;
    bool downPresent = false;
    bool leftPresent = false;
    bool rightPresent = false;

    for (int i = 0; i < explored.size(); i++) {
        if (up == explored[i]) {
            upPresent = true;
        }
        if (down == explored[i]) {
            downPresent = true;
        }
        if (left == explored[i]) {
            leftPresent = true;
        }
        if (right == explored[i]) {
            rightPresent = true;
        }
    }
    if ((up.Valid()) && !upPresent) {
        frontier.push(up);
    }
    if ((down.Valid()) && !downPresent) {
        frontier.push(down);
    }
    if ((left.Valid()) && !leftPresent) {
        frontier.push(left);
    }
    if ((right.Valid()) && !rightPresent) {
        frontier.push(right);
    }
}