
stack_st_X509_NAME * SSL_load_client_CA_file(char *file)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  long lVar2;
  X509 *pXVar3;
  int iVar4;
  X509_NAME *pXVar5;
  X509_NAME *xn;
  X509 *local_24 [2];
  
  xn = (X509_NAME *)0x0;
  type = BIO_s_file();
  bp = BIO_new(type);
  local_24[0] = (X509 *)0x0;
  iVar1 = OPENSSL_LH_new(0xe5bd9,0xe5b71);
  if (bp == (BIO *)0x0 || iVar1 == 0) {
    pXVar5 = (X509_NAME *)0x0;
    ERR_put_error(0x14,0xb9,0x41,"ssl/ssl_cert.c",0x265);
  }
  else {
    xn = (X509_NAME *)0x0;
    lVar2 = BIO_ctrl(bp,0x6c,3,file);
    if (lVar2 == 0) {
      xn = (X509_NAME *)0x0;
      pXVar5 = (X509_NAME *)0x0;
    }
    else {
      pXVar5 = xn;
      do {
        pXVar3 = PEM_read_bio_X509(bp,local_24,(undefined1 *)0x0,(void *)0x0);
        while( true ) {
          if (pXVar3 == (X509 *)0x0) {
            BIO_free(bp);
            X509_free(local_24[0]);
            OPENSSL_LH_free(iVar1);
            if (pXVar5 == (X509_NAME *)0x0) {
              return (stack_st_X509_NAME *)0x0;
            }
            ERR_clear_error();
            return (stack_st_X509_NAME *)pXVar5;
          }
          if ((pXVar5 == (X509_NAME *)0x0) &&
             (pXVar5 = (X509_NAME *)OPENSSL_sk_new_null(), pXVar5 == (X509_NAME *)0x0)) {
            ERR_put_error(0x14,0xb9,0x41,"ssl/ssl_cert.c",0x272);
            goto LAB_000e68aa;
          }
          xn = X509_get_subject_name(local_24[0]);
          if ((xn == (X509_NAME *)0x0) || (xn = X509_NAME_dup(xn), xn == (X509_NAME *)0x0))
          goto LAB_000e68aa;
          iVar4 = OPENSSL_LH_retrieve(iVar1,xn);
          if (iVar4 == 0) break;
          X509_NAME_free(xn);
          pXVar3 = PEM_read_bio_X509(bp,local_24,(undefined1 *)0x0,(void *)0x0);
          xn = (X509_NAME *)0x0;
        }
        OPENSSL_LH_insert(iVar1,xn);
        iVar4 = OPENSSL_sk_push(pXVar5,xn);
      } while (iVar4 != 0);
    }
  }
LAB_000e68aa:
  X509_NAME_free(xn);
  OPENSSL_sk_pop_free(pXVar5,(undefined *)0x177669);
  BIO_free(bp);
  X509_free(local_24[0]);
  OPENSSL_LH_free(iVar1);
  return (stack_st_X509_NAME *)0x0;
}

