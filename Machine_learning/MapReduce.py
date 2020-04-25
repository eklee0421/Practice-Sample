############### Map ##############
#sequence 자료형 각 element에 동일한 function을 적용함

ex = [1, 2, 3, 4, 5] #ex라는 자료형
f = lambda x: x ** 2
print(list(map(f, ex)))
#[1, 4, 9, 16, 25]

ex = [1, 2, 3, 4, 5]
f = lambda x, y: x + y
print(list(map(f, ex, ex)))
#[2, 4, 6, 8, 10]

list(map(
    lambda x: x ** 2 if x % 2 == 0 else x,  #만족하면 x**2 반환, 만족하지 않으면 x 반환
    ex))
#[1, 4, 3, 16, 5]

[value ** 2 for value in ex]
#[1, 4, 9, 16, 25]

#python 3에는 list를 꼭 붙여줘야함
ex = [1,2,3,4,5]
print(list(map(lambda x: x+x, ex)))
print((map(lambda x: x+x, ex)))

f = lambda x: x ** 2
print(map(f, ex))
for i in map(f, ex):
    print(i)
'''
1
4
9
16
25
'''

result = map(f, ex)
print(result)
print(next(result))

import sys
sys.getsizeof(ex)
sys.getsizeof((map(lambda x: x+x, ex)))
sys.getsizeof(list(map(lambda x: x+x, ex)))

############### Reduce ##############
# map function과 달리 list에 똑같은 함수를 적용해서 통합
from functools import reduce
print(reduce(lambda x, y: x+y, [1, 2, 3, 4, 5]))
#15
# (((((1) + 2) + 3) + 4) + 5) == 15가 된 것


def factorial(n):
    return reduce(
            lambda x, y: x*y, range(1, n+1))
factorial(5)
#120
