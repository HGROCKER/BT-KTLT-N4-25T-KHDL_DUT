// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
struct item{
    int sl;
    char name[1000];
};

int Nfind(struct item ds[],char s[],int k,int n){
    int i=0;
    for(i=0;i<n;i++)if(strcmp(s,ds[i].name)==0){
        ds[i].sl+=k;
        return 0;
    }
    return 1;
}
void findMAX(struct item ds[],int n){
    struct item *MAX;
    if(n){
    MAX = &ds[0];
    int i=1;
    for(i;i<n;i++){
        if(ds[i].sl > MAX->sl )MAX=&ds[i];
    }
    printf("%s %d",MAX->name,MAX->sl);
    }
}

int main() {
    int n;scanf("%d",&n);
    struct item ds[100000];
    int i=0;
    if(n){
        scanf("%s %d",ds[i].name,&ds[i].sl);
        i++;
        n--;
    }
    while(n--){
        scanf("%s %d",ds[i].name,&ds[i].sl);
        if(Nfind(ds,ds[i].name,ds[i].sl,i))i++;
    }
    findMAX(ds,i);
    return 0;
}
