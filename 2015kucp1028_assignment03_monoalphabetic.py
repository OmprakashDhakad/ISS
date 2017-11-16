'''
      Author : OMPRAKASH
      ID     : 2015KUCP1028
      
      compile and run the code : python 2015kucp1028_assignment03_monoalphabetic.py
      
      Example output  : 
                        Enter plain text of 4 letters : hello
				please try again  : abcd
				Cipher text      : fljq
				Cracking  of monoalphabetic cipher and iteration 
				match on iteration no =  732
				
'''


import random

str  = raw_input("Enter plain text of 4 letters : ") #input string to encrypt
while len(str)>4 :
     str  = raw_input("please try again  : ")        #while loop for string length should not greater than 4  
     
str = str.lower()                       #convert string in lowercase letters  
ct = str
temp = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for i in range(0,len(str)):
	k = random.randint(0,len(temp)-1) #generate random number to select char from temp array
	
	if str[i]==temp[k] :
		ct = ct.replace(str[i],temp[k+1]) #replace the element of input string using random element from temp if str[i]==temp[k] element
		del temp[k+1]
	else:
		ct = ct.replace(str[i],temp[k])
		del temp[k]

print "Cipher text      :",ct

#crack begining of monoalphabetic only for 4 letters 

print "Cracking  of monoalphabetic cipher and iteration "
temp = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
# i created temp list again because of i have delete the temp element during encryption of monoalphabetic   
ite = 0
for i in temp :
	for j in temp :
	   for k in temp :
	      for l in temp :
	          ite = ite +1
	          if (i+j+k+l) == str :
	             print "match on iteration no = ",ite
	             break
