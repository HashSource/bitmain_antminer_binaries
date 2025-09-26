
int SSL_add_dir_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *dir)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  int *piVar3;
  int iVar4;
  int local_424;
  char acStack_420 [1024];
  
  local_424 = 0;
  while( true ) {
    __s = (char *)OPENSSL_DIR_read(&local_424,dir);
    if (__s == (char *)0x0) {
      piVar3 = __errno_location();
      if (*piVar3 == 0) {
        iVar4 = 1;
      }
      else {
        ERR_put_error(2,10,*piVar3,"ssl/ssl_cert.c",0x2e5);
        ERR_add_error_data(3,"OPENSSL_DIR_read(&ctx, \'",dir,&DAT_0020e914);
        ERR_put_error(0x14,0xd7,2,"ssl/ssl_cert.c",0x2e7);
        iVar4 = 0;
      }
      goto LAB_000e6a84;
    }
    sVar1 = strlen(dir);
    sVar2 = strlen(__s);
    if (0x400 < sVar1 + sVar2 + 2) break;
    iVar4 = BIO_snprintf(acStack_420,0x400,"%s/%s",dir,__s);
    if ((0x3fe < iVar4 - 1U) ||
       (iVar4 = SSL_add_file_cert_subjects_to_stack(stackCAs,acStack_420), iVar4 == 0))
    goto LAB_000e6a82;
  }
  ERR_put_error(0x14,0xd7,0x10e,"ssl/ssl_cert.c",0x2d6);
LAB_000e6a82:
  iVar4 = 0;
LAB_000e6a84:
  if (local_424 != 0) {
    OPENSSL_DIR_end(&local_424);
  }
  return iVar4;
}

