
undefined4 json_string_set(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined4 uVar2;
  
  if (param_2 != (char *)0x0) {
    sVar1 = strlen(param_2);
    uVar2 = json_string_setn(param_1,param_2,sVar1,param_4);
    return uVar2;
  }
  return 0xffffffff;
}

