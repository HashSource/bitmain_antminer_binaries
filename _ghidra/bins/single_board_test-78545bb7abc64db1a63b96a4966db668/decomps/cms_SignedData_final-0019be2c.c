
undefined4 cms_SignedData_final(CMS_ContentInfo *param_1,undefined4 param_2)

{
  stack_st_CMS_SignerInfo *psVar1;
  int iVar2;
  CMS_SignerInfo *si;
  EVP_MD_CTX *ctx;
  uchar *puVar3;
  code *pcVar4;
  int iVar5;
  EVP_PKEY_CTX *local_80;
  size_t local_70;
  size_t local_6c;
  uint local_68 [17];
  
  iVar5 = 0;
  psVar1 = CMS_get0_SignerInfos(param_1);
  while( true ) {
    iVar2 = OPENSSL_sk_num(psVar1);
    if (iVar2 <= iVar5) {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 8) + 8) = 0;
      return 1;
    }
    si = (CMS_SignerInfo *)OPENSSL_sk_value(psVar1,iVar5);
    ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
    if (ctx == (EVP_MD_CTX *)0x0) {
      ERR_put_error(0x2e,0x96,0x41,"crypto/cms/cms_sd.c",0x234);
      return 0;
    }
    if (*(int *)(si + 0x20) == 0) {
      ERR_put_error(0x2e,0x96,0x85,"crypto/cms/cms_sd.c",0x239);
      local_80 = (EVP_PKEY_CTX *)0x0;
      goto LAB_0019beb4;
    }
    iVar2 = cms_DigestAlgorithm_find_ctx(ctx,param_2,*(undefined4 *)(si + 8));
    if (iVar2 == 0) goto LAB_0019beb2;
    if (*(int *)(si + 0x28) != 0) break;
LAB_0019be96:
    iVar2 = CMS_signed_get_attr_count(si);
    if (iVar2 < 0) {
      local_80 = *(EVP_PKEY_CTX **)(si + 0x28);
      if (local_80 == (EVP_PKEY_CTX *)0x0) {
        iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(si + 0x20));
        puVar3 = (uchar *)CRYPTO_malloc(iVar2,"crypto/cms/cms_sd.c",0x26b);
        if (puVar3 == (uchar *)0x0) {
          iVar5 = 0x26d;
LAB_0019c044:
          ERR_put_error(0x2e,0x96,0x41,"crypto/cms/cms_sd.c",iVar5);
          goto LAB_0019beb4;
        }
        iVar2 = EVP_SignFinal(ctx,puVar3,local_68,*(EVP_PKEY **)(si + 0x20));
        if (iVar2 == 0) {
          ERR_put_error(0x2e,0x96,0x8b,"crypto/cms/cms_sd.c",0x271);
          CRYPTO_free(puVar3);
          goto LAB_0019beb4;
        }
        ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),puVar3,local_68[0]);
      }
      else {
        iVar2 = EVP_DigestFinal_ex(ctx,(uchar *)local_68,&local_6c);
        if (iVar2 == 0) goto LAB_0019beb4;
        local_70 = EVP_PKEY_size(*(EVP_PKEY **)(si + 0x20));
        puVar3 = (uchar *)CRYPTO_malloc(local_70,"crypto/cms/cms_sd.c",0x25e);
        if (puVar3 == (uchar *)0x0) {
          iVar5 = 0x260;
          goto LAB_0019c044;
        }
        iVar2 = EVP_PKEY_sign(local_80,puVar3,&local_70,(uchar *)local_68,local_6c);
        if (iVar2 < 1) {
          CRYPTO_free(puVar3);
          goto LAB_0019beb4;
        }
        ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),puVar3,local_70);
      }
    }
    else {
      iVar2 = EVP_DigestFinal_ex(ctx,(uchar *)local_68,&local_6c);
      if ((((iVar2 == 0) ||
           (iVar2 = CMS_signed_add1_attr_by_NID(si,0x33,4,local_68,local_6c), iVar2 == 0)) ||
          (iVar2 = CMS_signed_add1_attr_by_NID
                             (si,0x32,6,(void *)**(undefined4 **)(*(int *)(param_1 + 4) + 8),-1),
          iVar2 < 1)) || (iVar2 = CMS_SignerInfo_sign(si), iVar2 == 0)) goto LAB_0019beb2;
      local_80 = (EVP_PKEY_CTX *)0x0;
    }
    iVar5 = iVar5 + 1;
    EVP_MD_CTX_free(ctx);
    EVP_PKEY_CTX_free(local_80);
  }
  iVar2 = *(int *)(*(int *)(si + 0x20) + 0xc);
  if ((iVar2 == 0) || (pcVar4 = *(code **)(iVar2 + 0x5c), pcVar4 == (code *)0x0)) goto LAB_0019be96;
  iVar2 = (*pcVar4)(*(int *)(si + 0x20),5,0,si);
  if (iVar2 == -2) {
    ERR_put_error(0x2e,0xaa,0x7d,"crypto/cms/cms_sd.c",0xe7);
  }
  else {
    if (0 < iVar2) goto LAB_0019be96;
    ERR_put_error(0x2e,0xaa,0x6f,"crypto/cms/cms_sd.c",0xeb);
  }
LAB_0019beb2:
  local_80 = (EVP_PKEY_CTX *)0x0;
LAB_0019beb4:
  EVP_MD_CTX_free(ctx);
  EVP_PKEY_CTX_free(local_80);
  return 0;
}

