// C++ program to find predecessor and successor in a BST
#include <iostream>
#include <stack>
using namespace std;

// BST Node
struct node
{
    int data;
    struct node *left, *right;
};

/* Given a non-empty binary search tree, return the minimum data
    value found in that tree. Note that the entire tree does not need
    to be searched. */
struct node * minValue(struct node* node) {
  struct node* current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

/* Helper function that allocates a new node with the given data and
    NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = new (struct node);
  node->data   = data;
  node->left   = NULL;
  node->right  = NULL;
  //node->parent = NULL;
  return(node);
}

/* Give a binary search tree and a number, inserts a new node with
    the given number in the correct place in the tree. Returns the new
    root pointer which the caller should then use (the standard trick to
    avoid using reference parameters). */
struct node* insert(struct node* node, int data)
{
  /* 1. If the tree is empty, return a new,
      single node */
  if (node == NULL)
    return(newNode(data));
  else
  {
    /* 2. Otherwise, recur down the tree */
    if (data <= node->data)
    {
         node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    /* return the (unchanged) node pointer */
    return node;
  }
}

void printTree(struct node* root)
{
    if(root == NULL)
        return;
    else
    {
        printTree(root->left);
        cout << root->data << endl;
        printTree(root->right);
    }
}
void findInorderPreSuc(struct node* root,struct node*& suc,struct node*& pre,int key)
{
    //cout << "hello" << endl;
    if(root==NULL)
        return;
    if(root->data==key)
    {
        //cout << "hello1" << endl;
        struct node* curr=root->left;
        if(curr != NULL)
        {
            while(curr->right!=NULL)
                curr=curr->right;
            pre = curr;
        }
        curr=root->right;
        if(curr != NULL)
        {
            while(curr->left!=NULL)
                curr=curr->left;
            suc=curr;
        }
        return;
    }
    else if(root->data > key)
    {
        //cout << "hello2" << endl;
        suc = root;
        findInorderPreSuc(root->left,suc,pre,key);
    }
    else
    {
        //cout << "hello3" << endl;
        pre = root;
        findInorderPreSuc(root->right,suc,pre,key);
    }

}
void printAllGreter(struct node* root,int& val)
{
    if(root==NULL)
        return;
    printAllGreter(root->right,val);
    val=root->data+val;
    root->data=val;
    printAllGreter(root->left,val);
}
struct node* construstTree(int arr[],int& index,int min,int max,int size)
{
    if(index >=size)
        return NULL;
    struct node* root=NULL;
    if(arr[index]>min && arr[index]<max)
    {
        root=newNode(arr[index]);
        index++;
        root->left=construstTree(arr,index,min,root->data,size);
        root->right=construstTree(arr,index,root->data,max,size);
    }
    return root;
};

void printCommonNode(struct node* root1,struct node* root2)
{
   stack<struct node*> s1,s2;
   while(1)
   {
        while(root1!=NULL)
        {
            s1.push(root1);
            root1=root1->left;
        }
        while(root2!=NULL)
        {
            s2.push(root2);
            root2=root2->left;
        }
        if(!s1.empty() || !s2.empty())
        {
            struct node* tmp1 = s1.top();
            struct node* tmp2 = s2.top();
            //cout << tmp1->data;
            //cout <<' ' << tmp2->data;
            //cout << endl;
            if(tmp1->data==tmp2->data)
            {
                cout << tmp1->data << endl;
                s1.pop();
                s2.pop();
                root1=tmp1->right;
                root2=tmp2->right;
            }
            else if(tmp1->data > tmp2->data)
            {
                s2.pop();
                root2 =tmp2->right;
            }
            else
            {
                s1.pop();
                root1=tmp1->right;
            }
        }
        else
            break;
   }
}
/* Driver program to test above functions*/
int main()
{
  struct node* root = NULL;
  struct node* succ = NULL;
  struct node* pre = NULL;
  int key;

  //creating the tree given in the above diagram
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);
  struct node* root2=NULL;
   root2 = insert(root2, 21);
  root2 = insert(root2, 8);
  root2 = insert(root2, 22);
  root2 = insert(root2, 4);
  root2 = insert(root2, 18);
  root2 = insert(root2, 10);
  root2 = insert(root2, 16);
  //temp = root->left->right->right;
 /*
  succ =  inOrderSuccessor(root, temp);
  if(succ !=  NULL)
    printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);
  else
    printf("\n Inorder Successor doesn't exit");

  getchar();
  */
  printTree(root);
  printTree(root2);
  cin >> key;
  findInorderPreSuc(root,succ,pre,key);
  //cout << "hi" << endl;
  if(succ != NULL)
    cout << succ->data << endl;
  if(pre != NULL)
    cout<< pre->data << endl;
    int val=0;
  //printAllGreter(root,val);
  //printTree(root);
  int preee[] = {10, 5, 1, 7, 40, 50};
  int index=0;
  struct node* r = construstTree(preee,index,-1,10000,6);
  printTree(r);
  //cout << "common" << endl;
  printCommonNode(root,root2);
  return 0;
}
