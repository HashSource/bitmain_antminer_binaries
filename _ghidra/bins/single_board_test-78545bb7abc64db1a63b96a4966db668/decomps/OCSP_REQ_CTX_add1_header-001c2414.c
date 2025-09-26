
int OCSP_REQ_CTX_add1_header(OCSP_REQ_CTX *rctx,char *name,char *value)

{
  int iVar1;
  
  if (name == (char *)0x0) {
    return 0;
  }
  iVar1 = BIO_puts(*(BIO **)(rctx + 0x10),name);
  if ((0 < iVar1) &&
     (((value == (char *)0x0 ||
       ((iVar1 = BIO_write(*(BIO **)(rctx + 0x10),": ",2), iVar1 == 2 &&
        (iVar1 = BIO_puts(*(BIO **)(rctx + 0x10),value), 0 < iVar1)))) &&
      (iVar1 = BIO_write(*(BIO **)(rctx + 0x10),"\r\n",2), iVar1 == 2)))) {
    *(undefined4 *)rctx = 0x1009;
    return 1;
  }
  return 0;
}

