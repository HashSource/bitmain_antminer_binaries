
/* WARNING: Unknown calling convention */

int32_t write_core_reg_with_addr(uint8_t chain,uint32_t asic,uint32_t corereg,uint32_t data)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (chain,'\0',asic,0x3c,data & 0xff | (corereg & 0x1f) << 8 | 0x80008000);
  return iVar1;
}

