#include<iostream>
using namespace std;
char arr[502][2]; // Original array
int tot; // total number of '#' in an array
int n;
bool traverse(int x, int y){
	int vert = 0; // to check whether we have traversed vertically in that column
	int trav = 0; // trav -> total number of '#' traversed
	int i, j;
	for ( i=x, j=y; i<n; ){
		if ( arr[i][j] == '.' ) break; // Initial condition
		++trav; // Increment trav if '#'
		if ( !vert && arr[i][1-j]=='#' ){ // check if the other cell in column is '#'
			vert = 1; // signifies that we have traversed vertically
			j = 1-j; // move to other cell in same column
		}
		else{ // else move to right
			vert = 0; // we haven't traversed vertically in new column
			++i;
		}
	}
	if ( trav == tot ) // if all '#' are traversed
		return true;
	return false;
}
int main(){
	int t, i;
	cin >> t;
	while ( t-- ){
		cin >> n;
		tot = 0;
		// scanning row 0
  		for ( i=0; i<n; ++i ){
			cin >> arr[i][0];
			if ( arr[i][0]=='#' ) ++tot;
		}
		// scanning row 1
		for ( i=0; i<n; ++i ){
			cin >> arr[i][1];
			if ( arr[i][1]=='#' )
				++tot;
		}
		// Finding the leftmost column with atleast one '#'
		for ( i=0; i<n; ++i )
			if ( arr[i][0]=='#' || arr[i][1] == '#' )
				break;
		/* calling traverse to traverse the array
		traverse(i,0) -> start traversal from (i, 0)
		Don't worry, if arr[i][0] = '.', it would be false */
		if ( i<n && (traverse(i, 0) || traverse(i,1)) )
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
