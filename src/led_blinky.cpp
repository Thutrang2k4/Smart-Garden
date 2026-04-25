#include "led_blinky.h"

void led_blinky(void *pvParameters){
  pinMode(LED_GPIO, OUTPUT);
  
  int current_blinking_interval = 1000U;
  while(1) {
    if(xSemaphoreTake(xMutexBlinkingInterval, (TickType_t)10) == pdTRUE) 
    {
        // ----- (CRITICAL SECTION) -----
        current_blinking_interval = blinkingInterval;
        // return the mutex after updating the state
        xSemaphoreGive(xMutexBlinkingInterval); 
        // ------------------------------------------------
    } 
    else 
    {
        Serial.println("⚠️ ERROR: cannot get Mutex, skip reading blinking interval!");
    }

<<<<<<< HEAD
    // ------------------------------------------------
    // 2. Tìm kiếm Interval tương ứng với mảng cấu hình do User thiết lập
    // ------------------------------------------------
    if(xSemaphoreTake(xMutexLedStates, (TickType_t)10) == pdTRUE) {
        if (numLedStates > 0) {
            bool found = false;
            // Duyệt qua danh sách ngưỡng (Giả sử User/JS đã sắp xếp tăng dần)
            for (int i = 0; i < numLedStates; i++) {
                if (local_temp < ledStates[i].tempThreshold) {
                    current_blinking_interval = ledStates[i].interval;
                    found = true;
                    break;
                }
            }
            // Nếu nhiệt độ cao hơn tất cả các ngưỡng, dùng state cuối cùng
            if (!found) {
                current_blinking_interval = ledStates[numLedStates - 1].interval;
            }
        }
        xSemaphoreGive(xMutexLedStates); 
    }

    // ------------------------------------------------
    // 3. THỰC THI NHẤP NHÁY
    // ------------------------------------------------
    digitalWrite(LED_GPIO, HIGH);  
    vTaskDelay(pdMS_TO_TICKS(current_blinking_interval));
    digitalWrite(LED_GPIO, LOW);  
    vTaskDelay(pdMS_TO_TICKS(current_blinking_interval));
=======
    digitalWrite(LED_GPIO, HIGH);  // turn the LED ON
    vTaskDelay(current_blinking_interval);
    digitalWrite(LED_GPIO, LOW);  // turn the LED OFF
    vTaskDelay(current_blinking_interval);
>>>>>>> parent of 58c4e31 (Update threshold as well as states of the blinky led task)
  }
}