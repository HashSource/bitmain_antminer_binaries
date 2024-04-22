
/* WARNING: Unknown calling convention */

void * pic_heart_beat_func(void)

{
  int i;
  
  do {
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] != 0) {
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        dsPIC33EP16GS202_pic_heart_beat((uchar)i);
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
        cgsleep_ms(10);
      }
    }
    sleep(10);
  } while( true );
}

