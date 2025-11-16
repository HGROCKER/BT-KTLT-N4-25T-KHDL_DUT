#include <stdio.h>
#include <math.h>
void solve(){
	long long N,sqrtX;
    printf("Nhap N: ");
    scanf("%lld", &N);
	sqrtN = sqrt(N);
    if (N == sqrtX*sqrtX) {
        printf("%lld = %lld^2\n", N, sqrtX);
        return 0;
    }
    for (long long a=0;a*a<=N;a++){
        long long b2=N-a*a;
		sqrtX = sqrt(b2);
        if (b2 == sqrtX*sqrtX) {
            printf("%lld = %lld^2 + %lld^2\n", N, a,sqrtX);
            return 0;
        }
    }
    for (long long a=0;a*a<=N;a++) {
        for (long long b=0;b*b<=N-a*a;b++) {
            long long c2=N-a*a-b*b;
			sqrtX=sqrt(c2);
            if (c2 >= 0 && c2==sqrtX*sqrtX) {
                printf("%lld = %lld^2 + %lld^2 + %lld^2\n",N,a,b,sqrtX);
                return 0;
            }
        }
    }
    for (long long a=0;a*a<=N;a++) {
        for (long long b=0;b*b<=N-a*a;b++) {
            long long k = N-a*a-b*b;
            for (long long c=0;c*c<=k;c++) {
                long long d2=k-c*c;
				sqrtX=sqrt(d2);
                if (d2>=0&&d2==sqrtX*sqrtX){
                    printf("%lld = %lld^2 + %lld^2 + %lld^2 + %lld^2\n",N,a,b,c,sqrtX);
                    return 0;
                }
            }
        }
    }
}
int main() {
    solve();
    return 0;
}
