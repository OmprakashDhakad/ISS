/*
      
          Author : OMPRAKASH
     	    ID     : 2015KUCP1028
    
    
	    Compile the program  : gcc 2015kucp1028_assignment02_modicaesar.c
	    run the program      : ./a.out
	    
	    Example output : 
			            Enter plain text :om prakash
					Enter key value :5
					Cipher text : tr uwfpfxm
					key = 5 and plain text = om prakash

   
*/

//Encryption code of modified caesar cipher
#include<stdio.h>
#include<string.h>

int main()
{
  int k,i;
  char arr[100],pt[100],pt1[100];
  printf("Enter plain text :");
  gets(arr);
  strcpy(pt,arr);
  printf("Enter key value :");
  scanf("%d",&k);
  
  for(i=0;i<strlen(arr);i++)
  {
    if(arr[i]>=97 && arr[i]<=122)
    {
            arr[i]+=k;
	    if(arr[i]>122)
	    {
	       arr[i]=arr[i]- 26; 
	    }
    }
    if(arr[i]>=65 && arr[i]<=90)
    {
	    arr[i]+=k;
	    if(arr[i]>90)
	    {
	    	arr[i]=arr[i]- 26; 
	    } 
    }
  }
  printf("Cipher text : %s\n",arr);
  
//Decryption code of modified caesar cipher
  strcpy(pt1,arr);
  int key=1;
 for(k=1;k<26;k++)
 {

  for(i=0;i<strlen(arr);i++)
  {
    if(arr[i]>=97 && arr[i]<=122)
    {
            arr[i]+=key;
	    if(arr[i]>122)
	    {
	       arr[i]=arr[i]- 26; 
	    }
	    
    }
    if(arr[i]>=65 && arr[i]<=90)
    {
	    arr[i]+=key;
	    if(arr[i]>90)
	    {
	    	arr[i]=arr[i]-26; 
	    } 
    }
  }
      
	  if(strcmp(pt,arr)==0)
	  {
	   printf("key = %d and plain text = %s\n",26-k,arr);
	   break;
	  }
	  
 }
  
  
  
}
