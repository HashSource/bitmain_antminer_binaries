
size_t file_write(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  if ((*(int *)(param_1 + 0x10) != 0 && param_2 != (void *)0x0) &&
     (sVar1 = fwrite(param_2,param_3,1,*(FILE **)(param_1 + 0x24)), sVar1 != 0)) {
    return param_3;
  }
  return 0;
}

