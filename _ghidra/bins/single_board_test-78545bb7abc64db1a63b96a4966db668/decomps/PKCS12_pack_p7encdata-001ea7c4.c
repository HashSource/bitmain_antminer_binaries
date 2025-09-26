
PKCS7 * PKCS12_pack_p7encdata
                  (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  stack_st_PKCS12_SAFEBAG *bags)

{
  PKCS7 *p7;
  int iVar1;
  char *name;
  EVP_CIPHER *cipher;
  X509_ALGOR *algor;
  ASN1_OCTET_STRING *pAVar2;
  PKCS7_ENC_CONTENT *pPVar3;
  
  p7 = PKCS7_new();
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x23,0x73,0x41,"crypto/pkcs12/p12_add.c",0x5d);
    return (PKCS7 *)0x0;
  }
  iVar1 = PKCS7_set_type(p7,0x1a);
  if (iVar1 == 0) {
    ERR_put_error(0x23,0x73,0x78,"crypto/pkcs12/p12_add.c",0x62);
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
      ERR_put_error(0x23,0x73,0x41,"crypto/pkcs12/p12_add.c",0x6e);
    }
    else {
      X509_ALGOR_free(((p7->d).encrypted)->enc_data->algorithm);
      pPVar3 = ((p7->d).encrypted)->enc_data;
      pPVar3->algorithm = algor;
      ASN1_OCTET_STRING_free(pPVar3->enc_data);
      pPVar3 = ((p7->d).encrypted)->enc_data;
      pAVar2 = PKCS12_item_i2d_encrypt(algor,(ASN1_ITEM *)PKCS12_SAFEBAGS_it,pass,passlen,bags,1);
      pPVar3->enc_data = pAVar2;
      if (pAVar2 != (ASN1_OCTET_STRING *)0x0) {
        return p7;
      }
      ERR_put_error(0x23,0x73,0x67,"crypto/pkcs12/p12_add.c",0x77);
    }
  }
  PKCS7_free(p7);
  return (PKCS7 *)0x0;
}

