
/* Define Tick Data Type */
typedef uint64_t tick_t;

// Fclk = 204 MHz ==> 4.9019607843137254901960784313725 ns
#define INACCURATE_TO_MS       20400   // Number of cycles for 1 ms
#define INACCURATE_TO_US_x10   204     // Number of cycles for 10 ns
#define INACCURATE_MIN_NS      4.901960849761962890625f

/* Define Boolean Data Type */
typedef uint8_t bool_t;

/* Functional states */
#ifndef ON
#define ON     1
#endif
#ifndef OFF
#define OFF    0
#endif

/* Electrical states */
#ifndef HIGH
#define HIGH   1
#endif
#ifndef LOW
#define LOW    0
#endif

/* Logical states */

#ifndef FALSE
#define FALSE  0
#endif
#ifndef TRUE
#define TRUE   (!FALSE)
#endif

typedef enum {

   // Configure GPIO pins for each board

      VCC = -2, GND = -1,
      // P1 header
      T_FIL1,    T_COL2,    T_COL0,    T_FIL2,      T_FIL3,  T_FIL0,     T_COL1,
      CAN_TD,    CAN_RD,    RS232_TXD, RS232_RXD,
      // P2 header
      GPIO8,     GPIO7,     GPIO5,     GPIO3,       GPIO1,
      LCD1,      LCD2,      LCD3,      LCDRS,       LCD4,
      SPI_MISO,
      ENET_TXD1, ENET_TXD0, ENET_MDIO, ENET_CRS_DV, ENET_MDC, ENET_TXEN, ENET_RXD1,
      GPIO6,     GPIO4,     GPIO2,     GPIO0,
      LCDEN,
      SPI_MOSI,
      ENET_RXD0,
      // Switches
      // 36   37     38     39
      TEC1,  TEC2,  TEC3,  TEC4,
      // Leds
      // 40   41     42     43     44     45
      LEDR,  LEDG,  LEDB,  LED1,  LED2,  LED3,
      //#error EDU-CIAA-NXP
} gpioMap_t;


typedef enum {
   GPIO_INPUT, GPIO_OUTPUT,
   GPIO_INPUT_PULLUP, GPIO_INPUT_PULLDOWN,
   GPIO_INPUT_PULLUP_PULLDOWN,
   GPIO_ENABLE
} gpioInit_t;

/* ---- Inaccurate Delay ---- */
void delayInaccurateMs( tick_t delay_ms );
void delayInaccurateUs( tick_t delay_us );
void delayInaccurateNs( tick_t delay_ns ); // Resolution ~5 ns

/* ---- Blocking Delay ---- */
void delay( tick_t duration_ms );

/* ---- Non Blocking Delay ---- */
//void delayInit( delay_t * delay, tick_t duration );
//bool_t delayRead( delay_t * delay );
//void delayWrite( delay_t * delay, tick_t duration );
bool_t gpioConfig( gpioMap_t pin, gpioInit_t config );
bool_t gpioRead( gpioMap_t pin );
bool_t gpioWrite( gpioMap_t pin, bool_t value );



