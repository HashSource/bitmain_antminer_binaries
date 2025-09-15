
void set_misc_control(uchar chain,uchar mode,uchar addr,int i2c)

{
  int i2c_local;
  uchar addr_local;
  uchar mode_local;
  uchar chain_local;
  misc_ctrl_t misc_reg;
  
  if (i2c != 0) {
    misc_reg.v = gBM1391_MISC_CONTROL_reg & 0xffffff8f | 0x4030;
    gBM1391_MISC_CONTROL_reg = misc_reg.v;
  }
  send_set_config_command((uint)chain,mode,addr,'\x18',gBM1391_MISC_CONTROL_reg);
  return;
}

