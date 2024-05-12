#include <iostream>
#include <vector>

using namespace std;


bool isSafe(int v, vector<vector<int> >& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}


bool graphColoringUtil(int v, vector<vector<int> >& graph, vector<int>& color, int M) {
    if (v == graph.size())
        return true;

    for (int c = 1; c <= M; c++) {
      
        if (isSafe(v, graph, color, c)) {
            color[v] = c; 
            if (graphColoringUtil(v + 1, graph, color, M))
                return true;
            color[v] = 0;
        }
    }
    return false; 
}

bool graphColoring(vector<vector<int> >& graph, int M) {
    vector<int> color(graph.size(), 0); 

   
    if (!graphColoringUtil(0, graph, color, M))
        return false; 

    return true;
}

int main() {

    int N1 = 4, M1 = 3;
    vector<vector<int> > graph1 = { {0, 1, 0, 1},
                                   {1, 0, 1, 0},
                                   {0, 1, 0, 1},
                                   {1, 0, 1, 0}};
    cout << "1 Output: " << graphColoring(graph1, M1) << endl;

    int N2 = 3, M2 = 2;
    vector<vector<int> > graph2 = { {0, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 0}};
    cout << "2 Output: " << graphColoring(graph2, M2) << endl;

return 0;
}

