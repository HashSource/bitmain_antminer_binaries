
/* WARNING: Unknown calling convention */

int32_t set_clock_delay_control
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,uint8_t pwth_sel,
                  uint8_t ccdly_sel,uint8_t swpf_mode)

{
  int32_t iVar1;
  byte bVar2;
  
  bVar2 = (pwth_sel & 7) << 2 | ccdly_sel << 5;
  if (swpf_mode != '\0') {
    bVar2 = bVar2 | 1;
  }
  iVar1 = send_set_config_command(which_chain,mode,which_asic_address,0x3c,bVar2 | 0x80008000);
  return iVar1;
}

