#include<stdio.h>
#include<math.h>
long long kTraSoHoanHao(long long n){
    long long s=-n,k=sqrt(n);
    for(long long  i=1;i<=k;i++){if(n%i==0){s+=i;s+=n/i;}}
    if(k*k==n)s-=k;
    if(s==n) return 1;
    else return 0;
}
int main(){
    long long n;
    printf("Nhap so can kiem tra: ");
    scanf("%lld",&n);
    if(kTraSoHoanHao(n)){
        printf("%lld la so hoan hao!\n",n);
    }
    else{
        printf("%lld khong phai la so hoan hao!\n",n);
    }
    return 0;
}