#include<stdio.h>
long a[2],b[2];
char op;
long ucln(long a,long b){
while(a!=b){
if(a>b)a-=b;
else b-=a;
}
return a;
}
void congPs(){
    a[0]=a[0]*b[1]+(b[0]*a[1]);
    a[1]*=b[1];
}
void truPs(){
    a[0]=a[0]*b[1]-(b[0]*a[1]);
    a[1]*=b[1];
}
void nhanPs(){
    a[0]*=b[0];
    a[1]*=b[1];
}
void chiaPs(){
    a[0]*=b[1];
    a[1]*=b[0];
}
void rutGon(){
if(a[0]%a[1]){
    long uc = ucln(a[0],a[1]);
    a[0]/=uc;
    a[1]/=uc;
}
else {
    a[0]=0;
    a[1]=a[0]/a[1];}
}
void OUTPUT(){
switch(op){
case '+': {congPs();break;}
case '-': {truPs();break;}
case '*': {nhanPs();break;}
case '/': {chiaPs();break;}
default : printf("Toan tu khong xac dinh! Co the gay loi!");
}
rutGon();
if(a[0]){printf("%ld/%ld",a[0],a[1]);}
else printf("%ld",a[1]);
}
int main(){
scanf("%ld/%ld%c%ld/%ld",&a[0],&a[1],&op,&b[0],&b[1]);
OUTPUT();
}
