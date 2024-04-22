
int CMS_SignerInfo_verify_content(CMS_SignerInfo *si,BIO *chain)

{
  int iVar1;
  ASN1_OBJECT *oid;
  size_t *psVar2;
  int iVar3;
  EVP_MD *p2;
  EVP_PKEY_CTX *ctx;
  code *pcVar4;
  size_t local_74;
  EVP_MD_CTX EStack_70;
  uchar auStack_58 [68];
  
  EVP_MD_CTX_init(&EStack_70);
  iVar1 = CMS_signed_get_attr_count(si);
  if (iVar1 < 0) {
    psVar2 = (size_t *)0x0;
  }
  else {
    oid = OBJ_nid2obj(0x33);
    psVar2 = (size_t *)CMS_signed_get0_data_by_OBJ(si,oid,-3,4);
    if (psVar2 == (size_t *)0x0) {
      ERR_put_error(0x2e,0x9a,0x72,DAT_00110e10,0x33c);
      iVar1 = -1;
      goto LAB_00110cec;
    }
  }
  iVar1 = cms_DigestAlgorithm_find_ctx(&EStack_70,chain,*(undefined4 *)(si + 8));
  if (iVar1 == 0) {
    iVar1 = -1;
    goto LAB_00110cec;
  }
  iVar1 = EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_74);
  if (iVar1 < 1) {
    ERR_put_error(0x2e,0x9a,0x93,DAT_00110e10,0x346);
    iVar1 = -1;
    goto LAB_00110cec;
  }
  if (psVar2 != (size_t *)0x0) {
    if (*psVar2 == local_74) {
      iVar3 = memcmp(auStack_58,(void *)psVar2[2],*psVar2);
      iVar1 = 1;
      if (iVar3 != 0) {
        ERR_put_error(0x2e,0x9a,0x9e,DAT_00110e10,0x355);
        iVar1 = 0;
      }
    }
    else {
      ERR_put_error(0x2e,0x9a,0x78,DAT_00110e10,0x34f);
      iVar1 = -1;
    }
    goto LAB_00110cec;
  }
  p2 = EVP_MD_CTX_md(&EStack_70);
  ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(si + 0x20),(ENGINE *)0x0);
  iVar1 = EVP_PKEY_verify_init(ctx);
  if (iVar1 < 1) {
LAB_00110dc6:
    iVar1 = -1;
  }
  else {
    iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0xf8,1,0,p2);
    if (iVar1 < 1) goto LAB_00110dc6;
    *(EVP_PKEY_CTX **)(si + 0x3c) = ctx;
    iVar1 = *(int *)(*(int *)(si + 0x20) + 0xc);
    if ((iVar1 != 0) && (pcVar4 = *(code **)(iVar1 + 0x58), pcVar4 != (code *)0x0)) {
      iVar1 = (*pcVar4)(*(int *)(si + 0x20),5,1,si);
      if (iVar1 == -2) {
        ERR_put_error(0x2e,0xaa,0x7d,DAT_00110e10,0x100);
      }
      else {
        if (0 < iVar1) goto LAB_00110d64;
        ERR_put_error(0x2e,0xaa,0x6f,DAT_00110e10,0x104);
      }
      goto LAB_00110dc6;
    }
LAB_00110d64:
    iVar1 = EVP_PKEY_verify(ctx,(uchar *)(*(size_t **)(si + 0x14))[2],**(size_t **)(si + 0x14),
                            auStack_58,local_74);
    if (iVar1 < 1) {
      iVar1 = 0;
      ERR_put_error(0x2e,0x9a,0x9e,DAT_00110e10,0x367);
    }
  }
  if (ctx != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(ctx);
  }
LAB_00110cec:
  EVP_MD_CTX_cleanup(&EStack_70);
  return iVar1;
}

