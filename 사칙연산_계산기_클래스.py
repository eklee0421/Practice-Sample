###########################################
###############계산기 클래스###############

class FourCal:
  def setdata(self,first, second):
    self.first = first
    self.second = second
  def sum(self):
      result = self.first + self.second
      return result
  def mul(self):
      result = self.first * self.second
      return result
  def sub(self):
      result = self.first - self.second
      return result
  def div(self):
      result = self.first / self.second
      return result
    
###########################################
###############동작 확인하기###############

a = FourCal()
b = FourCal()
a.setdata(4,2)
b.setdata(3,7)
print(a.sum())  #6
print(a.mul())  #8
print(a.sub())  #2
print(a.div())  #2
print(b.sum())  #10
print(b.mul())  #21
print(b.sub())  #-4
print(b.div())  #0
