#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("mergeheap.in");
ofstream fout("mergeheap.out");
 
class Node {
private:
    Node* leftChild;
    Node* brother;
    int val;
 
public:
    Node() : leftChild(nullptr), brother(nullptr), val(-1) {};
    Node(int v, Node* left = nullptr, Node* bro = nullptr) : leftChild(left), brother(bro), val(v) {};
 
    int getVal() {
        return val;
    }
 
    Node* getLeftChild() {
        return leftChild;
    }
 
    void setLeftChild(Node* left) {
        leftChild = left;
    }
 
    Node* getBrother() {
        return brother;
    }
 
    void setBrother(Node* bro) {
        brother = bro;
    }
 
    void addChild(Node* heap) {
        if(leftChild == nullptr) 
            leftChild = heap;
        else {
            heap->setBrother(leftChild);
            leftChild = heap;
        }
    }

    int top() {
        return val;
    }
 
    ~Node() {
        delete leftChild;
        delete brother;
    }
};
 
Node* merge(Node* a, Node* b) {
        if(a == nullptr) return b;
        if(b == nullptr) return a;
 
        if( a->getVal() > b->getVal() ) {
            a->addChild(b);
            return a;
        } else {
            b->addChild(a);
            return b;
        }
 
        return nullptr;
}
 
Node* insert(Node* a, int val_) {
    return merge(a, new Node(val_));
}
 
Node* createNewHeap(Node* a) {
    if( a == nullptr || a->getBrother() == nullptr )
        return a;
    else {
        Node* first = a;
        Node* second = a->getBrother();
        Node* maybe = a->getBrother()->getBrother();
 
        first->setBrother(nullptr);
        second->setBrother(nullptr);
 
        return merge( merge(first, second), createNewHeap(maybe) );
    }
}

Node* naiveCreateNewHeap(Node* a) {
    //a is left child
    if( a == nullptr || a->getBrother() == nullptr ) 
        return a;
    else {
        Node* first = a;
        Node* brother = a->getBrother();
        first->setBrother(nullptr);

        while( brother != nullptr ) {
            first->addChild(brother);
            brother = brother->getBrother();
        }

        return first;
    }
}
 
vector<Node*> v;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, q, op, val1, val2;
    fin >> n >> q;
    v.resize(n + 2);
 
    for(int i = 0; i < q; i++) {
        fin >> op >> val1;
        if( op != 2 ) fin >> val2;
 
        if( op == 1 ) {
            v[val1] = insert(v[val1], val2);
        } else if( op == 2 ) {
            fout << v[val1]->top() << '\n';
            v[val1] = createNewHeap(v[val1]->getLeftChild());
        } else {
            v[val1] = merge(v[val1], v[val2]);
            v[val2] = nullptr;
        }
    }
 
    return 0;
}