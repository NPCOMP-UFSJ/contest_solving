# Feito por Gian Teixeira

while True:
    try: C, K = map(int, input().split())
    except: break
    suspicious = set()
    for _ in range(C):
        a = input()
        S = int(input())
        for _ in range(S):
            b = input()
            suspicious.add(f'{a};{b}')
    for _ in range(K):
        pair = input()
        print('Y'
              if pair in suspicious
              else 'N')
