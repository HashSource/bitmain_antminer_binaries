
undefined4 early_data_count_ok(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0x474) + 0x1e0);
    if ((uVar3 == 0) &&
       ((*(int *)(param_1 + 0x478) == 0 ||
        (uVar3 = *(uint *)(*(int *)(param_1 + 0x478) + 0x1e0), uVar3 == 0)))) {
      ossl_statem_fatal(param_1,0x50,0x214,0x44,"ssl/record/ssl3_record.c",0x76);
      return 0;
    }
  }
  else {
    if (*(int *)(param_1 + 0x5ac) == 2) {
      uVar1 = *(uint *)(*(int *)(param_1 + 0x474) + 0x1e0);
      uVar3 = *(uint *)(param_1 + 0xf54);
      if (uVar1 <= *(uint *)(param_1 + 0xf54)) {
        uVar3 = uVar1;
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0xf54);
    }
    if (uVar3 == 0) {
      if (param_4 == 0) {
        uVar4 = 10;
      }
      else {
        uVar4 = 0x50;
      }
      ossl_statem_fatal(param_1,uVar4,0x214,0xa4,"ssl/record/ssl3_record.c",0x86);
      return 0;
    }
  }
  uVar1 = param_2 + *(int *)(param_1 + 0xf58);
  if (uVar3 + param_3 < uVar1) {
    if (param_4 == 0) {
      uVar2 = 10;
    }
    else {
      uVar2 = 0x50;
    }
    uVar4 = 0;
    ossl_statem_fatal(param_1,uVar2,0x214,0xa4,"ssl/record/ssl3_record.c",0x8f);
  }
  else {
    *(uint *)(param_1 + 0xf58) = uVar1;
    uVar4 = 1;
  }
  return uVar4;
}

