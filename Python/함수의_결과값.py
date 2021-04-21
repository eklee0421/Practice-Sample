"""
함수는 하나의 결과값만을 리턴한다
다음과 같이 두 개의 결과값을 리턴하게 되면, 튜플 형식으로 돌려준다.
만약 2개의 결과값처럼 받고 싶다면 두 개의 변수를 이용하여 함수를 리턴 받으면 된다
"""
def sum_and_mul(a,b):
  return a+b, a*b
  
result = sum_and_mul(3,4) #result = (7, 12) #튜플 형식으로 반환
sum, mul = sum_and_mul(3,4) #sum = 7, mul = 12
