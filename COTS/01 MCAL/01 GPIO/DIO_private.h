#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H


#define GPIOA_BASE_ADD	((uint32)0x40010800)

#define GPIOA_CRL		(*((volatile uint32*) ((GPIOA_BASE_ADD)+(uint32) 0)))
#define GPIOA_CRH		(*((volatile uint32 *) ((GPIOA_BASE_ADD)+(uint32) 0x4)))
#define GPIOA_IDR		(*((volatile uint32 *) ((GPIOA_BASE_ADD)+(uint32) 0x8)))
#define GPIOA_ODR		(*((volatile uint32 *) ((GPIOA_BASE_ADD)+(uint32) 0xc)))
#define GPIOA_BSRR		(*((volatile uint32 *) ((GPIOA_BASE_ADD)+(uint32) 0x10)))
#define GPIOA_BRR		(*((volatile uint32 *) ((GPIOA_BASE_ADD)+(uint32) 0x14)))
#define GPIOA_LCKR		(*((volatile uint32 *) ((GPIOA_BASE_ADD)+(uint32) 0x18)))


#define GPIOB_BASE_ADD	((uint32)0x40010C00)
#define GPIOB_CRL		(*((volatile uint32 *) ((GPIOB_BASE_ADD)+(uint32) 0x0)))
#define GPIOB_CRH		(*((volatile uint32 *) ((GPIOB_BASE_ADD)+(uint32) 0x4)))
#define GPIOB_IDR		(*((volatile uint32 *) ((GPIOB_BASE_ADD)+(uint32) 0x8)))
#define GPIOB_ODR		(*((volatile uint32 *) ((GPIOB_BASE_ADD)+(uint32) 0xc)))
#define GPIOB_BSRR		(*((volatile uint32 *) ((GPIOB_BASE_ADD)+(uint32) 0x10)))
#define GPIOB_BRR		(*((volatile uint32 *) ((GPIOB_BASE_ADD)+(uint32) 0x14)))
#define GPIOB_LCKR		(*((volatile uint32 *) ((GPIOB_BASE_ADD)+(uint32) 0x18)))



#define GPIOC_BASE_ADD	((uint32)0x40011000)
#define GPIOC_CRL		(*((volatile uint32 *) ((GPIOC_BASE_ADD)+(uint32) 0x0)))
#define GPIOC_CRH		(*((volatile uint32 *) ((GPIOC_BASE_ADD)+(uint32) 0x4)))
#define GPIOC_IDR		(*((volatile uint32 *) ((GPIOC_BASE_ADD)+(uint32) 0x8)))
#define GPIOC_ODR		(*((volatile uint32 *) ((GPIOC_BASE_ADD)+(uint32) 0xc)))
#define GPIOC_BSRR		(*((volatile uint32 *) ((GPIOC_BASE_ADD)+(uint32) 0x10)))
#define GPIOC_BRR		(*((volatile uint32 *) ((GPIOC_BASE_ADD)+(uint32) 0x14)))
#define GPIOC_LCKR		(*((volatile uint32 *) ((GPIOC_BASE_ADD)+(uint32) 0x18)))


#endif /*ifndef DIO_PRIVATE_H*/
