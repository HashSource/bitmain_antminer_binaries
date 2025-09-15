
char * opt_set_invbool_arg(char *arg,_Bool *b)

{
  char *pcVar1;
  _Bool *b_local;
  char *arg_local;
  char *err;
  
  pcVar1 = opt_set_bool_arg(arg,b);
  if (pcVar1 == (char *)0x0) {
    *b = *b == false;
  }
  return pcVar1;
}

