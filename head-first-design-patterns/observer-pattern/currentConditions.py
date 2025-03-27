from observer import Observer
from subject import Subject


class CurrentConditions(Observer):

    def __init__(self, weather_data: Subject) -> None:
        self.temp = 0.0
        self.humidity = 0.0
        self.weather_data = weather_data
        weather_data.register_Observer(self)


    def update(self, temp, humidity, pressure):
        self.temp
        self.humidity
        self.display()


    def display(self):
        print(f"Current Conditions: {self.temp}F, and {self.humidity}% humidity")


class StatisticsDisplay(Observer):

    def __init__(self, weather_data: Subject) -> None:
        self.temp = []
        self.weather_data = weather_data
        weather_data.register_Observer(self)


    def update(self, temp, humidity, pressure):
        self.temp.append(temp)
        self.display()


    def display(self):
        avg_temp = sum(self.temp) / len(self.temp)
        print(f"Avg/Max/Min temps: {avg_temp:.1f}/{max(self.temp):.1f}/{min(self.temp):.1f}")
