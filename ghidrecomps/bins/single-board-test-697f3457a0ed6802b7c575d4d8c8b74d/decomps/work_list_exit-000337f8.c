
/* WARNING: Unknown calling convention */

void work_list_exit(void)

{
  int i;
  
  for (i = 0; i < 10; i = i + 1) {
    free(work_list_info.work_list[i].work);
  }
  pthread_mutex_destroy(DAT_00033834);
  return;
}

