#include <iostream>
#include <cstddef>
class AVLNode
{
public:
    int val;
    AVLNode *leftNode;
    AVLNode *rightNode;
    int height;
    AVLNode(int v)
    {
        val =v;
        leftNode=NULL;
        rightNode=NULL;
        height=1;
    };
};
AVLNode* insertNode(int val);
AVLNode* rightright(AVLNode *node);
AVLNode* leftleft (AVLNode *node);

using namespace std;

int getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}
int getBalance(AVLNode *node)
{
    if(node == NULL)
        return 0;
    return getHeight(node->leftNode)-getHeight(node->rightNode);
}

AVLNode* rightright(AVLNode *node)
{
    AVLNode *root=node->rightNode;
    AVLNode *ll = root->leftNode;
    root->leftNode = node;
    node->rightNode=ll;
    node->height=max(getHeight(node->leftNode),getHeight(node->rightNode))+1;
    root->height=max(getHeight(root->leftNode),getHeight(root->rightNode))+1;
    return root;
}
AVLNode* leftleft(AVLNode *node)
{
    AVLNode *root = node->leftNode;
    AVLNode *tmp = root->rightNode;
    root->rightNode=node;
    node->leftNode=tmp;
    node->height=max(getHeight(node->leftNode),getHeight(node->rightNode))+1;
    tmp->height=max(getHeight(root->leftNode),getHeight(root->rightNode))+1;
    return root;
}

AVLNode *insertNode(AVLNode* root,int key

{
    if(root == 0)
    {
        return new AVLNode(key);
        cout << "Hi" << endl;
    }

    cout << "root is not null" << root << endl;
    if(key < root->val)
        root->leftNode=insertNode(root->leftNode,key);
    else
        root->rightNode=insertNode(root->rightNode,key);
    root->height=max(getHeight(root->leftNode),getHeight(root->rightNode))+1;

    int balance = getBalance(root);
    //leftleft
    if(balance>1 && root->leftNode->val > key)
        return leftleft(root);
    //leftright
    if(balance>1 && root->leftNode->val < key)
    {
         root->leftNode = rightright(root->leftNode);
         return leftleft(root);
    }
    //righteight
    if(balance <-1 && root->rightNode->val < key)
        return rightright(root);
    if(balance <-1 && root->rightNode->val > key)
    {
        root->rightNode= leftleft(root->rightNode);
        return rightright(root);
    }
    return root;

}
// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(AVLNode *root)
{
    if(root != NULL)
    {
        cout << root->val <<endl;
        preOrder(root->leftNode);
        preOrder(root->rightNode);
    }
}

/* Drier program to test above function*/
int main()
{
  AVLNode* root = 0;

  /* Constructing tree given in the above figure */
  root = insertNode(root, 10);
  root = insertNode(root, 20);
  root = insertNode(root, 30);
  root = insertNode(root, 40);
  root = insertNode(root, 50);
  root = insertNode(root, 25);


  cout<<"Pre order traversal of the constructed AVL tree is \n";
  preOrder(root);

  return 0;
}
