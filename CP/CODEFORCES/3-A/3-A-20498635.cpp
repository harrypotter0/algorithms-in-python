#include <bits/stdc++.h>
using namespace std;

int main()
{ char h,i,j,k;
    cin>>h>>i>>j>>k;
    cout << max( abs ( h - j ) , abs ( i - k ) )<<endl;
    while (h!=j || i!=k)
    {if (h>j){ cout <<"L"; h--;}
    if (j>h) {cout <<"R"; h++;}
     if (i>k) {cout<<"D"; i--;}
    if (k>i) {cout<<"U"; i++;}
    cout<<endl;
    }
    return 0;
}