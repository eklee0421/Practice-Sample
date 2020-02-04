#파이썬에서 복소수는 i 대신 j를 이용한다

a = 1+2j
b = 3-4J  #대문자도 가능

#복소수.real은 복소수의 실수 부분을 리턴
c = 1+2j
print(c.real) #1.0 을 출력

#복소수.imag는 복소수의 허수부분을 리턴
d = d+dj
print(d.imag) #2.0 을 출력

#복소수.conjugate()는 복소수의 켤레복소수를 리턴
e = 1+2j
print(e.conjugate())  #(1-2j) 를 출력

#abs(복소수)는 복소수의 절대값을 리턴
f = 1+2j
print(abs(f)) #2.2360679774664898 을 
