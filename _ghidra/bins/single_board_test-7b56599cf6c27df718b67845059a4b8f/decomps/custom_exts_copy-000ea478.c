
undefined4 custom_exts_copy(int *param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (param_2[1] == 0) {
    return 1;
  }
  iVar3 = CRYPTO_memdup(*param_2,param_2[1] * 0x24,"ssl/statem/extensions_cust.c",0x117);
  *param_1 = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  param_1[1] = param_2[1];
  uVar5 = param_2[1];
  if (uVar5 == 0) {
    return 1;
  }
  bVar1 = false;
  iVar6 = 0;
  do {
    iVar7 = *param_2 + iVar6 * 0x24;
    if (*(int *)(iVar7 + 0x10) == 0xea0d1) {
      iVar3 = iVar3 + iVar6 * 0x24;
      if (!bVar1) {
        uVar4 = CRYPTO_memdup(*(undefined4 *)(iVar7 + 0x18),0xc,"ssl/statem/extensions_cust.c",0x12f
                             );
        *(undefined4 *)(iVar3 + 0x18) = uVar4;
        iVar7 = CRYPTO_memdup(*(undefined4 *)(iVar7 + 0x20),8,"ssl/statem/extensions_cust.c",0x131);
        uVar5 = param_2[1];
        *(int *)(iVar3 + 0x20) = iVar7;
        bVar1 = iVar7 == 0 || *(int *)(iVar3 + 0x18) == 0;
        goto LAB_000ea4be;
      }
      *(undefined4 *)(iVar3 + 0x18) = 0;
      bVar1 = true;
      *(undefined4 *)(iVar3 + 0x20) = 0;
      bVar2 = true;
      if (uVar5 <= iVar6 + 1U) goto LAB_000ea4f4;
    }
    else {
LAB_000ea4be:
      bVar2 = bVar1;
      if (uVar5 <= iVar6 + 1U) {
LAB_000ea4f4:
        if (bVar1) {
          custom_exts_free(param_1);
          return 0;
        }
        return 1;
      }
    }
    bVar1 = bVar2;
    iVar6 = iVar6 + 1;
    iVar3 = *param_1;
  } while( true );
}

