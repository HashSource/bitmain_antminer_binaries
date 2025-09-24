
undefined4 cms_RecipientInfo_kari_encrypt(int param_1,int *param_2)

{
  int iVar1;
  EVP_CIPHER *pEVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ASN1_VALUE *pAVar7;
  int iVar8;
  undefined4 uVar9;
  uchar *in;
  EVP_CIPHER_CTX *ctx;
  int *piVar10;
  EVP_CIPHER *cipher;
  int iVar11;
  uchar *local_8c;
  uint local_70;
  int local_6c;
  uchar auStack_68 [68];
  
  if (*param_2 == 1) {
    iVar8 = param_2[1];
    iVar11 = *(int *)(*(int *)(param_1 + 4) + 0xc);
    ctx = *(EVP_CIPHER_CTX **)(iVar8 + 0x18);
    uVar9 = *(undefined4 *)(iVar8 + 0x10);
    cipher = *(EVP_CIPHER **)(iVar11 + 0xc);
    iVar1 = EVP_CIPHER_key_length(cipher);
    pEVar2 = EVP_CIPHER_CTX_cipher(ctx);
    if (pEVar2 == (EVP_CIPHER *)0x0) {
      iVar4 = EVP_CIPHER_type(cipher);
      if (iVar4 == 0x2c) {
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
      pEVar2 = EVP_CIPHER_CTX_cipher(ctx);
      uVar3 = EVP_CIPHER_flags(pEVar2);
      if ((uVar3 & 0xf0007) != 0x10002) {
        return 0;
      }
    }
    piVar10 = *(int **)(iVar8 + 4);
    if (*piVar10 == -1) {
      *piVar10 = 2;
      pAVar7 = ASN1_item_new((ASN1_ITEM *)CMS_OriginatorPublicKey_it);
      piVar10[1] = (int)pAVar7;
      if (pAVar7 == (ASN1_VALUE *)0x0) {
        return 0;
      }
    }
    iVar1 = cms_env_asn1_ctrl(param_2,0);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = 0;
    while (iVar4 = OPENSSL_sk_num(uVar9), iVar1 < iVar4) {
      iVar4 = OPENSSL_sk_value(uVar9,iVar1);
      iVar5 = EVP_PKEY_derive_set_peer(*(EVP_PKEY_CTX **)(iVar8 + 0x14),*(EVP_PKEY **)(iVar4 + 8));
      if (iVar5 < 1) {
        return 0;
      }
      iVar5 = *(int *)(iVar11 + 0x14);
      in = *(uchar **)(iVar11 + 0x10);
      local_70 = EVP_CIPHER_CTX_key_length(*(EVP_CIPHER_CTX **)(iVar8 + 0x18));
      if (0x40 < local_70) {
        return 0;
      }
      iVar6 = EVP_PKEY_derive(*(EVP_PKEY_CTX **)(iVar8 + 0x14),auStack_68,&local_70);
      if ((iVar6 < 1) ||
         (iVar6 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(iVar8 + 0x18),(EVP_CIPHER *)0x0,
                                    (ENGINE *)0x0,auStack_68,(uchar *)0x0,1), iVar6 == 0)) {
LAB_00190ba4:
        local_8c = (uchar *)0x0;
LAB_00190ba8:
        OPENSSL_cleanse(auStack_68,local_70);
        CRYPTO_free(local_8c);
        EVP_CIPHER_CTX_reset(*(undefined4 *)(iVar8 + 0x18));
        EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar8 + 0x14));
        *(undefined4 *)(iVar8 + 0x14) = 0;
        return 0;
      }
      iVar6 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(iVar8 + 0x18),(uchar *)0x0,&local_6c,in,iVar5);
      if ((iVar6 == 0) ||
         (local_8c = (uchar *)CRYPTO_malloc(local_6c,"crypto/cms/cms_kari.c",0xd0),
         local_8c == (uchar *)0x0)) goto LAB_00190ba4;
      iVar1 = iVar1 + 1;
      iVar6 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(iVar8 + 0x18),local_8c,&local_6c,in,iVar5);
      iVar5 = local_6c;
      if (iVar6 == 0) goto LAB_00190ba8;
      OPENSSL_cleanse(auStack_68,local_70);
      EVP_CIPHER_CTX_reset(*(undefined4 *)(iVar8 + 0x18));
      EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar8 + 0x14));
      *(undefined4 *)(iVar8 + 0x14) = 0;
      ASN1_STRING_set0(*(ASN1_STRING **)(iVar4 + 4),local_8c,iVar5);
    }
    uVar9 = 1;
  }
  else {
    uVar9 = 0;
    ERR_put_error(0x2e,0xb2,0xb5,"crypto/cms/cms_kari.c",0x178);
  }
  return uVar9;
}

