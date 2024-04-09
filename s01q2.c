#include<stdio.h>
#include<stdlib.h>
void main(){
	int i,n,init,total=0;
	printf("Enter number of disk request : ");
	scanf("%d",&n);
	int req[n];
	printf("Enter disk request queue : ");
	for (i=0;i<n;i++)
		scanf("%d",&req[i]);
	printf("Enter initial head position : ");
	scanf("%d",&init);
	for (i=0;i<n;i++){
		total+=abs(req[i]-init);
		init=req[i];
	}
	printf("Total head movements : %d",total);
}
