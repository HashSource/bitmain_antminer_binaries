
/* WARNING: Unknown calling convention */

int32_t _bitmain_get_power_fw_version(int32_t fd)

{
  int32_t fd_00;
  uint uVar1;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  
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
  send_data[2] = '\x04';
  send_data[3] = '\x01';
  send_data[4] = '\x05';
  send_data[5] = '\0';
  fd_00 = exec_power_cmd(fd,send_data,6,read_back_data,8);
  if (fd_00 == 0) {
    uVar1 = read_back_data._4_4_ & 0xffff;
  }
  else {
    uVar1 = _bitmain_get_power_fw_version(fd_00);
  }
  return uVar1;
}

