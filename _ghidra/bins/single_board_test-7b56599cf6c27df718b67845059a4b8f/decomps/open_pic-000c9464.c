
/* WARNING: Unknown calling convention */

int32_t open_pic(uint8_t which_chain)

{
  uint uVar1;
  uint32_t uVar2;
  uint32_t extraout_r2;
  uint32_t uVar3;
  bitmain_pic_t *extraout_r3;
  bitmain_pic_t *pbVar4;
  iic_init_param_t param;
  
  uVar1 = (uint)which_chain;
  if (uVar1 < 0x10) {
    uVar2 = g_bitmain_pic_state[uVar1].pic_fd;
    if ((uVar2 == 0) || (g_bitmain_pic_state[uVar1].chain_has_opened == 0)) {
      param.master_addr = 0;
      param.slave_high = '\x04';
      param.chain_id = uVar1;
      param.slave_low = which_chain;
      pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
      uVar2 = iic_init(&param);
      pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
      uVar3 = extraout_r2;
      pbVar4 = extraout_r3;
      if (-1 < (int)uVar2) {
        pbVar4 = g_bitmain_pic_state + uVar1;
        g_bitmain_pic_state[uVar1].pic_fd = uVar2;
        uVar3 = 1;
      }
      if (-1 < (int)uVar2) {
        pbVar4->chain_has_opened = uVar3;
      }
    }
  }
  else {
    uVar2 = open_pic(which_chain);
  }
  return uVar2;
}

