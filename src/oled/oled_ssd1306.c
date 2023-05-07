#include "oled_ssd1306.h"

//===========send command=========================
void SSD1306_SendCommand(uint8_t command)
{
  SSD1306_CS_CLR();		/* CS=L		     */
  SSD1306_DC_CLR();		/* DC=L		     */
  SSP0_Send_Request(command);
  SSD1306_CS_SET();
}

//===========send data=================================
void SSD1306_SendData(uint8_t date)
{
  SSD1306_CS_CLR();		/* CS=L		     */
  SSD1306_DC_SET();		/* DC=H		     */
  SSP0_Send_Request(date);
  SSD1306_CS_SET();		/* CS=H		     */
}

//===========clear oled=========================
uint8_t page = 0;

void OLED_ClearScreen (uint8_t state)
{
  uint8_t k,i;

  for(k=0;k<8;k++) {
    SSD1306_SendCommand(0xb0+k);
    SSD1306_SendCommand(0x10);
    SSD1306_SendCommand(0x00);
    for(i=0;i<128;i++) {
      SSD1306_SendData(state);
    }
  }
}

//===============================================
void OLED_Config_Request(void)
{
//	    SSD1306_DC
  Chip_GPIO_SetPinDIROutput(LPC_GPIO, 1, 4);
  Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_4, (IOCON_FUNC0 | IOCON_MODE_INACT));
  Chip_GPIO_SetPinState(LPC_GPIO, 1, 4, true); // high

//	    SSD1306_RES
  Chip_GPIO_SetPinDIROutput(LPC_GPIO, 1, 5);
  Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_5, (IOCON_FUNC0 | IOCON_MODE_INACT));
  Chip_GPIO_SetPinState(LPC_GPIO, 1, 5, true); // high

  SPI_Config_Request(8, SSP_SLOW, CS_GPIO);
  SSD1306_Config_Request();
  OLED_ClearScreen(0);
}

void SSD1306_Config_Request(void)
{
 	SSD1306_CS_SET();
 	SSD1306_CS_CLR();
 	SSD1306_RES_CLR();
 	Delay(20);
 	SSD1306_RES_SET();
 	Delay(50);

  SSD1306_SendCommand(SSD1306_COMMAND_SET_DISPLAY_OFF);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_DISPLAY_CLOCK_DIVIDE_RATIO);     //display divide ratio/osc. freq. mode
  SSD1306_SendCommand(0x80);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_MULTIPLEX_RATIO);     //multiplex ration mode:63
  SSD1306_SendCommand(0x3F);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_DISPLAY_OFFSET);
  SSD1306_SendCommand(0x00);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_START_LINE);
  SSD1306_SendCommand(SSD1306_COMMAND_CHARGE_PUMP);
  // SSD1306_SendCommand(0x10);
  SSD1306_SendCommand(0x14);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_SEG_REMAP1);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_COM_OUTPUT_SCAN_DIRECTION_REMAPPED);
  //SSD1306_SendCommand(0xC8);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_COM_PINS_HARDWARE_CONFIGURATION);     //common pads hardware: alternative
  SSD1306_SendCommand(0x12);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_CONTRAST_CONTROL);
  //SSD1306_SendCommand(0x9F);     //
  SSD1306_SendCommand(0x66);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_PRECHARGE_PERIOD);
  //SSD1306_SendCommand(0x22);	    //set period 1:1;period 2:15
  SSD1306_SendCommand(0xF1);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_VCOMH_DESELECT_LEVEL);
  SSD1306_SendCommand(0x40);	   //set Vvcomh=0.83*Vcc
  SSD1306_SendCommand(SSD1306_COMMAND_DISPLAY_ALL_ON_RESUME);     //Set Entire Display On/Off
  SSD1306_SendCommand(SSD1306_COMMAND_SET_NORMAL_DISPLAY);
  SSD1306_SendCommand(SSD1306_COMMAND_SET_DISPLAY_ON);
}
