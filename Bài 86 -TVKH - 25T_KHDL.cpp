#include<stdio.h>
#include<string.h>
void kTraAnagram(char a[50000],char b[50000]){
int c['z'+2];
int i;
for(i='a';i<='z';i++){c[i]=0;}
int n=strlen(a);
if(n==strlen(b)){
for(i=0;i<n;i++){c[a[i]]++;c[b[i]]--;}
for(i='a';i<='z'&&!c[i];i++){}
if(i=='z'+1)printf("%s va %s la anagram cua nhau!",a,b);
else printf("%s va %s khong phai anagram cua nhau!",a,b);
}
else printf("%s va %s khong phai anagram cua nhau!",a,b);
}

int main(){
    char word_1[50000],word_2[50000];
    scanf("%s",&word_1);scanf("%s",&word_2);
    kTraAnagram(word_1,word_2);
    return 0;
}
