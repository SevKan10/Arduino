#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST); // Cho chuẩn màn hình I2C
//U8GLIB_SSD1306_128X64 u8g(13, 11, 8, 9, 10);   // SPI communication: SCL,D0 = 13, SDA,D1 = 11, RES = 10, DC = 9, CS = 8, Cho chuẩn màn hình SPI

int potentiometer_value = 0; // value from the potentiometer
char buffer[20];       // helper buffer for converting values into C-style string (array of chars)
int string_width;      // helper value for string widths

float pixel_x = 0;     // x pos for pixel
float pixel_y = 0;     // y pos for pixel
float line_x = 0;      // x pos for line end
float line_y = 0;      // y pos for line end
float text_x = 0;      // x pos for text
float text_y = 0;      // y pos for text

int center_x = 64;     // x center of the knob 
int center_y = 108;    // y center of the knob (outside of the screen)
int radius_pixel = 92; // radius for pixel tickmarks
int radius_line = 87;  // radius for line end
int radius_text = 75;  // radius for text

int angle;             // angle for the individual tickmarks
int tick_value;        // numeric value for the individual tickmarks

byte precalculated_x_radius_pixel[180]; // lookup table to prevent expensive sin/cos calculations
byte precalculated_y_radius_pixel[180]; // lookup table to prevent expensive sin/cos calculations

unsigned long millis_time;       // fps
unsigned long millis_time_last;  // fps
int fps;                         // actual FPS value


const uint8_t upir_logo[] U8G_PROGMEM = {
B00010101, B11010111,     //  ░░░█░█░███░█░███
B00010101, B01000101,     //  ░░░█░█░█░█░░░█░█
B00010101, B10010110,     //  ░░░█░█░██░░█░██░
B00011001, B00010101      //  ░░░██░░█░░░█░█░█
};


void setup() {
  
  u8g.setColorIndex(1);          // set color to white

  for (int i = 0; i < 180; i++) {    // pre-calculate x and y positions into the look-up tables
     precalculated_x_radius_pixel[i] =  sin(radians(i-90)) * radius_pixel + center_x; 
     precalculated_y_radius_pixel[i] = -cos(radians(i-90)) * radius_pixel + center_y;      
  }
}

void loop() {
  u8g.firstPage();                // required for u8g library
  do {                            //  --//--


    u8g.setColorIndex(1);          // set color to white
    u8g.setFont(u8g_font_6x10r);   // set smaller font for tickmarks   
 
    // calculate tickmarks
    for (int i=-48; i<=48; i=i+3) {                                // only try to calculate tickmarks that would end up be displayed
      angle = i + ((potentiometer_value*3)/10) % 3;                // final angle for the tickmark
      tick_value = round((potentiometer_value/10.0) + angle/3.0);  // get number value for each tickmark

      //pixel_x =  sin(radians(angle)) * radius_pixel + center_x;    // calculate the tickmark pixel x value
      //pixel_y = -cos(radians(angle)) * radius_pixel + center_y;    // calculate the tickmark pixel y value
      pixel_x = precalculated_x_radius_pixel[angle+90];              // get x value from lookup table
      pixel_y = precalculated_y_radius_pixel[angle+90];              // get y value from lookup table

      if (pixel_x > 0 && pixel_x < 128 && pixel_y > 0 && pixel_y < 64) {  // only draw inside of the screen

        if(tick_value >= 0 && tick_value <= 180) {  // only draw tickmarks between values 0-100%, could be removed when using rotary controller

          if (tick_value % 10 == 0) {                                // draw big tickmark == lines + text
            line_x =  sin(radians(angle)) * radius_line + center_x;  // calculate x pos for the line end
            line_y = -cos(radians(angle)) * radius_line + center_y;  // calculate y pos for the line end
            u8g.drawLine(pixel_x, pixel_y, line_x, line_y);          // draw the line

            text_x =  sin(radians(angle)) * radius_text + center_x;  // calculate x pos for the text
            text_y = -cos(radians(angle)) * radius_text + center_y;  // calculate y pos for the text 
            itoa(tick_value, buffer, 10);                            // convert integer to string
            string_width = u8g.getStrWidth(buffer);                  // get string width
            u8g.drawStr(text_x - string_width/2, text_y, buffer);    // draw text - tickmark value
            
          } 
          else {                                                     // draw small tickmark == pixel tickmark
            u8g.drawPixel(pixel_x, pixel_y);                         // draw a single pixel

          }      
  
        }
      }
    }

    // draw the big value on top
    u8g.setFont(u8g_font_8x13r);                      // set bigger font
    dtostrf(potentiometer_value/10.0, 1, 1, buffer);  // float to string, -- value, min. width, digits after decimal, buffer to store
    sprintf(buffer, "%s%s", buffer, " Angel");             // add some random ending character

    string_width = u8g.getStrWidth(buffer);           // calculate string width

    u8g.setColorIndex(1);                             // set color to white
    u8g.drawRBox(64-(string_width+4)/2, 0, string_width+4, 11, 2);  // draw background rounded rectangle
    u8g.drawTriangle( 64-3, 11,   64+4, 11,   64, 15);              // draw small arrow below the rectangle
    u8g.setColorIndex(0);                                           // set color to black 
    u8g.drawStr(64-string_width/2, 10, buffer);                     // draw the value on top of the display

    // draw upir logo
    u8g.setColorIndex(1);
    u8g.drawBitmapP(112, 0, 2, 4, upir_logo);  

    // display FPS, could be commented out for the final product
    //u8g.setColorIndex(1);                                           // set color to white   
    //u8g.setFont(u8g_font_5x7r);                                     // set very small font
    //itoa(fps, buffer, 10);                                          // convert FPS number to string
    //u8g.drawStr(0,10,buffer);                                       // draw the FPS number


  } while ( u8g.nextPage() );    // required for u8g library


  potentiometer_value = map(analogRead(A0), 0, 1023, 0, 1800); 

  millis_time_last = millis_time;                                  // store last millisecond value
  millis_time = millis();                                          // get millisecond value from the start of the program
  fps = round(1000.0/ (millis_time*1.0-millis_time_last));         // calculate FPS (frames per second) value


}