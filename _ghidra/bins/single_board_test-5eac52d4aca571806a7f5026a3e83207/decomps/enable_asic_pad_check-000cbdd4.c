
/* WARNING: Unknown calling convention */

int32_t enable_asic_pad_check
                  (uint8_t which_chain,uint32_t which_asic_address,_Bool pad_check_enable)

{
  uint uVar1;
  int32_t iVar2;
  
  uVar1 = pad_check_enable & 0xf;
  if (pad_check_enable != 0) {
    uVar1 = 0xb;
  }
  iVar2 = send_set_config_command(which_chain,'\0',which_asic_address,0x9c,uVar1 << 0x1c);
  return iVar2;
}

