
/* WARNING: Unknown calling convention */

char * opt_set_bool_arg(char *arg,_Bool *b)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = strcasecmp(arg,DAT_0003aae4);
  if ((iVar1 == 0) || (iVar1 = strcasecmp(arg,DAT_0003aae8), iVar1 == 0)) {
    *b = true;
    return (char *)0x0;
  }
  iVar1 = strcasecmp(arg,DAT_0003aaec);
  if ((iVar1 != 0) && (iVar1 = strcasecmp(arg,DAT_0003aaf0), iVar1 != 0)) {
    pcVar2 = opt_invalid_argument(arg);
    return pcVar2;
  }
  *b = false;
  return (char *)0x0;
}

