class Singleton:

    _instance = None


    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            print("Creating the singleton instance")
            cls._instance = super().__new__(cls)
        return cls._instance

 
    def __init__(self) -> None:
        if not hasattr(self, "initialized"):
            self.value = "Default value"
            self.initialized = True


if __name__ == "__main__":
    Singleton_a = Singleton()
    print(f"singleton_a value: {Singleton_a.value}")

    Singleton_b = Singleton()
    Singleton_b.value = "Updated Values"

    print(f"singleton_a value after update: {Singleton_a.value}")
    print(f"singleton_b value: {Singleton_b.value}")
    print(f"Are both instances the same? {Singleton_a is Singleton_b}")
