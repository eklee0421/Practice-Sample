#문자열 더해서 연결하기
head = "Python"
tail = " is fun!"
print(head + tail)  #Python is fun! 이 출력

#문자열 곱하기
a = "Python"
print(a * 2)  #PythonPython 출력


###########################
#######문자열 인덱싱#######
###########################
b = "abcdefg"
print(a[2]) #c 출력 -> 첫번째 문자는 0부터 시작한다
print(a[-1]) #g 출력 -> -는 문자열을 뒤에서부터 센다

#############################
#######문자열 슬라이싱########
#############################
c = "qwertyu"
print(c[0:4]) #qwer 출력  -> c[0] <= 부터 < c[4] 까지 출력
print(c[1:5]) #wert 출력  -> c[1] <= 부터 < c[5] 까지 출력
print(c[3:])  #rtyu 출력  -> c[3] 부터 끝까지 출력
print(c[:4])  #qwe 출력 -> 처음부터 c[3]까지 출력
print(c[:]) #qwertyu 출력 -> 처음부터 끝까지 출력
print(c[1:-2]) #wert 출력 -> c[1]부터 c[-3]까지 출력

# b를 "gbcdefg"로 바꾸기
# 다음과 같은 형식은 불가능 하다! => b[0] = 'g'
print('g' + c[1:]) #이와 같이 슬라이싱 하여 변경 할 수 있다

###########################
#######문자열 포매팅#######
###########################
#문자열 포매팅이란 문자열 내의 특정한 값만 바꿀 필요가 있을 때 사용

#1. 숫자 바로 대입
print("I eat %d apples")  %3  #I eat 3 apples 출력

#2. 문자열 바로 대입
print("I eat %s apples") %three #I eat three apples 출력

#3. 숫자 값을 나타내는 변수로 대입
number = 3
print("I eat %d apples") %number  #I eat 3 apples 출력

#4. 두 개 이상의 값 넣기
n = 10
d = five
print("I eat %d apples and %s bananas") %(n,d) #I eat 10 apples and five bananas 출력
