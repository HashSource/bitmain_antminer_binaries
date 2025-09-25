
BIO * cms_EnvelopedData_init_bio(int param_1)

{
  BIO *a;
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  undefined8 uVar10;
  
  iVar9 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  a = (BIO *)cms_EncryptedContent_init_bio(iVar9);
  if ((a == (BIO *)0x0) || (*(int *)(iVar9 + 0xc) == 0)) {
    return a;
  }
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 4) + 8);
  iVar4 = 0;
  while( true ) {
    iVar2 = OPENSSL_sk_num(uVar6);
    if (iVar2 <= iVar4) break;
    uVar1 = OPENSSL_sk_value(uVar6,iVar4);
    iVar2 = CMS_RecipientInfo_encrypt(param_1,uVar1);
    iVar4 = iVar4 + 1;
    if (iVar2 < 1) {
      ERR_put_error(0x2e,0x7d,0x74,"crypto/cms/cms_env.c",0x376);
      *(undefined4 *)(iVar9 + 0xc) = 0;
      CRYPTO_clear_free(*(undefined4 *)(iVar9 + 0x10),*(undefined4 *)(iVar9 + 0x14),
                        "crypto/cms/cms_env.c",0x380);
      *(undefined4 *)(iVar9 + 0x10) = 0;
      *(undefined4 *)(iVar9 + 0x14) = 0;
      BIO_free(a);
      return (BIO *)0x0;
    }
  }
  piVar8 = *(int **)(param_1 + 4);
  iVar4 = *piVar8;
  if (3 < iVar4) goto LAB_0018bf0c;
  puVar7 = (undefined4 *)piVar8[1];
  if (puVar7 == (undefined4 *)0x0) {
LAB_0018bfd4:
    if (2 < iVar4) goto LAB_0018bf0c;
    iVar4 = 0;
    while( true ) {
      iVar2 = OPENSSL_sk_num(piVar8[2]);
      iVar5 = iVar4 + 1;
      if (iVar2 <= iVar4) break;
      piVar3 = (int *)OPENSSL_sk_value(piVar8[2],iVar4);
      if (*piVar3 - 3U < 2) {
        *piVar8 = 3;
        goto LAB_0018bf0c;
      }
      iVar4 = iVar5;
      if ((*piVar3 != 0) || (*(int *)piVar3[1] != 0)) {
        *piVar8 = 2;
      }
    }
    if ((piVar8[1] != 0) || (piVar8[4] != 0)) {
      *piVar8 = 2;
      goto LAB_0018bf0c;
    }
    iVar2 = 0;
    if (*piVar8 == 2) goto LAB_0018bf0c;
  }
  else {
    iVar4 = 0;
    while( true ) {
      iVar2 = OPENSSL_sk_num(*puVar7);
      iVar5 = iVar4 + 1;
      if (iVar2 <= iVar4) break;
      piVar3 = (int *)OPENSSL_sk_value(*puVar7);
      iVar2 = *piVar3;
      if (iVar2 == 4) goto LAB_0018bfae;
      iVar4 = iVar5;
      if ((iVar2 == 3) && (*piVar8 < 3)) {
        *piVar8 = 3;
      }
    }
    iVar2 = 0;
    do {
      iVar4 = OPENSSL_sk_num(puVar7[1],iVar4);
      if (iVar4 <= iVar2) {
        iVar4 = *piVar8;
        goto LAB_0018bfd4;
      }
      uVar10 = OPENSSL_sk_value(puVar7[1],iVar2);
      iVar4 = (int)((ulonglong)uVar10 >> 0x20);
      iVar2 = iVar2 + 1;
    } while (*(int *)uVar10 != 1);
    iVar2 = 4;
  }
LAB_0018bfae:
  *piVar8 = iVar2;
LAB_0018bf0c:
  *(undefined4 *)(iVar9 + 0xc) = 0;
  CRYPTO_clear_free(*(undefined4 *)(iVar9 + 0x10),*(undefined4 *)(iVar9 + 0x14),
                    "crypto/cms/cms_env.c",0x380);
  *(undefined4 *)(iVar9 + 0x10) = 0;
  *(undefined4 *)(iVar9 + 0x14) = 0;
  return a;
}

