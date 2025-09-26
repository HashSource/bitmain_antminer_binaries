
/* WARNING: Unknown calling convention */

int32_t set_ocv_pulse_width(uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,
                           uint8_t edge_sel)

{
  int32_t iVar1;
  byte bVar2;
  
  if (edge_sel == '\0') {
    bVar2 = 0;
  }
  else {
    bVar2 = 0x40;
  }
  iVar1 = send_set_config_command(which_chain,mode,which_asic_address,0x3c,bVar2 | 0x80009600);
  return iVar1;
}

