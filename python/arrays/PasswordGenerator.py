import random


a = []
x = input("Please enter a string, type 000 to exit: ")
while x != "000" :
    a.append(x)
    x = input("Please enter a string, type 000 to exit: ")

if len((a)) >= 3:
    n1 = random.randint(0,len(a)-1)
    n2 = random.randint(0,len(a)-1)
    n3 = random.randint(0,len(a)-1)
    x1 = a[n1]
    x2 = a[n2]
    x3 = a[n3]
    pejo= x1+x2+x3
    print("Your New Password is: " + pejo )
else:
    print("You Need at least Three Strings")
    
