
/* WARNING: Unknown calling convention */

void check_chain(void)

{
  int iVar1;
  char tmp42 [2048];
  int ret;
  int i;
  
  dev->chain_num = '\0';
  iVar1 = get_hash_on_plug();
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s: get_hash_on_plug is 0x%x\n","check_chain",iVar1);
    _applog(5,tmp42,false);
  }
  if (iVar1 < 0) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: get_hash_on_plug functions error\n");
      _applog(7,tmp42,false);
    }
  }
  else {
    for (i = 0; i < 0x10; i = i + 1) {
      if ((iVar1 >> (i & 0xffU) & 1U) == 0) {
        dev->chain_exist[i] = 0;
      }
      else {
        dev->chain_exist[i] = 1;
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"!!%s: chain[%d]is exist\n","check_chain",i);
          _applog(5,tmp42,false);
        }
        dev->chain_num = dev->chain_num + '\x01';
      }
    }
  }
  return;
}

