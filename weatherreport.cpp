#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
            virtual ~IWeatherSensor() = default; // Virtual destructor
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class SensorStub : public IWeatherSensor {
        private:
            double temperature;
            int precipitation;
            int humidity;
            int windSpeed;

        public:
            SensorStub(double temp, int precip, int hum, int wind)
                : temperature(temp), precipitation(precip), humidity(hum), windSpeed(wind) {}

            double TemperatureInC() const override {
                return temperature;
            }

            int Precipitation() const override {
                return precipitation;
            }

            int Humidity() const override {
                return humidity;
            }

            int WindSpeedKMPH() const override {
                return windSpeed;
            }
    };

    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        int windSpeed = sensor.WindSpeedKMPH();
        double temperature = sensor.TemperatureInC();

        string report = "Sunny Day";

        if (temperature > 25) {
            if (precipitation >= 20 && precipitation < 60) {
                report = "Partly Cloudy";
            } else if (precipitation >= 60 && windSpeed < 50) {
                report = "Heavy Rain";
            } else if (precipitation >= 60 && windSpeed >= 50) {
                report = "Alert, Stormy with heavy rain";
            }
        }
        return report;
    }

    void TestRainy()
    {
        SensorStub sensor(26, 70, 72, 52);
        string report = Report(sensor);
        cout << "TestRainy Report: " << report << endl;
        assert(report.find("rain") != string::npos); // Ensure "rain" is in the report
    }

    void TestHighPrecipitation()
    {
        SensorStub sensor(26, 70, 72, 40);
        string report = Report(sensor);
        cout << "TestHighPrecipitation Report: " << report << endl;
        assert(report.length() > 0); // Ensure the report is not empty
        assert(report.find("Heavy Rain") != string::npos); // Ensure "Heavy Rain" is in the report
    }
}

void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}
