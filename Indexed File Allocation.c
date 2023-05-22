#include<stdio.h>
struct file
{
char fname[10],s;
int index[10][10];
}f[10];
main()
{
inti,j,n,s,t,k;
printf("Enter no. of files:");
scanf("%d",&n);
for(i=0;i<n;i++)
 {
printf("Enter file name:");
scanf("%s",&f[i].fname);
printf("Enter index block:");
scanf("%d",&f[i].s);
printf("Enter the no.of content in  index block:");
scanf("%d",&t);
for(j=0;j<t;j++)
{
k=s;
scanf("%d",&f[i].index[k][j]);
}
}
printf("File\tindex block\t content\n");
for(i=0;i<n;i++)
{
printf("%s\t%d",f[i].fname,f[i].s);
for(j=0;j<t;j++)
{
printf("\t%d",f[i].index[s][j]);
}
printf("\n");
}
}
