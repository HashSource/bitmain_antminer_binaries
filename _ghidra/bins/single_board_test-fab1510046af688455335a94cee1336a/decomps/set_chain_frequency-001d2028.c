
/* WARNING: Unknown calling convention */

int32_t set_chain_frequency(uint8_t which_chain,uint8_t which_pll,uint32_t frequency)

{
  int32_t iVar1;
  
  iVar1 = set_frequency(which_chain,'\x01',0,which_pll,frequency);
  return iVar1;
}

