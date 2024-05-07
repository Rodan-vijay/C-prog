//File handling
#include<stdio.h>
#include<string.h>
int n;
struct student
{
char roll[10],name[30];
float cgpa;
}temp;
void sort(struct student std[])
{
for (int i=0;i<n;i++)
	for(int j=0;j<n-i-1;j++)
		if(strcmp(std[j].roll,std[j+1].roll)>0)
{
temp=std[j];
std[j]=std[j+1];
std[j+1]=temp;
}

}
void main()
{
printf("Enter the number of students in the list : ");
scanf("%d",&n);
struct student std[n];
FILE *fptr;
fptr=fopen("std.txt","r");
int i=0;
while(fscanf(fptr,"%s %s %f",&std[i].roll,&std[i].name,&std[i].cgpa)!=EOF)
{//printf("%s %s %f",std[i].roll,std[i].name,std[i].cgpa);
i++;
}
//printf("%s",(std[2].roll)[3:5]);
sort(std);
for(int i=0;i<n;i++)
printf("%s %s %f\n",std[i].roll,std[i].name,std[i].cgpa);
}
----------------------------------------
//File handling
#include<stdio.h>
#include<string.h>
struct student
{
char roll[10],name[30];
float cgpa;
}temp;
void sort(struct student std[],int n)
{
for (int i=0;i<n;i++)
	for(int j=0;j<n-i-1;j++)
		if(strcmp(std[j].roll,std[j+1].roll)>0)
{
temp=std[j];
std[j]=std[j+1];
std[j+1]=temp;
}

}
void main()
{int n=0;
//printf("Enter the number of students in the list : ");
//scanf("%d",&n);
struct student std[100];
FILE *fptr;
fptr=fopen("std.txt","r");
int n=0,i=0;
while(fscanf(fptr,"%s %s %f",&std[i].roll,&std[i].name,&std[i].cgpa)!=EOF)
{//printf("%s %s %f",std[i].roll,std[i].name,std[i].cgpa);
n++;
i++;
}
//printf("%d",n);
sort(std,n);
for(int i=0;i<n;i++)
printf("%s %s %f\n",std[i].roll,std[i].name,std[i].cgpa);
}

