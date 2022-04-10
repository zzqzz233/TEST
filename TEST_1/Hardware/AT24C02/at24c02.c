#include "at24c02.h"


/**
  * @brief I2C�Ķ�����ʱ
  * @param None
  * @retval None
  */

void Write_Bit_24c02(uint8_t addr,uint8_t data)
{
//	uint8_t Ack = 1;
	
	I2CStart();
	I2CSendByte(0xa0);//EEPROM��ַ&дָ��
	I2CWaitAck();
	I2CSendByte(addr);//д���ݵ��ֽ�
	I2CWaitAck();
	I2CSendByte(data);
	I2CWaitAck();
	I2CStop();	
	HAL_Delay(5);
	
//	if(Ack == 0)
//	{
//		printf("SUCCESS");
//	}
//	else
//	{
//		printf("ERROR");
//	}
}

uint8_t Read_Bit_24c02(uint8_t addr)
{	
	uint8_t data = 0;
//	uint8_t Ack = 1;
	
	I2CStart();
	I2CSendByte(0xa0);//EEPROM��ַ&��д����
	I2CWaitAck();
	I2CSendByte(addr);//�����ֽڵĵ�ַ
	I2CWaitAck();
	I2CStart();
	I2CSendByte(0xa1);//EEPROM��ַ&������
	I2CWaitAck();
	data = I2CReceiveByte();
	I2CWaitAck();
	I2CStop();
	
	return data;
}

void Initial_24c02(void)
{
	I2CInit();
}

