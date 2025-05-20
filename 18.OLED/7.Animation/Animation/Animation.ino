#include<Wire.h>
#include<Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 oled(128, 64, &Wire, -1);

// Define tImage structure
typedef struct {
    const uint8_t* imageData;  // Pointer to image data
    uint16_t width;            // Image width
    uint16_t height;           // Image height
} tImage;
#include "frames.h"

// Include the generated frames_array.h header file
#include "frames_array.h"  

// Total number of frames
const int total_frames = sizeof(frames) / sizeof(frames[0]);

// Function to render a frame
void renderFrame(const tImage* frame) 
{
    // Use the OLED display function to render the current frame
    oled.drawBitmap(0, 0, frame->imageData, frame->width, frame->height, WHITE);
}

void setup() 
{
    Serial.begin(9600);
    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    {
      Serial.println(F("failed to start SSD1306 OLED"));
      while (1);
    }
    delay(2000); // wait two seconds for initializing
    oled.setCursor(0, 0);
}

void loop() {
    for (int i = 0; i < total_frames; i++) {
        renderFrame(frames[i]); // Render the current frame

        delay(100); // Delay for animation (adjust as needed)
    }
}
