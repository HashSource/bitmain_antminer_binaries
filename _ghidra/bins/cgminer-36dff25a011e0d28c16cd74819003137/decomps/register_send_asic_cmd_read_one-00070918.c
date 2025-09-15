
void register_send_asic_cmd_read_one(int chain,uint8_t asic,uint8_t asic_reg)

{
  uint8_t asic_reg_local;
  uint8_t asic_local;
  int chain_local;
  uint bc_cmd [3];
  get_status_t get_st;
  uint value;
  uint origin;
  
  clear_register_value_buf();
  register_build_get_status_command(&get_st,asic,asic_reg);
  register_build_bc_command(bc_cmd,get_st.v,5);
  set_BC_command_buffer(bc_cmd);
  origin = get_BC_write_command();
  value = chain << 0x10 | origin & 0xfff0ffff | 0x80800000;
  set_BC_write_command(value);
  return;
}

