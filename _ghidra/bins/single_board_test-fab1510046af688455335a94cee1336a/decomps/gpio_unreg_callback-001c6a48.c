
/* WARNING: Unknown calling convention */

int32_t gpio_unreg_callback(uint32_t port,bitmain_gpio_callback function)

{
  undefined4 uVar1;
  int iVar2;
  clib_bool cVar3;
  int32_t iVar4;
  uint32_t local_814;
  char tmp42 [2048];
  
  local_814 = port;
  if (function == (bitmain_gpio_callback)0x0) {
    iVar4 = -1;
    builtin_strncpy(tmp42,"bad para",8);
    tmp42[8] = 'm';
    tmp42[9] = '\n';
    tmp42[10] = '\0';
    _applog(0,tmp42,false);
  }
  else {
    iVar2 = pthread_mutex_lock((pthread_mutex_t *)&gpio_ctrl_map);
    uVar1 = tmp42._28_4_;
    if (iVar2 == 0) {
      cVar3 = exists_c_map(gpio_ctrl_map.gpio_callback_map,&local_814);
      if (cVar3 == 1) {
        remove_c_map(gpio_ctrl_map.gpio_callback_map,&local_814);
      }
      else {
        builtin_strncpy(tmp42,"callback function not registered before\n",0x28);
        tmp42[0x28] = '\0';
        _applog(1,tmp42,false);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&gpio_ctrl_map);
      iVar4 = 0;
    }
    else {
      iVar4 = -1;
      builtin_strncpy(tmp42,"fail to lock gpio ctrl mutex\n",0x1e);
      tmp42._30_2_ = SUB42(uVar1,2);
      _applog(0,tmp42,false);
    }
  }
  return iVar4;
}

