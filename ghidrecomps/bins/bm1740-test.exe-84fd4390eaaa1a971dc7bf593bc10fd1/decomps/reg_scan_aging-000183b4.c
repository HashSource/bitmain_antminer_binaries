
void reg_scan_aging(void)

{
  pthread_t __th;
  int local_c;
  
  __th = pthread_self();
  pthread_detach(__th);
  do {
    sleep(1);
    pthread_mutex_lock((pthread_mutex_t *)reg_scan_mutex);
    for (local_c = 0; local_c < 100; local_c = local_c + 1) {
      if (-1 < *(int *)(&DAT_000312a0 + local_c * 0xc)) {
        *(int *)(&DAT_000312a0 + local_c * 0xc) = *(int *)(&DAT_000312a0 + local_c * 0xc) + -1;
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)reg_scan_mutex);
  } while( true );
}

