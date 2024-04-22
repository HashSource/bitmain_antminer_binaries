
int write_dc_dc(void *args,uint8_t which_i2c,uint8_t i2c_dev_addr,uint8_t reg,uint8_t *data,int len)

{
  uchar uVar1;
  int iVar2;
  uint8_t reg_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  void *args_local;
  uint8_t send_data [16];
  uint8_t read_back_data [16];
  uint8_t crc_data [2];
  uint8_t length;
  uint8_t which_chain;
  int j;
  int i_1;
  uint8_t i;
  uint16_t crc;
  
                    /* WARNING: Load size is inaccurate */
  which_chain = *args;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[11] = '\0';
  read_back_data[12] = '\0';
  read_back_data[13] = '\0';
  read_back_data[14] = '\0';
  read_back_data[15] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  crc = 0;
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[11] = '\0';
  send_data[12] = '\0';
  send_data[13] = '\0';
  send_data[14] = '\0';
  send_data[15] = '\0';
  length = (char)len + '\x06';
  printf("%s dev addr = %02x\n","write_dc_dc",(uint)i2c_dev_addr);
  send_data[2] = length;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '2';
  send_data._4_2_ = CONCAT11(reg,i2c_dev_addr << 1);
  for (i_1 = 0; i_1 < len; i_1 = i_1 + 1) {
    send_data[i_1 + 6] = data[i_1];
  }
  for (j = 2; j < len + 6; j = j + 1) {
    crc = crc + send_data[j];
  }
  crc_data[1] = (uint8_t)crc;
  send_data[len + 6] = (uint8_t)(crc >> 8);
  send_data[len + 7] = crc_data[1];
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; (uint)i < length + 2; i = i + '\x01') {
    write_pic(which_i2c,which_chain,send_data[i]);
  }
  usleep(100000);
  memset(read_back_data,0,0x10);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[1] == '2') && (read_back_data[2] == '\x01')) {
    iVar2 = 0;
  }
  else {
    printf("--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n\n"
           ,"write_dc_dc",read_back_data._0_4_ & 0xff,(uint)read_back_data[1],
           (uint)read_back_data[2],(uint)read_back_data._0_4_ >> 0x18);
    iVar2 = -1;
  }
  return iVar2;
}

