
void send_set_config_command
               (int chain,uint8_t mode,uint8_t chip_addr,uint8_t reg_addr,uint32_t reg_data)

{
  byte bVar1;
  uint8_t reg_addr_local;
  uint8_t chip_addr_local;
  uint8_t mode_local;
  int chain_local;
  uint bc_cmd [3];
  set_config_t set_cfg;
  FILE *pFile;
  uint value;
  uint origin;
  
  if (dev->chain_exist[chain] == 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile = (FILE *)fopen(log_file,"a+");
      if (pFile != (FILE *)0x0) {
        fprintf((FILE *)pFile,"%s:%d:%s: Chain %d not exist.\n","chip1391.c",0x2a,
                "send_set_config_command",chain);
      }
      fclose((FILE *)pFile);
    }
  }
  else {
    memset(&set_cfg,0,9);
    set_cfg.v[0] = (mode != '\0') << 4 | 0x41;
    set_cfg.u._Length = '\t';
    set_cfg.u._REGDATA[0] = (uint8_t)(reg_data >> 0x18);
    set_cfg.u._REGDATA[1] = (uint8_t)(reg_data >> 0x10);
    set_cfg.u._REGDATA[2] = (uint8_t)(reg_data >> 8);
    set_cfg.u._REGDATA[3] = (uint8_t)reg_data;
    set_cfg.u._ADDR = chip_addr;
    set_cfg.u._REGADDR = reg_addr;
    bVar1 = CRC5(set_cfg.v,'@');
    set_cfg.v[8] = set_cfg.v[8] & 0xe0 | bVar1 & 0x1f;
    memset(bc_cmd,0,0xc);
    bc_cmd[0] = (uint)set_cfg.v[0] << 0x18 | (uint)set_cfg.u._Length << 0x10 |
                (uint)set_cfg.u._ADDR << 8 | (uint)set_cfg.u._REGADDR;
    bc_cmd[1] = (uint)set_cfg.u._REGDATA[0] << 0x18 | (uint)set_cfg.u._REGDATA[1] << 0x10 |
                (uint)set_cfg.u._REGDATA[2] << 8 | (uint)set_cfg.u._REGDATA[3];
    bc_cmd[2] = (uint)set_cfg.v[8] << 0x18;
    set_BC_command_buffer(bc_cmd);
    origin = get_BC_write_command();
    value = chain << 0x10 | origin & 0xfff0ffff | 0x80800000;
    set_BC_write_command(value);
  }
  return;
}

