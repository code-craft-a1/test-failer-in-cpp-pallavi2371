#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{
    // Interface representing a generic weather sensor
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
            virtual ~IWeatherSensor() = default; // Virtual destructor
    };

    // Stub sensor class for testing weather reports
    class SensorStub : public IWeatherSensor {
        private:
            double temperature;
            int precipitation;
            int humidity;
            int windSpeed;

        public:
            // Constructor to set initial conditions
            SensorStub(double temp, int precip, int hum, int wind)
                : temperature(temp), precipitation(precip), humidity(hum), windSpeed(wind) {}

            // Override methods to return preset values
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

    // Generate a weather report based on sensor readings
    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        int windSpeed = sensor.WindSpeedKMPH();
        double temperature = sensor.TemperatureInC();

        // Default report
        string report = "Sunny Day";

        // Determine actual weather based on readings
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

    // Test case for stormy condition
    void TestRainy()
    {
        SensorStub sensor(26, 70, 72, 52); // High temp, high precipitation, high wind
        string report = Report(sensor);
        cout << "TestRainy Report: " << report << endl;
        assert(report.find("rain") != string::npos);
    }

    // Test case for heavy rain with calm winds
    void TestHighPrecipitation()
    {
        SensorStub sensor(26, 70, 72, 40); // High precipitation, low wind
        string report = Report(sensor);
        cout << "TestHighPrecipitation Report: " << report << endl;
        assert(!report.empty());
        assert(report.find("Heavy Rain") != string::npos);
    }
}

// Run all weather-related tests
void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}

