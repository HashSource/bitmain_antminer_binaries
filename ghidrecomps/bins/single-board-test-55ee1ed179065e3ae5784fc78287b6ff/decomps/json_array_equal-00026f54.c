
undefined4 json_array_equal(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_c;
  
  uVar1 = json_array_size(param_1);
  uVar2 = json_array_size(param_2);
  if (uVar2 == uVar1) {
    for (local_c = 0; local_c < uVar1; local_c = local_c + 1) {
      uVar5 = json_array_get(param_1,local_c);
      uVar3 = json_array_get(param_2,local_c);
      iVar4 = json_equal(uVar5,uVar3);
      if (iVar4 == 0) {
        return 0;
      }
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

