
/* WARNING: Unknown calling convention */

void * pic_heart_beat_func(void)

{
  int *piVar1;
  int i;
  
  piVar1 = DAT_0002d164;
  i = 0;
  do {
    if (0xf < i) {
      i = 0;
      sleep(10);
    }
    if (*(int *)(*piVar1 + (i + 2) * 4) != 0) {
      pthread_mutex_lock(DAT_0002d168);
      pic_heart_beat_each_chain((uchar)i);
      pthread_mutex_unlock(DAT_0002d168);
      cgsleep_ms(10);
    }
    i = i + 1;
  } while( true );
}

