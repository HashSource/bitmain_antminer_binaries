
void writeLogFile(char *param_1)

{
  FILE *__s;
  size_t __n;
  
  __s = fopen("/tmp/temp","a+");
  if (__s == (FILE *)0x0) {
    return;
  }
  __n = strlen(param_1);
  fwrite(param_1,1,__n,__s);
  fclose(__s);
  return;
}

