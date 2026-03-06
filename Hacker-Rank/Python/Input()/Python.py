x, k = (int(a) for a in input().split(' '))
p = input()
result = eval(p.replace('x', str(x)))
print(result == k)
