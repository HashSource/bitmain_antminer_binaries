
/* WARNING: Unknown calling convention */

int32_t set_asic_clock_delay_control
                  (uint8_t which_chain,uint32_t which_asic_address,uint8_t pwth_sel,
                  uint8_t ccdly_sel,uint8_t swpf_mode)

{
  int32_t iVar1;
  
  iVar1 = set_clock_delay_control(which_chain,'\0',which_asic_address,pwth_sel,ccdly_sel,swpf_mode);
  return iVar1;
}

