#include"main.h"
#include"..\lib\Soft_I2c.h"
//#include"..\lib\Lcd4.h"
#include"..\lib\Rtc_Ds1307.h"
#include"Port.h"


char so[]= {0x40, 0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
char Maquet[] = {0xbf, 0xdf, 0xef, 0xf7, 0xfb, 4, 0x7e};
unsigned char chuSo[7];
unsigned long dem, temp, i;

void delay(int time){
	while(time--);
}

void main()
{
	unsigned char Hour, Minute, Second, old_second, Mode;

	Soft_I2c_Init();
	Ds1307_Init();
	//Lcd_Init();

	while(1)
	{
		Ds1307_Read_Time(&Hour, &Minute, &Second, &Mode);
		// Tra ve so co so 10 nen phai cong cho 0x30 de thanh ma ASCI
																		
				P3_5 = 0;
				P0 = so[Second%10];
				delay(5);
				P3_5 = 1;
		
				P3_4 = 0;
				P0 = so[Second/10];
				delay(5);
				P3_4 = 1;

				P3_3 = 0;
				P0 = so[Minute%10];
				delay(5);
				P3_3 = 1;
		
				P3_2 = 0;
				P0 = so[Minute/10];
				delay(5);
				P3_2 = 1;

				P3_1 = 0;
				P0 = so[Hour%10];
				delay(5);
				P3_1 = 1;
		
				P3_0 = 0;
				P0 = so[Hour/10];
				delay(5);
				P3_0 = 1;

			
			
			
		
		

	}
}


