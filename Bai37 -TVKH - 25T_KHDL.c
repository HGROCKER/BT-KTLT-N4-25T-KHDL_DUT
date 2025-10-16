#include <stdio.h>
#include <math.h>
#define MAX 2645

int phanTich(int n,int b[], int nho){
int k = sqrt(n);
for(int i=0;i<=k;i++)b[i]=0;
while(n){
b[k]+=n/(k*k);
if(b[k]){nho=k;}
n%=k*k;
k--;
}
return nho;
}
void OUTPUT(int b[],int k, int nho){
	for(int i=k;i>nho;i--){
		for(int j=0;j<b[i];j++){
			printf("%d^2 + ",i);
		}
	}
	for(int j=0;j<b[nho]-1;j++){
			printf("%d^2 + ",nho);
		}printf("%d^2",nho);
}

int main(){
	int b[MAX],nho=2645,n;
	scanf("%d",&n);
	nho = phanTich(n,b,nho);
	OUTPUT(b,sqrt(n),nho);
	
	return 0;
}