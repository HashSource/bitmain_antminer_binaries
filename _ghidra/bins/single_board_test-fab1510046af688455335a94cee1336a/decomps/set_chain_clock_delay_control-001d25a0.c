
/* WARNING: Unknown calling convention */

int32_t set_chain_clock_delay_control
                  (uint8_t which_chain,uint8_t pwth_sel,uint8_t ccdly_sel,uint8_t swpf_mode)

{
  int32_t iVar1;
  
  iVar1 = set_clock_delay_control(which_chain,'\x01',0,pwth_sel,ccdly_sel,swpf_mode);
  return iVar1;
}

