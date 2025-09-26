
int X509_load_cert_crl_file_part_0(int param_1,char *param_2)

{
  BIO *bp;
  _STACK *st;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  bp = BIO_new_file(param_2,"r");
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xb,0x84,2,"by_file.c",0xfd);
    iVar5 = 0;
  }
  else {
    st = &PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,(void *)0x0)->stack;
    BIO_free(bp);
    if (st == (_STACK *)0x0) {
      ERR_put_error(0xb,0x84,9,"by_file.c",0x103);
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      iVar3 = 0;
      while( true ) {
        iVar1 = sk_num(st);
        iVar4 = iVar3 + 1;
        if (iVar1 <= iVar3) break;
        puVar2 = (undefined4 *)sk_value(st,iVar3);
        if ((X509 *)*puVar2 != (X509 *)0x0) {
          iVar5 = iVar5 + 1;
          X509_STORE_add_cert(*(X509_STORE **)(param_1 + 0x10),(X509 *)*puVar2);
        }
        iVar3 = iVar4;
        if ((X509_CRL *)puVar2[1] != (X509_CRL *)0x0) {
          iVar5 = iVar5 + 1;
          X509_STORE_add_crl(*(X509_STORE **)(param_1 + 0x10),(X509_CRL *)puVar2[1]);
        }
      }
      sk_pop_free(st,(func *)0x1a1c99);
    }
  }
  return iVar5;
}

