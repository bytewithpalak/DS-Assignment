#include <bits/stdc++.h>
using namespace std;

class Cell {
public:
    int val;
    Cell *next, *prev, *up, *down;
    Cell(int v): val(v), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
};

class MatrixLinked {
public:
    vector<vector<Cell*>> nodes;
    int R, C;

    MatrixLinked(vector<vector<int>>& mat) {
        R = mat.size();
        C = R ? mat[0].size() : 0;
        nodes.assign(R, vector<Cell*>(C, nullptr));
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++)
                nodes[i][j] = new Cell(mat[i][j]);
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++) {
                if (j+1<C) nodes[i][j]->next = nodes[i][j+1];
                if (j-1>=0) nodes[i][j]->prev = nodes[i][j-1];
                if (i-1>=0) nodes[i][j]->up = nodes[i-1][j];
                if (i+1<R) nodes[i][j]->down = nodes[i+1][j];
            }
    }

    void printRowMajor() {
        for (int i=0;i<R;i++) {
            Cell* cur = nodes[i][0];
            while (cur) {
                cout << cur->val << " ";
                cur = cur->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    MatrixLinked m(mat);
    m.printRowMajor();
}
