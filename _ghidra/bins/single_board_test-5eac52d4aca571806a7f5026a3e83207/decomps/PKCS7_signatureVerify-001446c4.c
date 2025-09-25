
int PKCS7_signatureVerify(BIO *bio,PKCS7 *p7,PKCS7_SIGNER_INFO *si,X509 *x509)

{
  EVP_MD_CTX *out;
  int iVar1;
  int n;
  EVP_MD *pEVar2;
  BIO *bp;
  EVP_PKEY *pkey;
  char *name;
  size_t cnt;
  ASN1_OCTET_STRING *pAVar3;
  ASN1_VALUE *val;
  EVP_MD_CTX *local_74;
  uchar *local_70;
  size_t local_6c;
  uchar auStack_68 [68];
  
  out = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (out == (EVP_MD_CTX *)0x0) {
    ERR_put_error(0x21,0x71,0x41,"crypto/pkcs7/pk7_doit.c",0x3b8);
    EVP_MD_CTX_free(0);
    return 0;
  }
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 = OBJ_obj2nid(p7->type), iVar1 != 0x18)) {
    iVar1 = 0;
    ERR_put_error(0x21,0x71,0x72,"crypto/pkcs7/pk7_doit.c",0x3bd);
LAB_0014478a:
    EVP_MD_CTX_free(out);
    return iVar1;
  }
  n = OBJ_obj2nid(si->digest_alg->algorithm);
  if (bio != (BIO *)0x0) {
    do {
      bp = BIO_find_type(bio,0x208);
      if (bp == (BIO *)0x0) break;
      BIO_ctrl(bp,0x78,0,&local_74);
      if (local_74 == (EVP_MD_CTX *)0x0) {
        ERR_put_error(0x21,0x71,0x44,"crypto/pkcs7/pk7_doit.c",0x3cd);
        EVP_MD_CTX_free(out);
        return 0;
      }
      pEVar2 = EVP_MD_CTX_md(local_74);
      iVar1 = EVP_MD_type(pEVar2);
      if (n == iVar1) {
LAB_00144798:
        iVar1 = EVP_MD_CTX_copy_ex(out,local_74);
        if (iVar1 == 0) goto LAB_0014478a;
        val = (ASN1_VALUE *)si->auth_attr;
        if ((val == (ASN1_VALUE *)0x0) || (iVar1 = OPENSSL_sk_num(val), iVar1 == 0)) {
LAB_001447ba:
          pAVar3 = si->enc_digest;
          pkey = (EVP_PKEY *)X509_get0_pubkey(x509);
          if (pkey == (EVP_PKEY *)0x0) {
            iVar1 = -1;
          }
          else {
            iVar1 = EVP_VerifyFinal(out,pAVar3->data,pAVar3->length,pkey);
            if (iVar1 < 1) {
              iVar1 = -1;
              ERR_put_error(0x21,0x71,0x69,"crypto/pkcs7/pk7_doit.c",0x411);
            }
            else {
              iVar1 = 1;
            }
          }
        }
        else {
          local_70 = (uchar *)0x0;
          iVar1 = EVP_DigestFinal_ex(out,auStack_68,&local_6c);
          if (iVar1 != 0) {
            pAVar3 = PKCS7_digest_from_attributes((stack_st_X509_ATTRIBUTE *)val);
            if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
              ERR_put_error(0x21,0x71,0x6c,"crypto/pkcs7/pk7_doit.c",0x3ee);
              iVar1 = 0;
              goto LAB_0014478a;
            }
            if ((pAVar3->length != local_6c) ||
               (iVar1 = memcmp(pAVar3->data,auStack_68,pAVar3->length), iVar1 != 0)) {
              iVar1 = -1;
              ERR_put_error(0x21,0x71,0x65,"crypto/pkcs7/pk7_doit.c",0x3f3);
              goto LAB_0014478a;
            }
            name = OBJ_nid2sn(n);
            pEVar2 = EVP_get_digestbyname(name);
            iVar1 = EVP_DigestInit_ex(out,pEVar2,(ENGINE *)0x0);
            if (iVar1 != 0) {
              cnt = ASN1_item_i2d(val,&local_70,(ASN1_ITEM *)&PKCS7_ATTR_VERIFY_it);
              if ((int)cnt < 1) {
                iVar1 = -1;
                ERR_put_error(0x21,0x71,0xd,"crypto/pkcs7/pk7_doit.c",0x3fe);
                goto LAB_0014478a;
              }
              iVar1 = EVP_DigestUpdate(out,local_70,cnt);
              if (iVar1 != 0) {
                CRYPTO_free(local_70);
                goto LAB_001447ba;
              }
            }
          }
          iVar1 = 0;
        }
        goto LAB_0014478a;
      }
      pEVar2 = EVP_MD_CTX_md(local_74);
      iVar1 = EVP_MD_pkey_type(pEVar2);
      if (n == iVar1) goto LAB_00144798;
      bio = BIO_next(bp);
    } while (bio != (BIO *)0x0);
  }
  ERR_put_error(0x21,0x71,0x6c,"crypto/pkcs7/pk7_doit.c",0x3c8);
  EVP_MD_CTX_free(out);
  return 0;
}

