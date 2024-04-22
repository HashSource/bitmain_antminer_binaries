
PKCS7 * PKCS12_pack_p7encdata
                  (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  stack_st_PKCS12_SAFEBAG *bags)

{
  PKCS7 *p7;
  int iVar1;
  char *name;
  EVP_CIPHER *cipher;
  X509_ALGOR *algor;
  PKCS7_ENC_CONTENT *pPVar2;
  ASN1_OCTET_STRING *pAVar3;
  
  p7 = PKCS7_new();
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x23,0x73,0x41,DAT_0010ed08,0xb2);
  }
  else {
    iVar1 = PKCS7_set_type(p7,0x1a);
    if (iVar1 == 0) {
      ERR_put_error(0x23,0x73,0x78,DAT_0010ed08,0xb7);
      p7 = (PKCS7 *)0x0;
    }
    else {
      name = OBJ_nid2sn(pbe_nid);
      cipher = EVP_get_cipherbyname(name);
      if (cipher == (EVP_CIPHER *)0x0) {
        algor = PKCS5_pbe_set(pbe_nid,iter,salt,saltlen);
      }
      else {
        algor = PKCS5_pbe2_set(cipher,iter,salt,saltlen);
      }
      if (algor == (X509_ALGOR *)0x0) {
        ERR_put_error(0x23,0x73,0x41,DAT_0010ed08,0xc3);
        p7 = (PKCS7 *)0x0;
      }
      else {
        X509_ALGOR_free(((p7->d).encrypted)->enc_data->algorithm);
        pPVar2 = ((p7->d).encrypted)->enc_data;
        pPVar2->algorithm = algor;
        ASN1_STRING_free(pPVar2->enc_data);
        pPVar2 = ((p7->d).encrypted)->enc_data;
        pAVar3 = PKCS12_item_i2d_encrypt(algor,DAT_0010ed04,pass,passlen,bags,1);
        pPVar2->enc_data = pAVar3;
        if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
          ERR_put_error(0x23,0x73,0x67,DAT_0010ed08,0xcc);
          p7 = (PKCS7 *)0x0;
        }
      }
    }
  }
  return p7;
}

