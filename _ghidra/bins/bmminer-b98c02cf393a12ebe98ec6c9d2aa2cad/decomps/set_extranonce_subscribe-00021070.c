
undefined4 set_extranonce_subscribe(void)

{
  undefined4 *puVar1;
  char acStack_808 [2048];
  
  total_extranonce = total_extranonce + 1;
  if (total_pools < total_extranonce) {
    add_pool();
  }
  puVar1 = *(undefined4 **)(pools + (total_extranonce + 0x3fffffff) * 4);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_808,0x800,"Enable extranonce subscribe on %d",*puVar1);
    _applog(7,acStack_808,0);
  }
  opt_set_bool(puVar1 + 0x91);
  return 0;
}

