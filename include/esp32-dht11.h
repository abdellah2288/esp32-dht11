#ifndef _DHT_11
#define _DHT_11
#include <driver/gpio.h>
#include <stdio.h>
#include <string.h>
#include <rom/ets_sys.h>
#include "esp_log.h"
/**
 * Structure containing readings and info about the dht11
 * @var dht11_pin the pin associated with the dht11
 * @var temperature last temperature reading
 * @var humidity last humidity reading 
*/
typedef struct
{
    int dht11_pin;
    float temperature;
    float humidity;
} dht11_t;
/**
 * @brief Wait on pin until it reaches the specified state
 * @return returns either the time waited or -1 in the case of a timeout
 * @param state state to wait for
 * @param timeout if counter reaches timeout the function returns -1
*/
int wait_for_state(dht11_t dht11,int state,int timeout);
/**
 * @brief Holds the pin low fo the specified duration
 * @param hold_time_us time to hold the pin low for in microseconds
*/
void hold_low(dht11_t dht11,int hold_time_us);
/**
 * @brief The function for reading temperature and humidity values from the dht11
 * @note  This function is blocking, ie: it forces the cpu to busy wait for the duration necessary to finish comms with the sensor.
 * @note  Wait for atleast 2 seconds between reads 
 * @param connection_timeout the number of connection attempts before declaring a timeout
*/
int dht11_read(dht11_t *dht11,int connection_timeout);
#endif