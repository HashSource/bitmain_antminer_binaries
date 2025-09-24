
/* WARNING: Unknown calling convention */

int32_t reg_key_callback(bitmain_key_callback function)

{
  int iVar1;
  uint32_t uVar2;
  _func_void_ui_type_e_bitmain_key_status_e **pp_Var3;
  int32_t iVar4;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  if (iVar1 == 0) {
    if (reg_key_callback::reged == 0) {
      uVar2 = convert_ui_type_to_port(RESET_KEY);
      gpio_reg_callback(uVar2,(bitmain_gpio_callback)0xc6bb1);
      uVar2 = convert_ui_type_to_port(IP_REPORT_KEY);
      gpio_reg_callback(uVar2,(bitmain_gpio_callback)0xc6bb1);
      reg_key_callback::reged = 1;
    }
    iVar1 = 0;
    pp_Var3 = ui_callback;
    do {
      if (*pp_Var3 == (_func_void_ui_type_e_bitmain_key_status_e *)0x0) {
        ui_callback[iVar1] = function;
        iVar4 = 0;
        goto LAB_000c6e5a;
      }
      iVar1 = iVar1 + 1;
      pp_Var3 = pp_Var3 + 1;
    } while (iVar1 != 5);
    iVar4 = -2;
    builtin_strncpy(tmp42,"no more listener available\n",0x1c);
    _applog(0,tmp42,false);
LAB_000c6e5a:
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
  }
  else {
    builtin_strncpy(tmp42,"failed to api lock\n",0x14);
    _applog(0,tmp42,false);
    iVar4 = -1;
  }
  return iVar4;
}

