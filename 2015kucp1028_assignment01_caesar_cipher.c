/*
    Author : OMPRAKASH
    ID     : 2015KUCP1028
    
    Compile the program  : gcc 2015kucp1028_assignment01_caesar_cipher.c
    Run the program      : ./a.out
    
    Example output : 
	                  Enter plain text : om prakash,dhakad
				Cipher text      : rp sudndvk,gkdndg
				Decrypted cipher : om prakash,dhakad
    
 */

#include<stdio.h>
#include<string.h>
main()
{
  int k=3,i; // key = 3 in caesar cipher to encrypt the plain text
  char arr[100];
  printf("Enter plain text : ");
  gets(arr);
  for(i=0;i<strlen(arr);i++)
  {
    if(arr[i]>=97 && arr[i]<=122)
    {
            arr[i]+=k;
	    if(arr[i]>=122)
	    {
	       arr[i]=arr[i]-26; 
	    }
    }
    if(arr[i]>=65 && arr[i]<=90)
    {
	    arr[i]+=k;
	    if(arr[i]>=90)
	    {
	    	arr[i]=arr[i]-26; 
	    } 
    }
  }
  printf("Cipher text      : %s\n",arr);
  
  
  for(i=0;i<strlen(arr);i++)
  {
    if(arr[i]>=97 && arr[i]<=122)
    {
            arr[i]-=k;
	    if(arr[i]>=122)
	    {
	       arr[i]=arr[i]-26; 
	    }
    }
    if(arr[i]>=65 && arr[i]<=90)
    {
	    arr[i]-=k;
	    if(arr[i]>=90)
	    {
	    	arr[i]=arr[i]-26; 
	    } 
    }
  }
  printf("Decrypted cipher : %s\n",arr);
  
}
