int main(){
	int n=getchar()-'0',i,j,k;
	for(i=-n;i<=n;i++) for(j=-n;j<=n-abs(i);j++) {
		k=n-abs(i)-abs(j);
		if(k<0) printf("  ");
		else    printf("%d%c",k,j<n-abs(i)?' ':'\n');
	}
	return 0;
}