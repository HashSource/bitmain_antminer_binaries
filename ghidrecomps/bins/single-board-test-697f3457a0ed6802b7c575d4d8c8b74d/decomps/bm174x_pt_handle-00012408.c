
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
        tmp42[0] = s_open_failed_pattern_result_txt_0003401c[0];
        tmp42[1] = s_open_failed_pattern_result_txt_0003401c[1];
        tmp42[2] = s_open_failed_pattern_result_txt_0003401c[2];
        tmp42[3] = s_open_failed_pattern_result_txt_0003401c[3];
        tmp42[4] = s_open_failed_pattern_result_txt_0003401c[4];
        tmp42[5] = s_open_failed_pattern_result_txt_0003401c[5];
        tmp42[6] = s_open_failed_pattern_result_txt_0003401c[6];
        tmp42[7] = s_open_failed_pattern_result_txt_0003401c[7];
        tmp42[8] = s_open_failed_pattern_result_txt_0003401c[8];
        tmp42[9] = s_open_failed_pattern_result_txt_0003401c[9];
        tmp42[10] = s_open_failed_pattern_result_txt_0003401c[10];
        tmp42[11] = s_open_failed_pattern_result_txt_0003401c[11];
        tmp42[12] = s_open_failed_pattern_result_txt_0003401c[12];
        tmp42[13] = s_open_failed_pattern_result_txt_0003401c[13];
        tmp42[14] = s_open_failed_pattern_result_txt_0003401c[14];
        tmp42[15] = s_open_failed_pattern_result_txt_0003401c[15];
        tmp42[16] = s_open_failed_pattern_result_txt_0003401c[16];
        tmp42[17] = s_open_failed_pattern_result_txt_0003401c[17];
        tmp42[18] = s_open_failed_pattern_result_txt_0003401c[18];
        tmp42[19] = s_open_failed_pattern_result_txt_0003401c[19];
        tmp42[20] = s_open_failed_pattern_result_txt_0003401c[20];
        tmp42[21] = s_open_failed_pattern_result_txt_0003401c[21];
        tmp42[22] = s_open_failed_pattern_result_txt_0003401c[22];
        tmp42[23] = s_open_failed_pattern_result_txt_0003401c[23];
        tmp42[24] = s_open_failed_pattern_result_txt_0003401c[24];
        tmp42[25] = s_open_failed_pattern_result_txt_0003401c[25];
        tmp42[26] = s_open_failed_pattern_result_txt_0003401c[26];
        tmp42[27] = s_open_failed_pattern_result_txt_0003401c[27];
        tmp42[28] = s_open_failed_pattern_result_txt_0003401c[28];
        tmp42[29] = s_open_failed_pattern_result_txt_0003401c[29];
        tmp42[30] = s_open_failed_pattern_result_txt_0003401c[30];
        tmp42[31] = s_open_failed_pattern_result_txt_0003401c[31];
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

