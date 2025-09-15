
int pic_voltage_clamp_disable(uint8_t chain)

{
  int iVar1;
  uint8_t chain_local;
  
  iVar1 = volt_clamp(chain,'\0');
  return iVar1;
}

