
void register_build_core_command_read_one(core_command_t *core_cmd,uint8_t core_id,uint8_t reg)

{
  uint8_t reg_local;
  uint8_t core_id_local;
  core_command_t *core_cmd_local;
  
  memset(core_cmd,0,4);
  (core_cmd->u)._REG_WDATA = 0xff;
  core_cmd->v[1] = core_cmd->v[1] & 0xf8 | reg & 7;
  core_cmd->v[1] = core_cmd->v[1] & 0xbf;
  core_cmd->v[1] = core_cmd->v[1] & 0x7f;
  (core_cmd->u)._CORE_ID = core_id;
  core_cmd->v[3] = core_cmd->v[3] & 0x7f;
  return;
}

