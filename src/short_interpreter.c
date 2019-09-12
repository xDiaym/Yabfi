#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define e case
#define a break 
typedef char c;typedef size_t s;c k[30000]={0};s z(FILE*f){fseek(f,0L,SEEK_END)
;s z=ftell(f);fseek(f,0L,SEEK_SET);return z;}c*r(const c*n){c*b;FILE*f;if((f=
fopen(n,"r"))==0)exit(-1);s l=z(f);b=calloc(l,sizeof(c));if(b==0)exit(-2);fread
(b,sizeof(c),l,f);fclose(f);return b;}void i(c*p){c*t=k;c o;for(s i=0;(o=p[i])
!='\0';++i){switch(o){e'+':++(*t);a;e'-':--(*t);a;e'>':++t;a;e'<':--t;a;e'.':
putchar(*t);a;e',':*t=getchar();a;e'[':{s n=1;if(*t==0){while(n>0){o=p[++i];if(
o==']')--n;else if(o=='[')++n;}}a;}e']':{s n=1;if(*t!=0){while(n>0){o=p[--i];if
(o==']')++n;else if(o=='[')--n;}}a;}}}}int main(int g, c* v[]){if(g==1)return-3
;c*p=r(v[1]);i(p);}