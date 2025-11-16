#include<stdio.h>
void solve(){
    long long a=0,s=0;
    do{
        s+=a;
        scanf("%lld",&a);
    }while(a);
    printf("Tong cac so da nhap: %lld\n",s);
}

int main(){
    solve();
    return 0;
}
