
/* WARNING: Unknown calling convention */

void writeLogFile(char *logstr)

{
  FILE *__s;
  size_t __n;
  
  __s = fopen("/tmp/temp","a+");
  if (__s == (FILE *)0x0) {
    return;
  }
  __n = strlen(logstr);
  fwrite(logstr,1,__n,__s);
  (*(code *)(undefined *)0x0)(__s);
  return;
}

