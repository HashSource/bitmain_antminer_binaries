
void set_core_number_BM1390(uchar which_chain,uchar chip_addr)

{
  uint uVar1;
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
  buf[0] = 'A';
  buf[1] = '\t';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\x13';
  buf[5] = 0x93;
  buf[6] = 0xd0;
  buf[7] = chip_addr;
  buf[8] = CRC5(buf,'@');
  cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
  cmd_buf[1] = (uint)buf[7] | (uint)buf[4] << 0x18 | (uint)buf[5] << 0x10 | (uint)buf[6] << 8;
  cmd_buf[2] = (uint)buf[8] << 0x18;
  set_BC_command_buffer(cmd_buf);
  uVar1 = get_BC_write_command();
  set_BC_write_command(uVar1 & 0xfff0ffff | (uint)which_chain << 0x10 | 0x80800000);
  return;
}

