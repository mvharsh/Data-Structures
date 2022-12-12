#include<iostream>
using namespace std;

class node
{
 public:
 int data;
 node* left;
 node* right;
 int height;
};

int height(node* n)
{
 if(n==NULL)
    return 0;
 else
    return n->height;
}

int getBalance(node* n)
{
 if(n==NULL)
    return 0;
 else
    return(height(n->left) - height(n->right));
}

node* rightRotate(node* y)
{
 node* x = y->left;
 node* T2 = x->right;
 x->right = y;
 y->left = T2;
 y->height = 1 + max(height(y->left),height(y->right));
 x->height = 1 + max(height(x->left),height(x->right));
 return x;
}

node* leftRotate(node* x)
{
 node* y = x->right;
 node* T2 = y->left;
 y->left = x;
 x->right = T2;
 y->height = 1 + max(height(y->left),height(y->right));
 x->height = 1 + max(height(x->left),height(x->right));
 return y;
}

node* InsertNode(node* root, int data)
{
 if(root == NULL)
 {
  node* nn = new node();
  nn->data = data;
  nn->left = NULL;
  nn->right = NULL;
  root = nn;
  return root;
 }
 if(data < root->data)
    root->left = InsertNode(root->left, data);
 else if(data > root->data)
    root->right = InsertNode(root->right, data);
 root->height = 1 + max(height(root->left),height(root->right));
 int balance = getBalance(root);
 if(balance > 1 && data < root->left->data)
    return rightRotate(root);
 if(balance < -1 && data > root->right->data)
    return leftRotate(root);
 if(balance > 1 && data > root->left->data)
 {
    root->left = leftRotate(root->left);
    return rightRotate(root);
 }
 if(balance < -1 && data < root->right->data)
 {
    root->right = rightRotate(root->right);
    return leftRotate(root);
 }
 return root;
}

node* MinValueNode(node* root)
{
 node* current = root;
 while(current && current->left!=NULL)
 {
  current = current->left;
 }
 return current;
}

node* DeleteNode(node* root, int data)
{
 if(root == NULL)
 {
  cout<<"No element to delete\n";
  return root;
 }
 if(data < root->data)
    root->left = DeleteNode(root->left, data);
 else if(data > root->data)
    root->right = DeleteNode(root->right, data);
 else
 {
  if(root->left==NULL && root->right==NULL)
    return NULL;
  if(root->right==NULL)
  {
    node* temp = root->left;
    delete(root);
    return temp;
  }
  else if(root->left==NULL)
  {
    node* temp = root->right;
    delete(root);
    return temp;
  }
  node* temp = MinValueNode(root->right);
  root->data = temp->data;
  root->right = DeleteNode(root->right, temp->data);
 }
  root->height = 1 + max(height(root->left),height(root->right));
 int balance = getBalance(root);
 if(balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);
 if(balance < -1 && getBalance(root->right) >= 0)
    return leftRotate(root);
 if(balance > 1 && getBalance(root->left) < 0)
 {
    root->left = leftRotate(root->left);
    return rightRotate(root);
 }
 if(balance < -1 && getBalance(root->right) < 0)
 {
    root->right = rightRotate(root->right);
    return leftRotate(root);
 }
 return root;
}

void searchNode(node* root, int key)
{
 int depth = 0;
 node* temp = root;
 while(temp!=NULL)
 {
  depth++;
  if(temp->data == key)
  {
    cout<<"Element found at depth "<<depth<<endl;
    return;
  }
  else if(key < temp->data)
    temp = temp->left;
  else
    temp = temp->right;
 }
 cout<<"Element not found";
 return;
}

void inorder(node* root)
{
 if(root==NULL)
    return;
 else{
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
 }
}

int main()
{
 int ch,key;
 node* root = NULL;
 cout<<"\n== AVL TREE ==\n";
 cout<<"1.Insertion\n2.Deletion\n3.Search\n4.Display\n5.Exit\n";
 while(1)
 {
    cout<<"\n\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
     case 1:
        cout<<"Enter element to insert: ";
        cin>>key;
        root = InsertNode(root,key);
        cout<<"Element inserted";
        cout<<"\n\nAVL: ";
        inorder(root);
        break;

     case 2:
        cout<<"Enter element to delete: ";
        cin>>key;
        root = DeleteNode(root,key);
        cout<<"Element deleted";
        cout<<"\n\nAVL: ";
        inorder(root);
        break;

     case 3:
        cout<<"Enter element to search: ";
        cin>>key;
        searchNode(root,key);
        break;

     case 4:
        cout<<"\n\nAVL: ";
        inorder(root);
        break;

     case 5:
        return 0;
    }
 }
}
