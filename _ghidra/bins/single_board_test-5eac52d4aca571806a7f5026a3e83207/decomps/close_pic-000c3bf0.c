
/* WARNING: Unknown calling convention */

void close_pic(uint8_t which_chain)

{
  uint uVar1;
  char tmp42 [2048];
  
  uVar1 = (uint)which_chain;
  if (uVar1 < 0x10) {
    if ((g_bitmain_pic_state[uVar1].pic_fd != 0) ||
       (g_bitmain_pic_state[uVar1].chain_has_opened != 0)) {
      pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
      iic_uninit(g_bitmain_pic_state[uVar1].pic_fd);
      g_bitmain_pic_state[uVar1].chain_has_opened = 0;
      g_bitmain_pic_state[uVar1].pic_fd = 0;
      pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
    }
    return;
  }
  snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","close_pic",uVar1);
  _applog(0,tmp42,false);
  return;
}

