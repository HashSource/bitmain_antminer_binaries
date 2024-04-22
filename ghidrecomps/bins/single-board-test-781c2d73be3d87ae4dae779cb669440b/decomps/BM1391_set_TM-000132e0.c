
/* WARNING: Unknown calling convention */

void BM1391_set_TM(uchar which_chain,uchar asic_addr,uint tm,_Bool mode)

{
  uint uVar1;
  uint ret;
  uchar buf [9];
  uint cmd_buf [3];
  
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (mode) {
    buf[0] = 'Q';
  }
  else {
    buf[0] = 'A';
  }
  buf[1] = '\t';
  buf[2] = asic_addr;
  buf[3] = '\x14';
  buf._4_2_ = CONCAT11(bit_swap_table[tm >> 8 & 0xff],bit_swap_table[tm & 0xff]);
  buf._4_3_ = CONCAT12(bit_swap_table[tm >> 0x10 & 0xff],buf._4_2_);
  buf[7] = bit_swap_table[tm >> 0x18];
  buf[8] = CRC5(buf,'@');
  cmd_buf[2] = (uint)buf[8] << 0x18;
  cmd_buf[0] = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 | (uint)buf._0_4_ >> 0x18;
  cmd_buf[1] = buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._4_4_ >> 0x10 & 0xff) << 8 | (uint)buf._4_4_ >> 0x18;
  set_BC_command_buffer(cmd_buf);
  uVar1 = get_BC_write_command();
  set_BC_write_command(uVar1 & 0xfff0ffff | (uint)which_chain << 0x10 | 0x80800000);
  usleep(10000);
  return;
}

