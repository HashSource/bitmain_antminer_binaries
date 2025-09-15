
/* WARNING: Unknown calling convention */

char * opt_set_bool_arg(char *arg,_Bool *b)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = strcasecmp(arg,"yes");
  if ((iVar1 == 0) || (iVar1 = strcasecmp(arg,"true"), iVar1 == 0)) {
    *b = true;
    return (char *)0x0;
  }
  iVar1 = strcasecmp(arg,"no");
  if ((iVar1 != 0) && (iVar1 = strcasecmp(arg,"false"), iVar1 != 0)) {
    pcVar2 = opt_invalid_argument(arg);
    return pcVar2;
  }
  *b = false;
  return (char *)0x0;
}

