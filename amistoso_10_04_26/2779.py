n = int(input())
m = int(input()) 
v = []
for i in range(m):
    x = int(input(''))
    v.append(x)
    
print(f'{n - len(set(v))}')

