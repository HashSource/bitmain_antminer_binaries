
/* WARNING: Unknown calling convention */

char * Strsep(char **stringp,char *delim)

{
  char *pcVar1;
  char *p;
  char *ret;
  char *__s;
  
  __s = *stringp;
  if ((__s != (char *)0x0) && (pcVar1 = strpbrk(__s,delim), pcVar1 != (char *)0x0)) {
    *pcVar1 = '\0';
    *stringp = pcVar1 + 1;
    return __s;
  }
  *stringp = (char *)0x0;
  return __s;
}

