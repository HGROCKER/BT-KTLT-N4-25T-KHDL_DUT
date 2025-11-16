#include <stdio.h>
#include <math.h>
#define ll long long
void solve(){
	ll N,sqrtX;
    printf("Nhap N: ");
    scanf("%lld", &N);
	sqrtX = sqrt(N);
    if (N == sqrtX*sqrtX) {
        printf("%lld = %lld^2\n",N,sqrtX);
        return ;
    }
    for (ll a=0;a*a<=N;a++){
        ll b2=N-a*a;
		sqrtX = sqrt(b2);
        if (b2 == sqrtX*sqrtX) {
            printf("%lld = %lld^2 + %lld^2\n",N,sqrtX,a);
            return ;
        }
    }
    for (ll a=0;a*a<=N;a++) {
        for (ll b=0;b*b<=N-a*a;b++) {
            ll c2=N-a*a-b*b;
			sqrtX=sqrt(c2);
            if (c2 >= 0 && c2==sqrtX*sqrtX) {
                printf("%lld = %lld^2 + %lld^2 + %lld^2\n",N,sqrtX,b,a);
                return ;
            }
        }
    }
    for (ll a=0;a*a<=N;a++) {
        for (ll b=0;b*b<=N-a*a;b++) {
            ll k = N-a*a-b*b;
            for (ll c=0;c*c<=k;c++) {
                ll d2=k-c*c;
				sqrtX=sqrt(d2);
                if (d2>=0&&d2==sqrtX*sqrtX){
                    printf("%lld = %lld^2 + %lld^2 + %lld^2 + %lld^2\n",N,sqrtX,c,b,a);
                    return ;
                }
            }
        }
    }
}
int main() {
    solve();
    return 0;
}
