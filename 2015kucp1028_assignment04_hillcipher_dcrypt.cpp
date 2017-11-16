/*
     NAME : OMPRAKASH
     ID   : 2015KUCP1028
     
     compile  : g++ 2015kucp1028_assignment04_hillcipher_dcrypt.cpp 
     Run      : ./a.out
     
     Example out : Enter Cipher text : lnshdlewmtrw
                   Your plain text : PAYMOREMONEY

     

*/

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
   int i;
   int k=0,p,q,sum,j;
   string pt;
   cout << "Enter Cipher text : ";
   cin >> pt;
   
   //convert lowercase to uppercase
   for(int i = 0; i < pt.length(); i++)
         pt[i] = toupper(pt[i]);
         
   
   int PT[3][1];
   int CT[3][1];
   int key[3][3] = { {4,9,15},
                     {15,17,6},
                     {24,0,17}};
                     
    cout << "Your plain text : ";
    for(j=0;j<pt.length();j=j+3)
    {
	    for(i=0;i<3;i++)
	    {
		 PT[i][1] = int(pt[i+j])-65 ;
		 
		 
	    }
	    
	    for(p=0;p<3;p++)
	    {
	       sum=0;
		 for(q=0;q<3;q++)
		 {
		    
		    sum=sum+key[p][q]*PT[q][1];
		    
		 }
		 
		 CT[p][1] = sum%26;
		 
		 printf("%c",(CT[p][1]+65));
	    }
   }
printf("\n");

}
