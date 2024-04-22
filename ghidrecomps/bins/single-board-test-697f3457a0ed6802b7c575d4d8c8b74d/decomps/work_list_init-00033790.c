
void work_list_init(int work_len)

{
  uint8_t *puVar1;
  int work_len_local;
  int i;
  
  memset(&work_list_info,0,0x70);
  work_list_info.work_len = work_len;
  pthread_mutex_init(DAT_000337f4,(pthread_mutexattr_t *)0x0);
  for (i = 0; i < 10; i = i + 1) {
    puVar1 = (uint8_t *)calloc(work_len,1);
    work_list_info.work_list[i].work = puVar1;
  }
  return;
}

