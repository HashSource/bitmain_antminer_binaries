
/* WARNING: Unknown calling convention */

int32_t enbale_chain_hwsweep(uint8_t which_chain,uint8_t sweep_pattern_num)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,'\x01',0,0xd0,(sweep_pattern_num - 1 & 7) << 4 | 0x38001801);
  return iVar1;
}

