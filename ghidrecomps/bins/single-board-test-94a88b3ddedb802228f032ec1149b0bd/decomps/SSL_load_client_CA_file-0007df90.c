
stack_st_X509_NAME * SSL_load_client_CA_file(char *file)

{
  _STACK *st;
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  X509 *pXVar2;
  X509_NAME *pXVar3;
  int iVar4;
  _STACK *st_00;
  X509 *local_1c [2];
  
  local_1c[0] = (X509 *)0x0;
  st = sk_new(DAT_0007e06c);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (st == (_STACK *)0x0 || bp == (BIO *)0x0) {
    iVar4 = 0x374;
LAB_0007e012:
    ERR_put_error(0x14,0xb9,0x41,DAT_0007e070,iVar4);
LAB_0007e020:
    st_00 = st;
    if (st == (_STACK *)0x0) goto LAB_0007e02c;
    st_00 = (_STACK *)0x0;
  }
  else {
    st_00 = (_STACK *)0x0;
    lVar1 = BIO_ctrl(bp,0x6c,3,file);
    if (lVar1 == 0) goto LAB_0007e020;
    while (pXVar2 = PEM_read_bio_X509(bp,local_1c,(undefined1 *)0x0,(void *)0x0),
          pXVar2 != (X509 *)0x0) {
      if ((st_00 == (_STACK *)0x0) && (st_00 = sk_new_null(), st_00 == (_STACK *)0x0)) {
        iVar4 = 0x381;
        goto LAB_0007e012;
      }
      pXVar3 = X509_get_subject_name(local_1c[0]);
      if ((pXVar3 == (X509_NAME *)0x0) ||
         (pXVar3 = X509_NAME_dup(pXVar3), pXVar3 == (X509_NAME *)0x0)) {
        sk_pop_free(st_00,DAT_0007e074);
        sk_free(st);
        st_00 = (_STACK *)0x0;
        goto LAB_0007e02c;
      }
      iVar4 = sk_find(st,pXVar3);
      if (iVar4 < 0) {
        sk_push(st,pXVar3);
        sk_push(st_00,pXVar3);
      }
      else {
        X509_NAME_free(pXVar3);
      }
    }
  }
  sk_free(st);
LAB_0007e02c:
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
  if (local_1c[0] != (X509 *)0x0) {
    X509_free(local_1c[0]);
  }
  if (st_00 != (_STACK *)0x0) {
    ERR_clear_error();
  }
  return (stack_st_X509_NAME *)st_00;
}

