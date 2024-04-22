
void set_core_cmd_BM1391(core_cmd *core)

{
  core_command_t cVar1;
  core_cmd *core_local;
  core_command_t core_cmd;
  
  memset(&core_cmd,0,4);
  core_cmd.v_32._0_2_ = CONCAT11(core_cmd.v[1] & 0xf0 | core->cmd_type & 0xf,(char)core->reg_data);
  core_cmd.v_32 = CONCAT22(core_cmd.v_32._2_2_,core_cmd.v_32._0_2_) & 0xffffbfff;
  core_cmd.v[1] = core_cmd.v[1] & 0x7f | (byte)((core->rw_falg & 1) << 7);
  core_cmd.v_32._2_2_ = core_cmd.v_32._2_2_ & 0xfe00 | (ushort)((core->core_id << 0x17) >> 0x17);
  cVar1 = core_cmd;
  core_cmd.v[3] = (uint8_t)((ushort)core_cmd.v_32._2_2_ >> 8);
  core_cmd.v_32._0_3_ = (undefined3)cVar1.v_32;
  core_cmd.v[3] = core_cmd.v[3] & 0x7f | (core->mode != '\0') << 7;
  send_set_config_command((uint)core->chain,core->mode,core->chip_addr,'<',core_cmd.v_32);
  return;
}

