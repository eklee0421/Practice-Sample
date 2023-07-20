result = [i for i in range(10)]
print(result)
#[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

result = [i for i in range(10) if i % 2 == 0] #if문을 넣어서 조건을 만족하는 것만 리스트로!
print(result)
#[0, 2, 4, 6, 8]

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#Nested For loop - 이중 for문을 사용한 것

word_1 = "Hello"
word_2 = "World"
result = [i+j for i in word_1 for j in word_2]
print(result)
'''
['HW', 'Ho', 'Hr', 'Hl', 'Hd', 'eW', 'eo', 'er'.
'el', 'ed', 'lw', 'lo', 'lr', 'll', 'ld', 'lw',
'lo', 'lr', 'll', 'ld', 'oW', 'oo', 'or', 'ol', 'od']
'''

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#Nested For loop + if 문

case_1 = ["A", "B", "C"]
case_2 = ["D", "E", "A"]

result = [i+j for i in case_1 for j in case_2]
print(result)
#['AD', 'AE', 'BD', 'BE','BA', 'CD', 'CE', 'CA']

result = [[a+b for a in case_1] for b in case_2]
print(result)
#[['AD', 'BD', 'CD'], ['AE', 'BE', 'CE'], ['AF', 'BF', 'CF']]

# if 문 추가 - filter: i와 j가 같다면 list에 추가하지 않음
result = [i+j for i in case_1 for j in case_2 if not(i==j)]
result.sort()
print(result)
#['AD', 'AE', 'BA', 'BD', 'BE', 'CA', 'CD', 'CE']

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#split + list Comprehension

words = 'The quick brown fox jumps over the lazy dog'.split() #문장을 빈칸 기준으로 나눠 list로 변환
print(words)
#['The', 'quick', 'brown', 'fox', 'jumps', 'over', 'the', 'lazy', 'dog']

stuff = [[w.upper(), w.lower(), len(w)] for w in words] #list의 각 elemente들을 대문자, 소문자, 길이로 변환하여 two dimensiomal list로 변환

for i in stuff:
    print(i)
    
 '''
 ['THE', 'the', 3]
 ['QUICK', 'quick', 5]
 ['BROWN', 'brown' , 5]
 ['FOX', 'fox' ,3]
 ['JUMPS', 'jumps' , 5]
 ['OVER', 'over', 4]
 ['THE', 'the', 3]
 ['LAZY', 'lazy', 4]
 ['DOG', 'dog', 3]
 '''
