
/* WARNING: Unknown calling convention */
/* Local variable err:char *[r0:4] conflicts with parameter, skipped. */

char * opt_set_invbool_arg(char *arg,_Bool *b)

{
  char *pcVar1;
  
  pcVar1 = opt_set_bool_arg(arg,b);
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
  *b = (_Bool)(*b ^ 1);
  return (char *)0x0;
}

