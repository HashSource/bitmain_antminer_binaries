
int construct_key_exchange_tbs(int param_1,undefined4 *param_2,void *param_3,size_t param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(param_4 + 0x40,"ssl/statem/statem_lib.c",0x946);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = *(int *)(param_1 + 0x7c);
    uVar4 = *(undefined4 *)(iVar3 + 0xb0);
    uVar5 = *(undefined4 *)(iVar3 + 0xb4);
    uVar2 = *(undefined4 *)(iVar3 + 0xb8);
    *puVar1 = *(undefined4 *)(iVar3 + 0xac);
    puVar1[1] = uVar4;
    puVar1[2] = uVar5;
    puVar1[3] = uVar2;
    uVar4 = *(undefined4 *)(iVar3 + 0xc0);
    uVar5 = *(undefined4 *)(iVar3 + 0xc4);
    uVar2 = *(undefined4 *)(iVar3 + 200);
    puVar1[4] = *(undefined4 *)(iVar3 + 0xbc);
    puVar1[5] = uVar4;
    puVar1[6] = uVar5;
    puVar1[7] = uVar2;
    iVar3 = *(int *)(param_1 + 0x7c);
    uVar4 = *(undefined4 *)(iVar3 + 0x90);
    uVar5 = *(undefined4 *)(iVar3 + 0x94);
    uVar2 = *(undefined4 *)(iVar3 + 0x98);
    puVar1[8] = *(undefined4 *)(iVar3 + 0x8c);
    puVar1[9] = uVar4;
    puVar1[10] = uVar5;
    puVar1[0xb] = uVar2;
    uVar2 = *(undefined4 *)(iVar3 + 0xa8);
    uVar4 = *(undefined4 *)(iVar3 + 0xa0);
    uVar5 = *(undefined4 *)(iVar3 + 0xa4);
    puVar1[0xc] = *(undefined4 *)(iVar3 + 0x9c);
    puVar1[0xd] = uVar4;
    puVar1[0xe] = uVar5;
    puVar1[0xf] = uVar2;
    memcpy(puVar1 + 0x10,param_3,param_4);
    *param_2 = puVar1;
    return param_4 + 0x40;
  }
  ossl_statem_fatal(param_1,0x50,0x229,0x41,"ssl/statem/statem_lib.c",0x94a);
  return 0;
}

