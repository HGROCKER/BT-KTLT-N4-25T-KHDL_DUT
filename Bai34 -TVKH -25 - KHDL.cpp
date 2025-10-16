#include <stdio.h>
#include <string.h>
#define MAX 50010

int ktra(char s[]){
    int n = strlen(s);
    for (int i=0;i<n/2; i++) {
        if(s[i]!=s[n-i-1])return 0;
    }
    return 1;
}

int main(){
	char a[MAX];scanf("%s",a);
	if(ktra(a))printf("Day la xau doi xung!");
	else printf("Day KHONG PHAI la xau doi xung!")
	return 0;
}