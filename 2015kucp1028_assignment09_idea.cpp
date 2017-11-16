/*

     Author   : OMPRAKASH
     Id       : 2015kucp1028
     
     compile the code :  g++ 2015kucp1028_assignment09_idea.cpp 
     Run the code     :  ./a.out
     
     Example output  : 
				Enter your plain text of 8 character : helloopdhi
				Please Enter only  8 character : helloopd
				Enter your key text of 16 character:abcdefghijklmnopqrstuvwxyz
				Please Enter only  16 character : abcdefghijklmnop
				your 64bit plain text :0110100001100101011011000110110001101111011011110111000001100100
				your 128bit key text :01100001011000100110001101100100011001010110011001100111011010000110100101101
				010011010110110110001101101011011100110111101110000
				your four part of cipher text in binary format : 
				pt2[0] = 1000010101000011
				pt2[1] = 1001100100110001
				pt2[2] = 0101100100100101
				pt2[3] = 1110010110011101
				your final 64bit cipher text in binary format : 
				1000010101000011100110010011000101011001001001011110010110011101

*/



#include<bits/stdc++.h>
using namespace std;
#define m 65537

string key[52] ;
string pt[4] ;
int keys[52];
unsigned int ptp[4];
string pt2[4];

/* Integer to binary string converting function using required base */
string itobs(int a ,int base)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < base; i++)
    {
        if((mask&a) >= 1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    
    return binary;
}

/* String to integer converting function using length of the string */
int sktoik(string str , int base)
{
    int temp =0,i;
    int b =  base-1;
    for (i=b;i>=0;i--)
    {
        temp += ((int)str[i]-48) * pow(2,b-i);
    }
    
    return temp;
}

void rounds(int j)            // rounds function for 8  rounds using 52 keys
{
   int result[14];                             //result array to store the values of each step in a perticular round
         int  i = j*6;
         result[0] =  (ptp[0] * keys[i+0])%m;            //m is for convert value in range of 65536
	   result[1] =  (ptp[1] + keys[i+1])%m;
	   result[2] =  (ptp[2] + keys[i+2])%m;
	   result[3] =  (ptp[3] * keys[i+3])%m;
	   result[4] =  (result[0] ^ result[2])%m;
	   result[5] =  (result[1] ^ result[3])%m;
	   result[6] =  (result[4] * keys[i+4])%m;
	   result[7] =  (result[5] + result[6])%m;
	   result[8] =  (result[7] * keys[i+5])%m;
	   result[9] =  (result[6] + result[4])%m;
	   result[10] = (result[0] ^ result[8])%m;
	   result[11] = (result[2] ^ result[8])%m;
	   result[12] = (result[1] ^ result[9])%m;
	   result[13] = (result[3] ^ result[9])%m;
	   
	   ptp[0] = result[10]%m;                   //store the last four results in intermediate array
	   ptp[1] = result[11]%m;
	   ptp[2] = result[12]%m;
	   ptp[3] = result[13]%m;
	   
	   /*for(i=0;i<4;i++)                     // if you want to see your intermediate plain texts you can uncomment it
	   {
	     cout << "ptp["<<i<<"] = "<<ptp[i] <<endl;;
	   }*/
}
 
string leftshift(string arr)                  //leftcircular shift function for 128bit key to make 52 keys
{ 
    string temp = arr.substr(25,128-25);
    temp = temp + arr.substr(0,25);
    
    return temp;
}

void binaryptconverter(string arr)            //function for divide 64bit plain text in 16bits of 4 plaintexts
{
   int i,j=0;
   
	    for(i = 0; i < 64; i++)
	    { 
	        pt[j]+= arr[i];
	        if(i==15 || i==31 || i==47)
	        { 
	           j++;
	        } 
		  
	    }
   /*for(i = 0; i < 4; i++)                  // if you want to see your 4 part of plain texts  you can uncomment it
   { 
     cout << "pt["<<i<<"] = " << pt[i] <<endl;
   }*/
}

void binarykeyconverter(string arr)       //function for divide 128bit key text in 16bits of 8 keytexts
{
   
   int i,j=0,l;
   
     for(l = 0; l < 8; l++)
	{
	    for(i = 0; i < 128; i++)
	    { 
	        key[j]+= arr[i];
	        if(i==15 || i==31 || i==47 || i==63 || i==79 || i==95 ||i==111 || i==127)
	        { 
	           j++;
	        } 
		  
	    }
	    arr = leftshift(arr);
	    
	}
	        key[48] = arr.substr(0,16);
	        key[49] = arr.substr(16,16);
	        key[50] = arr.substr(32,16);
	        key[51] = arr.substr(48,16);
		  
   /*for(i = 0; i < 52; i++)                          // if you want to see your 52 binary keys you can uncomment it
   { 
     cout << "key["<<i<<"] = "<<key[i] <<endl;
   }*/
}


int main()
{ 
   int i,j;
   string pt1 ;                                         // initial input plaintext and key strings in character
   string key1 ;
   
   printf("Enter your plain text of 8 character : ");
   cin >> pt1;
   if(pt1.length() != 8)                               // to check the length of plaintext of 8 character
   {
      while(pt1.length() != 8)
      {
         printf("Please Enter only  8 character : ");
         cin >> pt1;
      }
   } 
   
   printf("Enter your key text of 16 character:");
   cin >> key1;
   if(key1.length() != 16)                           // to check the length of keytext of 16 character
   {
      while(key1.length() != 16)
      {
         printf("Please Enter only  16 character : ");
         cin >> key1;
      }
   } 
   
   
   string pti,keyi;
   for(i=0;i<8;i++)                                 // convert every charcter of plaintext in 8 binary bits as a string 
   {
     pti += itobs((int)pt1[i] , 8);
   }
   cout << "your 64bit plain text :" << pti << endl;
   for(i=0;i<16;i++)                                // convert every charcter of key in 8 binary bits as a string 
   {
     keyi += itobs((int)key1[i] , 8);
   }
   cout << "your 128bit key text :" << keyi  << endl;
   //printf("your 4 plain text strings :\n");
   binaryptconverter(pti);
   //printf("your 52 key text  strings :\n");
   binarykeyconverter(keyi);
   
   
   
   for(i=0;i<52;i++)                                   // convert 52 keys binary into integer key values
   {
      keys[i] = sktoik(key[i] , 16);
   }
   
   for(i=0;i<4;i++)                                   // convert 4 keys plain texts  into integer values
   {
     ptp[i] = sktoik(pt[i] ,16);
   }
   
   
   
   for(i=0;i<8;i++)                                    // performing 8 rounds on plaintexts  according to algorithm
   {
     rounds(i);
   }
     ptp[0] = (ptp[0] * keys[48])%m;                  // four operations for output transformation
     ptp[1] = (ptp[1] + keys[49])%m;
     ptp[2] = (ptp[2] + keys[50])%m;
     ptp[3] = (ptp[3] * keys[51])%m;
    
     
     
    cout << "your four part of cipher text in binary format : "<< endl;
   for(i=0;i<4;i++)                                   //converting four part of cipher text in binary strings
   {
     pt2[i] = itobs(ptp[i],16);
     cout << "pt2["<<i<<"] = "<<pt2[i] <<endl;;
   }
   
   
   string ct;
   for(i=0;i<4;i++)                                 //combine four part of cipher text in final ct string
   {
     ct += pt2[i];;
   }
   cout << "your final 64bit cipher text in binary format : "<< endl;
   cout << ct <<endl;                                            //your final cipher text in binary format 
   
   
   string last;                                    //if you want to see your binary string into charcter format you can uncomment it
   for (i=0;i<4;i++)
   {
      int ch1,ch2;
      ch1 =  sktoik(pt2[i].substr(0,8) , 8);
      ch2  = sktoik(pt2[i].substr(8,16) , 8);
      cout << (ch1%128) << " " << (ch2%128) << endl; 
      cout << (char)(ch1%128) << " " << (char)(ch2%128) << endl;
      last += (char)(ch1%128);
      last += (char)(ch2%128);
      
   }
   cout << "final cipher text : "<< last << endl;
   
   
     
}

