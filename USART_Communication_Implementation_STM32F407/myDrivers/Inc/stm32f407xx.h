
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <string.h>
#include <stddef.h>


/*
 * Microprocessor Defines
 *
 */
#define NVIC_ISER0					((uint32_t*)(0xE000E100))


#define __IO volatile

#define SET_BIT(REG, BIT)			( (REG) |=  (BIT) ) //SET_BIT(RCC -> AHB1ENR, RCC_AHB1ENR_GPIOAEN);
#define CLEAR_BIT(REG, BIT)			( (REG) &= ~(BIT) )
#define READ_BIT(REG, BIT)			( (REG) &   (BIT) )
#define UNUSED(x)					(void)x  // Precaution for warning typedef enum

typedef enum
{
	DISABLE = 0x0U,
	ENABLE = !DISABLE

}FunctionalState_t;

/*
 * IRQ Number of MCU == Vector Table
 *
 */

typedef enum
{
	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	SPI1_IRQNumber = 35,
	USART2_IRQn = 38

}IRQNumber_TypeDef_t;


/*
 * Memory Base Address
 *
 */
#define FLASH_BASE_ADDR				(0x08000000UL) 						/* Flash Base Address(up to 1MB) */ //unsigned long or ((uint32_t)(0x08000000))
#define SRAM1_BASE_ADDR				(0x20000000UL) 						/* SRAM1 Base Address 112 KB     */
#define SRAM2_BASE_ADDR				(0x2001C000UL)						/* SRAM2 Base Address 16 KB      */

/*
 * Peripherals Base Addresses
 *
 */

#define PERIPH_BASE_ADDR			(0x40000000UL) 						/* Base Address for All peripherals	 */

#define APB1_BASE_ADDR				PERIPH_BASE_ADDR 					/* APB1 Bus Domain Base Address	  	 */
#define APB2_BASE_ADDR				(PERIPH_BASE_ADDR + 0x00010000UL) 	/* APB2 Bus Domain Base Address	  	 */
#define AHB1_BASE_ADDR				(PERIPH_BASE_ADDR + 0x00020000UL) 	/* AHB1 Bus Domain Base Address	  	 */
#define AHB2_BASE_ADDR				(PERIPH_BASE_ADDR + 0x10000000UL)	/* AHB2 Bus Domain Base Address	  	 */

/*
 * APB1 Peripherals Base Addresses
 *
 */

#define TIM2_BASE_ADDR				(APB1_BASE_ADDR + 0x0000UL)			/* Timer 2 Base Address */
#define TIM3_BASE_ADDR				(APB1_BASE_ADDR + 0x0400UL)			/* Timer 3 Base Address */
#define TIM4_BASE_ADDR				(APB1_BASE_ADDR + 0x0800UL)			/* Timer 4 Base Address */
#define TIM5_BASE_ADDR				(APB1_BASE_ADDR + 0x0C00UL)			/* Timer 5 Base Address */
#define TIM6_BASE_ADDR				(APB1_BASE_ADDR + 0x1000UL)			/* Timer 6 Base Address */
#define TIM7_BASE_ADDR				(APB1_BASE_ADDR + 0x1400UL)			/* Timer 7 Base Address */

#define SPI2_BASE_ADDR				(APB1_BASE_ADDR + 0x3800UL)			/* SPI 2 Base Address 	*/
#define SPI3_BASE_ADDR				(APB1_BASE_ADDR + 0x3C00UL)			/* SPI 3 Base Address 	*/

#define USART2_BASE_ADDR			(APB1_BASE_ADDR + 0x4400UL)			/* USART 2 Base Address */
#define USART3_BASE_ADDR			(APB1_BASE_ADDR + 0x4800UL)			/* USART 3 Base Address */
#define UART4_BASE_ADDR				(APB1_BASE_ADDR + 0x4C00UL)			/* UART 4 Base Address  */
#define UART5_BASE_ADDR				(APB1_BASE_ADDR + 0x5000UL)			/* UART 5 Base Address  */

#define I2C1_BASE_ADDR				(APB1_BASE_ADDR + 0x5400UL)			/* I2C 1 Base Address   */
#define I2C2_BASE_ADDR				(APB1_BASE_ADDR + 0x5800UL)			/* I2C 2 Base Address   */
#define I2C3_BASE_ADDR				(APB1_BASE_ADDR + 0x5C00UL)			/* I2C 3 Base Address   */

