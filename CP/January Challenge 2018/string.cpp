#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
ll lcs( string X, string Y, ll m, ll n )
{
   int L[m+1][n+1];
   int i, j;

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

char * removeDuplicates(char S[]){

   int n = strlen(S);

   // We don't need to do anything for
   // empty or single character string.
   if (n < 2)
     return S;

   // j is used to store index is result
   // string (or index of current distinct
   // character)
   int j = 0;

   // Traversing string
   for (int i=1; i<n; i++)
   {
       // If current character S[i]
       // is different from S[j]
       if (S[j] != S[i])
       {
           j++;
           S[j] = S[i];
       }
   }

   // Putting string termination
   // character.
   j++;
   S[j] = '\0';
   return S;
}

int main()
{
	ll t,n,m,i,x,y;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		char a[n],b[m];
    string a1,b1;
		scanf("%s",a);
		scanf("%s",b);
    a1 = removeDuplicates(a); //cout<<removeDuplicates(a)<<endl;
    b1 = removeDuplicates(b); //cout<<removeDuplicates(b)<<endl;
    x = a1.length();
		y = b1.length();
    //cout << x << " "<< y;
		ll l = lcs(a1,b1,x,y);
		//cout<< l;
		printf("%lld\n",(x+y-l));
	}
	return 0;
}
