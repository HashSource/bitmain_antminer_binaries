
void set_sno(uint sno)

{
  uint uVar1;
  uint sno_local;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  uint i;
  
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (opt_multi_version != 0)) {
      buf[0] = 'Q';
      buf[1] = '\t';
      buf[2] = '\0';
      buf[3] = '\x10';
      buf._4_2_ = CONCAT11((uchar)(sno >> 0x10),(uchar)(sno >> 0x18));
      buf._4_3_ = CONCAT12((uchar)(sno >> 8),buf._4_2_);
      buf[7] = (uchar)sno;
      buf[8] = CRC5(buf,'@');
      cmd_buf[0] = (uint)buf._0_4_ >> 0x18 |
                   buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                   ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
      cmd_buf[1] = (uint)buf._4_4_ >> 0x18 |
                   buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 |
                   ((uint)buf._4_4_ >> 0x10 & 0xff) << 8;
      cmd_buf[2] = (uint)buf[8] << 0x18;
      set_BC_command_buffer(cmd_buf);
      uVar1 = get_BC_write_command();
      set_BC_write_command(uVar1 & 0xfff0ffff | i << 0x10 | 0x80800000);
    }
  }
  return;
}

