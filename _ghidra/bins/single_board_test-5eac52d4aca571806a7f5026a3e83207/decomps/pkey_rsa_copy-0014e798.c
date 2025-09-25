
undefined4 pkey_rsa_copy(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x34,"crypto/rsa/rsa_pmeth.c",0x37,param_4,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    piVar6 = (int *)*param_1;
    *puVar1 = 0x800;
    iVar2 = *piVar6;
    puVar1[9] = 0xffffffff;
    puVar1[2] = 2;
    puVar1[8] = 0xfffffffe;
    if (iVar2 == 0x390) {
      uVar4 = 6;
    }
    else {
      uVar4 = 1;
    }
    puVar1[5] = uVar4;
    param_1[5] = puVar1;
    puVar7 = *(undefined4 **)(param_2 + 0x14);
    param_1[8] = puVar1 + 3;
    param_1[9] = 2;
    pBVar3 = (BIGNUM *)puVar7[1];
    *puVar1 = *puVar7;
    if (pBVar3 != (BIGNUM *)0x0) {
      pBVar3 = BN_dup(pBVar3);
      puVar1[1] = pBVar3;
      if (pBVar3 == (BIGNUM *)0x0) {
        return 0;
      }
    }
    iVar2 = puVar7[0xb];
    uVar4 = puVar7[6];
    uVar5 = puVar7[7];
    puVar1[5] = puVar7[5];
    puVar1[6] = uVar4;
    puVar1[7] = uVar5;
    if (iVar2 == 0) {
      return 1;
    }
    CRYPTO_free((void *)puVar1[0xb]);
    iVar2 = CRYPTO_memdup(puVar7[0xb],puVar7[0xc],"crypto/rsa/rsa_pmeth.c",0x5e);
    puVar1[0xb] = iVar2;
    if (iVar2 != 0) {
      puVar1[0xc] = puVar7[0xc];
      return 1;
    }
  }
  return 0;
}

