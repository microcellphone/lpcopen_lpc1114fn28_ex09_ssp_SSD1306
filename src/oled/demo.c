#include "stdint.h"
#include "oled_ssd1306.h"
#include "code.h"

void demo_1(void)
{
 	uint8_t k,i;

  for(k = 0; k < 8; k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++)  {
    	SSD1306_SendData(gImage_3w[k*128+i]);
    }
  }
	Delay(500);
}

void demo_2(void)
{
 	uint8_t k,i;

  for(k = 0; k < 8; k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++)  {
    	SSD1306_SendData(zimo_me_ASCII[k*128+i]);
    }
  }
	Delay(500);
}

void demo_3(void)
{
 	uint8_t k,i;

  for(k = 0; k < 8; k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++)  {
    	SSD1306_SendData(gImage_12w[k*128+i]);
    }
  }
	Delay(500);
}

void demo_4(void)
{
 	uint8_t k,i;

  for(k = 0; k < 8; k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++)  {
    	SSD1306_SendData(gImage_13w[k*128+i]);
    }
  }
	Delay(500);
}
void demo_5(void)
{
 	uint8_t k,i;

  for(k = 0; k < 8; k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++)  {
    	SSD1306_SendData(gImage_14w[k*128+i]);
    }
  }
	Delay(500);
}

void demo_6(void)
{
 	uint8_t k,i;

  for(k = 0; k < 8; k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++)  {
    	SSD1306_SendData(gImage_15w[k*128+i]);
    }
  }
	Delay(500);
}

void demo_7(void)
{
 	uint8_t k,i;

  for(k = 0; k < 8; k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++)  {
    	SSD1306_SendData(buffer[k*128+i]);
    }
  }
	Delay(500);
}

void demo_8(void)
{
 	uint8_t k,i;

  for(k = 0; k < 8; k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++)  {
    	SSD1306_SendData(BigFonts[k*128+i]);
    }
  }
	Delay(500);
}
