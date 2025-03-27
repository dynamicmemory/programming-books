import weatherData
import currentConditions

weather_data = weatherData.Weather_Data()

current_display = currentConditions.CurrentConditions(weather_data)
stats_display = currentConditions.StatisticsDisplay(weather_data)

weather_data.set_measurements(80, 65, 30.4)
weather_data.set_measurements(82, 70, 29.2)
weather_data.set_measurements(78, 90, 29.2)
