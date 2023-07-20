#asterisk는 우리가 흔히 알고 있는 * 를 의미함
#단순 곱셈, 제곱연산, 가변 인자 활용 등 다양하게 사용된다

def asterisk_test(a, *args):  #여러개의 값들을 한 번에 입력 받기
    print(a, args)
    print(type(args))
    
asterisk_test(1,2,3,4,5,6)  #a에는 1이, *args에는 2,3,4,5,6이 들어간다
'''
1 (2, 3, 4, 5, 6)
<class 'tuple'>
'''

def asterisk_test(a, **kargs):  #keyword 인자를 한 번에 넘겨줄 때는 **를 사용한다
    print(a, kargs)
    print(type(kargs))
    
asterisk_test(1, b=2, c=3, d=4, e=5, f=6)
'''
1 {'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6}
<class 'dict'>
'''

#unpacking a container - tuple, dict 등 자료형에 들어가 있는 값을 unpacking
def asterisk_test(a, *args):
    print(a, args[0])
    print(type(args))
    
asterisk_test(1, (2, 3, 4, 5, 6))
'''
1 ((2, 3, 4, 5, 6),) #맨 뒤에 콤마가 있으면 tuple 타입으로 들어왔다는 표시
<class 'tuple'>
'''

def asterisk_test(a, args): #unpacking이 된다!
    print(a, *args)
    print(type(args))

asterisk_test(1, (2,3,4,5,6))
'''
1 2 3 4 5 6
<class 'tuple'>
'''

a, b, c = ([1, 2], [3, 4], [5, 6])
print(a, b, c)
#[1, 2] [3, 4] [5, 6]

data = ([1, 2], [3, 4], [5, 6])
print(*data)
#[1, 2] [3, 4] [5, 6]

for data in zip(*([1, 2], [3, 4], [5, 6])):
    print(sum(data))
'''   
9      # 1+3+5
12     # 2+4+6
'''

def asterisk_test(a, b, c, d, e=0):
    print(a, b, c, d, e)

data = {"d":1 , "c":2, "b":3, "e":56}
asterisk_test(10, **data)
#10 3 2 1 56
