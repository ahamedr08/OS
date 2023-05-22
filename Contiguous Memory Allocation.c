#include<stdio.h>
#include<conio.h>
#define max 25
int main()
{
int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0,lowest=10000, type; 
static int bf[max],ff[max];
printf("\nNumber of memory blocks: "); 
scanf("%d",&nb);
printf("Number of process: ");
scanf("%d",&nf);
printf("\nSize of the memory blocks:-\n"); 
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Size of the process:-\n"); for(i=1;i<=nf;i++)
{
printf("Process %d:",i);
scanf("%d",&f[i]);
}
printf("\nType of algorithm: 1. First fit\t 2. Best fit\t 3. Worst fit\n" ); 
scanf("%d" ,&type);
if(type==1)
{
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i]; 
if(temp>=0)
{
ff[i]=j; break;
}
}
}
frag[i]=temp;
bf[ff[i]]=1;
}
}
else if(type==2)
{
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i]; 
if(temp>=0) 
if(lowest>temp)
{
ff[i]=j; 
lowest=temp;
}
}
}
frag[i]=lowest; 
bf[ff[i]]=1; 
lowest=10000;
}
}
else if(type==3)
{
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i]; 
if(temp>=0) 
if(highest<temp)
{
ff[i]=j; 
highest=temp;
}
}
}
frag[i]=highest; 
bf[ff[i]]=1; 
highest=0;
}
}
else
{
printf("Enter valid number");
}
printf("\nFile_no\tFile_size\tBlock_no\tBlock_size:\t\tFragment"); 
for(i=1;i<=nf;i++)
 printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]); 
getch();
return 0; }
