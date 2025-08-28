
void bm174x_pt_handle(uint8_t *str,int len,uint8_t chainid)

{
  ushort uVar1;
  FILE *__stream;
  uint8_t chainid_local;
  int len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  FILE *fpt;
  uint16_t crc16;
  pattern_test_respond *pt;
  int i;
  
  uVar1 = CRC16_v1(str + 2,len + -4);
  uVar1 = uVar1 >> 8 | uVar1 << 8;
  if (uVar1 == *(ushort *)(str + 0x404)) {
    __stream = fopen("./pattern_result.txt","a+");
    if (__stream == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"open failed pattern_result.txt\n",0x20);
        _applog(2,tmp42,false);
      }
    }
    else {
      for (i = 0; i < 0x80; i = i + 1) {
        dump_str(__stream,(char *)0x0,str + i * 8 + 4,8);
      }
      fclose(__stream);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s chainid=%d cal crc = %04x, chip crc = %04x\n","bm174x_pt_handle",
             (uint)chainid,(uint)uVar1,(uint)*(ushort *)(str + 0x404));
    _applog(2,tmp42,false);
  }
  return;
}

