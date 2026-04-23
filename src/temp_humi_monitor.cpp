#include "temp_humi_monitor.h"
DHT20 dht20;
LiquidCrystal_I2C lcd(33,16,2);


void temp_humi_monitor(void *pvParameters){

    Wire.begin(11, 12);
    Serial.begin(115200);
    dht20.begin();

    while (1){
        /* code */
        
        dht20.read();
        // Reading temperature in Celsius
        float temperature = dht20.getTemperature();
        // Reading humidity
        float humidity = dht20.getHumidity();

        

        // Check if any reads failed and exit early
        if (isnan(temperature) || isnan(humidity)) {
            Serial.println("Failed to read from DHT sensor!");
            temperature = humidity =  -1;
            //return;
        }

        //Update global variables for temperature and humidity
        glob_temperature = temperature;
        glob_humidity = humidity;

        // Print the results
        
<<<<<<< HEAD:src/task_temp_humi_monitor.cpp
        // Serial.print("Humidity: ");
        // Serial.print(humidity);
        // Serial.print("%  Temperature: ");
        // Serial.print(temperature);
        // Serial.println("°C");

        char tempBuf[32];
        sprintf(tempBuf, "Temperature: %.1f \xF7" "C", temperature);
        // Hiển thị nhiệt độ ở dòng thứ 3 (y=20), không làm mất dòng Wifi ở trên
        sendToOLED(0, 20, tempBuf);
        
<<<<<<< HEAD
        sprintf(tempBuf, "Humi:%.1f%%", humidity);
        sendToOLED(68, 20, tempBuf);
=======
        sprintf(tempBuf, "Humidity: %.1f %%  ", humidity);
        sendToOLED(0, 30, tempBuf);
>>>>>>> parent of 58c4e31 (Update threshold as well as states of the blinky led task)
=======
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print("%  Temperature: ");
        Serial.print(temperature);
        Serial.println("°C");
>>>>>>> parent of 0b8664e (Updated tinyML model and source codes for supporting reading soil moisture and display all of the necessary information onto the oled):src/temp_humi_monitor.cpp
        
<<<<<<< HEAD
        uint32_t current_sensor_interval = 1000;
        if (xSemaphoreTake(xMutexIntervals, (TickType_t)10) == pdTRUE) {
            current_sensor_interval = glob_sensor_interval;
            xSemaphoreGive(xMutexIntervals);
        } else {
            Serial.println("⚠️ ERROR: cannot get Mutex for Intervals, using default sensor interval!");
        }

        vTaskDelay(pdMS_TO_TICKS(current_sensor_interval));
=======
        vTaskDelay(5000);
>>>>>>> parent of 2d221ec (Add task for controlling user added relay and update web server for premitting user to add their wanted GPIO which will be controlled as a relay by user or the tinyML task)
    }
    
}