/*
 * APB2 Peripherals Base Addresses
 *
 */

#define TIM1_BASE_ADDR				(APB2_BASE_ADDR + 0x0000UL)			/* Timer 1 Base Address */
#define TIM8_BASE_ADDR				(APB2_BASE_ADDR + 0x0400UL)			/* Timer 8 Base Address */

#define USART1_BASE_ADDR			(APB2_BASE_ADDR + 0x1000UL)			/* USART 1 Base Address */
#define USART6_BASE_ADDR			(APB2_BASE_ADDR + 0x1400UL)			/* USART 6 Base Address */

#define SPI1_BASE_ADDR				(APB2_BASE_ADDR + 0x3000UL)			/* SPI 1 Base Address 	*/
#define SPI4_BASE_ADDR				(APB2_BASE_ADDR + 0x3400UL)			/* SPI 4 Base Address 	*/
#define SPI5_BASE_ADDR				(APB2_BASE_ADDR + 0x5000UL)			/* SPI 5 Base Address 	*/
#define SPI6_BASE_ADDR				(APB2_BASE_ADDR + 0x5400UL)			/* SPI 6 Base Address 	*/

#define SYSCFG_BASE_ADDR			(APB2_BASE_ADDR + 0x3800UL)			/* SYSCFG Base Address 	*/
#define EXTI_BASE_ADDR				(APB2_BASE_ADDR + 0x3C00UL)			/* EXTI Base Address 	*/

/*
 * AHB1 Peripherals Base Addresses
 *
 */

#define GPIOA_BASE_ADDR				(AHB1_BASE_ADDR + 0x0000UL)			/* GPIO A Base Address */
#define GPIOB_BASE_ADDR				(AHB1_BASE_ADDR + 0x0400UL)			/* GPIO B Base Address */
#define GPIOC_BASE_ADDR				(AHB1_BASE_ADDR + 0x0800UL)			/* GPIO C Base Address */
#define GPIOD_BASE_ADDR				(AHB1_BASE_ADDR + 0x0C00UL)			/* GPIO D Base Address */
#define GPIOE_BASE_ADDR				(AHB1_BASE_ADDR + 0x1000UL)			/* GPIO E Base Address */
#define GPIOF_BASE_ADDR				(AHB1_BASE_ADDR + 0x1400UL)			/* GPIO F Base Address */
#define GPIOG_BASE_ADDR				(AHB1_BASE_ADDR + 0x1800UL)			/* GPIO G Base Address */
#define GPIOH_BASE_ADDR				(AHB1_BASE_ADDR + 0x1C00UL)			/* GPIO H Base Address */
#define GPIOI_BASE_ADDR				(AHB1_BASE_ADDR + 0x2000UL)			/* GPIO I Base Address */
#define GPIOJ_BASE_ADDR				(AHB1_BASE_ADDR + 0x2400UL)			/* GPIO J Base Address */
#define GPIOK_BASE_ADDR				(AHB1_BASE_ADDR + 0x2800UL)			/* GPIO K Base Address */

#define CRC_BASE_ADDR				(AHB1_BASE_ADDR + 0x3000UL)			/* CRC Base Address	   */
#define RCC_BASE_ADDR				(AHB1_BASE_ADDR + 0x3800UL)			/* RCC Base Address    */

/*
 * Peripherals Structure Definitions
 *
 */

typedef struct
{
	__IO uint32_t MODER;		/*!< GPIO port mode register 										Address Offset = 0x0000 */
	__IO uint32_t OTYPER;		/*!< GPIO port output type register									Address Offset = 0x0004 */
	__IO uint32_t OSPEEDR;		/*!< GPIO port output speed register 								Address Offset = 0x0008 */
	__IO uint32_t PUPDR;		/*!< GPIO port pull-up/pull-down register 							Address Offset = 0x000C */
	__IO uint32_t IDR;			/*!< GPIO port input data register 									Address Offset = 0x0010 */
	__IO uint32_t ODR;			/*!< GPIO port output data register 								Address Offset = 0x0014 */
	__IO uint32_t BSRR;			/*!< GPIO port bit set/reset register 								Address Offset = 0x0018 */
	__IO uint32_t LCKR;			/*!< GPIO port configuration lock register 							Address Offset = 0x001C */
	__IO uint32_t AFR[2];		/*!< GPIO alternate function register 								Address Offset = 0x0020 */

}GPIO_TypeDef_t;

