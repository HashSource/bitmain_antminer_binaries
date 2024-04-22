
/* WARNING: Unknown calling convention */

_Bool power_send_cmd(uint8_t *cmd,uint8_t len,uint8_t *reply_buf,uint8_t reply_len)

{
  uchar uVar1;
  _Bool _Var2;
  byte *pbVar3;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  iVar5 = 1;
  do {
    if (len != '\0') {
      pbVar3 = cmd + -1;
      do {
        pbVar3 = pbVar3 + 1;
        i2c_write(*pbVar3 | 0x5201100);
      } while (pbVar3 != cmd + (byte)(len - 1));
    }
    puVar4 = reply_buf + -1;
    usleep(500000);
    if (reply_len != '\0') {
      do {
        uVar1 = i2c_read(0x4200000);
        puVar4 = puVar4 + 1;
        *puVar4 = uVar1;
      } while (puVar4 != reply_buf + (byte)(reply_len - 1));
    }
    _Var2 = power_check_reply(cmd,reply_buf,reply_len);
    if (_Var2) break;
    iVar6 = iVar5 + 1;
    printf("power send cmd 0x%02x failed, retry for %d times\n",(uint)cmd[3],iVar5);
    iVar5 = iVar6;
  } while (iVar6 != 4);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  return _Var2;
}

