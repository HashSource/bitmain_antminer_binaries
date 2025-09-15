
void register_build_core_command_write_all(core_command_t *core_cmd,uint8_t reg,uint8_t reg_data)

{
  uint8_t reg_data_local;
  uint8_t reg_local;
  core_command_t *core_cmd_local;
  
  memset(core_cmd,0,4);
  (core_cmd->u)._REG_WDATA = reg_data;
  core_cmd->v[1] = core_cmd->v[1] & 0xf8 | reg & 7;
  core_cmd->v[1] = core_cmd->v[1] & 0xbf;
  core_cmd->v[1] = core_cmd->v[1] | 0x80;
  (core_cmd->u)._CORE_ID = '\0';
  core_cmd->v[3] = core_cmd->v[3] | 0x80;
  return;
}

