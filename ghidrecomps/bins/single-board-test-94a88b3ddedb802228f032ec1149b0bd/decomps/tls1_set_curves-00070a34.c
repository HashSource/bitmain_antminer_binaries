
undefined * tls1_set_curves(void **param_1,int *param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined *ptr;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  
  ptr = (undefined *)CRYPTO_malloc(param_4 << 1,DAT_00070ac0,0x283);
  puVar3 = ptr;
  if (ptr != (undefined *)0x0) {
    if (param_4 != 0) {
      uVar7 = 0;
      puVar5 = (undefined4 *)(param_3 + -4);
      iVar6 = 0;
      do {
        puVar5 = puVar5 + 1;
        iVar6 = iVar6 + 1;
        uVar2 = tls1_ec_nid2curve_id(*puVar5);
        uVar4 = 1 << (uVar2 & 0xff);
        if ((uVar2 == 0) || (uVar1 = uVar4 & uVar7, uVar7 = uVar7 | uVar4, uVar1 != 0)) {
          CRYPTO_free(ptr);
          return (undefined *)0x0;
        }
        *puVar3 = (char)(uVar2 >> 8);
        puVar3[1] = (char)uVar2;
        puVar3 = puVar3 + 2;
      } while (iVar6 != param_4);
    }
    if (*param_1 != (void *)0x0) {
      CRYPTO_free(*param_1);
    }
    puVar3 = (undefined *)0x1;
    *param_1 = ptr;
    *param_2 = param_4 << 1;
  }
  return puVar3;
}

