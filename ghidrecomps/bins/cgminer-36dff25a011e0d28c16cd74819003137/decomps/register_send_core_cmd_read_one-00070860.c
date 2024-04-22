
void register_send_core_cmd_read_one(int chain,uint8_t asic,uint32_t core_id,uint8_t core_reg)

{
  uint32_t core_id_local;
  uint8_t core_reg_local;
  uint8_t asic_local;
  int chain_local;
  uint bc_cmd [3];
  set_config_t set_cfg;
  core_command_t core_cmd;
  uint value;
  uint origin;
  
  clear_register_value_buf();
  register_build_core_command_read_one(&core_cmd,core_id,core_reg);
  register_build_set_config_command(&set_cfg,asic,&core_cmd);
  register_build_bc_command(bc_cmd,set_cfg.v,9);
  set_BC_command_buffer(bc_cmd);
  origin = get_BC_write_command();
  value = chain << 0x10 | origin & 0xfff0ffff | 0x80800000;
  set_BC_write_command(value);
  return;
}

