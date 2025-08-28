
/* WARNING: Unknown calling convention */

void writeInitLogFile(char *logstr)

{
  FILE *__s;
  size_t __n;
  
  pthread_mutex_lock((pthread_mutex_t *)&init_log_mutex);
  __s = fopen("/tmp/freq","a+");
  if (__s != (FILE *)0x0) {
    __n = strlen(logstr);
    fwrite(logstr,1,__n,__s);
    fclose(__s);
  }
  (*(code *)(undefined *)0x0)(&init_log_mutex);
  return;
}

