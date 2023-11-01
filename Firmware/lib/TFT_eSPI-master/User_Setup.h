#define ST7789_DRIVER
#define TFT_SDA_READ   // Display has a bidirectionsl SDA pin

#define TFT_WIDTH  240
#define TFT_HEIGHT 280

#define CGRAM_OFFSET      // Library will add offsets required

#define TFT_RGB_ORDER TFT_RGB

#define TFT_MOSI 17
#define TFT_SCLK 16
#define TFT_CS   27  // Chip select control pin
#define TFT_DC    26  // Data Command control pin
#define TFT_RST   13  // Reset pin (could connect to RST pin)

//#define TFT_BL          4  // Display backlight control pin

//#define TFT_BACKLIGHT_ON HIGH  // HIGH or LOW are options

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT

//#define SPI_FREQUENCY  27000000
  #define SPI_FREQUENCY  40000000   // Maximum for ILI9341


#define SPI_READ_FREQUENCY  6000000 // 6 MHz is the maximum SPI read speed for the ST7789V
