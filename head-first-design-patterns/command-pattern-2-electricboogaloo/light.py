class Light:

    def __init__(self, name = "light"):
        self.name = name 

    
    def on(self):
        print(f"The {self.name} light has been switched on")


    def off(self):
        print(f"The {self.name} light has been switched off")
