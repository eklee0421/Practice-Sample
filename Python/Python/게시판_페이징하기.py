def getTotalPage(m, n):
    if m % n == 0:
        print(m//n) #소수점을 버리기 위해서는 '//'을 이용해서 
    else:
        print((m//n)+1)

m = int(input())
n = int(input())
getTotalPage(m,n)
