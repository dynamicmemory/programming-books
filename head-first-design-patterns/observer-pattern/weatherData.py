from subject import Subject

class Weather_Data(Subject):
    
    def __init__(self) -> None:
        self.observers = []
        self.temp = 0.0
        self.humidity = 0.0
        self.pressure = 0.0


    def register_Observer(self, Observer):
        self.observers.append(Observer)


    def remove_Observer(self, Observer):
        self.observers.remove(Observer)


    def notify_Observer(self):
        for o in self.observers:
            o.update(self.temp, self.humidity, self.pressure)


    def set_measurements(self, temp, humidity, pressure):
        self.temp = temp
        self.humidity = humidity
        self.pressure = pressure
        self.notify_Observer()



