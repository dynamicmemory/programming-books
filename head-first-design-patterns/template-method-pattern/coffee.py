from caffeine_beverage import Caffeine_beverages

class Coffee(Caffeine_beverages):


    def brew(self):
        print("Dripping coffee through the filer") 


    def add_condiments(self):
        print("Adding milk and sugar")


    def customer_wants_condiments(self):
        answer: str = self.get_user_input()

        return True if answer.lower()[0] == 'y' else False 


    def get_user_input(self):
        answer = input("Would you like milk and sugar with your coffee (y/n)?\n")

        if isinstance(answer, int):
            print("You entered a number and not y or n dummy")
            return "no"

        return answer

        
