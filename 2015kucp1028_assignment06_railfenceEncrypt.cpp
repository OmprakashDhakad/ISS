/*
    Author : OMPRAKASH
    ID     : 2015kucp1028
    
    compile the code  : g++ 2015kucp1028_assignment06_railfenceEncrypt.cpp  
    Run the code      : ./a.out
    
    Example output  : 
                        Enter a key : 4
				Enter a string  : omprakash dhakad
				omprakash dhakad
				o - - - - - a - - - - - a - - - 
				- m - - - k - s - - - h - k - - 
				- - p - a - - - h - d - - - a - 
				- - - r - - - - -   - - - - - d 
				Cipher text  : oaamkshkpahdar d

*/
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;
int main()
{
	int key;
	string str;
	cout << "Enter a key : ";
      cin >> key;
	cout << "Enter a string  : ";  //enter a string  with spaces
	cin.ignore();
      getline(cin, str, '\n');
      cout << str<<endl;
   
	int len = str.length();
	char rail[key][len];          //declare array for rail matrix
	for(int i=0;i<key;i++)
	{
	  for(int j=0;j<len;j++)
	   {
	     rail[i][j] ='-';
	   }
	}
	
	int i=0;
	int j=0;
	int k=0;
	int flag=0;
	int l=0;
	for (l=0;l<len;l++)
	{
	      
	      if(flag==0)                  // use flag for downword direction
	      {
	      
			 rail[i][j] = str[l];
			 i++;
			 j++;
			 k++;
			 if(i==key)
			 {
			     i=i-2;
			     flag=1;
			 }
		 }
		 
		 else if(flag==1)           // use flag for upword direction
		 {
			 rail[i][j] = str[l];
			 i--;
			 j++;
			 k++;
			 if(i==-1)
			 {
			     i=i+2;
			     flag=0;
			 }
	      }
	}
	//print the matrix after filling rai matrix
	for(i=0;i<key;i++)
	{
	  for(j=0;j<len;j++)
	   {
	     cout<< rail[i][j]<< " ";
	   }
	   cout <<endl;
	}
	cout << "Cipher text  : ";
	//print the text which is not eqaul to '-' sign which i used for diffrenciate charater
	for(i=0;i<key;i++)  
	{
	  for(j=0;j<len;j++)
	   {
	     if(rail[i][j]!='-')
	     {
	        cout<< rail[i][j];
	     }
	   }
	}
	 cout <<endl;
	return 0;
}
