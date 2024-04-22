
void register_build_bc_command(uint32_t *bc_cmd,uint8_t *cmd,int len)

{
  int len_local;
  uint8_t *cmd_local;
  uint32_t *bc_cmd_local;
  int i;
  
  memset(bc_cmd,0,0xc);
  memcpy(bc_cmd,cmd,len);
  for (i = 0; i < 3; i = i + 1) {
    bc_cmd[i] = bc_cmd[i] << 0x18 | (bc_cmd[i] & 0xff00) << 8 | bc_cmd[i] >> 8 & 0xff00 |
                bc_cmd[i] >> 0x18;
  }
  return;
}