typedef struct
{
	__IO uint32_t CR;			/*!< RCC clock control register 									Address Offset = 0x0000 */
	__IO uint32_t PLLCFGR;		/*!< RCC PLL configuration register 								Address Offset = 0x0004 */
	__IO uint32_t CFGR;			/*!< RCC clock configuration register 								Address Offset = 0x0008 */
	__IO uint32_t CIR;			/*!< RRCC clock interrupt register									Address Offset = 0x000C */
	__IO uint32_t AHB1RSTR;		/*!< RCC AHB1 peripheral reset register 							Address Offset = 0x0010 */
	__IO uint32_t AHB2RSTR;		/*!< RCC AHB2 peripheral reset register 							Address Offset = 0x0014 */
	__IO uint32_t AHB3RSTR;		/*!< RCC AHB3 peripheral reset register 							Address Offset = 0x0018 */
	__IO uint32_t RESERVED0;	/*!< RESERVED 0 													Address Offset = 0x001C */
	__IO uint32_t APB1RSTR;		/*!< RCC APB1 peripheral reset register 							Address Offset = 0x0020 */
	__IO uint32_t APB2RSTR;		/*!< RCC APB2 peripheral reset register 							Address Offset = 0x0024 */
	__IO uint32_t RESERVED1[2];	/*!< RESERVED 1  													Address Offset = 0x0028 */
	__IO uint32_t AHB1ENR;		/*!< RCC AHB1 peripheral clock enable register 						Address Offset = 0x0030 */
	__IO uint32_t AHB2ENR;		/*!< RCC AHB2 peripheral clock enable register 						Address Offset = 0x0034 */
	__IO uint32_t AHB3ENR;		/*!< RCC AHB3 peripheral clock enable register 						Address Offset = 0x0038 */
	__IO uint32_t RESERVED2;	/*!< RESERVED 2  													Address Offset = 0x003C */
	__IO uint32_t APB1ENR;		/*!< RCC APB1 peripheral clock enable register 						Address Offset = 0x0040 */
	__IO uint32_t APB2ENR;		/*!< RCC APB2 peripheral clock enable register 						Address Offset = 0x0044 */
	__IO uint32_t RESERVED3[2];	/*!< RESERVED 3 													Address Offset = 0x0048 */
	__IO uint32_t AHB1LPENR;	/*!< RCC AHB1 peripheral clock enable in low power mode register 	Address Offset = 0x0050 */
	__IO uint32_t AHB2LPENR;	/*!< RCC AHB2 peripheral clock enable in low power mode register 	Address Offset = 0x0054 */
	__IO uint32_t AHB3LPENR;	/*!< RCC AHB3 peripheral clock enable in low power mode register 	Address Offset = 0x0058 */
	__IO uint32_t RESERVED4;	/*!< RESERVED 4 													Address Offset = 0x005C */
	__IO uint32_t APB1LPENR;	/*!< RCC APB1 peripheral clock enable in low power mode register 	Address Offset = 0x0060 */
	__IO uint32_t APB2LPENR;	/*!< RCC APB2 peripheral clock enable in low power mode register 	Address Offset = 0x0064 */
	__IO uint32_t RESERVED5[2];	/*!< RESERVED 5 													Address Offset = 0x0068 */
	__IO uint32_t BDCR;			/*!< RCC Backup domain control register 							Address Offset = 0x0070 */
	__IO uint32_t CSR;			/*!< RCC clock control & status register 							Address Offset = 0x0074 */
	__IO uint32_t RESERVED6[2];	/*!< RESERVED 6 													Address Offset = 0x0078 */
	__IO uint32_t SSCGR;		/*!< RCC spread spectrum clock generation register 					Address Offset = 0x0080 */
	__IO uint32_t PLLI2SCFGR;	/*!< RCC PLLI2S configuration register 								Address Offset = 0x0084 */


}RCC_TypeDef_t;

