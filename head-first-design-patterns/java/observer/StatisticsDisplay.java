import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class StatisticsDisplay implements Observer, DisplayElement {
    private List<Float> weeklyTemps;
    private float temperature;
    private WeatherData weatherData;

    public StatisticsDisplay(WeatherData weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
        weeklyTemps = new ArrayList<Float>();
    }

    public void update(float temperature, float humidity, float pressure) {
        weeklyTemps.add(temperature);
        int total = 0;
        int counter = 0;
        for (float temp : weeklyTemps) {
            total += temp;
            counter++;
        }
        this.temperature = total/counter;
        display();
    }

    public void display() {
        System.out.println("AVG/MAX/MIN temperature = " + temperature + 
                "/" + Collections.max(weeklyTemps) + "/" + 
                Collections.min(weeklyTemps));
    }
}
