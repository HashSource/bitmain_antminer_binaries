
int makeup_set_address_cmd(uint8_t *str,uint32_t str_len,uint8_t chip_addr)

{
  byte bVar1;
  int iVar2;
  uint8_t chip_addr_local;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  set_address_cmd_t set_address_cmd;
  
  if (str_len < 7) {
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s input param error: str length = %u\n","makeup_set_address_cmd",7);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    memset(&set_address_cmd,0,5);
    set_address_cmd.chip_addr = chip_addr;
    set_address_cmd._0_2_ = 0x540;
    bVar1 = CRC5_v1((uchar *)&set_address_cmd,' ');
    *str = 'U';
    str[1] = 0xaa;
    *(undefined4 *)(str + 2) = set_address_cmd._0_4_;
    str[6] = set_address_cmd._4_1_ & 0xe0 | bVar1 & 0x1f;
    iVar2 = 7;
  }
  return iVar2;
}

