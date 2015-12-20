#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    char letter;
    double freq;
    Node* left;
    Node* right;

    Node(char letter, double freq, Node* left, Node* right):
        letter(letter),freq(freq),left(left),right(right){};
};

bool operator <(const Node& A, const Node& B)
{
    return A.freq < B.freq;
}

bool operator >(const Node& A, const Node& B)
{
    return A.freq > B.freq;
}

Node GenerateTree(priority_queue<Node, vector<Node>, greater<Node>>& Q, vector<Node>* result)
{
    int size = Q.size();
    while(size > 1)
    {
        result->push_back(Q.top());
        Q.pop();
        result->push_back(Q.top());
        Q.pop();
        int num = result->size();
        Node Z(' ', (*result)[num - 2].freq + (*result)[num - 1].freq, &((*result)[num - 2]), &((*result)[num - 1]));
        Q.push(Z);
        size = Q.size();
    }
    return Q.top();
}

void Print(Node& node)
{
    if(node.letter != ' ')
        cout << node.letter << "\t";

    if(node.left != nullptr)
        Print(*node.left);
    if(node.right != nullptr)
        Print(*node.right);
}

int main()
{
    priority_queue<Node, vector<Node>, greater<Node> > Q;
    Node A('a', 45, nullptr, nullptr);
    Q.push(A);
    Node B('b', 13, nullptr, nullptr);
    Q.push(B);
    Node C('c', 12, nullptr, nullptr);
    Q.push(C);
    Node D('d', 16, nullptr, nullptr);
    Q.push(D);
    Node E('e', 9, nullptr, nullptr);
    Q.push(E);
    Node F('f', 5, nullptr, nullptr);
    Q.push(F);
    vector<Node> result;
    Node root = GenerateTree(Q, &result);
    cout << "The result is :";
    Print(root);
    return 0;
}
