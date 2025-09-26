
/* WARNING: Unknown calling convention */

int32_t set_asic_frequency(uint8_t which_chain,uint32_t which_asic_address,uint8_t which_pll,
                          uint32_t frequency)

{
  int32_t iVar1;
  
  iVar1 = set_frequency(which_chain,'\0',which_asic_address,which_pll,frequency);
  return iVar1;
}

