#ifndef SEARCH_H
#define SEARCH_H
#include "..\header\node.h"
#include <queue>
#include <vector>

Node Search(int, Node);
void expand(int, Node, priority_queue<Node> &, vector<Node>);
#endif