typedef struct
{
	__IO uint32_t MEMRMP;		/*!< SYSCFG memory remap register 									Address Offset = 0x0000 */
	__IO uint32_t PMC;			/*!< SYSCFG peripheral mode configuration register 					Address Offset = 0x0004 */
	__IO uint32_t EXTI_CR[4];	/*!< SYSCFG external interrupt configuration register 				Address Offset = 0x0008 */
	__IO uint32_t CMPCR;		/*!< Compensation cell control register 							Address Offset = 0x0020 */

}SYSCFG_TypeDef_t;

typedef struct
{
	__IO uint32_t IMR;			/*!< Interrupt mask register 										Address Offset = 0x0000 */
	__IO uint32_t EMR;			/*!< Event mask register 											Address Offset = 0x0004 */
	__IO uint32_t RTSR;			/*!< Rising trigger selection register 								Address Offset = 0x0008 */
	__IO uint32_t FTSR;			/*!< Falling trigger selection register 							Address Offset = 0x000C */
	__IO uint32_t SWIER;		/*!< Software interrupt event register 								Address Offset = 0x0010 */
	__IO uint32_t PR;			/*!< Pending register 												Address Offset = 0x0014 */

}EXTI_TypeDef_t;

typedef struct
{
	__IO uint32_t CR1;			/*!< SPI control register 1 										Address Offset = 0x0000 */
	__IO uint32_t CR2;			/*!< SPI control register 2 										Address Offset = 0x0004 */
	__IO uint32_t SR;			/*!< SPI status  register 											Address Offset = 0x0008 */
	__IO uint32_t DR;			/*!< SPI data register 												Address Offset = 0x000C */
	__IO uint32_t CRCPR;		/*!< SPI CRC polynomial register 									Address Offset = 0x0010 */
	__IO uint32_t RXCRCR;		/*!< SPI RX CRC register 											Address Offset = 0x0014 */
	__IO uint32_t TXCRCR;		/*!< SPI TX CRC register 											Address Offset = 0x0018 */
	__IO uint32_t I2SCFGR;		/*!< SPI_I2S confıguration register 								Address Offset = 0x001C */
	__IO uint32_t I2SPR;		/*!< SPI_I2S prescaler register 									Address Offset = 0x0020 */

}SPI_TypeDef_t;

typedef struct
{
	__IO uint32_t SR;			/*!< USART Status register 											Address Offset = 0x0000 */
	__IO uint32_t DR;			/*!< USART Data register 											Address Offset = 0x0004 */
	__IO uint32_t BRR;			/*!< USART Baud rate register 										Address Offset = 0x0008 */
	__IO uint32_t CR1;			/*!< USART Control register 1 										Address Offset = 0x000C */
	__IO uint32_t CR2;			/*!< USART Control register 2										Address Offset = 0x0010 */
	__IO uint32_t CR3;			/*!< USART Control register 3 										Address Offset = 0x0014 */
	__IO uint32_t GTPR;			/*!< USART Guard time and prescaler register 						Address Offset = 0x0018 */

}USART_TypeDef_t;

typedef struct
{
	__IO uint32_t CR1;			/*!< I2C Control register 1 										Address Offset = 0x0000 */
	__IO uint32_t CR2;			/*!< I2C Control register 2 										Address Offset = 0x0004 */
	__IO uint32_t OAR1;			/*!< I2C Own address register 1 									Address Offset = 0x0008 */
	__IO uint32_t OAR2;			/*!< I2C Own address register 2 									Address Offset = 0x000C */
	__IO uint32_t DR;			/*!< I2C Data register								 				Address Offset = 0x0010 */
	__IO uint32_t SR1;			/*!< I2C Status register 1 											Address Offset = 0x0014 */
	__IO uint32_t SR2;			/*!< I2C Status register 2 											Address Offset = 0x0018 */
	__IO uint32_t CCR;			/*!< I2C Clock control register 									Address Offset = 0x001C */
	__IO uint32_t TRISE;		/*!< I2C TRISE register 											Address Offset = 0x0020 */
	__IO uint32_t FLTR;			/*!< I2C FLTR register 												Address Offset = 0x0024 */

}I2C_TypeDef_t;

/* Bases address definitions of ports */

#define GPIOA						((GPIO_TypeDef_t *)(GPIOA_BASE_ADDR)	)
#define GPIOB						((GPIO_TypeDef_t *)(GPIOB_BASE_ADDR)	)
#define GPIOC						((GPIO_TypeDef_t *)(GPIOC_BASE_ADDR)	)
#define GPIOD						((GPIO_TypeDef_t *)(GPIOD_BASE_ADDR)	)
#define GPIOE						((GPIO_TypeDef_t *)(GPIOE_BASE_ADDR)	)

