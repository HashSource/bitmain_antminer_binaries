
char * CRYPTO_strdup(char *str,char *file,int line)

{
  size_t sVar1;
  char *__dest;
  
  sVar1 = strlen(str);
  __dest = (char *)CRYPTO_malloc(sVar1 + 1,file,line);
  if (__dest != (char *)0x0) {
    strcpy(__dest,str);
  }
  return __dest;
}

