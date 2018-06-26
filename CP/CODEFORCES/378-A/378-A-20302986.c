main()
{
int a,b,i,c=0,d=0;
scanf("%d%d",&a,&b);
for(i=1;i<7;i++) if(abs(a-i)<abs(b-i)) c++;else if(abs(a-i)==abs(b-i)) d++;
printf("%d %d %d\n",c,d,6-(c+d));
return 0;
}