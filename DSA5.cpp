
//A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. 
//Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation


#include<iostream>
#include<string.h>
using namespace std;
struct node
{
    char key[20],mean[20];
    node *left,*right;
};

class Dict
{
    public:
    node *root;
    void create();
    void display(node *);
    void insert(node *root,node *temp);
    int search(node *,char[]);
    int update(node *,char[]);
    node *del(node *,char[]);
    node *minimum(node *);
};
void Dict :: create()
{   
    node *temp;
    int ch;
    do
    {
        temp = new node;
        cout <<"\nEnter the Keyword : ";
        cin >> temp -> key;
        cout <<"\nEnter the meaning : ";
        cin >> temp -> mean;
        temp -> left = NULL;
        temp -> right = NULL; 
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root,temp);
        }
        cout<<"\nDo you wnt to add more Press 1 for Yes and press 0 for no : ";
        cin >> ch;

    }while (ch ==1);

}
void Dict ::display(node *root)
{
    if (root != NULL)
    {
       display(root-> left);
       cout <<"\nKeyword is : "<<root->key;
       cout <<"\nMeaning is : "<<root-> mean;
       display(root->right); 
    }
}

void Dict ::displaydc(node *root)
{
    if (root != NULL)
    {
       display(root-> right);
       cout <<"\nKeyword is : "<<root->key;
       cout <<"\nMeaning is : "<<root-> mean;
       display(root->left); 
    }
}

void Dict :: insert(node *root,node *temp)
{
    if ((strcmp(temp->key ,root->key))<0)
    {
        if(root->left ==NULL)
        {
            root->left=temp;
        }
        else
        {
           insert(root->left,temp); 
        }

    }
    else
    {
        if(root->right ==NULL)
        {
            root->right=temp;
        }
        else
        {
           insert(root->right,temp); 
        }
    }
}

int Dict :: search(node *,char k[])
{
    int c =0;
    while(root != NULL)
    {
        c++;
        if((strcmp(k,root->key))==0)
        {
            cout<<"\nNo. of Comparison : "<<c;
            return 1;
        }
        else
        {
            if((strcmp(k,root->key))<0)
                root = root -> left;
            if((strcmp(k,root->key))>0)
                root = root ->right;
        }
    }
    return -1;
}

int Dict ::update(node *,char k[])
{
   
    while (root != NULL)
    {
        if((strcmp(k,root->key))==0)
        {
            cout<<"\nEnter the new meaning of that keyword : ";
            cin>>root->mean;
            return 1;
        }
        else
        {
            if((strcmp(k,root->key))<0)
                root = root -> left;
            if((strcmp(k,root->key))>0)
                root = root ->right; 
        }
    }
    return -1;
    
}
node * Dict :: minimum(node*z)
{
    while (z->left != NULL)
    {
        z=z->left;
    }
    return z;
    
}
node *Dict :: del(node *root,char k[])
{
    node *temp;
    if (root == NULL)
    {
        cout<<"\nNo keyword Found.";
        return root;
    }
    if((strcmp(k,root->key))<0)
    {
        root -> left = del(root -> left,k);
        return root;
    }
    if((strcmp(k,root->key))>0)
    {
        root -> right = del(root -> right,k);
        return root;
    }
    if (root -> left == NULL && root -> right == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }

    if(root->right == NULL)
    {
        temp = root;
        root = root -> left;
        delete temp;
        return root;
    }
    else if(root->left == NULL)
    {
        temp = root;
        root = root -> right;
        delete temp;
        return root;
    }
    else
    {
    	temp = minimum(root ->right);
    	strcpy(root->key,temp->key);
   		root->right = del(root->right,temp->key);
   	 	return root;	
	}
    
     
}


int main()
{
    int ch;
    Dict ob;
    ob.root = NULL;
    char keyword[20];
    do
    {
        cout<<"\nPress 1 to create a BST, ";
        cout<<"\nPress 2 to display.";
        cout<<"\nPress 3 to search.";
        cout<<"\nPress 4 to Update.";
        cout<<"\nPress 5 to Delete a node."<<endl;
        cin >>ch;
        switch(ch)
        {
            case 1:
                ob.create();
                break;
            case 2:
                if (ob.root == NULL)
                    cout <<"\nNo Keyword is present.";
                else
                    ob.display(ob.root);
                break;
             case 3:
                if (ob.root == NULL)
                    cout <<"\nDictionary is not present";
                else
                {
                    cout<<"\nEnter the Keyword which you want to search : ";
                    cin >> keyword;
                    if((ob.search(ob.root,keyword))==1)
                        cout << "\nKeyword is present";
                    else
                        cout<<"\nKeyword is not Present";
                }
                break;
            case 4:
                if (ob.root == NULL)
                    cout <<"\nDictionary is not present";
                else
                {
                    cout<<"\nEnter the Keyword whose meaning you want to change : ";
                    cin>>keyword;
                    if((ob.update(ob.root,keyword))==1)
                        cout <<"\nMeaning has been updated";
                    else
                        cout<<"\nMeaning has not been updated";
                }
                break;
            case 5:
                if (ob.root == NULL)
                    cout <<"\nDictionary is not present";
                else
                {
                    cout<<"\nEnter the keyword which you want to Delete";
                    cin>>keyword;
                    if (ob.root == NULL)
                        cout<<"\nNo Keyword";
                    else
                    {
                        ob.root = ob.del(ob.root,keyword);

                    }
                }

            
        }
        
    }while (ch<=5);
    
}

