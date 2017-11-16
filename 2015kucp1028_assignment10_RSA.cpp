/*
      NAME   :   OMPRAKASH
      ID     :   2015KUCP1028
      
      compile the code : 
      run the code     :  
      
      Example output   : 	n = 71501
					x = 70812
					e = 5
					d = 1002797057
					please enter msg between 2 to 71499  :123
					Encrypted message  = 38600
					Original Message = 123

                        

*/


#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

unsigned long long int powm(unsigned long long int a,unsigned long long int b,unsigned long long int n)
{
      unsigned long long int result = 1;
      while (b > 0)
       {   
               result = (result * a)%n;
               result=result%n;

        b--;
       }
    return result;
}
int main()
{

  int  prime[] = { 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };
  
  srand(time(NULL));
  int p = prime[rand()%149];             //generate random values of p and q between 71 to 997
  int q = prime[rand()%149];
  
  unsigned long long int n = p*q;
  printf("n = %llu\n",n);
  unsigned long long int e=2 ;
  
  unsigned long long int x = (p-1)*(q-1);   //calculate (p-1) * (q-1) as x
  printf("x = %llu\n",x);
  
  while(e<x)                           //calculate e using gcd function  
  {
     if(gcd(e,x)==1)
     {
       break;
     }
     else 
     {
         e++;
     }
  }
  printf("e = %llu\n",e);
  
  unsigned long long int k = 2;  
  
  unsigned long long int d;
  
  for(k=x-1;k>1;k--)              //calculate d   
  {
     d = (1+k*x)/e;
     if((d*e)%x == 1)
     {
      break;
     }
  }
  
  printf("d = %llu\n",d);
  unsigned long long int msg;
  unsigned long long int l = 2;
  printf("please enter msg between %llu to %llu  :",l,n-2);
  scanf("%llu",&msg);                                            // msg input 
  
  while(msg>=(n-2))                       // checking msg is less the n-2 or not 
  { 
     printf("please enter msg between %llu to %llu  :",l,n-2);
     scanf("%llu",&msg); 
  }
  
 
  unsigned long long int c = powm(msg,e,n);
  
  printf("Encrypted message  = %llu\n", c);
 
    
  unsigned long long int  m = powm(c,d,n);
  
  printf("Original Message = %llu\n",m);
 
  return 0;
  
   
}


