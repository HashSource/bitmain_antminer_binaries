
void tidyup(void *arg)

{
  void *arg_local;
  long *apisock;
  
  _mutex_lock(&quit_restart_lock,"api-btm.c","tidyup",0x11d9);
  bye = true;
                    /* WARNING: Load size is inaccurate */
  if (*arg != -1) {
                    /* WARNING: Load size is inaccurate */
    shutdown(*arg,2);
                    /* WARNING: Load size is inaccurate */
    close(*arg);
    *(undefined4 *)arg = 0xffffffff;
  }
  if (ipaccess != (IPACCESS *)0x0) {
    free(ipaccess);
    ipaccess = (IPACCESS *)0x0;
  }
  io_free();
  _mutex_unlock(&quit_restart_lock,"api-btm.c","tidyup",0x11ee);
  return;
}

