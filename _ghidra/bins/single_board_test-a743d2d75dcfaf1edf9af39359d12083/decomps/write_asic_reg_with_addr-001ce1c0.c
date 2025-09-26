
/* WARNING: Unknown calling convention */

int32_t write_asic_reg_with_addr(uint8_t chain,uint32_t asic,uint32_t reg,uint32_t data)

{
  int32_t iVar1;
  char tmp42 [2048];
  
  iVar1 = set_register_cache_value(asic_cache_level,chain,asic,reg,data);
  if (iVar1 == 0) {
    iVar1 = send_set_config_command(chain,'\0',asic,reg,data);
    return iVar1;
  }
  snprintf(tmp42,0x800,"set_register_cache_value returns %d\n",iVar1);
  _applog(3,tmp42,false);
  return iVar1;
}

