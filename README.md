# DHT11 Sensor Library for ESP32

This C library simplifies interfacing with the DHT11 temperature and humidity sensor on ESP32 microcontrollers.
Usage

Include esp32-dht11.h in your ESP32 project. Configure the GPIO pin for the DHT11 sensor before using the library functions.
## Dependencies
```
    driver/gpio.h
    stdio.h
    string.h
    esp_log.h
```
## API Reference
``` int wait_for_state(dht11_t dht11, int state, int timeout) ```
Waits on the specified GPIO pin until it reaches the specified state. Returns the time waited or -1 for a timeout.
``` void hold_low(dht11_t dht11, int hold_time_us) ```
Holds the GPIO pin low for the specified duration.
```int dht11_read(dht11_t *dht11, int connection_timeout)```
Reads temperature and humidity values from the DHT11 sensor. This blocking function forces the CPU to wait for the necessary duration.
## Example use
```
#include "esp32-dht11.h"
#define CONFIG_DHT11_PIN GPIO_NUM_4
#define CONFIG_CONNECTION_TIMEOUT 5

void app_main() {
    dht11_t dht11_sensor;
    dht11_sensor.dht11_pin = CONFIG_DHT11_PIN;

    // Read data
    while(1)
    {
      if(!dht11_read(&dht11_sensor, CONFIG_CONNECTION_TIMEOUT))
      {  
        printf("[Temperature]> %.2f \n",dht11_sensor.temperature);
        printf("[Humidity]> %.2f \n",dht11_sensor.humidity);
      }
      vTaskDelay(2000/portTICK_PERIOD_MS);
    } 
}
```
