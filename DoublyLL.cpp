

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}NODE, *PNODE;

class DoublyLL
{
	private:
	PNODE first;
	int size;
	
	public:
	DoublyLL()
	{
		first=NULL;
		size=0;
	}
	void InsertFirst(int no)
	{
		
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->prev=NULL;
		newn->data=no;
		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			newn->next=first;
			first=newn;
			newn->next->prev=newn;
		}
		size++;
	}
	void InsertAtPos(int iPos,int no)
	{
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->prev=NULL;
		newn->data=no;
		if((iPos>size+1)||(iPos<1))
		{
			cout<<"Enter Valid Pos\n";
			return ;
		}
		if(iPos==1)
		{
			InsertFirst(no);
		}
		else if(iPos==size+1)
		{
			InsertLast(no);
		}
		else
		{
			int iCnt=1;
			PNODE temp=first;
			while(iCnt<(iPos-1))
			{
				temp=temp->next;
				iCnt++;
			}
			newn->next=temp->next;
			temp->next=newn;
			newn->prev=temp;
			newn->next->prev=newn;
			size++;
		}
			
	}
	void InsertLast(int no)
	{
		
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->prev=NULL;
		newn->data=no;
		if(first==NULL)
		{
			InsertFirst(no);
		}
		else
		{
			PNODE temp=first;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
			newn->prev=temp;
		}
		size++;
	}
	void DeleteFirst()
	{
		if(first==NULL)
		{
			return;
		}
		else if(first->next==NULL)
		{
			first=NULL;
		}
		else
		{
			first=first->next;
			delete first->prev;
			first->prev=NULL;
		}
		size--;
	}
	void DeleteLast()
	{
		if(first==NULL)
		{
			return;
		}
		else if(first->next==NULL)
		{
			first=NULL;
		}
		else
		{
			PNODE temp=first;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			delete temp->next;
			temp->next=NULL;
		}
		size--;
	}
	void DeleteAtPos(int iPos)
	{
		
		if((iPos>size)||(iPos<1))
		{
			cout<<"Enter Valid Pos\n";
			return ;
		}
		if(iPos==1)
		{
			DeleteFirst();
		}
		else if(iPos==size)
		{
			DeleteLast();
		}
		else
		{
			int iCnt=1;
			PNODE temp=first;
			while(iCnt<(iPos-1))
			{
				temp=temp->next;
				iCnt++;
			}
			PNODE targetd=temp->next;
			temp->next=targetd->next;
			temp->next->prev=temp;
			size++;
		}
			
	}
	
	void Display()
	{
		PNODE temp=first;
		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}
		cout<<"NULL";
	}
	
	int Count()
	{
		return size;
	}
			
	
};
int main()
{
	DoublyLL dobj;
	dobj.InsertFirst(51);
	dobj.InsertFirst(21);
	dobj.InsertFirst(11);
	dobj.InsertLast(101);
	dobj.DeleteAtPos(4);
	dobj.Display();
	cout<<"\n Length is:"<<dobj.Count()<<"\n";
	
	
	return 0;
}