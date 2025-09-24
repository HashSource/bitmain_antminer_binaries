
int SSL_add_file_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *file)

{
  undefined4 uVar1;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  X509 *pXVar3;
  X509_NAME *pXVar4;
  int iVar5;
  X509 *local_1c;
  
  local_1c = (X509 *)0x0;
  uVar1 = OPENSSL_sk_set_cmp_func(stackCAs,0xdc005);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xd8,0x41,"ssl/ssl_cert.c",0x2a3);
    iVar5 = 0;
  }
  else {
    lVar2 = BIO_ctrl(bp,0x6c,3,file);
    if (lVar2 == 0) {
LAB_000dcde0:
      iVar5 = 0;
    }
    else {
      do {
        pXVar3 = PEM_read_bio_X509(bp,&local_1c,(undefined1 *)0x0,(void *)0x0);
        while( true ) {
          if (pXVar3 == (X509 *)0x0) {
            iVar5 = 1;
            ERR_clear_error();
            goto LAB_000dcde2;
          }
          pXVar4 = X509_get_subject_name(local_1c);
          if ((pXVar4 == (X509_NAME *)0x0) ||
             (pXVar4 = X509_NAME_dup(pXVar4), pXVar4 == (X509_NAME *)0x0)) goto LAB_000dcde0;
          iVar5 = OPENSSL_sk_find(stackCAs,pXVar4);
          if (iVar5 < 0) break;
          X509_NAME_free(pXVar4);
          pXVar3 = PEM_read_bio_X509(bp,&local_1c,(undefined1 *)0x0,(void *)0x0);
        }
        iVar5 = OPENSSL_sk_push(stackCAs,pXVar4);
      } while (iVar5 != 0);
      X509_NAME_free(pXVar4);
      iVar5 = 0;
    }
  }
LAB_000dcde2:
  BIO_free(bp);
  X509_free(local_1c);
  OPENSSL_sk_set_cmp_func(stackCAs,uVar1);
  return iVar5;
}

