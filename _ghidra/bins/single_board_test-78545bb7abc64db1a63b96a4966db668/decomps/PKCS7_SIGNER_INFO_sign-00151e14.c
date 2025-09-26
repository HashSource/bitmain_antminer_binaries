
int PKCS7_SIGNER_INFO_sign(PKCS7_SIGNER_INFO *si)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  EVP_MD_CTX *ctx;
  size_t cnt;
  EVP_PKEY_CTX *local_2c;
  uchar *local_28;
  size_t local_24 [2];
  
  local_2c = (EVP_PKEY_CTX *)0x0;
  local_28 = (uchar *)0x0;
  iVar1 = OBJ_obj2nid(si->digest_alg->algorithm);
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    return 0;
  }
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    ERR_put_error(0x21,0x8b,0x41,"crypto/pkcs7/pk7_doit.c",0x342);
  }
  else {
    iVar1 = EVP_DigestSignInit(ctx,&local_2c,type,(ENGINE *)0x0,si->pkey);
    if (0 < iVar1) {
      iVar1 = EVP_PKEY_CTX_ctrl(local_2c,-1,8,5,0,si);
      if (iVar1 < 1) {
        iVar1 = 0x34b;
      }
      else {
        cnt = ASN1_item_i2d((ASN1_VALUE *)si->auth_attr,&local_28,(ASN1_ITEM *)PKCS7_ATTR_SIGN_it);
        if ((local_28 == (uchar *)0x0) || (iVar1 = EVP_DigestUpdate(ctx,local_28,cnt), iVar1 < 1))
        goto LAB_00151f00;
        CRYPTO_free(local_28);
        local_28 = (uchar *)0x0;
        iVar1 = EVP_DigestSignFinal(ctx,(uchar *)0x0,local_24);
        if ((iVar1 < 1) ||
           ((local_28 = (uchar *)CRYPTO_malloc(local_24[0],"crypto/pkcs7/pk7_doit.c",0x359),
            local_28 == (uchar *)0x0 ||
            (iVar1 = EVP_DigestSignFinal(ctx,local_28,local_24), iVar1 < 1)))) goto LAB_00151f00;
        iVar1 = EVP_PKEY_CTX_ctrl(local_2c,-1,8,5,1,si);
        if (0 < iVar1) {
          EVP_MD_CTX_free(ctx);
          ASN1_STRING_set0(si->enc_digest,local_28,local_24[0]);
          return 1;
        }
        iVar1 = 0x361;
      }
      ERR_put_error(0x21,0x8b,0x98,"crypto/pkcs7/pk7_doit.c",iVar1);
    }
  }
LAB_00151f00:
  CRYPTO_free(local_28);
  EVP_MD_CTX_free(ctx);
  return 0;
}

