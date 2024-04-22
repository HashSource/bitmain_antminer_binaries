
void read_temp(uchar device,uint reg,uchar data,uchar write,uchar chip_addr,int chain)

{
  uint uVar1;
  uint reg_local;
  uchar write_local;
  uchar data_local;
  uchar device_local;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  uint i;
  
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (opt_multi_version != 0) {
    buf[0] = 'A';
    buf[1] = '\t';
    buf[2] = chip_addr;
    buf[3] = '\x1c';
    buf[4] = '\x01';
    buf[5] = write | device;
    buf[6] = (uchar)reg;
    buf[7] = data;
    buf[8] = CRC5(buf,'@');
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    cmd_buf[1] = (uint)buf[7] | (uint)buf[4] << 0x18 | (uint)buf[5] << 0x10 | (uint)buf[6] << 8;
    cmd_buf[2] = (uint)buf[8] << 0x18;
    while( true ) {
      uVar1 = get_BC_write_command();
      if (-1 < (int)uVar1) break;
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(uVar1 & 0xfff0ffff | chain << 0x10 | 0x80800000);
  }
  return;
}

