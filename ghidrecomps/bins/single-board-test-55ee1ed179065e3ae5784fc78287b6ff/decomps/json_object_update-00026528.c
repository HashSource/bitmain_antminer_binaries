
undefined4 json_object_update(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if ((((param_1 == (int *)0x0) || (*param_1 != 0)) || (param_2 == (int *)0x0)) || (*param_2 != 0))
  {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = json_object_iter(param_2);
    local_c = json_object_iter_key(uVar2);
    while (local_c != 0) {
      uVar2 = json_object_key_to_iter(local_c);
      iVar1 = json_object_iter_value(uVar2);
      if (iVar1 == 0) break;
      iVar1 = json_object_set_nocheck(param_1,local_c,iVar1);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      uVar2 = json_object_key_to_iter(local_c);
      uVar2 = json_object_iter_next(param_2,uVar2);
      local_c = json_object_iter_key(uVar2);
    }
    uVar2 = 0;
  }
  return uVar2;
}

