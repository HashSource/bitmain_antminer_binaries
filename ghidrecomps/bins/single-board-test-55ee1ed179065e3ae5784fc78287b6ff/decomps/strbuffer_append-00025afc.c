
undefined4 strbuffer_append(undefined4 param_1,char *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  
  sVar1 = strlen(param_2);
  uVar2 = strbuffer_append_bytes(param_1,param_2,sVar1);
  return uVar2;
}

