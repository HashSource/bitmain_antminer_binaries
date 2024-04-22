
void set_config_BM1393_t(uchar which_chain,uchar chip_addr,uchar mode,uchar reg,uint reg_data)

{
  uint uVar1;
  uchar reg_local;
  uchar mode_local;
  uchar chip_addr_local;
  uchar which_chain_local;
  uint cmd_buf [8];
  uchar buf [9];
  uint value;
  uint ret;
  
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  memset(cmd_buf,0,0x20);
  if (mode == '\0') {
    buf[0] = 'A';
  }
  else {
    buf[0] = 'Q';
  }
  buf[1] = '\t';
  buf[2] = chip_addr;
  buf[3] = reg;
  buf._4_2_ = CONCAT11((uchar)(reg_data >> 0x10),(uchar)(reg_data >> 0x18));
  buf._4_3_ = CONCAT12((uchar)(reg_data >> 8),buf._4_2_);
  buf[7] = (uchar)reg_data;
  if (reg == '\x14') {
    cmd_buf[7] = (uint)bit_swap_table[20];
  }
  buf[8] = CRC5(buf,'@');
  cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
               buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 | (uint)buf._0_4_ >> 0x18;
  cmd_buf[1] = ((uint)buf._4_4_ >> 0x10 & 0xff) << 8 |
               buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 | (uint)buf._4_4_ >> 0x18;
  cmd_buf[2] = (uint)buf[8] << 0x18;
  set_BC_command_buffer_t(cmd_buf);
  uVar1 = get_BC_write_command();
  set_BC_write_command_t(uVar1 & 0xfff0ffff | (uint)which_chain << 0x10 | 0x80800000);
  return;
}

