
/* WARNING: Unknown calling convention */

void _cg_memcpy(void *dest,void *src,uint n,char *file,char *func,int line)

{
  char *__format;
  char tmp42 [2048];
  
  if ((int)(n - 1) < 0) {
    if (((!use_syslog) && (!opt_log_output)) && (opt_log_level < 3)) {
      return;
    }
    __format = "ERR: Asked to memcpy %u bytes from %s %s():%d";
  }
  else if (dest == (void *)0x0) {
    if (((!use_syslog) && (!opt_log_output)) && (opt_log_level < 3)) {
      return;
    }
    __format = "ERR: Asked to memcpy %u bytes to NULL from %s %s():%d";
  }
  else {
    if (src != (void *)0x0) {
      (*(code *)(undefined *)0x0)();
      return;
    }
    if (((!use_syslog) && (!opt_log_output)) && (opt_log_level < 3)) {
      return;
    }
    __format = "ERR: Asked to memcpy %u bytes from NULL from %s %s():%d";
  }
  snprintf(tmp42,0x800,__format,n,file,func,line);
  _applog(3,tmp42,false);
  return;
}

