main(){   int n,m,min;
    scanf("%d%d",&n,&m);
    printf("%d",((n+1)/2+m-1)/m*m<=n?((n+1)/2+m-1)/m*m:-1);
}