
/* WARNING: Unknown calling convention */

void tidyup(void *arg)

{
  io_list *piVar1;
  int iVar2;
  char *func;
  char *func_00;
  int line;
  int line_00;
  io_list *__ptr;
  io_list *piVar3;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&quit_restart_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"tidyup",(char *)0x1218,func,line);
  }
                    /* WARNING: Load size is inaccurate */
  bye = true;
  if (*arg != -1) {
    shutdown(*arg,2);
                    /* WARNING: Load size is inaccurate */
    close(*arg);
    *(undefined4 *)arg = 0xffffffff;
  }
  if (ipaccess != (IPACCESS *)0x0) {
    free(ipaccess);
    ipaccess = (IPACCESS *)0x0;
  }
  piVar1 = io_head;
  __ptr = io_head;
  if (io_head != (io_list *)0x0) {
    do {
      piVar3 = __ptr->next;
      free(__ptr->io_data->ptr);
      free(__ptr->io_data);
      free(__ptr);
      __ptr = piVar3;
    } while (piVar1 != piVar3);
    io_head = (io_list *)0x0;
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&quit_restart_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"tidyup",(char *)0x122d,func_00,line_00);
  }
  (*selective_yield)();
  return;
}

