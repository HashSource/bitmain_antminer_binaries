
void _cg_memcpy(void *param_1,void *param_2,size_t param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  char *__format;
  char acStack_818 [2052];
  
  if ((int)(param_3 - 1) < 0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return;
    }
    __format = "ERR: Asked to memcpy %u bytes from %s %s():%d";
  }
  else if (param_1 == (void *)0x0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return;
    }
    __format = "ERR: Asked to memcpy %u bytes to NULL from %s %s():%d";
  }
  else {
    if (param_2 != (void *)0x0) {
      memcpy(param_1,param_2,param_3);
      return;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return;
    }
    __format = "ERR: Asked to memcpy %u bytes from NULL from %s %s():%d";
  }
  snprintf(acStack_818,0x800,__format,param_3,param_4,param_5,param_6);
  _applog(3,acStack_818,0);
  return;
}

