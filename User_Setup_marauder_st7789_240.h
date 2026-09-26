//                            USER DEFINED SETTINGS
//   Set driver type, fonts to be loaded, pins used and SPI control method etc
//
//   ESP32 Marauder - ST7789 1.54" 240x240 replacement display (NodeMCU-32 / AI-Thinker)
//   Based on User_Setup_og_marauder.h, adapted for a 240x240 ST7789 panel instead of
//   the stock 240x320 ILI9341 panel. Pin numbers are unchanged - they already match
//   the wiring used on the original hardware.


// ##################################################################################
//
// Section 1. Call up the right driver file and any options for it
//
// ##################################################################################

// Only define one driver, the other ones must be commented out
//#define ILI9341_DRIVER // OG Marauder (240 x 320) - NOT used, wrong panel for this build
#define ST7789_DRIVER      // 1.54" 240x240 ST7789 replacement panel

// Some displays support SPI reads via the MISO pin, other displays have a single
// bi-directional SDA pin and the library will try to read this via the MOSI line.
// To use the SDA line for reading data from the TFT uncomment the following line:

// #define TFT_SDA_READ      // This option is for ESP32 ONLY, tested with ST7789 display only

// For ST7789 ONLY, define the colour order IF the blue and red are swapped on your display.
// Most cheap "1.54TFT-SPI-ST7789 Ver:1.1" boards need BGR. If colours look swapped
// (skin tones blue, sky red, etc.) after flashing, switch to the other line.
//  #define TFT_RGB_ORDER TFT_RGB  // Colour order Red-Green-Blue
  #define TFT_RGB_ORDER TFT_BGR  // Colour order Blue-Green-Red (typical for these modules)

// For M5Stack ESP32 module with integrated ILI9341 display ONLY, remove // in line below

// #define M5STACK

// For ST7789, ST7735 and ILI9163 ONLY, define the pixel width and height in portrait orientation
// #define TFT_WIDTH  80
// #define TFT_WIDTH  128
  #define TFT_WIDTH  240 // 1.54" ST7789, 240 x 240
// #define TFT_HEIGHT 160
// #define TFT_HEIGHT 128
  #define TFT_HEIGHT 240 // 1.54" ST7789, 240 x 240 (was 320 for the stock ILI9341 panel)

// Some 240x240 ST7789 modules (this "Ver:1.1" board included) have GRAM that is
// physically 240x320 with the visible 240x240 area offset - if the image is shifted/cut
// off after flashing, uncomment the line below and let the library add the offset
// automatically based on TFT_WIDTH/TFT_HEIGHT:
// #define CGRAM_OFFSET

// If colours are inverted (white shows as black) then uncomment one of the next
// 2 lines, try both options - one of them should correct the inversion. This is a
// very common requirement on 1.54" ST7789 240x240 panels.
  #define TFT_INVERSION_ON
// #define TFT_INVERSION_OFF

// If a backlight control signal is available then define the TFT_BL pin in Section 2
// below. The backlight will be turned ON when tft.begin() is called, but the library
// needs to know if the LEDs are ON with the pin HIGH or LOW.

#define TFT_BACKLIGHT_ON HIGH  // HIGH or LOW are options

// ##################################################################################
//
// Section 2. Define the pins that are used to interface with the display here
//
// ##################################################################################

// ###### ESP32 (NodeMCU-32 / AI-Thinker) pin mapping - matches user wiring ######
//
// Display VCC  -> 3V3
// Display GND  -> GND
// Display SCL/CLK  -> GPIO18 (TFT_SCLK)
// Display SDA/MOSI -> GPIO23 (TFT_MOSI)
// Display RST  -> GPIO5  (TFT_RST)
// Display DC   -> GPIO16 (TFT_DC)
// Display CS   -> GPIO17 (TFT_CS)
// Display BLK  -> GPIO32 (TFT_BL)

//#define TFT_MISO 19  // Not connected - this ST7789 panel has no SDO/MISO line
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   17  // Chip select control pin
#define TFT_DC   16  // Data Command control pin
#define TFT_RST   5  // Reset pin
//#define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST

#define TFT_BL   32  // LED back-light (ST7789 backlight control pin)

//#define TOUCH_CS 21     // No touch controller on this panel


// ##################################################################################
//
// Section 3. Define the fonts that are to be used here
//
// ##################################################################################

#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define SMOOTH_FONT


// ##################################################################################
//
// Section 4. Other options
//
// ##################################################################################

// #define SPI_FREQUENCY   1000000
//#define SPI_FREQUENCY   5000000
// #define SPI_FREQUENCY  10000000
// #define SPI_FREQUENCY  20000000
#define SPI_FREQUENCY  27000000 // Marauder default // Actually sets it to 26.67MHz = 80/3
// #define SPI_FREQUENCY  40000000
// #define SPI_FREQUENCY  80000000

// Optional reduced SPI frequency for reading TFT
#define SPI_READ_FREQUENCY  20000000

// The XPT2046 requires a lower SPI clock rate of 2.5MHz so we define that here:
#define SPI_TOUCH_FREQUENCY  2500000

// The ESP32 has 2 free SPI ports i.e. VSPI and HSPI, the VSPI is the default.
//#define USE_HSPI_PORT

// #define SUPPORT_TRANSACTIONS
