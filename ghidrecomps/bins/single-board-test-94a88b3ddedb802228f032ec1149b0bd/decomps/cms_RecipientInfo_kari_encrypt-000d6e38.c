
undefined4 cms_RecipientInfo_kari_encrypt(int param_1,int *param_2)

{
  ASN1_ITEM *it;
  int iVar1;
  EVP_CIPHER *pEVar2;
  ulong uVar3;
  void *pvVar4;
  int iVar5;
  ASN1_VALUE *pAVar6;
  EVP_CIPHER_CTX *ctx;
  int *piVar7;
  int iVar8;
  int iVar9;
  _STACK *p_Var10;
  EVP_CIPHER *cipher;
  void *local_28;
  int local_24;
  
  if (*param_2 != 1) {
    ERR_put_error(0x2e,0xb2,0xb5,DAT_000d6f58,0x1ab);
    return 0;
  }
  iVar8 = param_2[1];
  iVar9 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  ctx = (EVP_CIPHER_CTX *)(iVar8 + 0x18);
  p_Var10 = *(_STACK **)(iVar8 + 0x10);
  cipher = *(EVP_CIPHER **)(iVar9 + 0xc);
  iVar1 = EVP_CIPHER_key_length(cipher);
  pEVar2 = EVP_CIPHER_CTX_cipher(ctx);
  if (pEVar2 == (EVP_CIPHER *)0x0) {
    iVar5 = EVP_CIPHER_type(cipher);
    if (iVar5 == 0x2c) {
      pEVar2 = (EVP_CIPHER *)EVP_des_ede3_wrap();
    }
    else if (iVar1 < 0x11) {
      pEVar2 = (EVP_CIPHER *)EVP_aes_128_wrap();
    }
    else if (iVar1 < 0x19) {
      pEVar2 = (EVP_CIPHER *)EVP_aes_192_wrap();
    }
    else {
      pEVar2 = (EVP_CIPHER *)EVP_aes_256_wrap();
    }
    iVar1 = EVP_EncryptInit_ex(ctx,pEVar2,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    uVar3 = EVP_CIPHER_CTX_flags(ctx);
    if ((uVar3 & 0xf0007) != 0x10002) {
      return 0;
    }
  }
  it = DAT_000d6f5c;
  piVar7 = *(int **)(iVar8 + 4);
  if (*piVar7 == -1) {
    *piVar7 = 2;
    pAVar6 = ASN1_item_new(it);
    piVar7[1] = (int)pAVar6;
    if (pAVar6 == (ASN1_VALUE *)0x0) {
      return 0;
    }
  }
  iVar1 = cms_env_asn1_ctrl(param_2,0);
  if (iVar1 != 0) {
    iVar1 = 0;
    while( true ) {
      iVar5 = sk_num(p_Var10);
      if (iVar5 <= iVar1) {
        return 1;
      }
      pvVar4 = sk_value(p_Var10,iVar1);
      iVar5 = EVP_PKEY_derive_set_peer
                        (*(EVP_PKEY_CTX **)(iVar8 + 0x14),*(EVP_PKEY **)((int)pvVar4 + 8));
      if ((iVar5 < 1) ||
         (iVar5 = cms_kek_cipher(&local_28,&local_24,*(undefined4 *)(iVar9 + 0x10),
                                 *(undefined4 *)(iVar9 + 0x14),iVar8,1), iVar5 == 0)) break;
      ASN1_STRING_set0(*(ASN1_STRING **)((int)pvVar4 + 4),local_28,local_24);
      iVar1 = iVar1 + 1;
    }
  }
  return 0;
}

