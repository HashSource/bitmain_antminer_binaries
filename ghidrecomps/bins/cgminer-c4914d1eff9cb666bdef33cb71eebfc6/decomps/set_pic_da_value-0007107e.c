
int set_pic_da_value(uint8_t chain,uint8_t da_value)

{
  int iVar1;
  uint8_t da_value_local;
  uint8_t chain_local;
  
  iVar1 = dsPIC33EP16GS202_set_pic_voltage(chain,da_value);
  return iVar1;
}

