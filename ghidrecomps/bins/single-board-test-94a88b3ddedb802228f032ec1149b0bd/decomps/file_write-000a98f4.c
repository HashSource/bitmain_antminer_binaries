
void * file_write(int param_1,void *param_2,void *param_3)

{
  size_t sVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    return (void *)0x0;
  }
  if (param_2 != (void *)0x0) {
    sVar1 = fwrite(param_2,(size_t)param_3,1,*(FILE **)(param_1 + 0x20));
    if (sVar1 == 0) {
      param_3 = (void *)0x0;
    }
    return param_3;
  }
  return param_2;
}

