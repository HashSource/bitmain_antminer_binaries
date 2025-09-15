
void btm_enable_one_corebyasic(uchar core_id,uchar mode,uchar chain,uchar chip_addr)

{
  byte bVar1;
  uint uVar2;
  uchar chip_addr_local;
  uchar chain_local;
  uchar mode_local;
  uchar core_id_local;
  uint cmd_buf [3];
  uchar buf [5];
  uint value;
  uint ret;
  
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  buf[0] = 'A';
  if (mode != '\0') {
    buf[0] = 'Q';
  }
  buf[1] = '\t';
  buf[3] = '<';
  buf[4] = '\0';
  buf[2] = chip_addr;
  bVar1 = CRC5(buf,'@');
  cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
  cmd_buf[1] = (uint)buf[4] << 0x18 | (uint)core_id << 0x10 | 0x84aa;
  cmd_buf[2] = (uint)bVar1 << 0x18;
  set_BC_command_buffer(cmd_buf);
  uVar2 = get_BC_write_command();
  set_BC_write_command(uVar2 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  usleep(5000);
  return;
}

