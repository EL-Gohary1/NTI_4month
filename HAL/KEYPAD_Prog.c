#include "KEYPAD.h"
#include "DIO_Interface.h"

void KEYPAD_Init(void)
{
	
}
u8 KEYPAD_GetEntry(void)
{
	u8 key=KEY_DEFAULT;
	
	DIO_WritePin(OUTPUT1,HIGH);
	DIO_WritePin(OUTPUT2,HIGH);
	DIO_WritePin(OUTPUT3,HIGH);
	DIO_WritePin(OUTPUT4,HIGH);

	for(u8 r=0;r<ROW;r++)
	{
		if (r==0)
		{
			DIO_WritePin(OUTPUT1,LOW);
			for (u8 c=0;c<COL;c++)
			{
				   if (!DIO_ReadPin(INPUT1))
				  {
					while(!DIO_ReadPin(INPUT1));
					key=KeysArray[r][0];
				  }
				  if (!DIO_ReadPin(INPUT2))
				  {
					  while(!DIO_ReadPin(INPUT2));
					  key=KeysArray[r][1];
				  }
				  
				  if (!DIO_ReadPin(INPUT3))
				  {
					  while(!DIO_ReadPin(INPUT3));
					  key=KeysArray[r][2];
				  }
				  if (!DIO_ReadPin(INPUT4))
				  {
					  while(!DIO_ReadPin(INPUT4));
					  key=KeysArray[r][3];
				  }
			}
			DIO_WritePin(OUTPUT1,HIGH);
		}
		else if (r==1)
		{
			DIO_WritePin(OUTPUT2,LOW);
			for (u8 c=0;c<COL;c++)
			{
				if (!DIO_ReadPin(INPUT1))
				{
					while(!DIO_ReadPin(INPUT1));
					key=KeysArray[r][0];
				}
				if (!DIO_ReadPin(INPUT2))
				{
					while(!DIO_ReadPin(INPUT2));
					key=KeysArray[r][1];
				}
				
				if (!DIO_ReadPin(INPUT3))
				{
					while(!DIO_ReadPin(INPUT3));
					key=KeysArray[r][2];
				}
				if (!DIO_ReadPin(INPUT4))
				{
					while(!DIO_ReadPin(INPUT4));
					key=KeysArray[r][3];
				}
			}
			DIO_WritePin(OUTPUT2,HIGH);
		}
		else if (r==2)
		{
			DIO_WritePin(OUTPUT3,LOW);
			for (u8 c=0;c<COL;c++)
			{
				if (!DIO_ReadPin(INPUT1))
				{
					while(!DIO_ReadPin(INPUT1));
					key=KeysArray[r][0];
				}
				if (!DIO_ReadPin(INPUT2))
				{
					while(!DIO_ReadPin(INPUT2));
					key=KeysArray[r][1];
				}
				
				if (!DIO_ReadPin(INPUT3))
				{
					while(!DIO_ReadPin(INPUT3));
					key=KeysArray[r][2];
				}
				if (!DIO_ReadPin(INPUT4))
				{
					while(!DIO_ReadPin(INPUT4));
					key=KeysArray[r][3];
				}
			  }
			DIO_WritePin(OUTPUT3,HIGH);
		}
		else
		{
			DIO_WritePin(OUTPUT4,LOW);
			for (u8 c=0;c<COL;c++)
			{
				if (!DIO_ReadPin(INPUT1))
				{
					while(!DIO_ReadPin(INPUT1));
					key=KeysArray[r][0];
				}
				if (!DIO_ReadPin(INPUT2))
				{
					while(!DIO_ReadPin(INPUT2));
					key=KeysArray[r][1];
				}
				
				if (!DIO_ReadPin(INPUT3))
				{
					while(!DIO_ReadPin(INPUT3));
					key=KeysArray[r][2];
				}
				if (!DIO_ReadPin(INPUT4))
				{
					while(!DIO_ReadPin(INPUT4));
					key=KeysArray[r][3];
				}
			  }
			DIO_WritePin(OUTPUT4,HIGH);
		}
	}
	return key;
}


