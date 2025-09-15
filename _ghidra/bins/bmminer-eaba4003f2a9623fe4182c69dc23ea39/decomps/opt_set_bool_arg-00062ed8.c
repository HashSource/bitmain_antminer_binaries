
char * opt_set_bool_arg(char *arg,_Bool *b)

{
  int iVar1;
  char *pcVar2;
  _Bool *b_local;
  char *arg_local;
  
  iVar1 = strcasecmp(arg,"yes");
  if ((iVar1 == 0) || (iVar1 = strcasecmp(arg,"true"), iVar1 == 0)) {
    pcVar2 = opt_set_bool(b);
  }
  else {
    iVar1 = strcasecmp(arg,"no");
    if ((iVar1 == 0) || (iVar1 = strcasecmp(arg,"false"), iVar1 == 0)) {
      pcVar2 = opt_set_invbool(b);
    }
    else {
      pcVar2 = opt_invalid_argument(arg);
    }
  }
  return pcVar2;
}

