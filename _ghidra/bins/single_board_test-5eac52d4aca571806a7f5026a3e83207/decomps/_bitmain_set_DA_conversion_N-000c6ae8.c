
/* WARNING: Unknown calling convention */

int32_t _bitmain_set_DA_conversion_N(int32_t fd,uint8_t N)

{
  int32_t fd_00;
  uint uVar1;
  uint8_t N_00;
  uint8_t send_data [8];
  uint8_t read_back_data [8];
  
  send_data[5] = '\0';
  send_data[4] = N;
  send_data[6] = (uint8_t)(N + 0x89);
  send_data[7] = (uint8_t)(N + 0x89 >> 8);
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = 0x83;
  fd_00 = exec_power_cmd(fd,send_data,8,read_back_data,8);
  if (fd_00 == 0) {
    uVar1 = read_back_data._4_4_ & 0xffff;
  }
  else {
    uVar1 = _bitmain_set_DA_conversion_N(fd_00,N_00);
  }
  return uVar1;
}

