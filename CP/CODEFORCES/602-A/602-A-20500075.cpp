#include<iostream>
long long n,a,b,s,p;
char *S="=<>";
int G(){ for(std::cin>>n>>b;n--;std::cin>>a,p=p*b+a); }
main(){ G();s=p,p=0;G(); std::cout<<S[(s<p)+(s>p)*2]; }