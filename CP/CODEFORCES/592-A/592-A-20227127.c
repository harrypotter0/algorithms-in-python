#include<stdio.h>
typedef unsigned u;
u A[8],B[8];
int main()
{
	u i,j,a,b;char c;
	for(a=b=i=-1;++i<8;)A[i]=B[i]=-1;
	for(i=-1;++i<8;)for(j=-1;++j<8;)
	{
		while((c=getchar())<=' ');
		if(c=='B')B[j]=i;
		if(c=='W'&&A[j]==-1u)
		{
			if(B[j]==-1u)A[j]=i;
			else B[j]=-1u;
		}
	}
	for(i=-1;++i<8;)
	{
		if(a>A[i])a=A[i];
		if(B[i]!=-1u&&b>7-B[i])b=7-B[i];
	}
	printf(a>b?"B\n":"A\n");
	return 0;
}