
/* WARNING: Unknown calling convention */

void writeInitLogFile(char *logstr)

{
  FILE *__s;
  FILE *fd;
  size_t __n;
  
  pthread_mutex_lock(DAT_0002eec8);
  __s = fopen(DAT_0002eecc,DAT_0002eed0);
  if (__s != (FILE *)0x0) {
    __n = strlen(logstr);
    fwrite(logstr,1,__n,__s);
    fclose(__s);
  }
                    /* WARNING: Could not recover jumptable at 0x0000a2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f228)(DAT_0002eec8);
  return;
}

