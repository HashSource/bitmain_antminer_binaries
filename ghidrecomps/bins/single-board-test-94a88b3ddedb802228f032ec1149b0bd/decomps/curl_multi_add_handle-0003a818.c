
undefined4 curl_multi_add_handle(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0xbab1e)) {
    return 1;
  }
  if ((param_2 != (undefined4 *)0x0) && (param_2[0x21e7] == -0x3f212453)) {
    if (param_2[0x10] != 0) {
      return 7;
    }
    iVar1 = Curl_llist_alloc(DAT_0003a8f0);
    if (iVar1 != 0) {
      param_2[0x219b] = iVar1;
      mstate(param_2,0);
      if ((*(char *)((int)param_2 + 0x325) == '\0') || (param_2[0xf] == 1)) {
        if ((param_2[0xe] == 0) || (param_2[0xf] == 0)) {
          param_2[0xe] = param_1 + 0xb;
          param_2[0xf] = 2;
        }
      }
      else {
        iVar1 = Curl_global_host_cache_init();
        if (iVar1 != 0) {
          param_2[0xe] = iVar1;
          param_2[0xf] = 1;
        }
      }
      iVar1 = param_1[1];
      param_2[0x160] = param_1 + 0x1a;
      *param_2 = 0;
      if (iVar1 == 0) {
        param_2[1] = 0;
        param_1[1] = (int)param_2;
        param_1[2] = (int)param_2;
      }
      else {
        puVar2 = (undefined4 *)param_1[2];
        *puVar2 = param_2;
        param_2[1] = puVar2;
        param_1[2] = (int)param_2;
      }
      param_2[0x10] = param_1;
      Curl_expire(param_2,1);
      param_1[3] = param_1[3] + 1;
      param_1[4] = param_1[4] + 1;
      memset(param_1 + 0x2f,0,8);
      update_timer(param_1);
      return 0;
    }
    return 3;
  }
  return 2;
}

