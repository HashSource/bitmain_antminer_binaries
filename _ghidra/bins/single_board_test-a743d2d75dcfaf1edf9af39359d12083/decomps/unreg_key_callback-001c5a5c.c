
/* WARNING: Unknown calling convention */

int32_t unreg_key_callback(bitmain_key_callback function)

{
  int iVar1;
  _func_void_ui_type_e_bitmain_key_status_e **pp_Var2;
  int32_t iVar3;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  pp_Var2 = ui_callback;
  if (iVar1 == 0) {
    do {
      if (*pp_Var2 == function) {
        ui_callback[iVar1] = (_func_void_ui_type_e_bitmain_key_status_e *)0x0;
        goto LAB_001c5aaa;
      }
      iVar1 = iVar1 + 1;
      pp_Var2 = pp_Var2 + 1;
    } while (iVar1 != 5);
    builtin_strncpy(tmp42,"listener not registered before\n",0x20);
    _applog(1,tmp42,false);
LAB_001c5aaa:
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
    iVar3 = 0;
  }
  else {
    iVar3 = -1;
    builtin_strncpy(tmp42,"failed to api lock\n",0x14);
    _applog(0,tmp42,false);
  }
  return iVar3;
}

