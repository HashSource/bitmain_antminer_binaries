
void set_core_cmd_BM1393(core_cmd *core)

{
  uint uVar1;
  core_cmd *core_local;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (core != (core_cmd *)0x0) {
    buf[0] = 'A';
    if (core->mode != '\0') {
      buf[0] = 'Q';
    }
    buf[1] = '\t';
    buf[2] = core->chip_addr;
    buf[3] = '<';
    buf[4] = '\0';
    if (core->core_mode != '\0') {
      buf[4] = 0x80;
    }
    buf[5] = core->core_id;
    buf[6] = core->cmd_type | (byte)((core->rw_falg & 1) << 7);
    buf[7] = (uchar)core->reg_data;
    buf[8] = '\0';
    buf[8] = CRC5(buf,'@');
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    cmd_buf[1] = (uint)buf[7] | (uint)buf[4] << 0x18 | (uint)buf[5] << 0x10 | (uint)buf[6] << 8;
    cmd_buf[2] = (uint)buf[8] << 0x18;
    set_BC_command_buffer(cmd_buf);
    uVar1 = get_BC_write_command();
    set_BC_write_command(uVar1 & 0xfff0ffff | (uint)core->chain << 0x10 | 0x80800000);
  }
  return;
}

