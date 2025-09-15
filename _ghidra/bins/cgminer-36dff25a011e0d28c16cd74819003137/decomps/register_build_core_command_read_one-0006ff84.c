
void register_build_core_command_read_one(core_command_t *core_cmd,uint32_t core_id,uint8_t reg)

{
  uint8_t reg_local;
  uint32_t core_id_local;
  core_command_t *core_cmd_local;
  
  memset(core_cmd,0,4);
  core_cmd->v[0] = 0xff;
  core_cmd->v[1] = core_cmd->v[1] & 0xf0 | reg & 0xf;
  core_cmd->v[1] = core_cmd->v[1] & 0xbf;
  core_cmd->v[1] = core_cmd->v[1] & 0x7f;
  *(ushort *)(core_cmd->v + 2) =
       *(ushort *)(core_cmd->v + 2) & 0xfe00 | (ushort)(((core_id >> 1) << 0x17) >> 0x17);
  core_cmd->v[3] = core_cmd->v[3] & 0x7f;
  return;
}

