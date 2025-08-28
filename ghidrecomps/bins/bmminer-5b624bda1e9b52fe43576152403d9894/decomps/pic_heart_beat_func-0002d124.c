
/* WARNING: Unknown calling convention */

void * pic_heart_beat_func(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (0xf < iVar1) {
      iVar1 = 0;
      sleep(10);
    }
    if (dev->chain_exist[iVar1] != 0) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      pic_heart_beat_each_chain((uchar)iVar1);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
      cgsleep_ms(10);
    }
    iVar1 = iVar1 + 1;
  } while( true );
}

