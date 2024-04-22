
int makeup_set_config_cmd
              (uint8_t *str,uint32_t str_len,uint8_t all,uint8_t chip_addr,uint8_t regaddr,
              uint32_t regdata)

{
  byte bVar1;
  int iVar2;
  uint8_t chip_addr_local;
  uint8_t all_local;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  uint32_t swap_reg;
  set_config_cmd_t set_config_cmd;
  
  if (str_len < 0xb) {
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s input param error: str length = %u\n","makeup_set_config_cmd",0xb);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    memset(&set_config_cmd,0,9);
    set_config_cmd.length = '\t';
    set_config_cmd._0_1_ = (all & 1) << 4 | 0x41;
    set_config_cmd.chip_addr = chip_addr;
    set_config_cmd.regaddr = regaddr;
    set_config_cmd.regdata =
         (uint8_t  [4])
         (regdata << 0x18 | (regdata >> 8 & 0xff) << 0x10 | (regdata >> 0x10 & 0xff) << 8 |
         regdata >> 0x18);
    bVar1 = CRC5_v1((uchar *)&set_config_cmd,'@');
    *str = 'U';
    str[1] = 0xaa;
    *(undefined4 *)(str + 2) = set_config_cmd._0_4_;
    *(uint8_t (*) [4])(str + 6) = set_config_cmd.regdata;
    str[10] = set_config_cmd._8_1_ & 0xe0 | bVar1 & 0x1f;
    iVar2 = 0xb;
  }
  return iVar2;
}

