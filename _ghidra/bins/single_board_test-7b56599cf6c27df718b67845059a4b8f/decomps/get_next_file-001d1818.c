
BIO * get_next_file(char *param_1,undefined4 *param_2)

{
  size_t sVar1;
  char *__s;
  size_t sVar2;
  int iVar3;
  char *filename;
  BIO *pBVar4;
  
  sVar1 = strlen(param_1);
  do {
    __s = (char *)OPENSSL_DIR_read(param_2,param_1);
    while( true ) {
      if (__s == (char *)0x0) goto LAB_001d18c8;
      sVar2 = strlen(__s);
      if (5 < sVar2) break;
      if (sVar2 == 5) goto LAB_001d1862;
      __s = (char *)OPENSSL_DIR_read(param_2,param_1);
    }
    iVar3 = strcasecmp(__s + (sVar2 - 5),".conf");
    if (iVar3 == 0) goto LAB_001d1872;
LAB_001d1862:
    iVar3 = strcasecmp(__s + (sVar2 - 4),".cnf");
    if (iVar3 == 0) {
LAB_001d1872:
      iVar3 = sVar2 + sVar1 + 2;
      filename = (char *)CRYPTO_zalloc(iVar3,"crypto/conf/conf_def.c",0x2e2);
      if (filename == (char *)0x0) {
        ERR_put_error(0xe,0x6b,0x41,"crypto/conf/conf_def.c",0x2e4);
LAB_001d18c8:
        OPENSSL_DIR_end(param_2);
        *param_2 = 0;
        return (BIO *)0x0;
      }
      if (*filename == '\0') {
        OPENSSL_strlcpy(filename,param_1,iVar3);
        OPENSSL_strlcat(filename,&DAT_0020a0ac,iVar3);
      }
      OPENSSL_strlcat(filename,__s,iVar3);
      pBVar4 = BIO_new_file(filename,"r");
      CRYPTO_free(filename);
      if (pBVar4 != (BIO *)0x0) {
        return pBVar4;
      }
    }
  } while( true );
}

