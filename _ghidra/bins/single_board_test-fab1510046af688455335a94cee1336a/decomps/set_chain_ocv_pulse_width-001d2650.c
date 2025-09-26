
/* WARNING: Unknown calling convention */

int32_t set_chain_ocv_pulse_width(uint8_t which_chain,uint8_t edge_sel)

{
  int32_t iVar1;
  
  iVar1 = set_ocv_pulse_width(which_chain,'\x01',0,edge_sel);
  return iVar1;
}

