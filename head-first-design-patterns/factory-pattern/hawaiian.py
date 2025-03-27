from pizza import Pizza

class Hawaiian(Pizza):
    
    def prepare(self):
        self.dough = self.style.create_dough()
        self.sauce = self.style.create_sauce()
        self.cheese = self.style.create_cheese()
        self.toppings = self.style.create_toppings()
        return f"Preparing a {self.style} {self.type} with {self.dough}, \
                {self.sauce}, {self.cheese}, {", ".join(self.toppings)}"
