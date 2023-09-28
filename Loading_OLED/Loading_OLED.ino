#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop()
{
  // Un-comment below sketch for round edge rectangle loading animation.
 /* for (int i = 14; i <= 100; i++)
    { display.clearDisplay();
    display.drawRoundRect(12, 20, 104, 20, 10 , WHITE);
    display.fillRoundRect(14, 23, i, 14,10, WHITE);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(30, 50);
    display.print("Loading ");
    display.print(i);
    display.print("%");
    //Un-comment below line for invert the display.
    //display.invertDisplay(true);
    display.display();
    }*/

  // Un-comment below sketch for rectangle loading animation.

   /*for (int i = 14; i <= 100; i++)
    { display.clearDisplay();
     display.drawRect(12, 20, 104, 20, WHITE);
     display.fillRect(14, 23, i, 14, WHITE);
     display.setTextSize(1);
     display.setTextColor(WHITE);
     display.setCursor(30, 50);
     display.print("Loading ");
     display.print(i);
     display.print("%");
     //Un-comment below line for invert the display.
     //display.invertDisplay(true);
     display.display();
    }*/
  // Un-comment below sketch for thin round edge rectangle loading animation
 /* for (int i = 14; i <= 100; i++)
    { display.clearDisplay();
    display.drawRoundRect(12, 30, 104, 8, 10 , WHITE);
    display.fillRoundRect(14, 32, i, 4,10, WHITE);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(30, 50);
    display.print("Loading ");
    display.print(i);
    display.print("%");
    //Un-comment below line for invert the display.
    //display.invertDisplay(true);
    display.display();
    }*/
}