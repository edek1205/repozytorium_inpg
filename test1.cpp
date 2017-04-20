#include<iostream>
using namespace std;

struct node
{
int data;
node *left;
node *right;
};

class tree
{
public:
    node *head;    //pointer to root
    int count;     //stores number of elements in tree
    tree();
    void addnode(int);
    void deletenode(int);
    bool search(int);
    int minimum();
    int maximum();
    void inorder();
    void preorder();
    void postorder();
    void printtree();
    int mthlargest();     //finds 'm'th largest element
    int mthsmallest();    //finds 'm'th smallest element
    void convert();       //converts binary tree to linked list
};

tree::tree()
{
   head=NULL;
   count =0;
}

void tree::addnode(int num)
{
   node *temp= new node;
   temp->data=num;
   temp->left=NULL;
   temp->right=NULL;

   node **ptr=&head;          //double pointer

   while(*ptr!=NULL)
   {
      if(num>(*ptr)->data)
         ptr=&((*ptr)->right);

      if(num<(*ptr)->data)
         ptr=&((*ptr)->left);
   }

   *ptr=temp;
}


bool tree::search(int num)
{
   node *temp=head;

   while(temp!=NULL)
   {
      if(temp->data==num)
         break;

      if(num>temp->data)
         temp=temp->right;

      if(num<temp->data)
         temp=temp->left;
   }

   if(temp==NULL)
      return false;
   else if(temp->data==num)
      return true;   
}    




int main()
{
   tree ob;
   ob.addnode(2);

   ob.search(2);

   ob.search(3);

   ob.search(-1);
   ob.search(2);
   cout<<endl<<endl;

   system("pause");
   return 0;
}               