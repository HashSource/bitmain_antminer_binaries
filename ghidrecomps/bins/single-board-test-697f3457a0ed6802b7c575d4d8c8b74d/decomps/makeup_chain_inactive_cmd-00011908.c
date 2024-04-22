
int makeup_chain_inactive_cmd(uint8_t *str,uint32_t str_len)

{
  byte bVar1;
  int iVar2;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  chain_inactive_cmd_t chain_inactive_cmd;
  
  if (str_len < 7) {
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s input param error: str length = %u\n","makeup_chain_inactive_cmd",7);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    memset(&chain_inactive_cmd,0,5);
    chain_inactive_cmd._0_2_ = 0x553;
    bVar1 = CRC5_v1((uchar *)&chain_inactive_cmd,' ');
    *str = 'U';
    str[1] = 0xaa;
    *(undefined4 *)(str + 2) = chain_inactive_cmd._0_4_;
    str[6] = chain_inactive_cmd._4_1_ & 0xe0 | bVar1 & 0x1f;
    iVar2 = 7;
  }
  return iVar2;
}

