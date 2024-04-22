
/* WARNING: Unknown calling convention */

void * reg_list_aging(void)

{
  pthread_t __th;
  int i;
  
  __th = pthread_self();
  pthread_detach(__th);
  while (rs.alive == 1) {
    sleep(1);
    pthread_mutex_lock(DAT_000328f0);
    for (i = 0; i < 100; i = i + 1) {
      if (-1 < rs.reg_list_items[i].age) {
        rs.reg_list_items[i].age = rs.reg_list_items[i].age + -1;
      }
    }
    pthread_mutex_unlock(DAT_000328f0);
  }
  return (void *)0x0;
}

