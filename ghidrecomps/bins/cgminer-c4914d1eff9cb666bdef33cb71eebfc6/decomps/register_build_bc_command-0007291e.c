
void register_build_bc_command(uint32_t *bc_cmd,set_config_t *set_cfg)

{
  set_config_t *set_cfg_local;
  uint32_t *bc_cmd_local;
  
  memset(bc_cmd,0,0xc);
  *bc_cmd = (uint)(set_cfg->u)._ADDR << 8 |
            (uint)set_cfg->v[0] << 0x18 | (uint)(set_cfg->u)._Length << 0x10 |
            (uint)(set_cfg->u)._REGADDR;
  bc_cmd[1] = (uint)(set_cfg->u)._REGDATA[3] |
              (uint)(set_cfg->u)._REGDATA[2] << 8 |
              (uint)(set_cfg->u)._REGDATA[0] << 0x18 | (uint)(set_cfg->u)._REGDATA[1] << 0x10;
  bc_cmd[2] = (uint)set_cfg->v[8] << 0x18;
  return;
}

