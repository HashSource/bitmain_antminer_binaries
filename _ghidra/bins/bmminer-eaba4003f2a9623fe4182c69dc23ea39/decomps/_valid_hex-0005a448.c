
_Bool _valid_hex(char *s,char *file,char *func,int line)

{
  size_t sVar1;
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
      snprintf(tmp42,0x800,"Null string passed to valid_hex from"," in %s %s():%d",file,func,line);
      _applog(3,tmp42,false);
    }
  }
  else {
    sVar1 = strlen(s);
    for (i = 0; i < (int)sVar1; i = i + 1) {
      if (hex2bin_tbl[(byte)s[i]] < 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42,0x800,"Invalid char 0x%x passed to valid_hex from"," in %s %s():%d",
                   (uint)(byte)s[i],file,func,line);
          _applog(3,tmp42,false);
        }
        return false;
      }
    }
    ret = true;
  }
  return ret;
}

