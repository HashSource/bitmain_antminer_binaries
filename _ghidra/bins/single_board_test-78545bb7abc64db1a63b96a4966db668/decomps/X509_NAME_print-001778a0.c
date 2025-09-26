
int X509_NAME_print(BIO *bp,X509_NAME *name,int obase)

{
  char *pcVar1;
  char *ptr;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *data;
  
  ptr = X509_NAME_oneline(name,(char *)0x0,0);
  if (ptr == (char *)0x0) {
    return 0;
  }
  if (*ptr == '\0') {
    CRYPTO_free(ptr);
    return 1;
  }
  pcVar4 = ptr + 1;
  pcVar1 = ptr + 2;
  data = pcVar4;
LAB_001778cc:
  for (; pcVar3 = pcVar1, *pcVar4 != '/'; pcVar4 = pcVar4 + 1) {
    if (*pcVar4 == '\0') goto LAB_001778d4;
LAB_00177922:
    pcVar1 = pcVar3 + 1;
  }
  iVar2 = ossl_ctype_check(pcVar4[1],2);
  if (((iVar2 == 0) ||
      ((pcVar4[2] != '=' &&
       ((iVar2 = ossl_ctype_check(pcVar4[2],2), iVar2 == 0 || (pcVar4[3] != '=')))))) &&
     (*pcVar4 != '\0')) goto LAB_00177922;
LAB_001778d4:
  iVar2 = BIO_write(bp,data,(int)pcVar4 - (int)data);
  if ((int)pcVar4 - (int)data == iVar2) {
    if (*pcVar4 == '\0') {
LAB_001778e8:
      CRYPTO_free(ptr);
      return 1;
    }
    iVar2 = BIO_write(bp,&DAT_0022ae34,2);
    if (iVar2 == 2) {
      if (*pcVar4 == '\0') goto LAB_001778e8;
      pcVar4 = pcVar4 + 1;
      pcVar1 = pcVar3 + 1;
      data = pcVar3;
      goto LAB_001778cc;
    }
  }
  ERR_put_error(0xb,0x75,7,"crypto/x509/x_name.c",0x217);
  CRYPTO_free(ptr);
  return 0;
}

