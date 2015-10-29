
/**
 *    Blinky project
 *
 *    @author     Tilen Majerle
 *    @email        tilen@majerle.eu
 *    @version     v1.0
 *    @gcc        v4.7 20013qr3
 *    @ide        CooCox CoIDE v1.7.6
 *    modify for STM32 nucleo F401RE by Paolo Della Vedova
 */
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

int main(void) {

	SystemInit();

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitDef;

    GPIO_InitDef.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
    //Initialize pins
    GPIO_Init(GPIOA, &GPIO_InitDef);

    volatile int i;
    while (1) {
        // Toggle leds
        GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
        // Waste some tome
        for (i = 0; i < 500000; i++);
    }
}
