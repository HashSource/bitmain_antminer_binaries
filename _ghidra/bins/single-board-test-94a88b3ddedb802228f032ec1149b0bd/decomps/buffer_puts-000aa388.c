
undefined4 buffer_puts(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined4 uVar2;
  bool bVar3;
  
  sVar1 = strlen(param_2);
  bVar3 = (int)param_2 < 0;
  if (param_2 != (char *)0x0) {
    bVar3 = (int)sVar1 < 0;
  }
  if ((param_2 != (char *)0x0 && sVar1 != 0) && !bVar3) {
    uVar2 = buffer_write_part_0(param_1,param_2,sVar1,param_4);
    return uVar2;
  }
  return 0;
}

