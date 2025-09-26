
int PKCS12_SAFEBAG_create_pkcs8_encrypt
              (int param_1,char *param_2,int param_3,uchar *param_4,int param_5,int param_6,
              PKCS8_PRIV_KEY_INFO *param_7)

{
  char *name;
  EVP_CIPHER *cipher;
  X509_SIG *a;
  int iVar1;
  
  name = OBJ_nid2sn(param_1);
  cipher = EVP_get_cipherbyname(name);
  if (cipher != (EVP_CIPHER *)0x0) {
    param_1 = -1;
  }
  a = PKCS8_encrypt(param_1,cipher,param_2,param_3,param_4,param_5,param_6,param_7);
  if (a == (X509_SIG *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = PKCS12_SAFEBAG_create0_pkcs8();
    if (iVar1 == 0) {
      X509_SIG_free(a);
    }
  }
  return iVar1;
}

