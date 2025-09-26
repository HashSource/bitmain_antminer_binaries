
undefined4 tls_validate_all_contexts(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 auStack_2c [8];
  
  if ((int)(param_2 << 0x18) < 0) {
    uVar6 = 1;
  }
  else if ((param_2 & 0x100) == 0) {
    uVar6 = 2;
  }
  else {
    uVar6 = 0;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x404) + 0xf4);
  if (iVar5 != -0x1a) {
    uVar3 = 0;
    puVar4 = &ext_defs;
    do {
      if (*(int *)(param_3 + 8) != 0) {
        if (uVar3 < 0x1a) {
          HintPreloadData(puVar4 + 0x29);
          uVar2 = puVar4[1];
        }
        else {
          iVar1 = custom_ext_find(*(int *)(param_1 + 0x404) + 0xf0,uVar6,
                                  *(undefined4 *)(param_3 + 0x10),auStack_2c);
          if (iVar1 == 0) {
            return 0;
          }
          uVar2 = *(uint *)(iVar1 + 8);
        }
        if ((uVar2 & param_2) == 0) {
          return 0;
        }
        if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
          iVar1 = uVar2 << 0x1f;
        }
        else {
          iVar1 = uVar2 << 0x1e;
        }
        if (iVar1 < 0) {
          return 0;
        }
      }
      uVar3 = uVar3 + 1;
      param_3 = param_3 + 0x18;
      puVar4 = puVar4 + 8;
    } while (iVar5 + 0x1aU != uVar3);
  }
  return 1;
}

