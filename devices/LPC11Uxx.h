#ifndef DEVICE_LPC11UXX_H
#define DEVICE_LPC11UXX_H
/**
 * NXP LPC11Uxx
 *
 * \author Andy Gock
 **/

#if defined(GLCD_DEVICE_LPC11UXX)

#define swap(a, b) { uint8_t t = a; a = b; b = t; }

#if !defined(GLCD_USE_PARALLEL)
	/* SPI interface */

	/* Define port and pins used to connecto LCD */
	#define CONTROLLER_SPI_PORT_NUMBER 1
	#define CONTROLLER_MOSI_PORT LPC_GPIO2
	#define CONTROLLER_MOSI_PIN  3
	#define CONTROLLER_MISO_PORT LPC_GPIO2
	#define CONTROLLER_MISO_PIN  2
	#define CONTROLLER_SCK_PORT  LPC_GPIO2
	#define CONTROLLER_SCK_PIN   1
	#define CONTROLLER_SS_PORT   LPC_GPIO2
	#define CONTROLLER_SS_PIN    0
	#define CONTROLLER_DC_PORT   LPC_GPIO2
	#define CONTROLLER_DC_PIN    4
	#define CONTROLLER_RST_PORT  LPC_GPIO2
	#define CONTROLLER_RST_PIN   5

	/* Preprocessor macros */
	#define GLCD_SELECT()     CONTROLLER_SS_PORT->DATA  &= ~(1 << CONTROLLER_SS_PIN)
	#define GLCD_DESELECT()   CONTROLLER_SS_PORT->DATA  |=  (1 << CONTROLLER_SS_PIN)
	#define GLCD_DC_LOW()     CONTROLLER_DC_PORT->DATA  &= ~(1 << CONTROLLER_DC_PIN)
	#define GLCD_DC_HIGH()    CONTROLLER_DC_PORT->DATA  |=  (1 << CONTROLLER_DC_PIN)
	#define GLCD_RESET_LOW()  CONTROLLER_RST_PORT->DATA &= ~(1 << CONTROLLER_RST_PIN)
	#define GLCD_RESET_HIGH() CONTROLLER_RST_PORT->DATA |=  (1 << CONTROLLER_RST_PIN)

#else
	/* Parallel interface */
	
	#define CONTROLLER_LCD_EN_PORT 0
	#define CONTROLLER_LCD_EN_PIN  12 /**< Read write enable pin */
	#define CONTROLLER_LCD_RW_PORT 0
	#define CONTROLLER_LCD_RW_PIN  13 /**< Read write signal pin */
	#define CONTROLLER_LCD_RS_PORT 0
	#define CONTROLLER_LCD_RS_PIN  14 /**< Command data select pin */
	#define CONTROLLER_LCD_CS_PORT 1
	#define CONTROLLER_LCD_CS_PIN  13 /**< Chip select pin */

	#define CONTROLLER_LCD_D0_PORT  1
	#define CONTROLLER_LCD_D1_PORT  1
	#define CONTROLLER_LCD_D2_PORT  1
	#define CONTROLLER_LCD_D3_PORT  1
	#define CONTROLLER_LCD_D4_PORT  1
	#define CONTROLLER_LCD_D5_PORT  1
	#define CONTROLLER_LCD_D6_PORT  1
	#define CONTROLLER_LCD_D7_PORT  1

	#define CONTROLLER_LCD_D0_PIN  19
	#define CONTROLLER_LCD_D1_PIN  20
	#define CONTROLLER_LCD_D2_PIN  21
	#define CONTROLLER_LCD_D3_PIN  22
	#define CONTROLLER_LCD_D4_PIN  26
	#define CONTROLLER_LCD_D5_PIN  27
	#define CONTROLLER_LCD_D6_PIN  28
	#define CONTROLLER_LCD_D7_PIN  31

#if (CONTROLLER_LCD_D1_PORT == CONTROLLER_LCD_D0_PORT) && \
    (CONTROLLER_LCD_D2_PORT == CONTROLLER_LCD_D0_PORT) && \
    (CONTROLLER_LCD_D3_PORT == CONTROLLER_LCD_D0_PORT) && \
    (CONTROLLER_LCD_D4_PORT == CONTROLLER_LCD_D0_PORT) && \
    (CONTROLLER_LCD_D5_PORT == CONTROLLER_LCD_D0_PORT) && \
    (CONTROLLER_LCD_D6_PORT == CONTROLLER_LCD_D0_PORT) && \
    (CONTROLLER_LCD_D7_PORT == CONTROLLER_LCD_D0_PORT)
	/* All data pins are on the same port */	
	#define CONTROLLER_LCD_DATA_PORT 1

	#define GLCD_PARALLEL_MASK (   \
		(1U<<CONTROLLER_LCD_D0_PIN)| \
		(1U<<CONTROLLER_LCD_D1_PIN)| \
		(1U<<CONTROLLER_LCD_D2_PIN)| \
		(1U<<CONTROLLER_LCD_D3_PIN)| \
		(1U<<CONTROLLER_LCD_D4_PIN)| \
		(1U<<CONTROLLER_LCD_D5_PIN)| \
		(1U<<CONTROLLER_LCD_D6_PIN)| \
		(1U<<CONTROLLER_LCD_D7_PIN)  \
	)

	#define GLCD_EN_LOW()      LPC_GPIO->CLR[CONTROLLER_LCD_EN_PORT] |= (1U<<CONTROLLER_LCD_EN_PIN);
	#define GLCD_EN_HIGH()     LPC_GPIO->SET[CONTROLLER_LCD_EN_PORT] |= (1U<<CONTROLLER_LCD_EN_PIN);
	#define GLCD_RW_LOW()      LPC_GPIO->CLR[CONTROLLER_LCD_RW_PORT] |= (1U<<CONTROLLER_LCD_RW_PIN);
	#define GLCD_RW_HIGH()     LPC_GPIO->SET[CONTROLLER_LCD_RW_PORT] |= (1U<<CONTROLLER_LCD_RW_PIN);
	#define GLCD_RS_LOW()      LPC_GPIO->CLR[CONTROLLER_LCD_RS_PORT] |= (1U<<CONTROLLER_LCD_RS_PIN);
	#define GLCD_RS_HIGH()     LPC_GPIO->SET[CONTROLLER_LCD_RS_PORT] |= (1U<<CONTROLLER_LCD_RS_PIN);
	#define GLCD_CS_LOW()      LPC_GPIO->CLR[CONTROLLER_LCD_CS_PORT] |= (1U<<CONTROLLER_LCD_CS_PIN);
	#define GLCD_CS_HIGH()     LPC_GPIO->SET[CONTROLLER_LCD_CS_PORT] |= (1U<<CONTROLLER_LCD_CS_PIN);
	
#else /* All parallel data pins on same port */
	#undef CONTROLLER_LCD_DATA_PORT
#endif 

#endif /* not use GLCD_USE_SPI */

#endif /* GLCD_DEVICE_LPC11UXX */

#endif /* DEVICE_LPC11UXX_H */
