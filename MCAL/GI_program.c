





#include "Utils.h"
#include "StdType.h"
#include "GI_interface.h"
#include "GI_register.h"

void M_GIE_Void_GlobalIntEnable(void)
{
	SET_BIT(SREG_REG,I_BIT);
}
void M_GIE_Void_GlobalIntDisable(void)
{
	CLR_BIT(SREG_REG,I_BIT);
}
