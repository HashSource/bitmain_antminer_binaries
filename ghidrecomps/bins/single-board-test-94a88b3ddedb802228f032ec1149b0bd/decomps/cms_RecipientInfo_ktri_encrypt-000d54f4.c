
undefined4 cms_RecipientInfo_ktri_encrypt(int param_1,int *param_2)

{
  int iVar1;
  uchar *out;
  undefined4 uVar2;
  EVP_PKEY_CTX *ctx;
  int iVar3;
  int iVar4;
  size_t local_24 [2];
  
  if (*param_2 == 0) {
    iVar3 = param_2[1];
    ctx = *(EVP_PKEY_CTX **)(iVar3 + 0x18);
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0xc);
    if (ctx == (EVP_PKEY_CTX *)0x0) {
      ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(iVar3 + 0x14),(ENGINE *)0x0);
      if (ctx == (EVP_PKEY_CTX *)0x0) goto LAB_000d55be;
      iVar1 = EVP_PKEY_encrypt_init(ctx);
      if (0 < iVar1) goto LAB_000d5542;
LAB_000d55c2:
      uVar2 = 0;
    }
    else {
      iVar1 = cms_env_asn1_ctrl(param_2,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
LAB_000d5542:
        iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,9,0,param_2);
        if (iVar1 < 1) {
          uVar2 = 0;
          ERR_put_error(0x2e,0x8d,0x6e,DAT_000d5604,0x17e);
        }
        else {
          iVar1 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,local_24,*(uchar **)(iVar4 + 0x10),
                                   *(size_t *)(iVar4 + 0x14));
          if (iVar1 < 1) goto LAB_000d55c2;
          out = (uchar *)CRYPTO_malloc(local_24[0],DAT_000d5604,0x185);
          if (out == (uchar *)0x0) {
            ERR_put_error(0x2e,0x8d,0x41,DAT_000d5604,0x188);
            uVar2 = 0;
          }
          else {
            iVar4 = EVP_PKEY_encrypt(ctx,out,local_24,*(uchar **)(iVar4 + 0x10),
                                     *(size_t *)(iVar4 + 0x14));
            if (iVar4 < 1) {
              EVP_PKEY_CTX_free(ctx);
              *(undefined4 *)(iVar3 + 0x18) = 0;
              CRYPTO_free(out);
              return 0;
            }
            uVar2 = 1;
            ASN1_STRING_set0(*(ASN1_STRING **)(iVar3 + 0xc),out,local_24[0]);
          }
        }
      }
    }
    EVP_PKEY_CTX_free(ctx);
    *(undefined4 *)(iVar3 + 0x18) = 0;
  }
  else {
    ERR_put_error(0x2e,0x8d,0x7c,DAT_000d5604,0x168);
LAB_000d55be:
    uVar2 = 0;
  }
  return uVar2;
}

