"""
*args 처럼 입역 변수 명 앞에 *를 붙이면 전부 모아서 튜플로 만들어준다
"""

def sum_many(*args):
  sum = 0
  for i in args:
    sum = sum + i #*args에 입력받은 모든 값을 더한다
   return sum
   
def sum_mul(choice, *args):
  if choice == "sum": #입력 인수 choice에 'sum'을 입력 받았을 때
    result = 0
    for i in args:
      result = result + i #args에 입력 받은 모든 값을 더한다
   elif choice == "mul":  #입력 인수 choice에 'mul'을 입력 받았을 때
    result = 1
    for i in args:
      result = result * i #*args에 입력 받은 모든 값을 곱한다
    return result
    
    
print(sum_many(1,2,3))  #6 을 출력
print(sum_mul('sum', 1,2,3,4,5))  #15 를 출력
print(sum_mul('mul', 1,2,3,4,5))  #120 을 출력
