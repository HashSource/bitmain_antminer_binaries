
int makeup_get_status_cmd
              (uint8_t *str,uint32_t str_len,uint8_t all,uint8_t chip_addr,uint8_t regaddr)

{
  byte bVar1;
  int iVar2;
  uint8_t chip_addr_local;
  uint8_t all_local;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  get_status_cmd_t get_status_cmd;
  
  if (str_len < 7) {
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s input param error: str length = %u\n","makeup_get_status_cmd",7);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    memset(&get_status_cmd,0,5);
    get_status_cmd.length = '\x05';
    get_status_cmd._0_1_ = (all & 1) << 4 | 0x42;
    get_status_cmd.chip_addr = chip_addr;
    get_status_cmd.regaddr = regaddr;
    bVar1 = CRC5_v1((uchar *)&get_status_cmd,' ');
    *str = 'U';
    str[1] = 0xaa;
    *(undefined4 *)(str + 2) = get_status_cmd._0_4_;
    str[6] = get_status_cmd._4_1_ & 0xe0 | bVar1 & 0x1f;
    iVar2 = 7;
  }
  return iVar2;
}

