//other approaches to the problem


//using count method

#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"ENTER NUMBER OF ELEMENTS:";
	cin>>n;
	int x[n];
	cout<<"\nENTER ARRAY ELEMENTS:\n";
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}

			

int zero=0,one=0,two=0;
		for(int i=0;i<n;i++)
		{
			if(x[i]==0)
			{
				++zero;
			}
			else if(x[i]==1)
			{
			    ++one;
			}
			
		}
	two=n-(zero+one);
cout<<"THE SORTED ARRAY IS:";

	while(zero!=0)
	{
		cout<<"\t";
		cout<<"0";
		--zero;
	}

while(one!=0)
	{
		cout<<"\t";
		cout<<"1"<<"\t";
		--one;
	}
	while(two!=0)
	{
		cout<<"\t";
		cout<<"2"<<"\t";
		--two;
	}
	return 0;	
}