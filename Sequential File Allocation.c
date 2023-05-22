#include<stdio.h>
voidmain()
{ 
intnf, fc[20], mb[100], i, j, k, fb[100], fs[20], mc=0; 
clrscr(); 
printf("\nEnter the number of files: "); 
scanf("%d",&nf); 
for(i=0;i<nf;i++) 
{ 
printf("\nEnter the capacity of file %d: ",i+1); 
scanf("%d",&fc[i]); 
printf("\nEnter the starting address of file %d: ",i+1); 
scanf("%d",&fs[i]); 
} 
printf("\n---CONTIGUOUS MEMORY ALLOCATION---\n"); 
for(i=0;i<100;i++) 
fb[i]=1; 
for(i=0;i<nf;i++) 
{ 
j=fs[i]; 
{ 
if(fb[j]==1) 
{ 
for(k=j;k<(j+fc[i]);k++) 
{ 
if(fb[k]==1) 
mc++; 
} 
if(mc==fc[i]) 
{ 
for(k=fs[i];k<(fs[i]+fc[i]);k++) 
{ 
fb[k]=0; 
} 
printf("\nFile %d allocated in memory %d to %d...",i+1,fs[i],fs[i]+fc[i]-1); 
} 
} 
else
printf("\nFile %d not allocated since %d contiguous memory not available from %d...",i+1,fc[i],fs[i]); 
} 
mc=0; 
} 
getch();
}
