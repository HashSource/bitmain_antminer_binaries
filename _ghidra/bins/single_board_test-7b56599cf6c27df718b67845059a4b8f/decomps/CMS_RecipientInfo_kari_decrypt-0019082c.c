
int CMS_RecipientInfo_kari_decrypt(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uchar *in;
  uchar *out;
  uint local_70;
  int local_6c;
  uchar auStack_68 [68];
  
  iVar3 = **(int **)(param_3 + 4);
  in = (uchar *)(*(int **)(param_3 + 4))[2];
  iVar1 = cms_env_asn1_ctrl(param_2,1);
  if (iVar1 == 0) goto LAB_00190848;
  iVar2 = *(int *)(param_2 + 4);
  local_70 = EVP_CIPHER_CTX_key_length(*(EVP_CIPHER_CTX **)(iVar2 + 0x18));
  if (0x40 < local_70) {
    iVar1 = 0;
    goto LAB_00190848;
  }
  iVar1 = EVP_PKEY_derive(*(EVP_PKEY_CTX **)(iVar2 + 0x14),auStack_68,&local_70);
  if ((iVar1 < 1) ||
     (iVar1 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(iVar2 + 0x18),(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                auStack_68,(uchar *)0x0,0), iVar1 == 0)) {
LAB_0019089a:
    out = (uchar *)0x0;
  }
  else {
    iVar1 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(iVar2 + 0x18),(uchar *)0x0,&local_6c,in,iVar3);
    if ((iVar1 == 0) ||
       (out = (uchar *)CRYPTO_malloc(local_6c,"crypto/cms/cms_kari.c",0xd0), out == (uchar *)0x0))
    goto LAB_0019089a;
    iVar1 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(iVar2 + 0x18),out,&local_6c,in,iVar3);
    if (iVar1 != 0) {
      iVar1 = 1;
      OPENSSL_cleanse(auStack_68,local_70);
      EVP_CIPHER_CTX_reset(*(undefined4 *)(iVar2 + 0x18));
      EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar2 + 0x14));
      *(undefined4 *)(iVar2 + 0x14) = 0;
      iVar3 = *(int *)(*(int *)(param_1 + 4) + 0xc);
      CRYPTO_clear_free(*(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14),
                        "crypto/cms/cms_kari.c",0xf6);
      *(int *)(iVar3 + 0x14) = local_6c;
      *(uchar **)(iVar3 + 0x10) = out;
      goto LAB_00190848;
    }
  }
  OPENSSL_cleanse(auStack_68,local_70);
  CRYPTO_free(out);
  EVP_CIPHER_CTX_reset(*(undefined4 *)(iVar2 + 0x18));
  EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar2 + 0x14));
  iVar1 = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
LAB_00190848:
  CRYPTO_free((void *)0x0);
  return iVar1;
}

