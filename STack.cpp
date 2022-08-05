//stack using LL
//Dynamic Stack
#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class Stack//Singly Linerar Linked List
{
private:
	PNODE first;
	int size;
	
public:
	Stack()
	{
		first=NULL;
		size=0;
	}
	void push(int no)//InsertFirst
	{
		PNODE newn=new NODE;
		newn->data=no;
		newn->next=NULL;
		
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
	int pop()//DeleteFirst
	{
		PNODE temp=first;
		int iValue=0;
		if(size==0)
		{
			cout<<"stack is empty\n";
			return -1;
		}
		
		if(size==1)
		{
			iValue=first->data;
			delete first;
			first =NULL;
		}
		else
		{
			iValue=temp->data;
			first=(first)->next;
			delete (temp);
		}
		size--;
		return iValue;
	}
	void Display()
	{
		PNODE temp=first;
		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|\n";
			temp=(temp)->next;
		}
		cout<<"NULL\n";
	}
	
	int Count()
	{
		return size;
	}
};
	

int main()
{
	int iRet=0, iRes=0;
	Stack obj;
	obj.push(11);
	obj.push(21);
	obj.push(51);
	obj.push(101);
	cout<<"elemnts of Stack:\n";
	obj.Display();
	
	iRet=obj.pop();
	cout<<"Poped elemnts are:"<<iRet<<"\n";
	
	cout<<"elemnts of Stack:\n";
	obj.Display();
	iRes=obj.Count();
	
	cout<<"size of Stack:"<<iRes;
	
	
	return 0;
}