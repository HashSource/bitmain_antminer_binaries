
void writeInitLogFile(char *param_1)

{
  FILE *__s;
  size_t __n;
  
  pthread_mutex_lock(DAT_00030108);
  __s = fopen("/tmp/freq",(char *)&DAT_0005e760);
  if (__s != (FILE *)0x0) {
    __n = strlen(param_1);
    fwrite(param_1,1,__n,__s);
    fclose(__s);
  }
  (*(code *)PTR_pthread_mutex_unlock_0007ce1c)(DAT_00030108);
  return;
}

