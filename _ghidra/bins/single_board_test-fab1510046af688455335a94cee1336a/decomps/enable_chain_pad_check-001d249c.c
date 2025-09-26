
/* WARNING: Unknown calling convention */

int32_t enable_chain_pad_check(uint8_t which_chain,_Bool pad_check_enable)

{
  uint uVar1;
  int32_t iVar2;
  
  uVar1 = pad_check_enable & 0xf;
  if (pad_check_enable != 0) {
    uVar1 = 0xb;
  }
  iVar2 = send_set_config_command(which_chain,'\x01',0,0x9c,uVar1 << 0x1c);
  return iVar2;
}

