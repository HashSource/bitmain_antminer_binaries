
char * opt_usage(char *argv0,char *extra)

{
  undefined uVar1;
  size_t sVar2;
  size_t sVar3;
  char *__s;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  int iVar9;
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
      if ((opt_table[i].cb == opt_usage_and_exit) && (opt_table[i].u.carg != (void *)0x0)) {
        extra_local = (char *)opt_table[i].u.carg;
        break;
      }
    }
  }
  sVar2 = strlen(argv0);
  iVar9 = sVar2 + opt_num_short;
  sVar2 = strlen(extra_local);
  len = iVar9 + sVar2 + 0x14;
  for (i = 0; i < opt_count; i = i + 1) {
    if (opt_table[i].type == OPT_SUBTABLE) {
      sVar2 = strlen(opt_table[i].desc);
      len = sVar2 + len + 3;
    }
    else if ((undefined4 *)opt_table[i].desc != &opt_hidden) {
      sVar2 = strlen(opt_table[i].names);
      sVar3 = strlen(opt_table[i].desc);
      iVar9 = sVar3 + sVar2 + len;
      len = iVar9 + 0x1b;
      if (opt_table[i].show != (_func_void_char_ptr_void_ptr *)0x0) {
        len = iVar9 + 0x7c;
      }
      len = len + 1;
    }
  }
  __s = (char *)malloc(len);
  if (__s == (char *)0x0) {
    __s = (char *)0x0;
  }
  else {
    iVar9 = sprintf(__s,"Usage: %s",argv0);
    p = __s + iVar9;
    *(undefined4 *)p = DAT_000af0c8;
    uVar4 = write_short_options((char *)((int)p + 3));
    if (uVar4 != 0) {
      puVar7 = (undefined2 *)((char *)((int)p + 3) + uVar4);
      *puVar7 = DAT_000af0cc;
      p = (char *)((int)puVar7 + 1);
    }
    if (extra_local != (char *)0x0) {
      iVar9 = sprintf(p," %s",extra_local);
      p = p + iVar9;
    }
    *(undefined2 *)p = DAT_000af0d4;
    p = p + 1;
    for (i = 0; i < opt_count; i = i + 1) {
      if ((undefined4 *)opt_table[i].desc != &opt_hidden) {
        if (opt_table[i].type == OPT_SUBTABLE) {
          iVar9 = sprintf(p,"%s:\n",opt_table[i].desc);
          p = p + iVar9;
        }
        else {
          len = sprintf(p,"%s",opt_table[i].names);
          if (((opt_table[i].type == OPT_HASARG) &&
              (pcVar5 = strchr(opt_table[i].names,0x20), pcVar5 == (char *)0x0)) &&
             (pcVar5 = strchr(opt_table[i].names,0x3d), pcVar5 == (char *)0x0)) {
            puVar8 = (undefined4 *)(p + len);
            *puVar8 = DAT_000af0e4;
            uVar1 = DAT_000af0ea;
            *(undefined2 *)(puVar8 + 1) = DAT_000af0e8;
            *(undefined *)((int)puVar8 + 6) = uVar1;
            len = len + 6;
          }
          if (len < 0x14) {
            iVar9 = 0x14 - len;
          }
          else {
            iVar9 = 1;
          }
          iVar9 = sprintf(p + len,"%.*s",iVar9,"                    ");
          iVar6 = sprintf(p + len + iVar9,"%s",opt_table[i].desc);
          len = len + iVar9 + iVar6;
          if (opt_table[i].show != (_func_void_char_ptr_void_ptr *)0x0) {
            buf[80] = (char)DAT_000af10c;
            buf[81] = DAT_000af10c._1_1_;
            buf[82] = DAT_000af10c._2_1_;
            buf[83] = DAT_000af10c._3_1_;
            (*opt_table[i].show)(buf,opt_table[i].u.carg);
            iVar9 = sprintf(p + len," (default: %s)",buf);
            len = len + iVar9;
          }
          *(undefined2 *)(p + len) = DAT_000af0d4;
          p = (char *)((int)(p + len) + 1);
        }
      }
    }
    *p = '\0';
  }
  return __s;
}

