
void enable_core_clock_BM1393(uchar core_id,uchar mode,uchar chain)

{
  uint uVar1;
  uchar chain_local;
  uchar mode_local;
  uchar core_id_local;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  buf[0] = 'A';
  if (mode != '\0') {
    buf[0] = 'Q';
  }
  buf[1] = '\t';
  buf[2] = '\0';
  buf[3] = '<';
  buf._4_2_ = (ushort)core_id << 8;
  buf._4_3_ = CONCAT12(0x84,buf._4_2_);
  buf[7] = 0xaa;
  buf[8] = CRC5(buf,'@');
  cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
               buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 | (uint)buf._0_4_ >> 0x18;
  cmd_buf[1] = ((uint)buf._4_4_ >> 0x10 & 0xff) << 8 |
               buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 | (uint)buf._4_4_ >> 0x18;
  cmd_buf[2] = (uint)buf[8] << 0x18;
  set_BC_command_buffer(cmd_buf);
  uVar1 = get_BC_write_command();
  set_BC_write_command(uVar1 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  usleep(5000);
  return;
}

