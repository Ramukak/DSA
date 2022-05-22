#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node
{
	node *next;
	int time;
	string vertex;
};

class ADJM 
{
	int m[10][10],i,j,n;
	char ch;
	string v[20];
	node *head[20],*temp = NULL;
	public:
		void getgraph();
		void adjlist();
		void displaym();
		void displaya();
}ob;

void ADJM :: getgraph()
{
	cout<<"Enter the no. of citites : ";
	cin>>n;
	cout<<"Enter names of cities";
	for (i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i == j)
			{
				m[i][j] = 0;
			}
			else
			{
				cout<<"press y if path is present between city "<<v[i] << "and city "<<v[j]<<endl;
				cin>>ch;
				if( ch == 'y')
				{
					cout<<"Enter time required to reach from "<<v[i]<<" to "<<v[j]<<"in minutes : "<<endl;
					cin>>m[i][j];
				}
				else if (ch == 'n')
				{
					m[i][j] = 0;
				}
				else
				{
					cout<<"Unknown entry";
				}
			}
		}
	}adjlist();
	
}

void ADJM :: adjlist()
{
	cout<<endl;
	for (i=0;i<n;i++)
	{
		node * p = new node;
		p->next = NULL;
		p->vertex = v[i];
		p->time = m[i][j];
		head[i] = p;
		cout<<endl<<head[i]->vertex;
	}
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if (m[i][j] != 0)
			{
				node *p = new node;
				
                p->vertex=v[j];
	            p->time=m[i][j];
	            p->next=NULL;
	            if(head[i]->next==NULL)
	            {  
	                head[i]->next=p;   
	            }
	            else
	            {  
	                temp=head[i];
	                while(temp->next!=NULL)
	                {   
	            		temp=temp->next;  
	                }
	                temp->next=p;
	        	}
			}
		}
	}
	}


void ADJM ::displaym()
{    cout<<"\n";
    for(j=0;j<n;j++)
    {  
		cout<<"\t"<<v[j]; 
	}

    for(i=0;i<n;i++)
    {  
		cout<<"\n "<<v[i];
        for(j=0;j<n;j++)
        {   
			cout<<"\t"<<m[i][j];
        }
        cout<<"\n";
    }
} 

void ADJM ::displaya()
{     
   cout<<"\n adjacency list is";
   for(i=0;i<n;i++)
   {       
	if(head[i]==NULL)
	{   
		cout<<"\n adjacency list not present";  
		break;   
	}
	else
	{ 
		cout<<"\n"<<head[i]->vertex;
		temp=head[i]->next;
		while(temp!=NULL)
		{
			cout<<"-> "<<temp->vertex;
			temp=temp->next;  
		}
		    
	}
    }
	cout<<"\n path and time required to reach cities is";
   
   for(i=0;i<n;i++)
   { 
	if(head[i]==NULL)
    {   
		cout<<"\n adjacency list not present";  
		break;   
	}
	else
    {    
	    temp=head[i]->next;
	    while(temp!=NULL)
	    {  
			cout<<"\n"<<head[i]->vertex;
		    cout<<"-> "<<temp->vertex<<"\n   [time required: "<<temp->time<<" min ]";
		    temp=temp->next;  
		}
	} 
   }
}

int main()
{  
   int m;   
   while(1)
   {
   cout<<"\n Enter the choice";
   cout<<"\n 1.enter graph";
   cout<<"\n 2.display adjacency matrix for cities";
   cout<<"\n 3.display adjacency list for cities";
   cout<<"\n 4.exit"<<endl;
   cin>>m;
  
        switch(m)
       {            case 1: 
	   					ob.getgraph();
                        break;
                    case 2: 
						ob.displaym();
                        break;
                    case 3: 
						ob.displaya();
                        break;
                    case 4: 
						exit(0);
                        default:  cout<<"\n unknown choice";
         }
    }
    return 0;
}  

