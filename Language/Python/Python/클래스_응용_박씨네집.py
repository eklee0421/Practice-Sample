#박씨 클래스
class HousePark:
  lastname = "박"
  
  def __init__(self, name):
    self.fullname = self.lastname + name
  
  def travel(self, where):
    print("%s, %s 여행을 가네" %(self.fullname, where))
    
  def love(self, other):
    print("%s, %s 사랑에 빠졌네" %(self.fullname, other.fullname))
  
  def fight(self, other):
    print("%s, %s 싸우네" %(self.fullname, other.fullname))
    
  def __add__(self, other):
    print("%s, %s 결혼했네" %(self.fullname, other.fullname))
    
  def __sub__(self, other):
    print("%s, %s 이혼했네" %(self.fullname, other.fullname))
    
 #김씨 클래스(박씨 클래스로부터 상속)   
class HouseKim(HousePark):
  lastname = "김"
  def travel(self, where, day):
    print("%s, %s 여행 %d일 가네" %(self.fullname, where, day))
 
#클래스 
romeo = HousePark("로미오")  #이름: 박로미오
juliet = HouseKim("줄리엣")  #이름: 김줄리엣
romeo.travel("부산")  #박로미오, 부산 여행을 가네
juliet.travle("부산, 3")  #김줄리엣, 부산여행 3일 가네
romeo.love(juliet)  #박로미오, 김줄리엣 사랑에 빠졌네
romeo + juliet  #박로미오, 김줄리엣 결혼했네
romeo.fight(juliet) #박로미오, 김줄리엣 싸우네
romeo - juliet  #박로미오, 김줄리엣 이혼했네
