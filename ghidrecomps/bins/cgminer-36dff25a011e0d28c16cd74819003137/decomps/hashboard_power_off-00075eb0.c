
int hashboard_power_off(uint8_t chain)

{
  int iVar1;
  uint8_t chain_local;
  
  iVar1 = hashboard_power_cntl(chain,'\0');
  return iVar1;
}

