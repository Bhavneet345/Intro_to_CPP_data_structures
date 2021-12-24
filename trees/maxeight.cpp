#include<iostream>
#include<queue>
#include "treeNode.h"

treeNode<int>* takeInput()
{
    int rootData, nodes, nodeData;
    cout << "Enter the data of root\n";
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pending;
    pending.push(root);
    while(!pending.empty())
    {
        treeNode<int> *front = pending.front();
        pending.pop();
        cout << "Enter the number of children of root " << front -> data << endl;
        cin >> nodes;
        for(int i = 0; i < nodes; i++)
        {
            cout << "Enter the nodedata of " << i + 1 << "th child of " << (*front).data << endl;
            cin >> nodeData;
            treeNode <int> *child = new treeNode<int>(nodeData);
            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

int getHeight(treeNode<int> *root)
{
    int mh = 0;
    for(int i = 0; i < root -> children.size(); i++)
    {
        int temp = getHeight(root -> children[i]);
        if(temp > mh)
        {
            mh = temp;
        }
    }
    return mh + 1;
}

int main()
{
    treeNode<int> *root = takeInput();
    cout << getHeight(root);
    return 0;
}