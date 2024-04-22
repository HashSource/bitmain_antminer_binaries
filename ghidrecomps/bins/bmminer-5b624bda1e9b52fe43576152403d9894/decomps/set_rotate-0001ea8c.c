
/* WARNING: Unknown calling convention */

char * set_rotate(char *arg,char *i)

{
  char *pcVar1;
  
  pool_strategy = POOL_ROTATE;
  pcVar1 = set_int_range(arg,&opt_rotate_period,0,9999);
  return pcVar1;
}

