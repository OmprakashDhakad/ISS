/*
     NAME   :  OMPRAKASH
     ID     :  2015KUCP1028
     
     COMPILE THE CODE :  g++ 2015kucp1028_assignment07_single_column.cpp  
     RUN THE CODE     : ./a.out 
     
     Example output   : Enter the plain text : 
				omprakash dhakad
				Enter the Key: 
				321
				Enter the Key again beacuse matrix can't fill : 
				4123
				Matrix form of single column cipher : 
				o m p r 
				a k a s 
				h   d h 
				a k a d 
				Encrypted cipher text : 
				rshdoahamk kpada
				Decryted cipher text : 
				omprakash dhakad

     
  
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{ 
   string pt,key;
   cout<<"Enter the plain text : "<<endl;            // take inputs plain text and key
   getline(cin,pt);
   cout<<"Enter the Key: "<<endl;
   cin>>key;
   int len = pt.length();
   int n = key.length();
   while(n*n < len)                     // check  the length of pt is not greater then lenofkey * lenofkey
   {
     cout<<"Enter the Key again beacuse matrix can't fill : "<<endl;
     cin>>key; 
     n = key.length();
   }
   char arr[n][n];
   
   for(int i=0;i<9;i++){                           // take matrix of 9x9 
   	for(int j=0;j<9;j++){
   		arr[i][j] = ' ';
   	}
   }
   for(int i=0;i<len;i++)                    // fill the elements of pt in matrix  
   {
       arr[i/n][i%n] = pt[i];
   }
   
   cout << "Matrix form of single column cipher : "<< endl;         // print the matrix form of single column
   int k=0;
   for(int i=0;i<n;i++){
   	for(int j=0;j<n;j++) {
   		cout <<arr[i][j]<< ' ';
   	   }  	   	
   		cout << endl;
   	}
   	
   	cout << "Encrypted cipher text : "<<endl;             // take the elemnets of matrix acc to key
   	int ke=0;
   	string ct="";
   	for(int i=0;i<n;i++)
   	{
   	  pre:;
   	  ke =((int)key[i]-48)-1; 
   	  for(int j=0;j<n;j++)
   	  {
   	    if((((n*(j) + ke+1))>len))
   	    {
   	     continue;
   	    }
   	     //cout<<  arr[j][ke];
   	     ct +=arr[j][ke];                                //make string for cipher text 
   	  }
   	}
   	
   	cout<<ct<<endl;
   	
   	int ke1=0;                                      // Decryption of the cipher text 
   	string pt1="";
   	char arr1[n][n];
   	for(int i=0;i<n;i++)
   	{
   	  
   	  ke1 =((int)key[i]-48)-1; 
   	  for(int j=0;j<n;j++)
   	  {
   	    if((((n*(j) + ke1+1))>len))
   	    {
   	     continue;
   	    }
   	     
   	     arr1[j][ke1] = arr[j][ke1];
   	  }
   	}
   	cout << "Decryted cipher text : "<<endl;
   	
   	for(int i=0;i<n;i++)
   	{
   	  
   	  
   	  for(int j=0;j<n;j++)
   	  {
   	    if((((n*(i) + j+1))>len))
   	    {
   	     continue;
   	    }
   	     cout << arr1[i][j] ;
   	     
   	  }
   	}
   cout << endl;
}
  
