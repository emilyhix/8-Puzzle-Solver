#include "..\header\Search.h"

Node Search(int algorithm, Node initialNode) {
    
    priority_queue<Node> frontier;
    vector<Node> explored;

    int totalNodesExpanded = 0;
    int longestFrontier = 0;

    frontier.push(initialNode);
    longestFrontier = frontier.size();

    while (!frontier.empty()) {
        Node temp = frontier.top();
        totalNodesExpanded++;
        //cout << "top of frontier:" << endl;
        //temp.printNode();
        //cout << "top of queue h(n): " << temp.gethN() << endl;
        if (temp.checkFinal()) {

            cout << "GOAL :D" << endl;
            cout << endl << "To solve this puzzle, the maximum number of nodes expanded (including the initial node/state) is " << totalNodesExpanded << "!!!" << endl;
            cout << "The maximum number of nodes in the queue at any one time: " << longestFrontier << "!" << endl;
            cout << "The depth of the goal node was " << temp.getgN() << "." << endl;
            
            return temp;
        }
        else {
            cout << "The best node to expand has g(n) = " << temp.getgN() << " and h(n) = " << temp.gethN() << "." << endl;
            temp.printNode();
            cout << "Expanding node #" << totalNodesExpanded << "..." << endl << endl;
            frontier.pop();
            explored.push_back(temp);
            expand(algorithm, temp, frontier, explored); 

            if (frontier.size() > longestFrontier){
                longestFrontier = frontier.size();
            }
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
            up.updateState(algorithm);
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
            down.updateState(algorithm);
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
            left.updateState(algorithm);
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
            right.updateState(algorithm);
            frontier.push(right);
        }
    }
    return;
}