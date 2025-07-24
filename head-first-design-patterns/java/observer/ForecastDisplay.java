public class ForecastDisplay implements Observer, DisplayElement {
    private float temperature;
    private float humidity;
    private WeatherData weatherData;

    public ForecastDisplay(WeatherData weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    public void update(float temperature, float humidity, float pressure) {
        this.humidity = humidity;
        display();
    }

    public void display() {
        String message = "";
        if (humidity < 70) {
            message = "Should be a dry day";
        }
        else if (humidity < 90) {
           message = "Look out for rain on the way";
        }
        else {
            message = "It's raining and will continue to do so";
        }

        System.out.println("Forecast: " + message);
    }
}
