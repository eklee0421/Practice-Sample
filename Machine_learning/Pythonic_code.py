"""Pythonic_code: 파이썬 스타일의 코드
파이썬은 코드 짜는 시간을 줄여준다"""

"""""""""""""""""""""""""""""""""""""""
""""""""""""""일반 코드"""""""""""""""""
"""""""""""""""""""""""""""""""""""""""
alphabet = ["a", "b", "c", "d", "e"]
result1=""

for s in colors:
  result1 += s
  
print(result1)
#>>>abcde

"""""""""""""""""""""""""""""""""""""""
"""""""""""pythonic code"""""""""""""""
"""""""""""""""""""""""""""""""""""""""
colors = ["red", "blue", "green", "yellow"]
result2 = "".join(colors)

print(result2)
#>>>redbluegreenyellow
