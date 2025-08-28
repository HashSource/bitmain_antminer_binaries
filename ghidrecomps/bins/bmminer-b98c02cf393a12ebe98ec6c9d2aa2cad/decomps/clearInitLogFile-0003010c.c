
void clearInitLogFile(void)

{
  FILE *pFVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)init_log_mutex);
  pFVar1 = fopen("/tmp/freq","w");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
  }
  if (opt_fixed_freq != '\0') {
    pFVar1 = fopen("/tmp/search","w");
    if (pFVar1 != (FILE *)0x0) {
      fclose(pFVar1);
    }
    pFVar1 = fopen("/tmp/freq","w");
    if (pFVar1 != (FILE *)0x0) {
      fclose(pFVar1);
    }
    pFVar1 = fopen("/tmp/lasttemp","w");
    if (pFVar1 != (FILE *)0x0) {
      fclose(pFVar1);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)init_log_mutex);
  return;
}

