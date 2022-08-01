

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE;

class SinglyCL
{
	
	private:
	PNODE first;
	PNODE last;
	int size;
	public:
	SinglyCL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}
	void InsertFirst(int no)
	{

		PNODE newn=new NODE;
		newn->next=NULL;
		newn->data=no;
		
		if((first==NULL)&&(last==NULL))
		{
			first=newn;
			last=first;
		}
		else 
		{
			newn->next=first;
			first=newn;
		}
		last->next=first;
		size++;
	}
	void InsertAtPos(int iPos,int no)
	{
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->data=no;
		if((iPos>size+1)||(iPos<1))
		{
			cout<<"Enter Valid Pos";
			return;
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
			PNODE temp=first;
			int iCnt=1;
			while(iCnt<iPos-1)
			{
				temp=temp->next;
				iCnt++;
			}
			newn->next=temp->next;
			temp->next=newn;
			size++;	
		}
		
	}
	void InsertLast(int no)
	{
		PNODE newn=new NODE;
		newn->next=NULL;
		newn->data=no;
		
		if((first==NULL)&&(last==NULL))
		{
			InsertFirst(no);
		}
		else 
		{
			last->next=newn;
			last=newn;
		}
		last->next=first;
		size++;
	}
	void DeleteFirst()
	{
		
		if((first==NULL)&&(last==NULL))
		{
			return;
		}
		else if(first==last)
		{
			first=NULL;
			last=NULL;
		}
		else 
		{
			first=first->next;
			delete last->next;
		}
		last->next=first;
		size--;
	}
			
	void DeleteLast()
	{
		PNODE temp=first;
		if((first==NULL)&&(last==NULL))
		{
			return;
		}
		else if(first==last)
		{
			first=NULL;
			last=NULL;
		}
		else 
		{
			
			while(temp->next!=last)
			{
				temp=temp->next;
			}
			last=temp;
		}
		last->next=first;
		size--;
	}
	void DeleteAtPos(int iPos)
	{
		if((iPos>size)||(iPos<1))
		{
			cout<<"Enter Valid Pos";
			return;
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
			PNODE temp=first;
			int iCnt=1;
			while(iCnt<iPos-1)
			{
				temp=temp->next;
				iCnt++;
			}
			PNODE targeted=temp->next;
			temp->next=targeted->next;
			delete targeted;
			size--;
		}
			
		
	}
	int Count()
	{
		return size;
	}
			
		
	void Display()
	{
		PNODE temp=first;
		if((first==NULL)&&(last==NULL))
		{
			return;
		}
		do
		{
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}while(temp!=last->next);
	}
};

int main()
{
	SinglyCL sobj;
	sobj.InsertFirst(51);
	sobj.InsertFirst(21);
	sobj.InsertFirst(11);
	sobj.InsertLast(101);
	sobj.Display();
	//sobj.DeleteLast();
	//sobj.Display();
	//cout<<"Length is:"<<sobj.Count();
	sobj.DeleteAtPos(2);
	sobj.Display();
	cout<<"Length is:"<<sobj.Count();
	
}