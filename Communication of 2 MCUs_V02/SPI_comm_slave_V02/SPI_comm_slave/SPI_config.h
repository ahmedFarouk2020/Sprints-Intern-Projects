/*
 * SPI_config.h
 *
 * Created: 9/23/2021 1:31:17 PM
 *  Author: Farouk
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* SPI PINS */
#define MOSI	GPIOB,PIN5
#define MISO	GPIOB,PIN6
#define SS		GPIOB,PIN4
#define CLK		GPIOB,PIN7

/* SPI Config (options in "SPI_interface" file) */
#define SPI_CLK				CLK_DIV128
#define SPI_MODE			MasterMode					// MASTER or SLAVE
#define INTERRUPT_STATE		SPI_InterruptDisable       //  INT_ENABLED or INT_DISABLED
#define BIT_ORDER			MSBFirst				  //   MSB_FIRST  or LSB_FIRST
#define DOUBLE_SPEED		DoubleSpeedDisable		 //    DS_ENABLED  or DS_DISABLED
#define SCK_MODE			SPI_Mode0


#endif /* SPI_CONFIG_H_ */