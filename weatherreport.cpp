#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace {

    // Interface for reading weather data
    class IWeatherSensor {
    public:
        virtual double TemperatureInC() const = 0;
        virtual int Precipitation() const = 0;
        virtual int Humidity() const = 0;
        virtual int WindSpeedKMPH() const = 0;
        virtual ~IWeatherSensor() = default;
    };

    // Stub for injecting test sensor data
    class SensorStub : public IWeatherSensor {
    private:
        double temperature;
        int precipitation;
        int humidity;
        int windSpeed;

    public:
        SensorStub(double temp, int precip, int hum, int wind)
            : temperature(temp), precipitation(precip), humidity(hum), windSpeed(wind) {}

        double TemperatureInC() const override { return temperature; }
        int Precipitation() const override { return precipitation; }
        int Humidity() const override { return humidity; }
        int WindSpeedKMPH() const override { return windSpeed; }
    };

    // Class responsible for generating weather reports
    class WeatherReporter {
    public:
        static string GenerateReport(const IWeatherSensor& sensor) {
            double temp = sensor.TemperatureInC();
            int precip = sensor.Precipitation();
            int wind = sensor.WindSpeedKMPH();

            if (temp > 25) {
                if (precip >= 60 && wind >= 50) return "Alert, Stormy with heavy rain";
                if (precip >= 60) return "Heavy Rain";
                if (precip >= 20) return "Partly Cloudy";
            }
            return "Sunny Day";
        }
    };

    // Simulate high wind and rain
    void TestRainy() {
        SensorStub sensor(26, 70, 72, 52);
        string report = WeatherReporter::GenerateReport(sensor);
        cout << "TestRainy Report: " << report << endl;
        assert(report.find("rain") != string::npos);
    }

    // Simulate heavy precipitation only
    void TestHighPrecipitation() {
        SensorStub sensor(26, 70, 72, 40);
        string report = WeatherReporter::GenerateReport(sensor);
        cout << "TestHighPrecipitation Report: " << report << endl;
        assert(!report.empty());
        assert(report.find("Heavy Rain") != string::npos);
    }
}

// Entry point to weather test cases
void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}

