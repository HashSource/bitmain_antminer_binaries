
/* WARNING: Unknown calling convention */

int32_t _bitmain_get_power_status_32bits(int32_t fd)

{
  int32_t fd_00;
  uint uVar1;
  uint8_t send_data [6];
  uint8_t read_back_data [14];
  
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[0xb] = '\0';
  read_back_data[0xc] = '\0';
  read_back_data[0xd] = '\0';
  send_data[4] = '\x0e';
  send_data[5] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\n';
  fd_00 = exec_power_cmd(fd,send_data,6,read_back_data,0xe);
  if (fd_00 == 0) {
    uVar1 = ((uint)read_back_data._4_4_ >> 8 & 0xff) << 8 | read_back_data._4_4_ & 0xff000000 |
            read_back_data._4_4_ & 0xff | ((uint)read_back_data._4_4_ >> 0x10 & 0xff) << 0x10;
  }
  else {
    uVar1 = _bitmain_get_power_status_32bits(fd_00);
  }
  return uVar1;
}

