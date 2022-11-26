#include "led.h"
#include "gpio.h"

void InpoutOutputConfig( GPIOA , GPIOD )
{
   //Enable the AHB clock all GPIO PORT A and PORT D
  GPIO_Clock_Enable(GPIOA);
  GPIO_Clock_Enable(GPIOD);
  
  //set Pin12 and pin15 to PORTD as output
  GPIO_Config(GPIOD,PIN12,OUTPUT,OUTPUT_OPEN_DRAIN, LOW_SPEED);
  GPIO_Config(GPIOD,PIN15,OUTPUT,OUTPUT_OPEN_DRAIN, LOW_SPEED);
  
  //set Pin0 to PORTA as output
  GPIO_Config(GPIOA,PIN0,INPUT,LOW_SPEED);
 
}
void  ButtonToggleLed( GPIO_WritePin ,GPIO_ReadPin )
{
  //Turn ON the LED blue of PORTD
  GPIO_WritePin(GPIOD, PIN15,SET);
  //Turn OFF the LED green of PORTD
  GPIO_WritePin(GPIOD, PIN12,RESET);
     if(GPIO_ReadPin(GPIOA, PIN0) == 1){
       GPIO_WritePin(GPIOD, PIN12, SET);
   }else{
       GPIO_WritePin(GPIOD, PIN12, RESET);
   }
}


