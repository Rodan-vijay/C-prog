// Online C compiler to run C program online
#include <stdio.h>
char s1[30],s2[30],s3[30];
int len(char *p1)
{int i;
for(i=0;*p1!='\0';i++,p1++);
return i;
}
int cat(char *p1,int l1,char *p2,int l2)
{
    for (int i=0;i<l1;i++,p1++);
    for(int i=0;*p2!='\0';i++,p2++,p1++)
        *p1=*p2;
    *p1='\0';
        
    printf("%s\n",s1);
    
}
int rev(char *p1,int l1)
{
    char s2[30],*p2=s2;
    for(int i=0;*p1!='\0';i++,p1++);p1--;
    for(int i=0;i<l1;i++,p1--,p2++)
        *p2=*p1;
    printf("%s\n",s2);
}
int comp(char *p1,char *p2)
{
    for(int i=0;*p1!='\0';p1++,p2++,i++)
        if(*p1!=*p2 && *p1!='\0')
            printf("%c",*p1);
}
void main()
{
    printf("enter the string : ");
    scanf("%s",s1);
    int i=len(s1);
    cat(s3,0,s1,i);
    printf("%d\n",i);
    printf("enter :");
    scanf("%s",s2);
    int j=len(s2);
    printf("%d\n",j);
    cat(s1,i,s2,j);
    rev(s1,i+j);
    comp(s3,s2);
    
}