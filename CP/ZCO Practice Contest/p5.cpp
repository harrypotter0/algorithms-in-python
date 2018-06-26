#include<iostream>
#include <cmath>
#include<cstdio>
#include <algorithm>
#include <vector>
#define gc getchar
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	int N;
	scanint(N);
	int brackets[N];
	int i,j;
	int dept=0,maxdept=0,maxdeptpos=0;
	int sym=0,maxsym=0,maxsympos=0;
	for(i=0;i<N;++i)
	{
		scanint(brackets[i]);
	}

	for(i=0;i<N;i++)
    {
		switch(brackets[i])
		{
			case 1:++dept;
					++sym;
					//cout<<"dep"<<++dept<<"sym:"<<++sym<<"\n";
				break;
			case 2:++sym;
					if(dept>maxdept)
					{
						maxdept=dept;
						maxdeptpos=i;
					}
					--dept;
					//cout<<"dep"<<dept<<"sym:"<<++sym<<"\n";
					//cout<<"\n"<<dept<<"sym"<<sym;
					if(dept==0)
					{
						if(sym>maxsym1)
						{
							maxsym=sym;
							maxsympos=(i-maxsym1)+1;
							if(brackets[maxsympos]==1)
								maxsym1=maxsym;
						}
						if(sym>maxsym2)
						{
							maxsym=sym;
							maxsympos=(i-maxsym2)+1;
							if(brackets[maxsympos]==3)
								maxsym3=maxsym;
						}
						sym=0;
					}
				break;
		}

  	}
   	cout<<maxdept<<" "<<maxdeptpos<<" "<<maxsym<<" "<<maxsympos;
	return 0;
} 
