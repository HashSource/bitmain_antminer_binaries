
void set_general_i2c(uchar chain,uchar chip_addr,int bottom_or_mid,uchar reg,uchar device,uchar data
                    ,uchar write)

{
  uint uVar1;
  uchar uVar2;
  int bottom_or_mid_local;
  uchar reg_local;
  uchar chip_addr_local;
  uchar chain_local;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  buf[2] = chip_addr;
  buf[0] = 'A';
  buf[1] = '\t';
  buf[3] = '\x1c';
  uVar2 = '\x01';
  if (bottom_or_mid == 1) {
    uVar2 = '\x05';
  }
  buf._4_2_ = CONCAT11(write | device,uVar2);
  buf._4_3_ = CONCAT12(reg,buf._4_2_);
  buf[7] = data;
  buf[8] = CRC5(buf,'@');
  cmd_buf[0] = (uint)buf._0_4_ >> 0x18 |
               buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
  cmd_buf[1] = (uint)buf._4_4_ >> 0x18 |
               buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._4_4_ >> 0x10 & 0xff) << 8;
  cmd_buf[2] = (uint)buf[8] << 0x18;
  while( true ) {
    uVar1 = get_BC_write_command();
    if (-1 < (int)uVar1) break;
    cgsleep_ms(1);
  }
  set_BC_command_buffer(cmd_buf);
  set_BC_write_command(uVar1 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  return;
}

