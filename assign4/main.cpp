/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.
  // min max返回指向最小/最大元素的迭代器
  double min = *(std::min_element(dailyWeather.begin(), dailyWeather.end()));
  double average =
//静态转换类型！
      std::accumulate(dailyWeather.begin(), dailyWeather.end(), static_cast<double>(0)) /
      static_cast<double>(dailyWeather.size());
  double max = *(std::max_element(dailyWeather.begin(), dailyWeather.end()));
  Forecast res = Forecast{min, max, average};
  return res;
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData which contains
   * std::vector<double> which contain values for the weather on that day.
   */
  std::vector<Forecast> result(weatherData.size());
  // gpt说:std::back_inserter(result),
  // std::back_inserter会自动在result的末尾添加新元素，因此不需要预先知道或设置result的大小。
  std::transform(weatherData.begin(), weatherData.end(), result.begin(), compute_forecast);
  return result;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with specific weather.
  std::vector<Forecast> res(forecastData.size());
  std::copy(forecastData.begin(), forecastData.end(), res.begin());
  res.erase(std::remove_if(res.begin(), res.end(),
                           [](Forecast x) {
                             return (x.max_temp - x.min_temp) <= kMaxTempRequirement ||
                                    x.avg_temp < uAvgTempRequirement;
                           }),
            res.end());
  return res;
}

std::vector<Forecast> get_shuffled_data(std::vector<Forecast>& forecastData) {
  // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the data!
  std::vector<Forecast> res(forecastData.size());
  std::copy(forecastData.begin(), forecastData.end(), res.begin());
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(res.begin(), res.end(), g);
  return res;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!
  std::vector<Forecast> res = get_forecasts(weatherData);
  res=get_filtered_data(res);
  res=get_shuffled_data(res);
  return res;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"