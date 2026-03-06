n = int(input())
a = n
i = n

if 0 < n < 151:
    while i > 0:
        c = n - a + 1  
        print(c, end='') 
        n += 1 
        i -= 1  
else:
    print("Invalid Input")
