#include<Wire.h>
#include<Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "frames.h"

#define SCR_WIDTH 128
#define SCR_HEIGHT 64

#define TOTAL_FRAMES 159

Adafruit_SSD1306 oled(SCR_WIDTH, SCR_HEIGHT, &Wire, -1);

const uint8_t* frames[TOTAL_FRAMES] = {'frame0', 'frame1', 'frame2', 'frame3', 'frame4', 'frame5', 'frame6', 'frame7', 'frame8', 'frame9', 'frame10', 'frame11', 'frame12', 'frame13', 'frame14', 'frame15', 'frame16', 'frame17', 'frame18', 'frame19', 'frame20', 'frame21', 'frame22', 'frame23', 'frame24', 'frame25', 'frame26', 'frame27', 'frame28', 'frame29', 'frame30', 'frame31', 'frame32', 'frame33', 'frame34', 'frame35', 'frame36', 'frame37', 'frame38', 'frame39', 'frame40', 'frame41', 'frame42', 'frame43', 'frame44', 'frame45', 'frame46', 'frame47', 'frame48', 'frame49', 'frame50', 'frame51', 'frame52', 'frame53', 'frame54', 'frame55', 'frame56', 'frame57', 'frame58', 'frame59', 'frame60', 'frame61', 'frame62', 'frame63', 'frame64', 'frame65', 'frame66', 'frame67', 'frame68', 'frame69', 'frame70', 'frame71', 'frame72', 'frame73', 'frame74', 'frame75', 'frame76', 'frame77', 'frame78', 'frame79', 'frame80', 'frame81', 'frame82', 'frame83', 'frame84', 'frame85', 'frame86', 'frame87', 'frame88', 'frame89', 'frame90', 'frame91', 'frame92', 'frame93', 'frame94', 'frame95', 'frame96', 'frame97', 'frame98', 'frame99', 'frame100', 'frame101', 'frame102', 'frame103', 'frame104', 'frame105', 'frame106', 'frame107', 'frame108', 'frame109', 'frame110', 'frame111', 'frame112', 'frame113', 'frame114', 'frame115', 'frame116', 'frame117', 'frame118', 'frame119', 'frame120', 'frame121', 'frame122', 'frame123', 'frame124', 'frame125', 'frame126', 'frame127', 'frame128', 'frame129', 'frame130', 'frame131', 'frame132', 'frame133', 'frame134', 'frame135', 'frame136', 'frame137', 'frame138', 'frame139', 'frame140', 'frame141', 'frame142', 'frame143', 'frame144', 'frame145', 'frame146', 'frame147', 'frame148', 'frame149', 'frame150', 'frame151', 'frame152', 'frame153', 'frame154', 'frame155', 'frame156', 'frame157', 'frame158'};

// Function to render a frame
void renderFrame(const uint8_t* imageData) 
{
    // Use the OLED display function to render the current frame
    oled.drawBitmap(0, 0, imageData, SCR_WIDTH, SCR_HEIGHT, WHITE);
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
    for (int i = 0; i < TOTAL_FRAMES; i++) {
        renderFrame(frames[i]); // Render the current frame

        delay(100); // Delay for animation (adjust as needed)
    }
}
