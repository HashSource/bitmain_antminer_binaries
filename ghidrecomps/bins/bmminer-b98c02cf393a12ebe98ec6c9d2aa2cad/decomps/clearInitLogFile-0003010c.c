
void clearInitLogFile(void)

{
  FILE *pFVar1;
  
  pthread_mutex_lock(DAT_000301a0);
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
  (*(code *)PTR_pthread_mutex_unlock_0007ce1c)(DAT_000301a0);
  return;
}

