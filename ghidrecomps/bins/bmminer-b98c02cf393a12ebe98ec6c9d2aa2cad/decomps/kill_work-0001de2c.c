
void kill_work(void)

{
  char local_808 [24];
  undefined2 local_7f0;
  
  cg_completion_timeout(0x20795,0,5000);
  builtin_strncpy(local_808,"Shutdown signal received",0x18);
  local_7f0 = 0x2e;
  _applog(3,local_808,1);
                    /* WARNING: Subroutine does not return */
  __quit(0,1);
}

