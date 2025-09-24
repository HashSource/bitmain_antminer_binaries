
/* WARNING: Unknown calling convention */

int32_t set_core_enable(uint8_t which_chain,uint8_t chip_mode,uint8_t core_mode,
                       uint32_t which_asic_address,uint32_t which_core)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,chip_mode,which_asic_address,0x3c,
                     (which_core & 0xff) << 0x10 | 0x82aa | (uint)core_mode << 0x1f);
  return iVar1;
}

