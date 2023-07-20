#연결 리스트

class Node:
    def __init__(self, data, next=None):    #이 클래스로 객체가 생성될 때 __init__ 메서드 호출
        self.data = data    #데이터를 저장
        self.next = next    #링크를 저장

#리스트 초기화
def init_list():
    global node_A
    node_A = Node("A")
    node_B = Node("B")
    node_D = Node("D")
    node_E = Node("E")
    node_A.next = node_B
    node_B.next = node_D
    node_D.next = node_E


#삭제 
def delete_node(del_data):
    global node_A
    pre_node = node_A
    next_node = pre_node.next

    if pre_node.data == del_data:
        node_A = next_node
        del pre_node
        return

    while next_node:
        if next_node.data == del_data:
            pre_node.next = next_node.next
            break
        pre_node = next_node
        next_node = next_node.next

#삽입
def insert_node(data):
    global Node_A
    new_node = Node(data)
    node_P = node_A
    node_T = node_A
    while node_T.data <= data:
        node_P = node_T
        node_T = node_T.next
    new_node.next = node_T
    node_P.next = new_node

#출력
def print_list():
    global node_A
    node = node_A
    while node:
        print(node.data, end = ' ')
        node =node.next
    print()

#main
if __name__ == '__main__':
    print("연결 리스트 초기화 후")
    init_list()
    print_list()
    print("node C를 추가한 후")
    insert_node("C")
    print_list()
    print("node B를 삭제한 후")
    delete_node("B")
    print_list()
