
_Bool eeprom_set_freq(uint8_t chain,uint32_t *buf)

{
  _Bool _Var1;
  uint8_t *buf_00;
  uint8_t *buf_01;
  int iVar2;
  uint32_t *buf_local;
  uint8_t chain_local;
  uint8_t *receive_buf;
  uint8_t *send_buf;
  int i;
  _Bool ret;
  int try_time;
  
  try_time = 0;
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    _Var1 = false;
  }
  else {
    buf_00 = (uint8_t *)malloc(0x6c);
    if (buf_00 == (uint8_t *)0x0) {
      perror("fetal error: allocate memory failed!\n");
      _Var1 = false;
    }
    else {
      buf_01 = (uint8_t *)malloc(0x6c);
      if (buf_01 == (uint8_t *)0x0) {
        perror("fetal error: allocate memory failed!\n");
        _Var1 = false;
      }
      else {
        for (i = 0; i < 0x6c; i = i + 1) {
          buf_00[i] = (char)buf[i] + '8';
        }
        while( true ) {
          pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
          eeprom_write_bytes('\x02',buf_00,chain,'l');
          usleep(10000);
          eeprom_read_bytes('\x02',buf_01,chain,'l');
          pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
          iVar2 = memcmp(buf,buf_01,0x6c);
          if (iVar2 == 0) break;
          if (try_time == 2) {
            ret = false;
            goto LAB_00011a86;
          }
          try_time = try_time + 1;
        }
        ret = true;
LAB_00011a86:
        if (buf_01 != (uint8_t *)0x0) {
          free(buf_01);
        }
        if (buf_00 != (uint8_t *)0x0) {
          free(buf_00);
        }
        _Var1 = eeprom_update_crc(chain);
        _Var1 = (_Var1 & ret) != 0;
      }
    }
  }
  return _Var1;
}

