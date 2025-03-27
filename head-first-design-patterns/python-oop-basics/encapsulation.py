class Encap:

    def __init__(self):

        self._protected_var = 10
        self.__private_var = 20


    def get_priv(self):
        print(self.__private_var)


c = Encap()

print(c._protected_var)

try:
    print(c.__private_var)
except(AttributeError):
    print("Cannot access private attributes")
finally:
    c.get_priv()
