
void bm174x_pm_handle(uint8_t *str,int len,uint8_t chainid)

{
  byte bVar1;
  uint8_t chainid_local;
  int len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  uint8_t crc5;
  pmonitor_respond *pm;
  
  bVar1 = CRC5_v1(str + 2,((char)len + -3) * '\b' + '\x03');
  if (bVar1 == (str[8] & 0x1f)) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"pmonitor[%02x] %02x %02x %02x %02x\n",(uint)str[7],(uint)str[3],
               (uint)str[4],(uint)str[5],(uint)str[6]);
      _applog(2,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s chain%d CRC error crc = %02x\n","bm174x_pm_handle",(uint)chainid,
             (uint)bVar1);
    _applog(0,tmp42,false);
  }
  return;
}

