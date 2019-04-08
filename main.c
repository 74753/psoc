//----------------------------------------------------------------------------
// Exercise 1 - LED/PinInput/LCD-Display
// Sebastian Kalide, Stefan Winter
// date: 04/08/2019
// PSoC Design TX00DB04
//----------------------------------------------------------------------------

#include <m8c.h>        					  // part specific constants and macros
#include "PSoCAPI.h"    					  // PSoC API definitions for all User Modules


void main(void)
{
   char counter[] = "0";   					  // Define RAM string
	
   M8C_EnableGInt ;                           // Turn on interrupts 
   SleepTimer_Start();
   SleepTimer_SetInterval(SleepTimer_8_HZ);   // Set interrupt to a
   SleepTimer_EnableInt();                    // 8 Hz rate
   
   LED_1_Start();

   LCD_Start();                 			 // Initialize LCD
   LCD_Position(0,0);           			 // Place LCD cursor at row 0, col 5.
   LCD_PrCString("Sebastian&Stefan");        // Print "Sebastian&Stefan" on the LCD
   LCD_Position(1,7);						 // Place LCD cursor at row 1, col 7.
   LCD_PrString(counter);					 // Print counter on the LCD

   while(1) 
   {
      SleepTimer_SyncWait(4, SleepTimer_WAIT_RELOAD); // Wait for 0.5s (2 HZ) each loop
		
	  if (Button_Data_ADDR & Button_MASK)
	  {			  									  // if Button is pressed
	 	LED_1_Invert();								  // toggle LED
		counter[0]++;								  // increments counter
		if (counter[0] > '9'){						  // if counter is greater than 9
			counter[0] = '0';						  // resets counter to 0
		}
		LCD_Position(1,7);							  // Place LCD cursor at row 1, col 7.
  		LCD_PrString(counter);						  // Print counter on the LCD
	}
   }
}
