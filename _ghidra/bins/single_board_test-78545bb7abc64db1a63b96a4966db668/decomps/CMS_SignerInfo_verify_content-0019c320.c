
int CMS_SignerInfo_verify_content(CMS_SignerInfo *si,BIO *chain)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  ASN1_OBJECT *oid;
  size_t *psVar2;
  EVP_PKEY_CTX *ctx_00;
  EVP_MD *p2;
  code *pcVar3;
  int line;
  size_t local_64;
  uchar auStack_60 [68];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    line = 0x32d;
    iVar1 = 0x41;
LAB_0019c3d4:
    ERR_put_error(0x2e,0x9a,iVar1,"crypto/cms/cms_sd.c",line);
  }
  else {
    iVar1 = CMS_signed_get_attr_count(si);
    if (iVar1 < 0) {
      psVar2 = (size_t *)0x0;
    }
    else {
      oid = OBJ_nid2obj(0x33);
      psVar2 = (size_t *)CMS_signed_get0_data_by_OBJ(si,oid,-3,4);
      if (psVar2 == (size_t *)0x0) {
        iVar1 = -1;
        ERR_put_error(0x2e,0x9a,0x72,"crypto/cms/cms_sd.c",0x337);
        ctx_00 = (EVP_PKEY_CTX *)0x0;
        goto LAB_0019c396;
      }
    }
    iVar1 = cms_DigestAlgorithm_find_ctx(ctx,chain,*(undefined4 *)(si + 8));
    if (iVar1 != 0) {
      iVar1 = EVP_DigestFinal_ex(ctx,auStack_60,&local_64);
      if (iVar1 < 1) {
        line = 0x341;
        iVar1 = 0x93;
      }
      else {
        if (psVar2 == (size_t *)0x0) {
          p2 = EVP_MD_CTX_md(ctx);
          ctx_00 = EVP_PKEY_CTX_new(*(EVP_PKEY **)(si + 0x20),(ENGINE *)0x0);
          if (ctx_00 == (EVP_PKEY_CTX *)0x0) goto LAB_0019c3dc;
          iVar1 = EVP_PKEY_verify_init(ctx_00);
          if (0 < iVar1) {
            iVar1 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,p2);
            if (0 < iVar1) {
              *(EVP_PKEY_CTX **)(si + 0x28) = ctx_00;
              iVar1 = *(int *)(*(int *)(si + 0x20) + 0xc);
              if ((iVar1 == 0) || (pcVar3 = *(code **)(iVar1 + 0x5c), pcVar3 == (code *)0x0)) {
LAB_0019c436:
                iVar1 = EVP_PKEY_verify(ctx_00,(uchar *)(*(size_t **)(si + 0x14))[2],
                                        **(size_t **)(si + 0x14),auStack_60,local_64);
                if (iVar1 < 1) {
                  iVar1 = 0;
                  ERR_put_error(0x2e,0x9a,0x9e,"crypto/cms/cms_sd.c",0x364);
                }
                goto LAB_0019c396;
              }
              iVar1 = (*pcVar3)(*(int *)(si + 0x20),5,1,si);
              if (iVar1 == -2) {
                ERR_put_error(0x2e,0xaa,0x7d,"crypto/cms/cms_sd.c",0xe7);
              }
              else {
                if (0 < iVar1) goto LAB_0019c436;
                ERR_put_error(0x2e,0xaa,0x6f,"crypto/cms/cms_sd.c",0xeb);
              }
            }
          }
          iVar1 = -1;
          goto LAB_0019c396;
        }
        if (*psVar2 == local_64) {
          ctx_00 = (EVP_PKEY_CTX *)memcmp(auStack_60,(void *)psVar2[2],*psVar2);
          iVar1 = 1;
          if (ctx_00 != (EVP_PKEY_CTX *)0x0) {
            iVar1 = 0;
            ERR_put_error(0x2e,0x9a,0x9e,"crypto/cms/cms_sd.c",0x350);
            ctx_00 = (EVP_PKEY_CTX *)0x0;
          }
          goto LAB_0019c396;
        }
        line = 0x34a;
        iVar1 = 0x78;
      }
      goto LAB_0019c3d4;
    }
  }
LAB_0019c3dc:
  iVar1 = -1;
  ctx_00 = (EVP_PKEY_CTX *)0x0;
LAB_0019c396:
  EVP_PKEY_CTX_free(ctx_00);
  EVP_MD_CTX_free(ctx);
  return iVar1;
}

