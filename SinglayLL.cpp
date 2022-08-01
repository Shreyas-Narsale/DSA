
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class SinglyLL
{
	private:
	PNODE first;
	int size;
	public:
	
	SinglyLL()
	{
		first=NULL;
		size=0;
	}
	void InsertFirst(int no)
	{
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->data=no;
		
		if(first==NULL)
		{
			first=newn;
		}
		else 
		{
			newn->next=first;
			first=newn;
		}
		size++;
	}
	void InsertAtPos(int iPos,int no)
	{
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->data=no;
		if((iPos>size+1)||(iPos<1))
		{
			cout<<"enter valid Pos";
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
			while(iCnt<iPos)
			{
				temp=temp->next;
				iCnt++;
			}
			newn->next=temp->next;
			temp->next=newn;
		}
				
		size++;		
				
	}
			
	void InsertLast(int no)
	{
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->data=no;
		
		if(first==NULL)
		{
			first=newn;
		}
		else 
		{
			PNODE temp=first;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
			
		}
		size++;
	}
	
		
	void DeleteFirst()
	{
		if(first==NULL)
		{
			cout<<"LinkedList is Empty";
		}
		if(first->next==NULL)
		{
			first=NULL;
		}
		else
		{
			PNODE temp=first;
			first=first->next;
			delete temp;
		}
		size--;
	}
	void DeleteLast()
	{
		if(first==NULL)
		{
			cout<<"LinkedList is Empty";
		}
		if(first->next==NULL)
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
			cout<<"enter valid Pos";
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
			while(iCnt<iPos)
			{
				temp=temp->next;
				iCnt++;
			}
			PNODE targeted=temp->next;
			temp->next=targeted->next;
			delete targeted;
		}
				
		size--;		
				
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
	SinglyLL sobj;
	sobj.InsertFirst(51);
	sobj.InsertFirst(21);
	sobj.InsertFirst(11);
	sobj.InsertLast(101);
	//sobj.DeleteLast();
	sobj.InsertAtPos(2,31);
	sobj.Display();
	sobj.DeleteAtPos(2);
	sobj.Display();
	

	
	return 0;
}