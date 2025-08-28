
size_t file_puts(int param_1,char *param_2)

{
  size_t __size;
  size_t sVar1;
  
  __size = strlen(param_2);
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0;
  }
  if (param_2 != (char *)0x0) {
    sVar1 = fwrite(param_2,__size,1,*(FILE **)(param_1 + 0x20));
    if (sVar1 == 0) {
      __size = 0;
    }
    return __size;
  }
  return 0;
}

