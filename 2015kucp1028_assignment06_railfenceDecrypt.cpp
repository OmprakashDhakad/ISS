/*
    Author : OMPRAKASH
    ID     : 2015kucp1028
    
    compile the code  : g++ 2015kucp1028_assignment06_railfenceDecrypt.cpp   
    Run the code      : ./a.out
    
    Example output  : 
                        Enter a key : 4
				Enter a string  : oaamkshkpahdar d
				o - - - - - a - - - - - a - - - 
				- m - - - k - s - - - h - k - - 
				- - p - a - - - h - d - - - a - 
				- - - r - - - - -   - - - - - d 
				Cipher text  : omprakash dhakad



*/
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;
int main()
{
	int key;
	string str;
	int i=0;
	int j=0;
	int k=0;
	int flag=0;
	int l=0;
	cout << "Enter a key : ";
      cin >> key;
	cout << "Enter a string  : ";
	cin.ignore();
      getline(cin, str, '\n');
      
	int len = str.length();
	char rail[key][len]; 
	for(i=0;i<key;i++)    // fill the rail matrix using - sign
	{
	  for(j=0;j<len;j++)
	   {
	     rail[i][j] ='-';
	   }
	}
	i=0;
	j=0;
	k=0;
	flag=0;
	for (int l=0;l<len;l++)
	{
	      
	      if(flag==0)
	      {
	      
			 rail[i][j] ='*';        //fill the rail diagonal character using * to allocate location for characters
			 i++;
			 j++;
			 if(i==key)
			 {
			     i=i-2;
			     flag=1;
			 }
		 }
		 else if(flag==1)
		 {
			 rail[i][j] ='*';
			 i--;
			 j++;
			 if(i==-1)
			 {
			     i=i+2;
			     flag=0;
			 }
	      }
	}
	k=0;
	i=0,j=0;
	//repalce the all * from our strings charcter 
	for(i=0;i<key;i++)
	{
	  for(j=0;j<len;j++) 
	  {
	     if(rail[i][j]=='*')
	     {
	        rail[i][j]=str[k];
	        k++;
	     }
	  }
	}
	//print the matrix after filling character of our decrypted string 
	for(i=0;i<key;i++)
	{
	  for(j=0;j<len;j++)
	   {
	     cout<< rail[i][j]<< " ";
	   }
	   cout <<endl;
	}
	cout << "Cipher text  : ";
	k=0;
	i=0,j=0;
	flag=0;
	//print the charcter which is on zigzag motion in railmatrix
	for (l=0;l<len;l++)
	{
	      
	      if(flag==0)
	      {
	      
			 cout << rail[i][j];
			 i++;
			 j++;
			 k++;
			 if(i==key)
			 {
			     i=i-2;
			     flag=1;
			 }
		 }
		 else if(flag==1)
		 {
			 cout << rail[i][j];
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
	 cout <<endl;
	return 0;
}
