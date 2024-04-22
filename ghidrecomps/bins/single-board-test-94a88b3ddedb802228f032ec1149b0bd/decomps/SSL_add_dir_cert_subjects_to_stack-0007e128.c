
int SSL_add_dir_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *dir)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  int *piVar3;
  int iVar4;
  int local_41c;
  char acStack_418 [1024];
  
  local_41c = 0;
  CRYPTO_lock(9,0x18,DAT_0007e204,0x3f4);
  while( true ) {
    __s = (char *)OPENSSL_DIR_read(&local_41c,dir);
    if (__s == (char *)0x0) {
      piVar3 = __errno_location();
      if (*piVar3 == 0) {
        iVar4 = 1;
      }
      else {
        ERR_put_error(2,10,*piVar3,DAT_0007e204,0x40d);
        ERR_add_error_data(3,DAT_0007e20c,dir,DAT_0007e210);
        ERR_put_error(0x14,0xd7,2,DAT_0007e204,0x40f);
        iVar4 = 0;
      }
      goto LAB_0007e1b2;
    }
    sVar1 = strlen(dir);
    sVar2 = strlen(__s);
    if (0x400 < sVar1 + sVar2 + 2) break;
    iVar4 = BIO_snprintf(acStack_418,0x400,DAT_0007e208,dir,__s);
    if ((0x3fe < iVar4 - 1U) ||
       (iVar4 = SSL_add_file_cert_subjects_to_stack(stackCAs,acStack_418), iVar4 == 0))
    goto LAB_0007e1b0;
  }
  ERR_put_error(0x14,0xd7,0x10e,DAT_0007e204,0x3fe);
LAB_0007e1b0:
  iVar4 = 0;
LAB_0007e1b2:
  if (local_41c != 0) {
    OPENSSL_DIR_end(&local_41c);
  }
  CRYPTO_lock(10,0x18,DAT_0007e204,0x418);
  return iVar4;
}

