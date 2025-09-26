
undefined4 tls_construct_stoc_cryptopro_bug(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_3c [9];
  
  puVar5 = &DAT_0020f1fc;
  puVar7 = local_3c;
  do {
    puVar6 = puVar5 + 4;
    uVar1 = puVar5[1];
    uVar2 = puVar5[2];
    puVar8 = puVar7 + 4;
    uVar3 = puVar5[3];
    *puVar7 = *puVar5;
    puVar7[1] = uVar1;
    puVar7[2] = uVar2;
    puVar7[3] = uVar3;
    puVar5 = puVar6;
    puVar7 = puVar8;
  } while (puVar6 != &DAT_0020f21c);
  iVar4 = *(int *)(param_1 + 0x7c);
  *puVar8 = 0x17020203;
  if ((*(ushort *)(*(int *)(iVar4 + 0x210) + 0xc) - 0x80 < 2) &&
     (iVar4 = SSL_get_options(param_1), iVar4 < 0)) {
    iVar4 = WPACKET_memcpy(param_2,local_3c,0x24);
    uVar1 = 1;
    if (iVar4 == 0) {
      ossl_statem_fatal(param_1,0x50,0x1c4,0x44,"ssl/statem/extensions_srvr.c",0x783);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

