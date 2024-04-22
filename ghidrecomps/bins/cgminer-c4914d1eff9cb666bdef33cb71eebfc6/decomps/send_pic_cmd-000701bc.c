
void send_pic_cmd(uint8_t chain,uint8_t *cmd,uint8_t cmd_len,uint8_t *reply_buf,uint8_t reply_len)

{
  uint8_t uVar1;
  uint8_t *reply_buf_local;
  uint8_t *cmd_local;
  uint8_t cmd_len_local;
  uint8_t chain_local;
  uint8_t crc_data [2];
  uint16_t crc;
  int32_t i;
  
  crc = cmd_len + 3;
  for (i = 0; i < (int)(uint)cmd_len; i = i + 1) {
    crc = crc + cmd[i];
  }
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  write_pic_iic(chain,'U');
  write_pic_iic(chain,0xaa);
  write_pic_iic(chain,cmd_len + '\x03');
  for (i = 0; i < (int)(uint)cmd_len; i = i + 1) {
    write_pic_iic(chain,cmd[i]);
  }
  write_pic_iic(chain,(uint8_t)(crc >> 8));
  write_pic_iic(chain,(uint8_t)crc);
  usleep(550000);
  for (i = 0; i < (int)(uint)reply_len; i = i + 1) {
    uVar1 = read_pic_iic(chain);
    reply_buf[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return;
}

