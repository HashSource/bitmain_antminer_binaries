
undefined4 * bn_expand_internal(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  
  if (0xffffff < param_2) {
    ERR_put_error(3,0x78,0x72,DAT_0009cf00,0x128);
    return (undefined4 *)0x0;
  }
  if ((int)(param_1[4] << 0x1e) < 0) {
    ERR_put_error(3,0x78,0x69,DAT_0009cf00,300);
    return (undefined4 *)0x0;
  }
  puVar2 = (undefined4 *)CRYPTO_malloc(param_2 << 2,DAT_0009cf00,0x12f);
  if (puVar2 == (undefined4 *)0x0) {
    ERR_put_error(3,0x78,0x41,DAT_0009cf00,0x131);
    return (undefined4 *)0x0;
  }
  puVar10 = (undefined4 *)*param_1;
  if (puVar10 == (undefined4 *)0x0) {
    return puVar2;
  }
  uVar7 = param_1[1];
  iVar1 = (int)uVar7 >> 2;
  iVar4 = iVar1;
  puVar6 = puVar2;
  puVar5 = puVar10;
  if (0 < iVar1) {
    do {
      iVar4 = iVar4 + -1;
      uVar9 = puVar5[1];
      uVar8 = puVar5[2];
      uVar3 = puVar5[3];
      *puVar6 = *puVar5;
      puVar6[1] = uVar9;
      puVar6[3] = uVar3;
      puVar6[2] = uVar8;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
    } while (iVar4 != 0);
    uVar7 = param_1[1];
    puVar10 = puVar10 + iVar1 * 4;
    puVar6 = puVar2 + iVar1 * 4;
  }
  uVar7 = uVar7 & 3;
  if (uVar7 != 2) {
    if (uVar7 != 3) {
      if (uVar7 != 1) {
        return puVar2;
      }
      goto LAB_0009ceb0;
    }
    puVar6[2] = puVar10[2];
  }
  puVar6[1] = puVar10[1];
LAB_0009ceb0:
  *puVar6 = *puVar10;
  return puVar2;
}

