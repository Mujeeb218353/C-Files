#include<stdio.h>
int main(){
	int i,j,k,l;
	char n='Z';
	for(i='A';i<='Z';i++){
		for(j='A';j<=i;j++){
			printf("%c ",j);
		}
		printf("\n");
	}
	for(k='A';k<='Z';k++){
		for(l='A';l<=n;l++){
		   printf("%c ",l);
		   n-l;
	    }
	    printf("\n");
	}
	return 0;
}
