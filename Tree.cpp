//BST(tree)

using namespace std;
#include<iostream>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE Head,int no)
{
	PNODE newn=new NODE;
	newn->data=no;
	newn->lchild=NULL;
	newn->rchild=NULL;
	PNODE temp=*Head;
	
	if(*Head == NULL)
	{
		*Head=newn;
	}
	else
	{
		PNODE temp=*Head;
		
		while(1) //unconditional loop  for(;;)
		{
			if(temp->data ==no)
			{
				delete newn;
				break;
			}
			else if(no<temp->data )//lahan data
			{
				if((temp->lchild)==NULL)
				{
					temp->lchild=newn;
					break;
				}
				temp=temp->lchild;
			}
			else if(no>temp->data)//motha deta
			{
				if((temp->rchild)==NULL)
				{
					temp->rchild=newn;
					break;
				}
				temp=temp->rchild;
			}
			
		}
			
	}
}
bool Search(PNODE Head,int no)
{
	
	if(Head ==NULL)//if tree is empty
	{
		return false;
	}
	else//tree contains atleast one node
	{
		
		while(Head !=NULL)
		{
			if(Head->data ==no)// node sapadala
			{
				
				break;
			}
			else if(no> Head->data )
			{
				if(Head->rchild ==NULL)
				{
					break;
				}
				Head=Head->rchild;
			}
			else if(no< Head->data )
			{
				if(Head->lchild ==NULL)
				{
					break;
				}
				Head=Head->lchild ;
			}
		}
	}
	if(Head ==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
int Count(PNODE Head)
{
	static int iCnt=0;
	if(Head !=NULL)
	{
		iCnt++;
		Count(Head->lchild);
		Count(Head->rchild);
	}
	return iCnt;
}
int CountLeaf(PNODE Head)
{
	static int iCnt=0;
	if(Head !=NULL )
	{
		if((Head->lchild)==NULL&&(Head->rchild)==NULL)
		{
			iCnt++;
		}
		CountLeaf(Head->lchild);
		CountLeaf(Head->rchild);
	}
	return iCnt;
}
int CountParent(PNODE Head)
{
	static int iCnt=0;
	if(Head !=NULL )
	{
		if(((Head->lchild)!=NULL)||((Head->rchild)!=NULL))
		{
			iCnt++;
		}
		CountParent(Head->lchild);
		CountParent(Head->rchild);
	}
	return iCnt;
}
void DisplayInOrder(PNODE Head)
{
	
	if(Head !=NULL )
	{
		DisplayInOrder(Head->lchild);
		cout<<Head->data<<"  ";
		DisplayInOrder(Head->rchild);
	}
	
}
void DisplayPreOrder(PNODE Head)
{
	
	if(Head !=NULL )
	{
		cout<<Head->data<<"  ";
		DisplayPreOrder(Head->lchild);
		DisplayPreOrder(Head->rchild);
	}
}
void DisplayPostOrder(PNODE Head)
{
	
	if(Head !=NULL )
	{
		DisplayPostOrder(Head->lchild);
		DisplayPostOrder(Head->rchild);
		cout<<Head->data<<"  ";
	}

}


int main()
{
	int no=0,iRet=0;
	bool bRet=false;
	PNODE first=NULL;
	
	Insert(&first,51);
	Insert(&first,21);
	Insert(&first,101);
	
	cout<<"enter no to search\n";
	cin>>no;
	
	bRet=Search(first,no);
	if(bRet==true)
	{
		cout<<"No. is present\n";
	}
	else
	{
		cout<<"No. is absent\n";
	}
	iRet=Count(first);
	cout<<"number of nodes are:\t"<<iRet<<"\n";
	
	iRet=CountLeaf(first);
	cout<<"number of Leafnodes are:\t"<<iRet<<"\n";
	iRet=CountParent(first);
	cout<<"number of Parentsnodes are:\t"<<iRet<<"\n";
	
	cout<<"InOrder\n";
	DisplayInOrder(first);
	cout<<"\nPreOrder\n";
	DisplayPreOrder(first);
	cout<<"\nPosOrder\n";
	DisplayPostOrder(first);
	
	return 0;
}
	/*              51
	         21            101
	
	*/
// inorder L-D-R  21  51  101
// preorder D-L-R  51  21  101
//postorder L-R-D  21 101  51