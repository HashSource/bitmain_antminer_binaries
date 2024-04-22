
int x509_name_oneline_constprop_5(X509_NAME *param_1,void *param_2)

{
  BIO_METHOD *type;
  BIO *out;
  uint uVar1;
  int iVar2;
  size_t __n;
  uint *local_1c [2];
  
  type = BIO_s_mem();
  out = BIO_new(type);
  if (out == (BIO *)0x0) {
    iVar2 = 1;
  }
  else {
    uVar1 = X509_NAME_print_ex(out,param_1,0,0x30000);
    BIO_ctrl(out,0x73,0,local_1c);
    __n = *local_1c[0];
    if (0x3ffe < __n) {
      __n = 0x3fff;
    }
    memcpy(param_2,(void *)local_1c[0][1],__n);
    *(undefined *)((int)param_2 + __n) = 0;
    BIO_free(out);
    iVar2 = 1 - uVar1;
    if (1 < uVar1) {
      iVar2 = 0;
    }
  }
  return iVar2;
}

