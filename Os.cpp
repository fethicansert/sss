#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>


using namespace std;


struct node
{
	int BTime;
	int arival;
	int Prty;
	struct node* next;
	
};

struct node * createnode(int data,int,int);
struct node* insertfront(struct node* header,int data);
struct node* insertback(struct node*,int Btime,int atime,int Pr);
void insertafter(struct node*,int);
void display(struct node*);
int countlenght(struct node*);
struct node *deletefront(struct node* );
struct node* deleteback(struct node* );
void deleteafter(struct node*);
int avgofodd(struct node*);
struct node* deletee(struct node* );
struct node * insertn (struct node *, int data,int atime);
void deleteall(struct node* header);
void copylist(struct node*,struct node *);
void ekle(struct node*,struct node*);
void sort(struct node* header);
void wtime(struct node * header);


int main(int argc,char **argv)
{	

int c;
string input;
string output;


while ((c = getopt (argc, argv, "f:o:")) != -1)
{
switch (c){
	
	case 'f':
	input = optarg;
	break;
	
	case'o':
		output = optarg;
		break;
		
		
	
}	
	
}





struct node* header=NULL;	
struct node* header1=NULL;


string line;
ifstream file_(input);
int a;
int b;
int g;
string x;

if(file_.is_open())
{
	while(file_ >> a  >> x >> b >>x >>  g)
	{
		
		header=insertback(header,a,b,g);
		
		
	}
	file_.close();
	
}
else
cout<<"File is not open";

display(header);
sort(header);
		
		
cout<<endl<<endl;

cout<<endl;
display(header);

wtime(header);




}
void wtime(struct node* header)	
{
struct node* temp;
temp=header;
int wTime=0;
int sum=0;
cout<<"Waitng times  : ";

int i=1;

while(temp!=NULL)
{
	cout<<"P"<<i<<":"<<wTime<<"  ";
    wTime=wTime+temp->BTime;
    sum=sum+wTime;
    
    
    temp=temp->next;
    i++;
    
}
cout<<endl;
cout<<"Average waiting time :"<<sum/4;



}
	


struct node *createnode(int Btime,int Atime,int Prty)
{
	
	struct node* temp;
	temp=(struct node*)malloc(sizeof(node));
	temp->BTime=Btime;
	temp->arival=Atime;
	temp->Prty=Prty;
	temp->next=NULL;
	return temp;
}

struct node* insertback(struct node* header,int Btime,int Atime,int Prty)
{
	
	struct node* temp=createnode(Btime,Atime,Prty);
	struct node* headertemp;
	if(header==NULL)
	{
		header=temp;
		return header;
	}
	headertemp=header;
	while(headertemp->next !=NULL)
	{
		headertemp=headertemp->next;
	}
	headertemp->next=temp;
	return header;
			
}

void display(struct node* header)
{
	int i=1;
	if(header==NULL)
	{
		cout<<"its empty";
	}
	struct node* temp=header;
	
	
	while(temp != NULL)
	{
		
		cout<<"P"<<i<<"  ";
		cout<<temp->BTime<<":"<<temp->arival<<":"<<temp->Prty;
		cout<<endl;
		
		temp=temp->next;
		i++;
		
	}
	cout<<endl;
}

int countlenght(struct node* header)
{
	struct node* temp=header;
    int count=0;
    while( temp !=NULL)
    {
    	count++;
    	temp=temp->next;
    	
	}
	return count;
}
struct node* deletefront(struct node* header)
{
	struct node* temp;
	
	if(header==NULL)
	return header;
	
	
		
	temp=header;
	
	header=header->next;
	
	free(temp);
	
	return header;
	
}

struct node* deleteback(struct node* header)
{

	struct node* temp,*headertemp;
	if(header==NULL)
	return header;
	
	headertemp=header;
	while(headertemp->next->next!=NULL)
	{
		headertemp=headertemp->next;
	}
	temp=headertemp->next;
	headertemp->next=NULL;
	free(temp);
	return header;
}
void deleteafter(struct node* afternode)
{
	struct node* temp;
	if(afternode->next==NULL||afternode==NULL)
	return;
	
	temp=afternode->next;
	afternode->next=temp->next;
	free(temp);
	
	
	
}


void deleteall(struct node* header)
{
	 struct node* temp;


    while(header!=NULL)
    {
        temp=header;
        header=header->next;

        free(temp);
    }
	
}


	

void sort(struct node* header)
{
	
	
    struct node* temp;
    struct node* helper;
	temp=header;
	helper=header;
    int headerdata;
    int burstTime;
    
   
    	while(temp->next!=NULL)
    	{
		
    	  if(helper->arival > helper->next->arival)
         	{
    		
    		  headerdata=helper->arival;
              helper->arival=helper->next->arival;
              helper->next->arival=headerdata;
              
              burstTime=helper->BTime;
              helper->BTime=helper->next->BTime;
              helper->next->BTime=burstTime;
             
               
                   
              return sort(header);

    		
	     	}
	     	temp=temp->next;
	     	helper=temp;
    	
    	}
	
}