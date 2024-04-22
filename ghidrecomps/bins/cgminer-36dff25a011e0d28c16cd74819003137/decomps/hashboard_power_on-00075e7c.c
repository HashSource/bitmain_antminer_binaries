
int hashboard_power_on(uint8_t chain)

{
  int iVar1;
  uint8_t chain_local;
  
  iVar1 = hashboard_power_cntl(chain,'\x01');
  return iVar1;
}

