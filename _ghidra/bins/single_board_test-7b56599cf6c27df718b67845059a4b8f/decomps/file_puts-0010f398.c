
size_t file_puts(int param_1,char *param_2)

{
  size_t __size;
  size_t sVar1;
  
  __size = strlen(param_2);
  if ((*(int *)(param_1 + 0x10) != 0) &&
     (sVar1 = fwrite(param_2,__size,1,*(FILE **)(param_1 + 0x24)), sVar1 != 0)) {
    return __size;
  }
  return 0;
}

