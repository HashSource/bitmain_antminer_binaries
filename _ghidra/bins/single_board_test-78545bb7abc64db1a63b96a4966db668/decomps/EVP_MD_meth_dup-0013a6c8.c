
void EVP_MD_meth_dup(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar1 = (undefined4 *)EVP_MD_meth_new(*param_1,param_1[1],param_3,param_4,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = param_1;
    do {
      puVar3 = puVar2 + 4;
      uVar6 = puVar2[1];
      uVar5 = puVar2[2];
      uVar4 = puVar2[3];
      *puVar1 = *puVar2;
      puVar1[1] = uVar6;
      puVar1[2] = uVar5;
      puVar1[3] = uVar4;
      puVar1 = puVar1 + 4;
      puVar2 = puVar3;
    } while (puVar3 != param_1 + 0xc);
  }
  return;
}

