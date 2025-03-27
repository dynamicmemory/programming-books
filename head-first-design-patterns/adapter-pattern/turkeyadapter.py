from duck import Duck 

class Turkeyadapter(Duck):
     

    def __init__(self, turkey):
        self.turkey = turkey


    def quack(self):
        self.turkey.gobble()


    def fly(self):
        for i in range(5):
             self.turkey.fly()
