
void restart_threads_part_59(void)

{
  char local_808 [2052];
  
  builtin_strncpy(local_808,"Failed to create restart thread",0x20);
  _applog(3,local_808,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

