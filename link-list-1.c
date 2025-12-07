#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
    char name[40];
    int sl;
    struct item *next;
};

struct item* create(char a[],int k){
    struct item* news = (struct item*)malloc(sizeof(struct item));
    strcpy(news->name,a);
    news->sl = k;
    news->next=NULL;
    return news;
}

int Nfind(struct item* ds,char s[],int k){
    while(ds!=NULL){
        if(strcmp(ds->name,s)==0){
            ds->sl +=k;
            return 0;
        }
        ds = ds->next;
    }
    return 1;
}

void findMAX(struct item* ds){
    struct item* M;
    M=ds;
    ds=ds->next;
    while(ds!=NULL){
        if(ds->sl > M->sl)M=ds;
        ds=ds->next;
    }
    printf("%s %d",M->name,M->sl);
}



int main() {
    struct item *head, *loop;
    char s[100];
    int n,k;scanf("%d",&n);
    if(n){
        n--;
        scanf("%s %d",s,&k);
        head = create(s,k);
        loop=head;
    }
    while(n--){
        scanf("%s %d",s,&k);
        if(Nfind(head,s,k)){
            loop->next = create(s,k);
            loop = loop->next;
        }
    }
    findMAX(head);
    return 0;
}
