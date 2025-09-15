
_Bool power_check_reply(uint8_t *cmd,uint8_t *reply_buf,uint8_t reply_len)

{
  ushort uVar1;
  FILE *pFVar2;
  _Bool _Var3;
  uint8_t reply_len_local;
  uint8_t *reply_buf_local;
  uint8_t *cmd_local;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  FILE *pFile_4;
  FILE *pFile_5;
  FILE *pFile_3;
  uint16_t pay_load_len;
  uint16_t crc_reply;
  uint16_t i;
  uint16_t crc;
  
  crc = 0;
  if ((((*cmd == *reply_buf) && (cmd[1] == reply_buf[1])) && (cmd[3] == reply_buf[3])) &&
     (reply_buf[2] + 2 == (uint)reply_len)) {
    for (i = 2; (int)(uint)i < (int)(reply_len - 2); i = i + 1) {
      crc = reply_buf[i] + crc;
    }
    uVar1 = (ushort)reply_buf[reply_len - 1] * 0x100 + (ushort)reply_buf[reply_len - 2];
    if (crc == uVar1) {
      _Var3 = true;
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: power reply crc error, crc %04x != crc_reply %04x:\n","power.c",
                  0x10a,"power_check_reply",(uint)crc,(uint)uVar1);
        }
        fclose(pFVar2);
      }
      for (i = 0; i < reply_len; i = i + 1) {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%02x ",(uint)reply_buf[i]);
          }
          fclose(pFVar2);
        }
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fputc(10,pFVar2);
        }
        fclose(pFVar2);
      }
      _Var3 = false;
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: power reply data error:\n","power.c",0xfa,"power_check_reply");
      }
      fclose(pFVar2);
    }
    for (i = 0; i < reply_len; i = i + 1) {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%02x ",(uint)reply_buf[i]);
        }
        fclose(pFVar2);
      }
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fputc(10,pFVar2);
      }
      fclose(pFVar2);
    }
    _Var3 = false;
  }
  return _Var3;
}

