
undefined4 pkey_dh_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x40,"crypto/dh/dh_pmeth.c",0x35);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(5,0x7d,0x41,"crypto/dh/dh_pmeth.c",0x36);
    uVar2 = 0;
  }
  else {
    *(undefined1 *)(puVar1 + 10) = 1;
    *puVar1 = 0x800;
    puVar1[1] = 2;
    puVar1[3] = 0xffffffff;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    puVar8 = *(undefined4 **)(param_2 + 0x14);
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 8;
    *(undefined4 *)(param_1 + 0x24) = 2;
    uVar7 = puVar8[4];
    uVar9 = *puVar8;
    uVar2 = puVar8[3];
    uVar5 = puVar8[1];
    uVar6 = puVar8[2];
    puVar1[5] = puVar8[5];
    *puVar1 = uVar9;
    uVar9 = puVar8[6];
    puVar1[3] = uVar2;
    uVar2 = puVar8[7];
    puVar1[1] = uVar5;
    puVar1[2] = uVar6;
    puVar1[7] = uVar2;
    puVar1[4] = uVar7;
    puVar1[6] = uVar9;
    *(undefined1 *)(puVar1 + 10) = *(undefined1 *)(puVar8 + 10);
    pAVar3 = OBJ_dup((ASN1_OBJECT *)puVar8[0xb]);
    puVar1[0xb] = pAVar3;
    if (pAVar3 == (ASN1_OBJECT *)0x0) {
      return 0;
    }
    iVar4 = puVar8[0xd];
    puVar1[0xc] = puVar8[0xc];
    if (iVar4 != 0) {
      iVar4 = CRYPTO_memdup(iVar4,puVar8[0xe],"crypto/dh/dh_pmeth.c",0x66);
      puVar1[0xd] = iVar4;
      if (iVar4 == 0) {
        return 0;
      }
      puVar1[0xe] = puVar8[0xe];
    }
    uVar2 = 1;
    puVar1[0xf] = puVar8[0xf];
  }
  return uVar2;
}

