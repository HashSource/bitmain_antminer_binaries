
int cms_DigestedData_do_final(int param_1,undefined4 param_2,int param_3)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  size_t __n;
  int iVar2;
  size_t local_5c;
  uchar auStack_58 [68];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    ERR_put_error(0x2e,0x75,0x41,"crypto/cms/cms_dd.c",0x40);
    EVP_MD_CTX_free(0);
    return 0;
  }
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = cms_DigestAlgorithm_find_ctx(ctx,param_2,*(undefined4 *)(iVar2 + 4));
  if (iVar1 != 0) {
    iVar1 = EVP_DigestFinal_ex(ctx,auStack_58,&local_5c);
    if (0 < iVar1) {
      if (param_3 == 0) {
        iVar1 = ASN1_STRING_set(*(ASN1_STRING **)(iVar2 + 0xc),auStack_58,local_5c);
        if (iVar1 != 0) {
          iVar1 = 1;
        }
        goto LAB_001ccca6;
      }
      __n = **(size_t **)(iVar2 + 0xc);
      if (__n != local_5c) {
        iVar1 = 0;
        ERR_put_error(0x2e,0x75,0x79,"crypto/cms/cms_dd.c",0x4f);
        goto LAB_001ccca6;
      }
      iVar2 = memcmp(auStack_58,(void *)(*(size_t **)(iVar2 + 0xc))[2],__n);
      iVar1 = 1;
      if (iVar2 == 0) goto LAB_001ccca6;
      ERR_put_error(0x2e,0x75,0x9e,"crypto/cms/cms_dd.c",0x55);
    }
  }
  iVar1 = 0;
LAB_001ccca6:
  EVP_MD_CTX_free(ctx);
  return iVar1;
}

