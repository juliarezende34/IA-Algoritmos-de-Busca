#include "functions.h"
int memoryUsage = 0, memoryDFS = 0;

vector<vector<int>> matriz = {
        {0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0}
};

unordered_map<char, int> char_to_index = {
        {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4},
        {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9},
        {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14},
        {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},
        {'U', 20}, {'V', 21}, {'X', 22}, {'Y', 23}, {'Z', 24}
};

void DFS(vector<vector<int>>& matriz, int start, int end, vector<bool>& visited, vector<int>& parent, unordered_set<int>& currentPath, bool& foundPath) {
    if (start == end) {
        // Print the path and set the foundPath flag
        cout << "Path found: ";
        int curr = end;
        while (curr != -1) {
            cout << (char)(curr + 'A') << " ";
            curr = parent[curr];
        }
        cout << endl;
        foundPath = true;
        return;
    }

    if (visited[start] || currentPath.count(start) || foundPath) {
        return; // Avoid cycles, already visited nodes, or if a path is found
    }

    visited[start] = true;
    currentPath.insert(start);
    memoryDFS += sizeof(start);

    for (int i = 0; i < (int)matriz.size(); ++i) {
        if (matriz[start][i] && !visited[i]) {
            parent[i] = start;
            DFS(matriz, i, end, visited, parent, currentPath, foundPath);
        }
    }

    // Clean up the current path for backtracking
    currentPath.erase(start);
    visited[start] = false;
}

void call_dfs() {
    cout << " -- DFS -- " << endl;
    // Assuming 'U' has index 20 and 'E' has index 4
    int start = 20; // 'U'
    int end = 4;   // 'E'

    int n = matriz.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    unordered_set<int> currentPath;

    bool foundPath = false;
    DFS(matriz, start, end, visited, parent, currentPath, foundPath);

    cout << "Memória usada: " << memoryDFS << " B\n";
}

void BFS(vector<vector<int>>& matriz, int start, int end) {
    int n = matriz.size();
    vector<bool> visited(n, false);
    queue<int> q;
    vector<int> parent(n, -1);

    q.push(start);
    visited[start] = true;

    bool foundPath = false;

    while (!q.empty() && !foundPath) {
        int curr = q.front();
        q.pop();

        if (curr == end) {
            // Print the path
            cout << "Path found: ";
            while (curr != -1) {
                cout << (char)(curr + 'A') << " ";
                curr = parent[curr];
            }
            cout << endl;
            foundPath = true;
            break;
        }

        for (int i = 0; i < n; ++i) {
            if (matriz[curr][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = curr;
                q.push(i);
                memoryUsage += sizeof(i);
            }
        }
    }
}

void call_bfs() {
    cout << " -- BFS -- " << endl;
    // Assuming 'U' has index 20 and 'E' has index 4
    int start = 20; // 'U'
    int end = 4;   // 'E'

    BFS(matriz, start, end);

    cout << "Memória usada: " << memoryUsage << " B\n";
}