
char * Strsep(char **stringp,char *delim)

{
  char *pcVar1;
  char *__s;
  char *delim_local;
  char **stringp_local;
  char *p;
  char *ret;
  
  __s = *stringp;
  if (__s == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = strpbrk(__s,delim);
  }
  if (pcVar1 == (char *)0x0) {
    *stringp = (char *)0x0;
  }
  else {
    *pcVar1 = '\0';
    *stringp = pcVar1 + 1;
  }
  return __s;
}

