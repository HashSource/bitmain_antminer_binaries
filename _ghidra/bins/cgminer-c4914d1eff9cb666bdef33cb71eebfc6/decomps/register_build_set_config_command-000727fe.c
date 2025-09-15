
void register_build_set_config_command(set_config_t *set_cfg,uint8_t asic,core_command_t *core_cmd)

{
  byte bVar1;
  FILE *__stream;
  core_command_t *core_cmd_local;
  uint8_t asic_local;
  set_config_t *set_cfg_local;
  FILE *pFile;
  
  if ((set_cfg == (set_config_t *)0x0) || (core_cmd == (core_command_t *)0x0)) {
    if (3 < log_level) {
      print_crt_time_to_file(register_file_str,3);
      __stream = fopen(register_file_str,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Invalid parameter.\n","register.c",0xc0,
                "register_build_set_config_command");
      }
      fclose(__stream);
    }
  }
  else {
    memset(set_cfg,0,9);
    set_cfg->v[0] = set_cfg->v[0] & 0xf0 | 1;
    set_cfg->v[0] = set_cfg->v[0] & 0xef;
    set_cfg->v[0] = set_cfg->v[0] & 0x1f | 0x40;
    (set_cfg->u)._Length = '\t';
    (set_cfg->u)._ADDR = asic * dev->addrInterval;
    (set_cfg->u)._REGADDR = '<';
    (set_cfg->u)._REGDATA[0] = core_cmd->v[3];
    (set_cfg->u)._REGDATA[1] = (core_cmd->u)._CORE_ID;
    (set_cfg->u)._REGDATA[2] = core_cmd->v[1];
    (set_cfg->u)._REGDATA[3] = (core_cmd->u)._REG_WDATA;
    bVar1 = CRC5(set_cfg->v,'@');
    set_cfg->v[8] = set_cfg->v[8] & 0xe0 | bVar1 & 0x1f;
  }
  return;
}

