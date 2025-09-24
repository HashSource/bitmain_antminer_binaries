
void pkey_rsa_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x34,"crypto/rsa/rsa_pmeth.c",0x37,param_4,param_4);
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  piVar2 = (int *)*param_1;
  *puVar1 = 0x800;
  iVar4 = *piVar2;
  puVar1[9] = 0xffffffff;
  puVar1[2] = 2;
  puVar1[8] = 0xfffffffe;
  if (iVar4 == 0x390) {
    uVar3 = 6;
  }
  else {
    uVar3 = 1;
  }
  puVar1[5] = uVar3;
  param_1[9] = 2;
  param_1[5] = puVar1;
  param_1[8] = puVar1 + 3;
  return;
}

