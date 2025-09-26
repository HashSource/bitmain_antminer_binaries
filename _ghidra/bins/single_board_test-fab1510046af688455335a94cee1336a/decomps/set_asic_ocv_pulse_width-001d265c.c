
/* WARNING: Unknown calling convention */

int32_t set_asic_ocv_pulse_width(uint8_t which_chain,uint32_t which_asic_address,uint8_t edge_sel)

{
  int32_t iVar1;
  
  iVar1 = set_ocv_pulse_width(which_chain,'\0',which_asic_address,edge_sel);
  return iVar1;
}