#define RCC							((RCC_TypeDef_t *)(RCC_BASE_ADDR)		)

#define SYSCFG						((SYSCFG_TypeDef_t *)(SYSCFG_BASE_ADDR) )

#define EXTI 					 	((EXTI_TypeDef_t *)(EXTI_BASE_ADDR)		)

#define SPI1						((SPI_TypeDef_t*)(SPI1_BASE_ADDR)		)
#define SPI2						((SPI_TypeDef_t*)(SPI2_BASE_ADDR)		)
#define SPI3						((SPI_TypeDef_t*)(SPI3_BASE_ADDR)		)
#define SPI4						((SPI_TypeDef_t*)(SPI4_BASE_ADDR)		)

#define USART2						((USART_TypeDef_t*)(USART2_BASE_ADDR)	)
#define USART3						((USART_TypeDef_t*)(USART3_BASE_ADDR)	)
#define UART4						((USART_TypeDef_t*)(UART4_BASE_ADDR	)	)
#define UART5						((USART_TypeDef_t*)(UART5_BASE_ADDR	)	)

#define USART1						((USART_TypeDef_t*)(USART1_BASE_ADDR	)	)
#define USART6						((USART_TypeDef_t*)(USART6_BASE_ADDR	)	)

#define I2C1						((I2C_TypeDef_t*)(I2C1_BASE_ADDR)		)
#define I2C2						((I2C_TypeDef_t*)(I2C2_BASE_ADDR)		)
#define I2C3						((I2C_TypeDef_t*)(I2C3_BASE_ADDR)		)

/*
 * Bit Operation
 *
 */

#define RCC_AHB1ENR_GPIOAEN_Pos		(0U)								//RCC AHB1ENR register GPIOAEN Bit Position
#define RCC_AHB1ENR_GPIOAEN_Msk		(0x1 << RCC_AHB1ENR_GPIOAEN_Pos)	//RCC AHB1ENR register GPIOAEN Bit Mask
#define RCC_AHB1ENR_GPIOAEN			RCC_AHB1ENR_GPIOAEN_Msk 			//RCC AHB1ENR register GPIOAEN Macro

#define RCC_AHB1ENR_GPIOBEN_Pos		(1U)								//RCC AHB1ENR register GPIOBEN Bit Position
#define RCC_AHB1ENR_GPIOBEN_Msk		(0x1 << RCC_AHB1ENR_GPIOBEN_Pos)	//RCC AHB1ENR register GPIOBEN Bit Mask
#define RCC_AHB1ENR_GPIOBEN			RCC_AHB1ENR_GPIOBEN_Msk 			//RCC AHB1ENR register GPIOBEN Macro

#define RCC_AHB1ENR_GPIOCEN_Pos		(2U)								//RCC AHB1ENR register GPIOCEN Bit Position
#define RCC_AHB1ENR_GPIOCEN_Msk		(0x1 << RCC_AHB1ENR_GPIOCEN_Pos)	//RCC AHB1ENR register GPIOCEN Bit Mask
#define RCC_AHB1ENR_GPIOCEN			RCC_AHB1ENR_GPIOCEN_Msk 			//RCC AHB1ENR register GPIOCEN Macro

#define RCC_AHB1ENR_GPIODEN_Pos		(3U)								//RCC AHB1ENR register GPIODEN Bit Position
#define RCC_AHB1ENR_GPIODEN_Msk		(0x1 << RCC_AHB1ENR_GPIODEN_Pos)	//RCC AHB1ENR register GPIODEN Bit Mask
#define RCC_AHB1ENR_GPIODEN			RCC_AHB1ENR_GPIODEN_Msk 			//RCC AHB1ENR register GPIODEN Macro

#define RCC_APB1ENR_SPI2EN_Pos      (14U)								//RCC APB1EBR register SPI2EN Bit Position
#define RCC_APB1ENR_SPI2EN_Msk		(0x1 << RCC_APB1ENR_SPI2EN_Pos )	//RCC APB1EBR register SPI2EN Bit Mask
#define RCC_APB1ENR_SPI2EN			RCC_APB1ENR_SPI2EN_Msk				//RCC APB1EBR register SPI2EN Macro

