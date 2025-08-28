
void equihash_miner_start(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  
  iVar1 = pthread_create(&p_miner,(pthread_attr_t *)0x0,(__start_routine *)0x15829,runtime);
  if (iVar1 == 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      builtin_strncpy(tmp42,"create mining mode thread successed\n",0x24);
      tmp42[0x24] = '\0';
      _applog(0,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    builtin_strncpy(tmp42,"create mining mode thread failed\n",0x22);
    _applog(0,tmp42,false);
  }
  return;
}

