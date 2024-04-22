
undefined4
blake2b(int param_1,int param_2,int param_3,byte param_4,uint param_5,uint param_6,byte param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_178 [364];
  
  if ((param_2 == 0) && ((param_5 | param_6) != 0)) {
    uVar2 = 0xffffffff;
  }
  else if (param_1 == 0) {
    uVar2 = 0xffffffff;
  }
  else if ((param_3 == 0) && (param_7 != 0)) {
    uVar2 = 0xffffffff;
  }
  else if ((param_4 == 0) || (0x40 < param_4)) {
    uVar2 = 0xffffffff;
  }
  else if (param_7 < 0x41) {
    if (param_7 == 0) {
      iVar1 = blake2b_init(auStack_178,param_4);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
    }
    else {
      iVar1 = blake2b_init_key(auStack_178,param_4,param_3,param_7);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
    }
    blake2b_update(auStack_178,param_2,param_5,param_6);
    blake2b_final(auStack_178,param_1,param_4);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

