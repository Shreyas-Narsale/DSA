//generic problem
#include<iostream>
using namespace std;
void Swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
int main()
{
	
	int x=0,y=0;
	
	cout<<"enter first No.\n";
	cin>>x;
	
	cout<<"enter second No.\n";
	cin>>y;
	Swap(&x,&y);//Swap(100,200)
	
	cout<<"Value of X becomes:"<<x<<"\n";
	cout<<"Value of Y becomes:"<<y<<"\n";
	
	return 0;
	
}
	
	