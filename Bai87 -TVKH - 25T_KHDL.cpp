#include<stdio.h>
struct phanSo
{
    long long tu;
    long long mau;
};
long long UCLN(long long a,long long b){
    long long r;
    while(b!=0){
        r=a%b;a=b;b=r;}
    return a;
}
void rutGon(struct phanSo ps,struct phanSo *kq){
    long long ucln=UCLN(ps.tu,ps.mau);
    kq->tu=ps.tu/ucln;
    kq->mau=ps.mau/ucln;
}
void daoNguoc(struct phanSo ps){
    printf("Phan so sau khi dao nguoc: %lld/%lld\n",ps.mau,ps.tu);
}
void hopPhanSo(struct phanSo ps){
    if(ps.tu>ps.mau){
        long long x = ps.tu/ps.mau;ps.tu%=ps.mau;
        printf("Phan so duoc hop la: %lld + %lld/%lld\n",x,ps.tu,ps.mau);
    }
}
long long BCNNmauSo(long long a,long long b){
    long long bcnn=(a*b)/UCLN(a,b);
    return bcnn;
}
void tongPhanSo(struct phanSo ps1,struct phanSo ps2){
    long long bcnn=BCNNmauSo(ps1.mau,ps2.mau);
    ps1.tu=(ps1.tu*(bcnn/ps1.mau))+(ps2.tu*(bcnn/ps2.mau));
    rutGon(ps1,&ps1);
    printf("Tong 2 phan so sau khi rut gon: %d/%d\n",ps1.tu,ps1.mau);
}
void soSanhPhanSo(struct phanSo ps1,struct phanSo ps2){
    ps1.tu*=ps2.mau;
    ps2.tu*=ps1.mau;
    if(ps1.tu>ps2.tu){
        printf("Phan so 1 lon hon phan so 2\n");
    }
    else if(ps1.tu<ps2.tu){
        printf("Phan so 1 nho hon phan so 2\n");
    }
    else{
        printf("Phan so 1 bang phan so 2\n");
    }
}

int main(){
    printf("Nhap so luong phan so {1 hoac 2} : ");
    int k;scanf("%d",&k);
    if(k==1){
        struct phanSo kq;
        printf("Nhap phan so 1{dang {a}/{b} }: ");
        struct phanSo ps1;scanf("%lld/%lld",&ps1.tu,&ps1.mau);
        daoNguoc(ps1);
        rutGon(ps1,&kq);
        printf("Phan so sau khi rut gon: %lld/%lld\n",kq.tu,kq.mau);
        hopPhanSo(ps1);
    }
    else if(k==2){
        printf("Nhap phan so 1{dang {a}/{b} }: ");
        struct phanSo ps1,ps2;scanf("%lld/%lld",&ps1.tu,&ps1.mau);
        printf("Nhap phan so 2{dang {a}/{b} }: ");
        scanf("%lld/%lld",&ps2.tu,&ps2.mau);
        printf("Boi chung nho nhat cua mau so: %lld\n",BCNNmauSo(ps1.mau,ps2.mau));
        tongPhanSo(ps1,ps2);
        soSanhPhanSo(ps1,ps2);
    }
    else{
        printf("So luong phan so khong hop le!\n");
    }
    return 0;
}