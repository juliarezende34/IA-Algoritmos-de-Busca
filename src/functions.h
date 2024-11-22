#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& matriz, int start, int end, vector<bool>& visited, vector<int>& parent, unordered_set<int>& currentPath, bool& foundPath);
void call_dfs();
void BFS(vector<vector<int>>& matriz, int start, int end);
void call_bfs();

#endif