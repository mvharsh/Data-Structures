#include <iostream>
using namespace std;

class node {
 public:
  int data;
  node* left;
  node* right;
  node(int val)
  {
   data=val;
   left=NULL;
   right=NULL;
  }
};

int countNodes(node* root)
{
  if(root==NULL)
    return 0;
  else
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int Findheight(node* root)
{
  if(root==NULL)
    return 0;
  else
  {
    int L = Findheight(root->left);
    int R = Findheight(root->right);
    if(L>R)
      return L + 1;
    else
      return R + 1;
  }
}

void inorder(node* root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
}

void preorder(node* root)
{
  if(root!=NULL)
  {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(node* root)
{
  if(root!=NULL)
  {
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
}

int search(node* root,int d)
{
 static int flag=0;
 if(root!=NULL)
  {
    if(root->data==d)
        flag=1;
    search(root->left,d);
    search(root->right,d);
  }
  return flag;
}

int main()
{
 int d;
 node* root = new node(1);
 root->left = new node(2);
 root->right = new node(3);
 root->left->left = new node(4);
 root->left->right = new node(5);
 root->right->left = new node(9);
 root->right->right = new node(8);
 root->left->left->left = new node(6);
 root->left->left->right = new node(7);
 cout<<"Inorder traversal: ";
 inorder(root);
 cout<<"\nPreorder traversal: ";
 preorder(root);
 cout<<"\nPostorder traversal: ";
 postorder(root);
 cout<<"\n\nCOUNT = "<<countNodes(root)<<endl;
 cout<<"\nHEIGHT = "<<Findheight(root)-1<<endl;
 cout<<"\nEnter data to search: ";
 cin>>d;
 if(search(root,d))
   cout<<"\nDATA PRESENT"<<endl;
 else
   cout<<"\nDATA NOT PRESENT"<<endl;;
 return 0;
}
