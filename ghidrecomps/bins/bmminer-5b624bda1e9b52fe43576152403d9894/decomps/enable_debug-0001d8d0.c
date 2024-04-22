
/* WARNING: Unknown calling convention */

char * enable_debug(_Bool *flag)

{
  *flag = false;
  opt_log_output = false;
  return (char *)0x0;
}

