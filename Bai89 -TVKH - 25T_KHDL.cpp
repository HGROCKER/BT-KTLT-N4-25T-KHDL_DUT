#include <stdio.h>
#include <string.h>
#define MAX 50010

void daoXau(char s[]){
    int n = strlen(s);
    for (int i=0;i<n/2; i++) {
        char x = s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=x;
    }
}

char* SUM(char a[], char b[]) {
    daoXau(a);daoXau(b);
    int p=strlen(a) , q=strlen(b), du=0;
    if(p<q){
        int i;
        for(i=0;i<p;i++){
            b[i]+=du;du=0;
            b[i]+=a[i]-'0';
            if(b[i]>'9'){b[i]-=10;du++;}
        
        }
        for(i;i<q&&du;i++){
            b[i]+=du;du=0;if(b[i]>'9'){b[i]-=10;du++;}
        }
        if(du){b[q]=1;b[q+1]='\0';}
        daoXau(b);
        return b;
    }
    else{
        int i;
        for(i=0;i<q;i++){
            a[i]+=du;du=0;
            a[i]+=b[i]-'0';
            if(a[i]>'9'){a[i]-=10;du++;}
        }
        
        for(i;i<p&&du;i++){
            a[i]+=du;du=0;if(a[i]>'9'){a[i]-=10;du++;}
        }
        if(du){a[p]='1';a[p+1]='\0';}
        daoXau(a);
        return a;
    }
}

char* SUB(char a[], char b[]) {
    daoXau(a);daoXau(b);
    int p=strlen(a) , q=strlen(b), du=0;
    if(p<q){
        int i;
        for(i=0;i<p;i++){
            b[i]+=du;du=0;
            b[i]-=a[i]-'0';
            if(b[i]<'0'){b[i]+=10;du=-1;}
        }
        for(i;i<q&&du;i++){
            b[i]+=du;du=0;
            if(b[i]<'0'){b[i]+=10;du=-1;}
        }
        for(i=q-1;i>-1&&b[i]=='0';i--){}
        b[i+1]='-';b[i+2]='\0';
        daoXau(b);
        return b;
    }
    else{
        int i;
        for(i=0;i<q;i++){
            a[i]+=du;du=0;
            a[i]-=b[i]-'0';
            if(a[i]<'0'){a[i]+=10;du=-1;}
        }
        for(i;i<p&&du;i++){
            a[i]+=du;du=0;
            if(a[i]<'0'){a[i]+=10;du=-1;}
        }
        for(i=p-1;i>-1&&a[i]=='0';i--){}
        if(i==-1){
            a[0]='0';a[1]='\0';
        }
        else {
            a[i+1]='\0';
        }
        daoXau(a);
        return a;
    }
}


int main() {
    char a[MAX], b[MAX], op, kq[MAX];
    scanf("%s %c %s", a, &op, b);
    switch(op){
        case '+':{printf("Kết quả: %s\n",SUM(a,b));break;}
        case '-':{printf("Kết quả: %s\n",SUB(a,b));break;}
        default : {printf("toan tu bi loi");return 1;};
    }
    return 0;
}