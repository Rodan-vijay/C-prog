// Online C compiler to run C program online
#include <stdio.h>
struct student
{
    char name[20];
    int roll;
};
union marks
{
    char name[10];
    int mark;
}mrk;

int main() {
    // Write C code here
    printf("Try programiz.pro");
    int n,i;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    struct student std[n];
    struct student *p=std;
    printf("Enter the student name and roll no : ");
    for ( i =0; i<n;i++)
    {
        scanf("%s%d",&p->name,&p->roll);
        p++;
        
    }
    p--;
    printf("Enter the roll no : ");
    int roll;
    scanf("%d",&roll);
    for (i=0;i<n;i++)
    { //printf("%s",p->name);
        if(p->roll==roll){
    printf("%s\n",p->name);
            break;
        }
    p--;
        
    }
    printf("Enter %d's name and mark : ",p->roll);
    scanf("%s%d",&mrk.name,&mrk.mark);
    printf("%s %d",mrk.name,mrk.mark);
    
    return 0;
}