
void register_send_core_cmd_write_all(int chain,uint8_t asic,uint8_t core_reg,uint8_t core_reg_data)

{
  uint8_t core_reg_data_local;
  uint8_t core_reg_local;
  uint8_t asic_local;
  int chain_local;
  uint32_t bc_cmd [3];
  set_config_t set_cfg;
  core_command_t core_cmd;
  uint32_t value;
  uint32_t origin;
  
  clear_register_value_buf();
  register_build_core_command_write_all(&core_cmd,core_reg,core_reg_data);
  register_build_set_config_command(&set_cfg,asic,&core_cmd);
  register_build_bc_command(bc_cmd,&set_cfg);
  set_BC_command_buffer(bc_cmd);
  origin = get_BC_write_command();
  value = origin & 0xfff0ffff | chain << 0x10 | 0x80800000;
  set_BC_write_command(value);
  return;
}

