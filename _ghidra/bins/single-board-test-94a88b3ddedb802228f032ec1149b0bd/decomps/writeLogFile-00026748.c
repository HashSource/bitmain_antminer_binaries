
void writeLogFile(char *param_1)

{
  FILE *__s;
  size_t __n;
  
  pthread_mutex_lock((pthread_mutex_t *)&log_mutex);
  __s = fopen("/tmp/search","a+");
  if (__s != (FILE *)0x0) {
    __n = strlen(param_1);
    fwrite(param_1,1,__n,__s);
    fclose(__s);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&log_mutex);
  return;
}

