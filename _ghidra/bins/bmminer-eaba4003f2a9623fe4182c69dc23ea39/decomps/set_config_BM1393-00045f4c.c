
void set_config_BM1393(uchar which_chain,uchar chip_addr,uchar mode,uchar reg,uint reg_data)

{
  uint uVar1;
  uchar reg_local;
  uchar mode_local;
  uchar chip_addr_local;
  uchar which_chain_local;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (mode == '\0') {
    buf[0] = 'A';
  }
  else {
    buf[0] = 'Q';
  }
  buf[1] = '\t';
  buf[4] = (uchar)(reg_data >> 0x18);
  buf[5] = (uchar)(reg_data >> 0x10);
  buf[6] = (uchar)(reg_data >> 8);
  buf[7] = (uchar)reg_data;
  buf[2] = chip_addr;
  buf[3] = reg;
  buf[8] = CRC5(buf,'@');
  cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
  cmd_buf[1] = (uint)buf[7] | (uint)buf[4] << 0x18 | (uint)buf[5] << 0x10 | (uint)buf[6] << 8;
  cmd_buf[2] = (uint)buf[8] << 0x18;
  set_BC_command_buffer_t(cmd_buf);
  uVar1 = get_BC_write_command();
  set_BC_write_command(uVar1 & 0xfff0ffff | (uint)which_chain << 0x10 | 0x80800000);
  return;
}

