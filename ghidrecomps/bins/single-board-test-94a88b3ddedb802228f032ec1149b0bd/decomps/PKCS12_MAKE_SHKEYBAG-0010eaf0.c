
PKCS12_SAFEBAG *
PKCS12_MAKE_SHKEYBAG
          (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
          PKCS8_PRIV_KEY_INFO *p8)

{
  PKCS12_SAFEBAG *pPVar1;
  ASN1_OBJECT *pAVar2;
  char *name;
  EVP_CIPHER *cipher;
  X509_SIG *pXVar3;
  
  pPVar1 = PKCS12_SAFEBAG_new();
  if (pPVar1 == (PKCS12_SAFEBAG *)0x0) {
    ERR_put_error(0x23,0x71,0x41,DAT_0010eb70,0x73);
  }
  else {
    pAVar2 = OBJ_nid2obj(0x97);
    pPVar1->type = pAVar2;
    name = OBJ_nid2sn(pbe_nid);
    cipher = EVP_get_cipherbyname(name);
    if (cipher != (EVP_CIPHER *)0x0) {
      pbe_nid = -1;
    }
    pXVar3 = PKCS8_encrypt(pbe_nid,cipher,pass,passlen,salt,saltlen,iter,p8);
    (pPVar1->value).shkeybag = pXVar3;
    if (pXVar3 == (X509_SIG *)0x0) {
      ERR_put_error(0x23,0x71,0x41,DAT_0010eb70,0x81);
      pPVar1 = (PKCS12_SAFEBAG *)0x0;
    }
  }
  return pPVar1;
}

