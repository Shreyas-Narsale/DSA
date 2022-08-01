#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}NODE, *PNODE;

class DoublyCL
{
	private:
	PNODE first=NULL;
	PNODE last=NULL;
	int size=0;
	public:
	DoublyCL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}
	void InsertFirst(int no)
	{
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->prev=NULL;
		newn->data=no;
		if((first==NULL)&&(last==NULL))
		{
			first=newn;
			last=first;
		}
		else
		{
			newn->next=first->next;
			first->prev=newn;
			first=newn;
		}
		first->prev=last;
		last->next=first;
		size++;
	}
	void Display()
	{
		PNODE temp=first;
		do
		{
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}while(temp!=last->next);
			
		cout<<"NULL";
	}
			
		
		
		
};
int main()
{
	
	DoublyCL dobj;
	dobj.InsertFirst(51);
	dobj.InsertFirst(21);
	dobj.InsertFirst(11);
	dobj.Display();
	
	return 0;
}