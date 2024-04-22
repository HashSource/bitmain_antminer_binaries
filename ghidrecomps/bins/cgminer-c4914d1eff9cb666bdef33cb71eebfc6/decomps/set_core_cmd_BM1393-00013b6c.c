
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
    buf._4_2_ = CONCAT11(core->core_id,buf[4]);
    buf._4_3_ = CONCAT12(core->cmd_type | core->rw_falg << 7,buf._4_2_);
    buf[7] = (uchar)core->reg_data;
    buf[8] = '\0';
    buf[8] = CRC5(buf,'@');
    cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                 buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 | (uint)buf._0_4_ >> 0x18
    ;
    cmd_buf[1] = ((uint)buf._4_4_ >> 0x10 & 0xff) << 8 |
                 buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 | (uint)buf._4_4_ >> 0x18
    ;
    cmd_buf[2] = (uint)buf[8] << 0x18;
    set_BC_command_buffer(cmd_buf);
    uVar1 = get_BC_write_command();
    set_BC_write_command(uVar1 & 0xfff0ffff | (uint)core->chain << 0x10 | 0x80800000);
  }
  return;
}

