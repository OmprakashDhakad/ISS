/*
    NAME  :  OMPRAKASH
    ID    :  2015kucp1028
    
    compile the code : 
    Run the code     :
    
    Example output   :
                        Enter plain text : jai maheshmati
				Enter key  : om prakash
				ascii	char
				5	
				12	

				73	I
				80	P
				31	
				0	
				3	
				4	
				0	
				0	
				109	m
				97	a
				116	t
				105	i
				final result after encryption : 
								         I P       m a t i 
				original text after decryption :jai maheshmati



    
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
   int i,j,k=0,l=0;
   string pt,key;
   
   cout << "Enter plain text : ";           // enter the inputs plain text and key  with spaces 
   getline(cin ,pt);
   cout << "Enter key  : ";
   getline(cin ,key);
   
   unsigned int result[pt.length()];
   string pt1[50],key1[50];
   unsigned lenpt = pt.size();
   unsigned lenkey = key.size();
   
   
    
      int temp = lenpt%8;
      pt.resize(lenpt+(8-temp),'\0');               //resize the length of plain text to multiple of 8 character (64bit)
      int temp1 = lenkey%8;
      key.resize(lenkey+(8-temp1),'\0');            //resize the length of key to multiple of 8 character (64bit)
      
   int z = (pt.size()) - (key.size());
   
   // check the difference of length of pt and key if diff is multiple of 8 the increase the length of key or pt
   
   if( z!=0 && (pt.size())>(key.size()) )           
   {
      key.resize(lenkey+z,'\0');
   }
   else if (z!=0 && (pt.size())<(key.size()) )
   {
       pt.resize(lenpt+z,'\0'); 
   }
   
   
   k=0;
   l=0;
   for (i=0;i<pt.length();i = i+8)              // take the 64bit plain text blocks and key also
   {
      pt1[k] = pt.substr(i,8);
      k++;
   }
   for (i=0;i<key.length();i = i+8)
   {
      key1[l] = key.substr(i,8);
      l++;
   }
   int x=0;
   int y = max(k,l);
   
   for (i=0;i<y;i++)
   {
      for (j=0;j<8;j++)
      {
         result[x] = (int)pt1[i][j] ^ (int)key1[i][j];             // take xor of corresponding  character of pt and key
         x++;
       }
       
   }
   
   printf("ascii\tchar\n");
   for (i=0;i<lenpt;i++)
   {
      printf("%d\t%c\n",result[i],(char)(result[i]));          // print the result of every charcter xor
   }
   printf("final result after encryption :");
   fflush(stdin);
   for (i=0;i<lenpt;i++)
   {
      printf("%c ",(char)(result[i]));          // print the whole result 
   }
   
   
   // Decryption of the ECB 
   x=0;
   for (i=0;i<y;i++)
   {
      for (j=0;j<8;j++)
      {
         result[x] = result[x] ^ (int)key1[i][j];             // take xor of corresponding  character of  key to result value
         x++;
       }
       
   }
   cout << endl;
   printf("original text after decryption :");
   fflush(stdin);
   for (i=0;i<lenpt;i++)
   {
      printf("%c",(char)(result[i]));          // decrypted result  
   }
   cout << endl;
   
}
