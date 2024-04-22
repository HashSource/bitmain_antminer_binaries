
char * file_puts(int param_1,char *param_2)

{
  char *__size;
  size_t sVar1;
  
  __size = (char *)strlen(param_2);
  if (*(int *)(param_1 + 0xc) == 0) {
    return (char *)0x0;
  }
  if (param_2 != (char *)0x0) {
    sVar1 = fwrite(param_2,(size_t)__size,1,*(FILE **)(param_1 + 0x20));
    if (sVar1 == 0) {
      __size = (char *)0x0;
    }
    return __size;
  }
  return param_2;
}

