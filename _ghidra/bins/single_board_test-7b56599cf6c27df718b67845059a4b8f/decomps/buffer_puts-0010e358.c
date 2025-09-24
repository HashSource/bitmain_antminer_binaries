
undefined4 buffer_puts(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined4 uVar2;
  
  sVar1 = strlen(param_2);
  if ((int)sVar1 < 1) {
    return 0;
  }
  uVar2 = buffer_write_part_0(param_1,param_2,sVar1,param_4);
  return uVar2;
}

