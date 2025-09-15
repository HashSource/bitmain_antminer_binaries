
_Bool _valid_ascii(char *s,char *file,char *func,int line)

{
  byte bVar1;
  size_t sVar2;
  int line_local;
  char *func_local;
  char *file_local;
  char *s_local;
  char tmp42 [2048];
  uchar idx;
  int len;
  _Bool ret;
  int i;
  
  ret = false;
  if (s == (char *)0x0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"Null string passed to valid_ascii from"," in %s %s():%d",file,func,line)
      ;
      _applog(3,tmp42,false);
    }
  }
  else {
    sVar2 = strlen(s);
    if (sVar2 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Zero length string passed to valid_ascii from"," in %s %s():%d",file,
                 func,line);
        _applog(3,tmp42,false);
      }
      ret = false;
    }
    else {
      for (i = 0; i < (int)sVar2; i = i + 1) {
        bVar1 = s[i];
        if ((bVar1 < 0x20) || (0x7e < bVar1)) {
          if ((use_syslog != false) || ((opt_log_output != false || (2 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Invalid char 0x%x passed to valid_ascii from"," in %s %s():%d",
                     (uint)bVar1,file,func,line);
            _applog(3,tmp42,false);
          }
          return false;
        }
      }
      ret = true;
    }
  }
  return ret;
}

