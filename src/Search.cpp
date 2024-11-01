#include "..\header\Search.h"

Node Search(int algorithm, Node initialNode) {
    
    priority_queue<Node> frontier;
    vector<Node> explored;

    frontier.push(initialNode);

    while (!frontier.empty()) {
        Node temp = frontier.top();
        if (temp.checkFinal()) {
            return temp;
        }
        else {
            frontier.pop();
            explored.push_back(temp);
            expand(algorithm, temp, frontier, explored);
        }
    }
    return initialNode; //ERROR - SHOULD NOT REACH  
}

void expand(int algorithm, Node parent, priority_queue<Node> &frontier, vector<Node> explored) {
    Node up(algorithm, UP, parent);
    Node down(algorithm, DOWN, parent);
    Node left(algorithm, LEFT, parent);
    Node right(algorithm, RIGHT, parent);

    bool upPresent = false;
    bool downPresent = false;
    bool leftPresent = false;
    bool rightPresent = false;

    if (up.Valid()) {
        for (int i = 0; i < explored.size(); i++) {
            if (up == explored[i]) {
                upPresent = true;
            }
        }
        if (!upPresent) {
            up.updateState();
            frontier.push(up);
        }
    }
    if (down.Valid()) {
        for (int i = 0; i < explored.size(); i++) {
            if (down == explored[i]) {
                downPresent = true;
            }
        }
        if (!downPresent) {
            down.updateState();
            frontier.push(down);
        }
    }
    if (left.Valid()) {
        for (int i = 0; i < explored.size(); i++) {
            if (left == explored[i]) {
                leftPresent = true;
            }
        }
        if (!leftPresent) {
            left.updateState();
            frontier.push(left);
        }
    }
    if (right.Valid()) {
        for (int i = 0; i < explored.size(); i++) {
            if (right == explored[i]) {
                rightPresent = true;
            }
        }
        if (!rightPresent) {
            right.updateState();
            frontier.push(right);
        }
    }
    return;
}