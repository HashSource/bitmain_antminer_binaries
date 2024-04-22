
int CMS_SignerInfo_verify(CMS_SignerInfo *si)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  EVP_MD_CTX *ctx;
  code *pcVar2;
  uchar *local_1c [2];
  
  ctx = (EVP_MD_CTX *)(si + 0x24);
  local_1c[0] = (uchar *)0x0;
  if (*(int *)(si + 0x20) == 0) {
    ERR_put_error(0x2e,0x98,0x86,DAT_00110b24,0x2ec);
    return -1;
  }
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(si + 8));
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    return -1;
  }
  EVP_MD_CTX_init(ctx);
  iVar1 = EVP_DigestVerifyInit
                    (ctx,(EVP_PKEY_CTX **)(si + 0x3c),type,(ENGINE *)0x0,*(EVP_PKEY **)(si + 0x20));
  if (0 < iVar1) {
    iVar1 = *(int *)(*(int *)(si + 0x20) + 0xc);
    if ((iVar1 == 0) || (pcVar2 = *(code **)(iVar1 + 0x58), pcVar2 == (code *)0x0)) {
LAB_00110a84:
      cnt = ASN1_item_i2d(*(ASN1_VALUE **)(si + 0xc),local_1c,DAT_00110b20);
      if (local_1c[0] != (uchar *)0x0) {
        iVar1 = EVP_DigestUpdate(ctx,local_1c[0],cnt);
        CRYPTO_free(local_1c[0]);
        if (0 < iVar1) {
          iVar1 = EVP_DigestVerifyFinal
                            (ctx,(uchar *)(*(size_t **)(si + 0x14))[2],**(size_t **)(si + 0x14));
          if (iVar1 < 1) {
            ERR_put_error(0x2e,0x98,0x9e,DAT_00110b24,0x307);
          }
          goto LAB_00110ae0;
        }
      }
    }
    else {
      iVar1 = (*pcVar2)(*(int *)(si + 0x20),5,1,si);
      if (iVar1 == -2) {
        ERR_put_error(0x2e,0xaa,0x7d,DAT_00110b24,0x100);
      }
      else {
        if (0 < iVar1) goto LAB_00110a84;
        ERR_put_error(0x2e,0xaa,0x6f,DAT_00110b24,0x104);
      }
    }
  }
  iVar1 = -1;
LAB_00110ae0:
  EVP_MD_CTX_cleanup(ctx);
  return iVar1;
}

