
/* WARNING: Unknown calling convention */

void tidyup(void *arg)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  char *in_r2;
  char *func;
  int in_r3;
  int line;
  long *apisock;
  io_list *io_list;
  io_list *piVar4;
  io_list *io_next;
  io_list *piVar5;
  
  iVar3 = pthread_mutex_lock(DAT_00019604);
  if (iVar3 != 0) {
    _mutex_lock(DAT_00019610,(char *)0x1218,in_r2,in_r3);
  }
  puVar1 = DAT_00019608;
                    /* WARNING: Load size is inaccurate */
  iVar3 = *arg;
  line = 1;
  func = (char *)(iVar3 + 1);
  *DAT_00019608 = 1;
  if (func != (char *)0x0) {
    shutdown(iVar3,2);
                    /* WARNING: Load size is inaccurate */
    close(*arg);
    line = -1;
    *(undefined4 *)arg = 0xffffffff;
  }
  puVar2 = DAT_00019608;
  if (*(void **)(puVar1 + 8) != (void *)0x0) {
    free(*(void **)(puVar1 + 8));
    line = 0;
    *(undefined4 *)(puVar2 + 8) = 0;
  }
  piVar5 = *(io_list **)(puVar1 + 0x24);
  io_list = piVar5;
  if (piVar5 != (io_list *)0x0) {
    do {
      piVar4 = io_list->next;
      free(io_list->io_data->ptr);
      free(io_list->io_data);
      free(io_list);
      io_list = piVar4;
    } while (piVar5 != piVar4);
    line = 0;
    *(undefined4 *)(puVar1 + 0x24) = 0;
  }
  iVar3 = pthread_mutex_unlock(DAT_00019604);
  if (iVar3 != 0) {
    _mutex_unlock_noyield(DAT_00019610,(char *)0x122d,func,line);
  }
  (**DAT_0001960c)();
  return;
}

