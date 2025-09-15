
undefined4 json_array_grow(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (*(uint *)(param_1 + 8) < (uint)(*(int *)(param_1 + 0xc) + param_2)) {
    uVar3 = *(undefined4 *)(param_1 + 0x10);
    uVar2 = *(int *)(param_1 + 8) << 1;
    uVar4 = *(int *)(param_1 + 8) + param_2;
    if (uVar4 <= uVar2) {
      uVar4 = uVar2;
    }
    iVar1 = jsonp_malloc(uVar4 << 2);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      *(uint *)(param_1 + 8) = uVar4;
      *(int *)(param_1 + 0x10) = iVar1;
      if (param_3 != 0) {
        array_copy(*(undefined4 *)(param_1 + 0x10),0,uVar3,0,*(undefined4 *)(param_1 + 0xc));
        jsonp_free(uVar3);
        uVar3 = *(undefined4 *)(param_1 + 0x10);
      }
    }
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar3;
}

