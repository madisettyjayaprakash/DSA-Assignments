#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct rec{
char stdid[20];
char stdname[20];
char mark[5];
};
void add();
void dis1();
void dis2();
void disall();
int main(int argc,char *argv[])
{
if(argc!=2)
{
printf("Improper args");
}
else
{
int a;
char f1name[20];
strcpy(f1name,argv[1]);
label:
printf("1.Add student details\n");
printf("2.Display the names of students who obtained less than 30 marks\n");
printf("3.Display the names of students who have insufficient attendance\n");
printf("4.Display all the records in the file\n");
printf("5.Exit\n");
printf("Enter your choice:");
scanf("%d",&a);
switch(a)
{
case 1:
add(f1name);
goto label;
case 2:
dis1(f1name);
goto label;
case 3:
dis2(f1name);
goto label;
case 4:
disall(f1name);
goto label;
case 5:
break;
}
}
return 0;
}
void add(char *fname)
{
FILE *p;
struct rec r1;
int d;
p=fopen(fname,"a");
printf("\nEnter student ID:");
scanf("%s",r1.stdid);
printf("\nEnter student name:");
scanf("%s",r1.stdname);
new:
printf("\nEnter marks of student:");
scanf("%s",r1.mark);
d=atoi(r1.mark);
if((d<0)||(d>100))
{
printf("Invalid input");
goto new;
}
else
{
fwrite(&r1,sizeof(r1),1,p);
fclose(p);
}
}
void disall(char *fname)
{
FILE *p;
struct rec r;
p=fopen(fname,"r");
printf("\n+---------------+---------------+----+");
printf("\n|Student_ID\t|Student_Name\t|Mark|");
printf("\n+---------------+---------------+----+\n");
while(1)
{
fread(&r,sizeof(r),1,p);
if(feof(p))
{
break;
}
printf("|%s\t\t",r.stdid);
printf("|%s\t\t",r.stdname);
printf("|%s\t\n",r.mark);
}
printf("\n+---------------+---------------+-------+\n");
fclose(p);
}
void dis1(char *fname)
{
FILE *p;
int i;
struct rec r;
p=fopen(fname,"r");
printf("Students who scored less than 30:\n");
while(1)
{
fread(&r,sizeof(r),1,p);
if(feof(p))
{
break;
}
else
{
i=atoi(r.mark);
if((i<30)&&(*r.mark!='I')&&(*r.mark!='A'))
printf("%s\n",r.stdname);
}
}
fclose(p);
}
void dis2(char *fname)
{
FILE *p;
struct rec r;
p=fopen(fname,"r");
printf("Students with insufficient attandance:\n");
while(1)
{
fread(&r,sizeof(r),1,p);
if(feof(p))
{
break;
}
else
{
if(*r.mark=='I')
printf("%s\n",r.stdname);
}
}
fclose(p);
}






