
undefined4 json_object_set_new(undefined4 param_1,char *param_2,int param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 != (char *)0x0) {
    sVar1 = strlen(param_2);
    iVar2 = utf8_check_string(param_2,sVar1);
    if (iVar2 != 0) {
      uVar3 = json_object_set_new_nocheck(param_1,param_2,param_3);
      return uVar3;
    }
  }
  if (param_3 != 0) {
    if (*(int *)(param_3 + 4) != -1) {
      iVar2 = *(int *)(param_3 + 4) + -1;
      *(int *)(param_3 + 4) = iVar2;
      if (iVar2 == 0) {
        json_delete(param_3);
      }
    }
  }
  return 0xffffffff;
}

