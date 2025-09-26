
BIO * cms_EnvelopedData_init_bio(int param_1)

{
  BIO *a;
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  _STACK *p_Var7;
  int *piVar8;
  int iVar9;
  
  iVar9 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  a = (BIO *)cms_EncryptedContent_init_bio(iVar9);
  if (a == (BIO *)0x0) {
    return (BIO *)0x0;
  }
  if (*(int *)(iVar9 + 0xc) == 0) {
    return a;
  }
  iVar4 = 0;
  p_Var7 = *(_STACK **)(*(int *)(param_1 + 4) + 8);
  do {
    iVar1 = sk_num(p_Var7);
    if (iVar1 <= iVar4) {
      piVar8 = *(int **)(param_1 + 4);
      iVar4 = *piVar8;
      if (3 < iVar4) goto LAB_001711c0;
      puVar2 = (undefined4 *)piVar8[1];
      if (puVar2 == (undefined4 *)0x0) goto LAB_0017121c;
      iVar4 = 0;
      goto LAB_001711ca;
    }
    puVar2 = (undefined4 *)sk_value(p_Var7,iVar4);
    switch(*puVar2) {
    case 0:
      iVar1 = cms_RecipientInfo_ktri_encrypt(param_1,puVar2);
      break;
    case 1:
      iVar1 = cms_RecipientInfo_kari_encrypt(param_1,puVar2);
      break;
    case 2:
      iVar1 = cms_RecipientInfo_kekri_encrypt(param_1,puVar2);
      break;
    case 3:
      iVar1 = cms_RecipientInfo_pwri_crypt(param_1,puVar2,1);
      break;
    default:
      ERR_put_error(0x2e,0xa9,0x9a,"cms_env.c",0x34b);
      goto LAB_00171180;
    }
    iVar4 = iVar4 + 1;
  } while (0 < iVar1);
LAB_00171180:
  bVar6 = false;
  ERR_put_error(0x2e,0x7d,0x74,"cms_env.c",0x3a9);
  goto LAB_00171194;
LAB_001711ca:
  iVar1 = sk_num((_STACK *)*puVar2);
  iVar5 = iVar4 + 1;
  if (iVar4 < iVar1) {
    piVar3 = (int *)sk_value((_STACK *)*puVar2,iVar4);
    iVar1 = *piVar3;
    if (iVar1 == 4) goto LAB_001711f6;
    iVar4 = iVar5;
    if ((iVar1 == 3) && (*piVar8 < 3)) {
      *piVar8 = 3;
    }
    goto LAB_001711ca;
  }
  iVar4 = 0;
LAB_0017120a:
  iVar1 = sk_num((_STACK *)puVar2[1]);
  if (iVar4 < iVar1) goto LAB_001711fe;
  iVar4 = *piVar8;
LAB_0017121c:
  if (iVar4 < 3) {
    iVar4 = 0;
    while( true ) {
      iVar1 = sk_num((_STACK *)piVar8[2]);
      iVar5 = iVar4 + 1;
      if (iVar1 <= iVar4) break;
      piVar3 = (int *)sk_value((_STACK *)piVar8[2],iVar4);
      if (*piVar3 - 3U < 2) {
        bVar6 = true;
        *piVar8 = 3;
        goto LAB_00171194;
      }
      iVar4 = iVar5;
      if ((*piVar3 != 0) || (*(int *)piVar3[1] != 0)) {
        *piVar8 = 2;
      }
    }
    if (*piVar8 != 2) {
      bVar6 = true;
      *piVar8 = 0;
      goto LAB_00171194;
    }
  }
  goto LAB_001711c0;
LAB_001711fe:
  piVar3 = (int *)sk_value((_STACK *)puVar2[1],iVar4);
  iVar4 = iVar4 + 1;
  if (*piVar3 == 1) goto LAB_001711f4;
  goto LAB_0017120a;
LAB_001711f4:
  iVar1 = 4;
LAB_001711f6:
  *piVar8 = iVar1;
LAB_001711c0:
  bVar6 = true;
LAB_00171194:
  *(undefined4 *)(iVar9 + 0xc) = 0;
  if (*(void **)(iVar9 + 0x10) != (void *)0x0) {
    OPENSSL_cleanse(*(void **)(iVar9 + 0x10),*(size_t *)(iVar9 + 0x14));
    CRYPTO_free(*(void **)(iVar9 + 0x10));
    *(undefined4 *)(iVar9 + 0x10) = 0;
    *(undefined4 *)(iVar9 + 0x14) = 0;
  }
  if (!bVar6) {
    BIO_free(a);
    a = (BIO *)0x0;
  }
  return a;
}

