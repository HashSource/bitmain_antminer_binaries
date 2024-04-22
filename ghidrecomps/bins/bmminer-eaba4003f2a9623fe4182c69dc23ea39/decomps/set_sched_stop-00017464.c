
char * set_sched_stop(char *arg)

{
  char *pcVar1;
  char *arg_local;
  
  pcVar1 = set_schedtime(arg,&schedstop);
  return pcVar1;
}

