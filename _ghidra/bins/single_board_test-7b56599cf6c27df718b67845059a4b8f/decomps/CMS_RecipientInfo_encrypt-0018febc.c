
uchar * CMS_RecipientInfo_encrypt(int param_1,undefined4 *param_2)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  EVP_PKEY_CTX *ctx;
  int iVar5;
  AES_KEY local_114;
  
  puVar2 = (uchar *)*param_2;
  switch(puVar2) {
  case (uchar *)0x0:
    break;
  case (uchar *)0x1:
    puVar2 = (uchar *)cms_RecipientInfo_kari_encrypt();
    return puVar2;
  case (uchar *)0x2:
    iVar4 = param_2[1];
    iVar5 = *(int *)(*(int *)(param_1 + 4) + 0xc);
    if (*(uchar **)(iVar4 + 0x10) == (uchar *)0x0) {
      ERR_put_error(0x2e,0x88,0x82,"crypto/cms/cms_env.c",0x284);
      return (uchar *)0x0;
    }
    iVar1 = AES_set_encrypt_key(*(uchar **)(iVar4 + 0x10),*(int *)(iVar4 + 0x14) << 3,&local_114);
    if (iVar1 == 0) {
      puVar2 = (uchar *)CRYPTO_malloc(*(int *)(iVar5 + 0x14) + 8,"crypto/cms/cms_env.c",0x28e);
      if (puVar2 == (uchar *)0x0) {
        ERR_put_error(0x2e,0x88,0x41,"crypto/cms/cms_env.c",0x291);
      }
      else {
        iVar5 = AES_wrap_key(&local_114,(uchar *)0x0,puVar2,*(uchar **)(iVar5 + 0x10),
                             *(uint *)(iVar5 + 0x14));
        if (0 < iVar5) {
          puVar3 = (uchar *)0x1;
          ASN1_STRING_set0(*(ASN1_STRING **)(iVar4 + 0xc),puVar2,iVar5);
          goto LAB_0018ff2e;
        }
        ERR_put_error(0x2e,0x88,0x9f,"crypto/cms/cms_env.c",0x298);
      }
    }
    else {
      puVar2 = (uchar *)0x0;
      ERR_put_error(0x2e,0x88,0x73,"crypto/cms/cms_env.c",0x28a);
    }
    puVar3 = (uchar *)0x0;
    CRYPTO_free(puVar2);
LAB_0018ff2e:
    OPENSSL_cleanse(&local_114,0xf4);
    return puVar3;
  case (uchar *)0x3:
    puVar2 = (uchar *)cms_RecipientInfo_pwri_crypt(param_1,param_2,1);
    return puVar2;
  default:
    ERR_put_error(0x2e,0xa9,0x9a,"crypto/cms/cms_env.c",0x318);
    return (uchar *)0x0;
  }
  iVar4 = param_2[1];
  ctx = *(EVP_PKEY_CTX **)(iVar4 + 0x18);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(iVar4 + 0x14),(ENGINE *)0x0);
    if (ctx == (EVP_PKEY_CTX *)0x0) {
      return puVar2;
    }
    iVar1 = EVP_PKEY_encrypt_init(ctx);
    if (iVar1 < 1) {
      puVar2 = (uchar *)0x0;
      puVar3 = (uchar *)0x0;
      goto LAB_0018fffe;
    }
  }
  else {
    puVar2 = (uchar *)cms_env_asn1_ctrl(param_2,0);
    puVar3 = puVar2;
    if (puVar2 == (uchar *)0x0) goto LAB_0018fffe;
  }
  puVar2 = (uchar *)0x0;
  iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,9,0,param_2);
  if (iVar1 < 1) {
    puVar3 = (uchar *)0x0;
    ERR_put_error(0x2e,0x8d,0x6e,"crypto/cms/cms_env.c",0x146);
  }
  else {
    iVar1 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,local_114.rd_key,*(uchar **)(iVar5 + 0x10),
                             *(size_t *)(iVar5 + 0x14));
    if (iVar1 < 1) {
      puVar3 = (uchar *)0x0;
    }
    else {
      puVar3 = (uchar *)CRYPTO_malloc(local_114.rd_key[0],"crypto/cms/cms_env.c",0x14d);
      if (puVar3 == (uchar *)0x0) {
        ERR_put_error(0x2e,0x8d,0x41,"crypto/cms/cms_env.c",0x150);
        puVar2 = (uchar *)0x0;
      }
      else {
        iVar5 = EVP_PKEY_encrypt(ctx,puVar3,local_114.rd_key,*(uchar **)(iVar5 + 0x10),
                                 *(size_t *)(iVar5 + 0x14));
        if (0 < iVar5) {
          puVar2 = (uchar *)0x1;
          ASN1_STRING_set0(*(ASN1_STRING **)(iVar4 + 0xc),puVar3,local_114.rd_key[0]);
          puVar3 = (uchar *)0x0;
        }
      }
    }
  }
LAB_0018fffe:
  EVP_PKEY_CTX_free(ctx);
  *(undefined4 *)(iVar4 + 0x18) = 0;
  CRYPTO_free(puVar3);
  return puVar2;
}

