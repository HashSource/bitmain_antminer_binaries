
_Bool _valid_hex(char *s,char *file,char *func,int line)

{
  size_t sVar1;
  size_t sVar2;
  uint uVar3;
  char tmp42 [2048];
  
  if (s == (char *)0x0) {
    if (((!use_syslog) && (!opt_log_output)) && (opt_log_level < 3)) {
      return opt_log_output;
    }
    snprintf(tmp42,0x800,"Null string passed to valid_hex from"," in %s %s():%d","util.c",file,func)
    ;
  }
  else {
    sVar1 = strlen(s);
    if ((int)sVar1 < 1) {
      return true;
    }
    uVar3 = (uint)(byte)*s;
    if (-1 < hex2bin_tbl[uVar3]) {
      sVar2 = 0;
      do {
        sVar2 = sVar2 + 1;
        if (sVar1 == sVar2) {
          return true;
        }
        s = (char *)((byte *)s + 1);
        uVar3 = (uint)(byte)*s;
      } while (-1 < hex2bin_tbl[uVar3]);
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
      return false;
    }
    snprintf(tmp42,0x800,"Invalid char 0x%x passed to valid_hex from"," in %s %s():%d",uVar3,
             "util.c",file,func);
  }
  _applog(3,tmp42,false);
  return false;
}