#define RCC_APB1ENR_SPI3EN_Pos      (15U)								//RCC APB1EBR register SPI3EN Bit Position
#define RCC_APB1ENR_SPI3EN_Msk		(0x1 << RCC_APB1ENR_SPI3EN_Pos )	//RCC APB1EBR register SPI3EN Bit Mask
#define RCC_APB1ENR_SPI3EN			RCC_APB1ENR_SPI3EN_Msk				//RCC APB1EBR register SPI3EN Macro

#define RCC_APB1ENR_USART2EN_Pos    (17U)								//RCC APB1EBR register USART2EN Bit Position
#define RCC_APB1ENR_USART2EN_Msk	(0x1 << RCC_APB1ENR_USART2EN_Pos )	//RCC APB1EBR register USART2EN Bit Mask
#define RCC_APB1ENR_USART2EN		RCC_APB1ENR_USART2EN_Msk			//RCC APB1EBR register USART2EN Macro

#define RCC_APB1ENR_I2C1EN_Pos 	 	(21U)								//RCC APB1EBR register I2C1EN Bit Position
#define RCC_APB1ENR_I2C1EN_Msk		(0x1 << RCC_APB1ENR_I2C1EN_Pos )	//RCC APB1EBR register I2C1EN Bit Mask
#define RCC_APB1ENR_I2C1EN			RCC_APB1ENR_I2C1EN_Msk				//RCC APB1EBR register I2C1EN Macro

#define RCC_APB2ENR_SYSCFGEN_Pos	(14U)								//RCC APB2EBR register SYSCFGEN Bit Position
#define RCC_APB2ENR_SYSCFGEN_Msk	(0x1U << RCC_APB2ENR_SYSCFGEN_Pos)	//RCC APB2EBR register SYSCFGEN Bit Mask
#define RCC_APB2ENR_SYSCFGEN	    RCC_APB2ENR_SYSCFGEN_Msk			//RCC APB2EBR register SYSCFGEN Macro

#define RCC_APB2ENR_SPI1EN_Pos		(12U)								//RCC APB2EBR register SPI1EN Bit Position
#define RCC_APB2ENR_SPI1EN_Msk		(0x1U << RCC_APB2ENR_SPI1EN_Pos)	//RCC APB2EBR register SPI1EN Bit Mask
#define RCC_APB2ENR_SPI1EN	   		 RCC_APB2ENR_SPI1EN_Msk				//RCC APB2EBR register SPI1EN Macro

#define RCC_APB2ENR_SPI4EN_Pos      (13U)								//RCC APB2EBR register SPI4EN Bit Position
#define RCC_APB2ENR_SPI4EN_Msk		(0x1 << RCC_APB2ENR_SPI4EN_Pos )	//RCC APB2EBR register SPI4EN Bit Mask
#define RCC_APB2ENR_SPI4EN			RCC_APB2ENR_SPI4EN_Msk				//RCC APB2EBR register SPI4EN Macro

#define SPI_SR_Busy					(7U)
#define SPI_SR_TxE					(1U)
#define SPI_SR_RxNE					(0U)

#define SPI_CR1_SPE					(6U)
#define SPI_CR1_DFF					(11U)

#define SPI_CR2_TXEIE				(7U)
#define SPI_CR2_RXNEIE				(6U)

#define USART_CR1_UE				(13U)
#define USART_CR1_TxEIE				(7U)
#define USART_CR1_RxNEIE			(5U)

#define UART_CR2_STOP				(12U)

#define USART_SR_TxE				(7U)
#define USART_SR_TC					(6U)
#define USART_SR_RxNE				(5U)

#define I2C_CR1_PE					(0U)

/*
 * Flag Definitions
 *
 */

#define SPI_TxE_FLAG				(0x1U << SPI_SR_TxE)
#define SPI_Busy_FLAG				(0x1U << SPI_SR_Busy)
#define SPI_RxNE_FLAG				(0x1U << SPI_SR_RxNE)

#define USART_TxE_FLAG				(0x1U << USART_SR_TxE)
#define USART_TC_FLAG				(0x1U << USART_SR_TC)
#define USART_RxNE_FLAG				(0x1U << USART_SR_RxNE)

#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"
#include "USART.h"
#include "I2C.h"



#endif /* INC_STM32F407XX_H_ */
