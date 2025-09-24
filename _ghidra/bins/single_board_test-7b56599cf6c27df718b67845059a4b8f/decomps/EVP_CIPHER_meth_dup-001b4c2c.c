
void EVP_CIPHER_meth_dup(undefined4 *param_1,undefined4 param_2,undefined4 param_3,
                        undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar1 = (undefined4 *)EVP_CIPHER_meth_new(*param_1,param_1[1],param_1[2],param_4,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = param_1;
    do {
      puVar4 = puVar3 + 4;
      uVar7 = puVar3[1];
      puVar2 = puVar1 + 4;
      uVar6 = puVar3[2];
      uVar5 = puVar3[3];
      *puVar1 = *puVar3;
      puVar1[1] = uVar7;
      puVar1[2] = uVar6;
      puVar1[3] = uVar5;
      puVar1 = puVar2;
      puVar3 = puVar4;
    } while (puVar4 != param_1 + 0xc);
    *puVar2 = *puVar4;
  }
  return;
}

