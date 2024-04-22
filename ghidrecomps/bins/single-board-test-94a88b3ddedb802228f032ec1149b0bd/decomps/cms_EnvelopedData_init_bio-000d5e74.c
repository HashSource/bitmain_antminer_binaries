
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
  _STACK **pp_Var8;
  int *piVar9;
  int iVar10;
  
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  a = (BIO *)cms_EncryptedContent_init_bio(iVar10);
  if (a == (BIO *)0x0) {
    return (BIO *)0x0;
  }
  if (*(int *)(iVar10 + 0xc) == 0) {
    return a;
  }
  iVar4 = 0;
  p_Var7 = *(_STACK **)(*(int *)(param_1 + 4) + 8);
  do {
    iVar1 = sk_num(p_Var7);
    if (iVar1 <= iVar4) {
      piVar9 = *(int **)(param_1 + 4);
      iVar4 = *piVar9;
      if (3 < iVar4) goto LAB_000d5f3c;
      pp_Var8 = (_STACK **)piVar9[1];
      if (pp_Var8 == (_STACK **)0x0) goto LAB_000d5f98;
      iVar4 = 0;
      goto LAB_000d5f46;
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
      ERR_put_error(0x2e,0xa9,0x9a,DAT_000d5fec,0x34b);
      goto LAB_000d5efc;
    }
    iVar4 = iVar4 + 1;
  } while (0 < iVar1);
LAB_000d5efc:
  bVar6 = false;
  ERR_put_error(0x2e,0x7d,0x74,DAT_000d5fec,0x3a9);
  goto LAB_000d5f10;
LAB_000d5f46:
  iVar1 = sk_num(*pp_Var8);
  iVar5 = iVar4 + 1;
  if (iVar4 < iVar1) {
    piVar3 = (int *)sk_value(*pp_Var8,iVar4);
    iVar1 = *piVar3;
    if (iVar1 == 4) goto LAB_000d5f72;
    iVar4 = iVar5;
    if ((iVar1 == 3) && (*piVar9 < 3)) {
      *piVar9 = 3;
    }
    goto LAB_000d5f46;
  }
  iVar4 = 0;
LAB_000d5f86:
  iVar1 = sk_num(pp_Var8[1]);
  if (iVar4 < iVar1) goto LAB_000d5f7a;
  iVar4 = *piVar9;
LAB_000d5f98:
  if (iVar4 < 3) {
    iVar4 = 0;
    while( true ) {
      iVar1 = sk_num((_STACK *)piVar9[2]);
      iVar5 = iVar4 + 1;
      if (iVar1 <= iVar4) break;
      piVar3 = (int *)sk_value((_STACK *)piVar9[2],iVar4);
      if (*piVar3 - 3U < 2) {
        bVar6 = true;
        *piVar9 = 3;
        goto LAB_000d5f10;
      }
      iVar4 = iVar5;
      if ((*piVar3 != 0) || (*(int *)piVar3[1] != 0)) {
        *piVar9 = 2;
      }
    }
    if (*piVar9 != 2) {
      bVar6 = true;
      *piVar9 = 0;
      goto LAB_000d5f10;
    }
  }
  goto LAB_000d5f3c;
LAB_000d5f7a:
  piVar3 = (int *)sk_value(pp_Var8[1],iVar4);
  iVar4 = iVar4 + 1;
  if (*piVar3 == 1) goto LAB_000d5f70;
  goto LAB_000d5f86;
LAB_000d5f70:
  iVar1 = 4;
LAB_000d5f72:
  *piVar9 = iVar1;
LAB_000d5f3c:
  bVar6 = true;
LAB_000d5f10:
  *(undefined4 *)(iVar10 + 0xc) = 0;
  if (*(void **)(iVar10 + 0x10) != (void *)0x0) {
    OPENSSL_cleanse(*(void **)(iVar10 + 0x10),*(size_t *)(iVar10 + 0x14));
    CRYPTO_free(*(void **)(iVar10 + 0x10));
    *(undefined4 *)(iVar10 + 0x10) = 0;
    *(undefined4 *)(iVar10 + 0x14) = 0;
  }
  if (!bVar6) {
    BIO_free(a);
    a = (BIO *)0x0;
  }
  return a;
}

