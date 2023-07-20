"""""""""""""""""""""
""""""""split""""""""
"""""""""""""""""""""
#string type의 값을 나눠서 list 형태로 변환

items = 'zero one two three'.split() #빈칸을 기준으로 문자열 나누기
print(items)
#['zero', 'one', 'two', 'three']

example = 'python,jqurey,javascript'  #","을 기준으로 문자열 나누기
example.split(",")
#['python', 'jquery', 'javascript']

a, b, c = example.split(",") #리스트에 있는 각 값을 a,b,c 변수로 unpacking

example2 = 'cs50.inha.edu'
subdomain, domain, tld = example.split('.') #"."을 기준으로 문자열 나눠서 unpacking

"""""""""""""""""""""
"""""""""join""""""""
"""""""""""""""""""""
#string list를 합쳐 하나의 string으로 만들 때 사용

colors = ['red', 'blue', 'green', 'yellow']
result = ''.jion(colors)
result
#'redbluegreenyellow'

result = ' '.join(colors) #연결시 빈칸 1칸으로 연결
result
#'red blue green yellow'

result = ', '.join(colors) #연결시 ', '으로 연결
result
#'red, blue, green, yellow'

result = '-'.join(colors) #연결시 "-"으로 연결
result
#'red-blue-green-yellow'
