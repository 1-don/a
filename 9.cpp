/*heap sort*/

#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 10

class heap
{
private:
	int marks[max];
	int n;

public:
	heap()
        {
	n=0;
	for(int i=0;i<max;i++)
	marks[i]=0;
	}

	void insert(int num);
	void makeheap();
	void heapsort();
	void display();
	void maxmin();						

};

void heap::insert(int num)
{
				if(n<max)
					{
				marks[n]=num;
				n++;
					}
		else
				cout<<"\nArray is full";
}

void heap::makeheap()
{
	for(int i=1;i<n;i++)
		{
		int val=marks[i];
		int j=i;
		int f=(j-1)/2;
	while(j>0&&marks[f]<val)
		{
		marks[j]=marks[f];
		j=f;
		f=(j-1)/2;
		}
		marks[j]=val;
			}

}

void heap::heapsort()
{
for(int i=n-1;i>0;i--)
	{
	int temp=marks[i];
	marks[i]=marks[0];
	int k=0;
	int j;
	if(i==1)
	j=-1;
	else
	j=1;
	if(j>2&&marks[2]>marks[1])
	j=2;
	while(j>=0&&temp<marks[j])
	{
		marks[k]=marks[j];
		k=j;
		j=(2*k)+1;
		if(j+1<=i-1&&marks[j]<marks[j+1])
		j++;
		if(j>i-1)
		j=-1;
	}

	marks[k]=temp;
	}

}

void heap::display()
{
for(int i=0;i<n;i++)
cout<<" "<<marks[i]<<"\n";
}

void heap::maxmin()
{
cout<<"\nMaximum marks="<<marks[n-1];
cout<<"\nMinimum marks="<<marks[0]<<endl;
}

int main()
{
int n1,no;
heap obj;
cout<<"\nEnter the no of students";
cin>>n1;
cout<<"\nMarks of M1"<<endl;

for(int i=1;i<=n1;i++)
{
cout<<"\nEnter the marks of student"<<i;
cin>>no;
obj.insert(no);
}

cout<<"\nMarks obtained by students"<<endl;
obj.display();
obj.makeheap();
cout<<"\nAfter heap sort"<<endl;
obj.heapsort();
obj.maxmin();

return 0;

}



		
