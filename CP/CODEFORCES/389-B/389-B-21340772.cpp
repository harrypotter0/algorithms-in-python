#include<iostream>
char A[101][101],i,j; int s,n;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s",A[i] + 1);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
	
			if(A[i][j] == '#' && A[i][j+1] == '#' && A[i+1][j] == '#' && A[i][j-1] == '#' && A[i-1][j] == '#')
				A[i][j] = A[i][j+1] = A[i+1][j] = A[i][j+1] = A[i+1][j] = 0, s += 5;

			else if(A[i][j] == '.') s++;

	printf(s == n * n ? "YES" : "NO");
	return 0;
}