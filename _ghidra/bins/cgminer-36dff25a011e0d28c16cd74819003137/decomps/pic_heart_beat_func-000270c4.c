
void * pic_heart_beat_func(void *arg)

{
  int iVar1;
  void *arg_local;
  int ret;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      iVar1 = pthread_create(dev->heart_beat_id + i,(pthread_attr_t *)0x0,heart_beat_func_one_chain,
                             (void *)i);
      if (iVar1 != 0) {
        perror("create pthread failed in pic_heart_beat_func");
      }
    }
  }
  return (void *)0x0;
}

