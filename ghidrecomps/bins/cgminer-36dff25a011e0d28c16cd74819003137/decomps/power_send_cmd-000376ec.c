
_Bool power_send_cmd(uint8_t *cmd,uint8_t len,uint8_t *reply_buf,uint8_t reply_len)

{
  uint8_t uVar1;
  _Bool _Var2;
  FILE *__stream;
  uint8_t *reply_buf_local;
  uint8_t reply_len_local;
  uint8_t len_local;
  uint8_t *cmd_local;
  FILE *pFile;
  uint8_t reg_addr;
  uint8_t dev_addr;
  uint8_t which_iic;
  uint8_t retry;
  uint8_t i;
  
  retry = '\0';
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  while (retry < 3) {
    for (i = '\0'; i < len; i = i + '\x01') {
      znyq_set_iic('\x10','\x01',false,true,'\x11',cmd[i]);
    }
    usleep(500000);
    for (i = '\0'; i < reply_len; i = i + '\x01') {
      uVar1 = znyq_set_iic('\x10','\x01',true,false,'\x11','\0');
      reply_buf[i] = uVar1;
    }
    _Var2 = power_check_reply(cmd,reply_buf,reply_len);
    if (_Var2) break;
    retry = retry + 1;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: power send cmd 0x%02x failed, retry for %d times\n","power.c",
                0x12d,"power_send_cmd",(uint)cmd[3],(uint)retry);
      }
      fclose(__stream);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return retry < 3;
}

