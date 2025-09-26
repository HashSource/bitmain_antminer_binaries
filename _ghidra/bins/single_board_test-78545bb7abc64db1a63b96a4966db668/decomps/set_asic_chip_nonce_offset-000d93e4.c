
/* WARNING: Unknown calling convention */

int32_t set_asic_chip_nonce_offset
                  (uint8_t which_chain,uint32_t which_asic_address,_Bool is_valid,
                  uint16_t chip_nonce_offset)

{
  int32_t iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (is_valid) {
    uVar2 = 0x80000000;
  }
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0xc,uVar2 | chip_nonce_offset)
  ;
  return iVar1;
}

