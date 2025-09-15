
void send_pic_cmd(uint8_t chain,uint8_t cmd,uint8_t len,uint8_t *crc,uint8_t *reply_buf,
                 uint8_t reply_len)

{
  uint8_t uVar1;
  uint8_t *crc_local;
  uint8_t len_local;
  uint8_t cmd_local;
  uint8_t chain_local;
  int i;
  
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  usleep(100000);
  write_pic_iic(chain,'U');
  write_pic_iic(chain,0xaa);
  write_pic_iic(chain,len);
  write_pic_iic(chain,cmd);
  write_pic_iic(chain,*crc);
  write_pic_iic(chain,crc[1]);
  usleep(400000);
  for (i = 0; i < (int)(uint)reply_len; i = i + 1) {
    uVar1 = read_pic_iic(chain);
    reply_buf[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return;
}

