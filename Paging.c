#include<stdio.h>
void main () 
{
int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
int s[10], fno[10][20];
int total_pages_required = 0;
printf ("Enter the memory size : ");  
scanf ("%d", &ms); 
printf ("Enter the page size : ");
scanf ("%d", &ps);
nop = ms / ps; 
printf ("The number of pages available in memory are : %d ", nop);
printf ("\nEnter the number of processes : ");  
scanf ("%d", &np);  
rempages = nop;  
for (i = 1; i <= np; i++)   
{
printf ("Enter the number of pages required for p[%d] : ", i);     
scanf ("%d", &s[i]);
if (s[i] > rempages)    
{
printf ("Memory is Full");
printf("\nThe available memory is %d only",ps);
for (i = 1; i <= np; i++) 
{
    total_pages_required += s[i];
}
printf("\nThe total number of pages required for this input is : %d", total_pages_required);      
break;
}    
rempages = rempages - s[i];
printf ("Enter pagetable for p[%d] : ", i);     
for (j = 0; j < s[i]; j++)    
scanf ("%d", &fno[i][j]);
}
printf ("\n--- Enter the Logical Address to find Physical Address ---"); 
printf ("\nEnter the Process number. and Page number and Offset : ");
scanf ("%d %d %d", &x, &y, &offset);
if (x > np || y >= s[i] || offset >= ps)   
  printf ("\nInvalid Process or Page Number or offset");
else
{
pa = fno[x][y] * ps + offset;      
printf ("\nThe Physical Address is : %d", pa);
}
}

