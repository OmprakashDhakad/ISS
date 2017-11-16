'''
    Author  : OMPRAKASH
    ID      : 2015kucp1028
    
    compile and rum the code : python 2015kucp1028_assignment05_playfair.py 
    
    Example output : 
                        Enter plain text : jaimaheshmati
				Enter key text : cheesecakepizza
				Cipher text :  bebgcesaafbyzw

'''

#plain text input with space problem
pt =  raw_input("Enter plain text : ").strip().split()
pt = ''.join(pt)

if len(pt)%2==1:  # if string length is odd
  pt= pt+'x'
pt = list(pt)

for i in xrange(len(pt)-1):  #if string have same character ex.aabc
   if pt[i]==pt[i+1]:
      pt[i+1]='x'
   else:
      pt[i+1]=pt[i+1]  

pt = ''.join(pt)

key = raw_input("Enter key text : ")  #input key string 
key = key.lower()
alpha = "abcdefghiklmnopqrstuvwxyz"   # assumption alphabet string 
keymat = {}
z=0
count = 0
for i in xrange(len(key)):            # put key text in a matrix using python dictonary
  if(('i' in keymat.values()) and (key[i]=='i' or key[i]=='j')):
      continue
  if(('j' in keymat.values()) and (key[i]=='i' or key[i]=='j')):
      continue
  if(key[i] in keymat.values()):
      continue
  else :
     	keymat[z] = key[i]
     	z=z+1


z = keymat.keys()[-1] + 1

for i in xrange(25):             # put rest charcters  in a matrix 
  if(('i' in keymat.values()) and (alpha[i]=='i' or alpha[i]=='j')):
      continue
  if(('j' in keymat.values()) and (alpha[i]=='i' or alpha[i]=='j')):
      continue
  if(alpha[i] in keymat.values()):
      continue
  else :
     if('i' or 'j' not in keymat.values()):
     	     keymat[z] = alpha[i]
     	     z= z+1
   
 
keymat = {v: k for k, v in keymat.iteritems()}  # use reverse dictanary to access value as key 

ct = ""
for i in xrange(0,len(pt)-1,2):
  first = pt[i]
  second = pt[i+1]
  
  if(first=='i' or first=='j'):
  	if('i' in keymat.keys()):
  	  first = 'i'
  	else:
  	  first = 'j'
  if(second=='i' or second=='j'):
  	if('i' in keymat.keys()):
  	  second = 'i'
  	else:
  	  second = 'j'
  
  r1=1
  r2=-1
  c1=1
  c2=-1
  #print first,'+',second
  for value in keymat:
  
     if first == value:
       #print keymat[value]
       r1 = keymat[value]/5
       c1 = keymat[value]%5
       #print 'first = ',r1,' ',c1
     if second == value:
       #print keymat[value]
       r2 = keymat[value]/5
       c2 = keymat[value]%5
       #print 'second = ',r2,' ',c2 
  keymat = {v: k for k, v in keymat.iteritems()}   # use reverse dictanary to access value as value
  if(r1==r2):
    c1=(c1+1)%5
    c2= (c2+1)%5
    ct =ct+keymat[r1*5+c1]
    ct = ct+keymat[r1*5+c2]
    
  elif(c1==c2):
    r1=(r1+1)%5
    r2= (r2+1)%5
    ct =  ct+keymat[r1*5+c1]
    ct = ct+keymat[r2*5+c1]
    
  else:
    temp =c1
    c1=c2
    c2=temp
    ct =  ct+keymat[r1*5+c1]
    ct = ct+keymat[r2*5+c2]
  #print ct
  
  keymat = {v: k for k, v in keymat.iteritems()}  # use reverse dictanary to access value as key to use again in for loop

print 'Cipher text : ',ct
