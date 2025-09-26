
/* WARNING: Unknown calling convention */

int32_t tsensor_close(uint32_t which_chain)

{
  uint32_t ctx;
  int32_t iVar1;
  uint uVar2;
  char tmp42 [2048];
  
  if (which_chain < 0x10) {
    uVar2 = 0;
    if (_g_tsensor_state[which_chain].num != '\0') {
      do {
        while (ctx = _g_tsensor_state[which_chain].bitmain_tsensor[uVar2].tsensor_fd, ctx == 0) {
          uVar2 = uVar2 + 1 & 0xff;
          if (_g_tsensor_state[which_chain].num <= uVar2) goto LAB_001cd0fa;
        }
        iic_uninit(ctx);
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < _g_tsensor_state[which_chain].num);
    }
LAB_001cd0fa:
    memset(_g_tsensor_state + which_chain,0,0x44);
    iVar1 = 0;
  }
  else {
    snprintf(tmp42,0x800," Bad T-sensor param, input chain is %d\n",which_chain);
    _applog(0,tmp42,false);
    iVar1 = -0x7ffff9ff;
  }
  return iVar1;
}

