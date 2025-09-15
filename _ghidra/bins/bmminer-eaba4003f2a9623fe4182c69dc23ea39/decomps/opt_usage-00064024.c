
char * opt_usage(char *argv0,char *extra)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *extra_local;
  char *argv0_local;
  char buf [84];
  uint num;
  char *ret;
  char *p;
  uint len;
  uint i;
  
  extra_local = extra;
  if (extra == (char *)0x0) {
    extra_local = "";
    for (i = 0; i < opt_count; i = i + 1) {
      if ((opt_table[i].cb == (_func_char_ptr_void_ptr *)0x631dd) &&
         (opt_table[i].u.carg != (void *)0x0)) {
        extra_local = (char *)opt_table[i].u.carg;
        break;
      }
    }
  }
  sVar1 = strlen(argv0);
  iVar6 = sVar1 + opt_num_short;
  sVar1 = strlen(extra_local);
  len = iVar6 + sVar1 + 0x14;
  for (i = 0; i < opt_count; i = i + 1) {
    if (opt_table[i].type == OPT_SUBTABLE) {
      sVar1 = strlen(opt_table[i].desc);
      len = sVar1 + len + 3;
    }
    else if (opt_table[i].desc != opt_hidden) {
      sVar1 = strlen(opt_table[i].names);
      sVar2 = strlen(opt_table[i].desc);
      iVar6 = sVar2 + sVar1 + len;
      len = iVar6 + 0x1b;
      if (opt_table[i].show != (_func_void_char_ptr_void_ptr *)0x0) {
        len = iVar6 + 0x7c;
      }
      len = len + 1;
    }
  }
  __s = (char *)malloc(len);
  if (__s == (char *)0x0) {
    __s = (char *)0x0;
  }
  else {
    iVar6 = sprintf(__s,"Usage: %s",argv0);
    p = __s + iVar6;
    builtin_strncpy(__s + iVar6," [-",4);
    uVar3 = write_short_options(p + 3);
    if (uVar3 != 0) {
      pcVar5 = p + 3 + uVar3;
      pcVar5[0] = ']';
      pcVar5[1] = '\0';
      p = pcVar5 + 1;
    }
    if (extra_local != (char *)0x0) {
      iVar6 = sprintf(p," %s",extra_local);
      p = p + iVar6;
    }
    p[0] = '\n';
    p[1] = '\0';
    p = p + 1;
    for (i = 0; i < opt_count; i = i + 1) {
      if (opt_table[i].desc != opt_hidden) {
        if (opt_table[i].type == OPT_SUBTABLE) {
          iVar6 = sprintf(p,"%s:\n",opt_table[i].desc);
          p = p + iVar6;
        }
        else {
          len = sprintf(p,"%s",opt_table[i].names);
          if (((opt_table[i].type == OPT_HASARG) &&
              (pcVar5 = strchr(opt_table[i].names,0x20), pcVar5 == (char *)0x0)) &&
             (pcVar5 = strchr(opt_table[i].names,0x3d), pcVar5 == (char *)0x0)) {
            builtin_strncpy(p + len," <arg>",7);
            len = len + 6;
          }
          if (len < 0x14) {
            iVar6 = 0x14 - len;
          }
          else {
            iVar6 = 1;
          }
          iVar6 = sprintf(p + len,"%.*s",iVar6,"                    ");
          iVar4 = sprintf(p + len + iVar6,"%s",opt_table[i].desc);
          len = len + iVar6 + iVar4;
          if (opt_table[i].show != (_func_void_char_ptr_void_ptr *)0x0) {
            builtin_strncpy(buf + 0x50,"...",4);
            (*opt_table[i].show)(buf,opt_table[i].u.carg);
            iVar6 = sprintf(p + len," (default: %s)",buf);
            len = len + iVar6;
          }
          pcVar5 = p + len;
          pcVar5[0] = '\n';
          pcVar5[1] = '\0';
          p = pcVar5 + 1;
        }
      }
    }
    *p = '\0';
  }
  return __s;
}

