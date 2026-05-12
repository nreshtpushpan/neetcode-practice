/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node * recur(const vector<vector<int>>& g, int n, int r, int c) {
        bool isSame = true;
        for(int i = 0; i < n && isSame; i++) {
            for(int j = 0; j < n && isSame; j++) {
                if(g[r][c] != g[r + i][c + j]) {
                    isSame = false;
                    break;
                }
            }
        }
        if(isSame) {
            return new Node(g[r][c], true);
        }
        n = n/2;
        Node * topLeft = recur(g, n, r, c);
        Node * topRight = recur(g, n, r, c + n);
        Node * bottomLeft = recur(g, n, r + n, c);
        Node * bottomRight = recur(g, n, r + n, c + n);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        return recur(grid, n, 0, 0);
    }
};