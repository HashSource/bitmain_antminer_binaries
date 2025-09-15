
void _cg_memcpy(void *dest,void *src,uint n,char *file,char *func,int line)

{
  char *file_local;
  uint n_local;
  void *src_local;
  void *dest_local;
  char tmp42 [2048];
  
  if ((n == 0) || (0x80000000 < n)) {
    if ((use_syslog) || ((opt_log_output || (2 < opt_log_level)))) {
      snprintf(tmp42,0x800,"ERR: Asked to memcpy %u bytes from %s %s():%d",n,file,func,line);
      _applog(3,tmp42,false);
    }
  }
  else if (dest == (void *)0x0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"ERR: Asked to memcpy %u bytes to NULL from %s %s():%d",n,file,func,line)
      ;
      _applog(3,tmp42,false);
    }
  }
  else if (src == (void *)0x0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"ERR: Asked to memcpy %u bytes from NULL from %s %s():%d",n,file,func,
               line);
      _applog(3,tmp42,false);
    }
  }
  else {
    memcpy(dest,src,n);
  }
  return;
}

