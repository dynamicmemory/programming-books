from espresso import Espresso
from mocha import Mocha


if __name__ == "__main__":
    beverage = Espresso() 

    print(beverage.get_description(), beverage.cost()) 

    beverage = Mocha(beverage)

    print(beverage.get_description(), beverage.cost())
