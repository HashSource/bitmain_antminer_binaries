
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
    buf[2] = chip_addr;
    buf[0] = 'A';
    buf[1] = '\t';
    buf[3] = '\x1c';
    buf._4_2_ = CONCAT11(write | device,'\x01');
    buf._4_3_ = CONCAT12((uchar)reg,buf._4_2_);
    buf[7] = data;
    buf[8] = CRC5(buf,'@');
    cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                 buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 | (uint)buf._0_4_ >> 0x18
    ;
    cmd_buf[1] = ((uint)buf._4_4_ >> 0x10 & 0xff) << 8 |
                 buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 | (uint)buf._4_4_ >> 0x18
    ;
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

