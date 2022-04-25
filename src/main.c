/* vzorový projekt (sem pište struèný popis projektu)

*/

#include "stm8s.h"
#include "milis.h"
#include "stm8_hd44780.h"

void tecka (void);
void carka (void);
void sleduj_enc (void);
void sleduj_UART (void);
void pockej (void);
void LCD (void);

char prijaty_znak;

int16_t hodnota=0;
uint16_t last_time=0;
uint8_t x=0;
uint8_t stav=0;
uint8_t pomocna=0;


void main(void){
CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // taktovat MCU na 16MHz
init_milis();
lcd_init();
GPIO_Init(GPIOC,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_SLOW);
GPIO_Init(GPIOE,GPIO_PIN_2,GPIO_MODE_IN_FL_NO_IT); //CLK
GPIO_Init(GPIOE,GPIO_PIN_1,GPIO_MODE_IN_FL_NO_IT); //DT
UART1_Init(115200,UART1_WORDLENGTH_8D,UART1_STOPBITS_1,UART1_PARITY_NO,UART1_SYNCMODE_CLOCK_DISABLE,UART1_MODE_RX_ENABLE);
UART1_Cmd(ENABLE);

lcd_gotoxy(5,0);
		lcd_puts("a .-");

	while (1){

		sleduj_UART();
		sleduj_enc();
		LCD();
			
		
	}
}


void sleduj_enc(void){
	static minule=1;	
	if(GPIO_ReadInputPin(GPIOE,GPIO_PIN_2) == RESET && minule==1){
		minule = 0; 
		if(GPIO_ReadInputPin(GPIOE,GPIO_PIN_1) != RESET){
			if (hodnota > 0){
				hodnota--;
				pomocna=1;
			}
			else{
				hodnota=25;
				pomocna=1;
			}
		}
		else{
			if (hodnota <25){
				hodnota++;
				pomocna=1;
			}
			else{
				hodnota=0;
				pomocna=1;
			}
		}
	}
	else if (minule==0 && GPIO_ReadInputPin(GPIOE,GPIO_PIN_2) != RESET){
		minule=1;
		if(GPIO_ReadInputPin(GPIOE,GPIO_PIN_1) != RESET){
			if (hodnota <25){
				hodnota++;
				pomocna=1;
			}
			else{
				hodnota=0;
				pomocna=1;
			}
		}
		else{
			if (hodnota > 0){
				hodnota--;
				pomocna=1;
			}
			else{
				hodnota=25;
				pomocna=1;
			}
		}
	}
}

void LCD (void) {
	if (hodnota==0 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("a .-");
		pomocna=0;
	}
	if (hodnota==1 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("b -...");
		pomocna=0;
	}
	if (hodnota==2 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("c -.-.");
		pomocna=0;
	}
	if (hodnota==3 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("d -..");
		pomocna=0;
	}
	if (hodnota==4 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("e .");
		pomocna=0;
	}
	if (hodnota==5 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("f ..-.");
		pomocna=0;
	}
	if (hodnota==6 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("g --.");
		pomocna=0;
	}
	if (hodnota==7 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("h ....");
		pomocna=0;
	}
	if (hodnota==8 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("i ..");
		pomocna=0;
	}
	if (hodnota==9 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("j .---");
		pomocna=0;
	}
	if (hodnota==10 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("k -.-");
		pomocna=0;
	}
	if (hodnota==11 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("l .-..");
		pomocna=0;
	}
	if (hodnota==12 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0 && pomocna==1);
		lcd_puts("m --");
		pomocna=0;
	}
	if (hodnota==13 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0 && pomocna==1);
		lcd_puts("n -.");
		pomocna=0;
	}
	if (hodnota==14 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("o ---");
		pomocna=0;
	}
	if (hodnota==15 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0 && pomocna==1);
		lcd_puts("p .--.");
		pomocna=0;
	}
	if (hodnota==16 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("q --.-");
		pomocna=0;
	}
	if (hodnota==17 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("r .-.");
		pomocna=0;
	}
	if (hodnota==18 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("s ...");
		pomocna=0;
	}
	if (hodnota==19 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("t -");
		pomocna=0;
	}
	if (hodnota==20 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("u ..-");
		pomocna=0;
	}
	if (hodnota==21 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("v ...-");
		pomocna=0;
	}	
	if (hodnota==22 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("w .--");
		pomocna=0;
	}
	if (hodnota==23 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("x -..-");
		pomocna=0;
	}
	if (hodnota==24 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("y -.--");
		pomocna=0;
	}
	if (hodnota==25 && pomocna==1){
		lcd_clear();
		lcd_gotoxy(5,0);
		lcd_puts("z --..");
		pomocna=0;
	}
}







void sleduj_UART (void){
	if(UART1_GetFlagStatus(UART1_FLAG_RXNE) != RESET && stav==0){ 
			stav=1;
			prijaty_znak=UART1_ReceiveData8(); 
			
			if(prijaty_znak == 'a'){ 
				tecka();
				carka();
				pockej();
				stav=0;
			} 
			
			else if(prijaty_znak == 'b'){
				carka();
				tecka();
				tecka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'c'){
				carka();
				tecka();
				carka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'd'){
				carka();
				tecka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'e'){
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'f'){
				tecka();
				tecka();
				carka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'g'){
				carka();
				carka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'h'){
				tecka();
				tecka();
				tecka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'i'){
				tecka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'j'){
				tecka();
				carka();
				carka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'k'){
				carka();
				carka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'l'){
				tecka();
				carka();
				tecka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'm'){
				carka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'n'){
				carka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'o'){
				carka();
				carka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'p'){
				tecka();
				carka();
				carka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'q'){
				carka();
				carka();
				tecka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'r'){
				tecka();
				carka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 's'){
				tecka();
				tecka();
				tecka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 't'){
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'u'){
				tecka();
				tecka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'v'){
				tecka();
				tecka();
				tecka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'w'){
				tecka();
				carka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'x'){
				carka();
				tecka();
				tecka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'y'){
				carka();
				tecka();
				carka();
				carka();
				pockej();
				stav=0;
			}
			
			else if(prijaty_znak == 'z'){
				carka();
				carka();
				tecka();
				tecka();	
				pockej();
				stav=0;
			}
			
			else {
				pockej();
				stav=0;
			}
	}
}

void tecka (void){
	while(x!=2){
		if (milis()-last_time >= 400){
			GPIO_WriteReverse(GPIOC,GPIO_PIN_5);
			last_time=milis();
			x++;
		}
	}
	x=0;
}

void carka (void){
	while(x!=2){
		if (milis()-last_time >= 1100){
			GPIO_WriteReverse(GPIOC,GPIO_PIN_5);
			last_time=milis();
			x++;
		}
	}
	x=0;
}

void pockej(void){
	while (x!=1) {
		if (milis()-last_time >= 2000){
			last_time=milis();
			x=1;
		}
	}
	x=0;
}



// pod tímto komentáøem nic nemìòte 
#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif