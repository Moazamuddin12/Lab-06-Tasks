#include <iostream>
using namespace std;

class WeatherStats{
public:
    static double calculateAverageTemperature(const double temps[], int size)
    {
        if (size <= 0) return 0;

        double sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += temps[i];
        }

        return sum / size;
    }
};

class ExtendedWeather : public WeatherStats{
public:
    double getTemperatureFluctuation(const double temps[], int size) const
    {
        if (size <= 0) return 0;

        double highest = temps[0];
        double lowest = temps[0];

        for (int i = 1; i < size; i++)
        {
            if (temps[i] > highest)
                highest = temps[i];

            if (temps[i] < lowest)
                lowest = temps[i];
        }

        return highest - lowest;
    }
};

int main()
{
	int size = 5, i;
    double temperatures[size];
    double avg;
    double fluctuation;
    ExtendedWeather ew;

	for(i = 0; i<size; i++){
		cout << "Temperature at Day " << i << ": " << endl;
		cin >> temperatures[i];
		cin.ignore();
	}
	
    avg = WeatherStats::calculateAverageTemperature(temperatures, size);
    cout << "Average Temperature: " << avg << endl;
    
	fluctuation = ew.getTemperatureFluctuation(temperatures, size);
    cout << "Temperature Fluctuation: " << fluctuation << endl;

    return 0;
}
