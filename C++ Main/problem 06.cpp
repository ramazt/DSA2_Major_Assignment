#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a cell is valid for the rat to enter
bool isValid(int x, int y, int N, vector<vector<int> >& maze, vector<vector<bool> >& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y]);
}

// Recursive function to explore all paths in the maze
void findPaths(vector<vector<int> >& maze, int x, int y, string path, vector<string>& paths, vector<vector<bool> >& visited) {
    int N = maze.size();
    // Check if the current position is the bottom-right corner
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Define possible movements: 'L', 'R', 'U', 'D'
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    const char dir[] = {'L', 'R', 'U', 'D'};

    // Explore all possible movements
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny, N, maze, visited)) {
            findPaths(maze, nx, ny, path + dir[i], paths, visited);
        }
    }

    // Unmark the current cell (backtrack)
    visited[x][y] = false;
}

// Main function to find all paths for the rat in the maze
vector<string> ratInMaze(vector<vector<int> >& maze) {
    vector<string> paths;
    int N = maze.size();
    // Check if the start or end is blocked
    if (maze[0][0] == 0 || maze[N-1][N-1] == 0) return paths;

    vector<vector<bool> > visited(N, vector<bool>(N, false));
    findPaths(maze, 0, 0, "", paths, visited);
    return paths;
}

int main() {
    // Define the mazes
    vector<vector<int> > maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<int>> maze2 = {
        {1, 0},
        {1, 0}
    };

    // Process the first maze
    vector<string> paths1 = ratInMaze(maze1);
    cout << "Example input 1: ";
    if (paths1.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& path : paths1) {
            cout << path << " ";
        }
        cout << endl;
    }

    // Process the second maze
    vector<string> paths2 = ratInMaze(maze2);
    cout << "Example input 2: ";
    if (paths2.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& path : paths2) {
            cout << path << " ";
        }
        cout << endl;
    }

return 0;
}

