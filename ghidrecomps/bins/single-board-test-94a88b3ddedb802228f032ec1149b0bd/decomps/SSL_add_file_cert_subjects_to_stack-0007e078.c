
int SSL_add_file_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *file)

{
  void *pvVar1;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  X509 *pXVar3;
  X509_NAME *pXVar4;
  int iVar5;
  X509 *local_1c [2];
  
  local_1c[0] = (X509 *)0x0;
  pvVar1 = (void *)sk_set_cmp_func(stackCAs,DAT_0007e120);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xd8,0x41,DAT_0007e124,0x3bd);
    iVar5 = 0;
  }
  else {
    lVar2 = BIO_ctrl(bp,0x6c,3,file);
    if (lVar2 == 0) {
LAB_0007e0a6:
      iVar5 = 0;
    }
    else {
      while (pXVar3 = PEM_read_bio_X509(bp,local_1c,(undefined1 *)0x0,(void *)0x0),
            pXVar3 != (X509 *)0x0) {
        pXVar4 = X509_get_subject_name(local_1c[0]);
        if ((pXVar4 == (X509_NAME *)0x0) ||
           (pXVar4 = X509_NAME_dup(pXVar4), pXVar4 == (X509_NAME *)0x0)) goto LAB_0007e0a6;
        iVar5 = sk_find(&stackCAs->stack,pXVar4);
        if (iVar5 < 0) {
          sk_push(&stackCAs->stack,pXVar4);
        }
        else {
          X509_NAME_free(pXVar4);
        }
      }
      ERR_clear_error();
      iVar5 = 1;
    }
    BIO_free(bp);
  }
  if (local_1c[0] != (X509 *)0x0) {
    X509_free(local_1c[0]);
  }
  sk_set_cmp_func(stackCAs,pvVar1);
  return iVar5;
}

