
undefined4 ssl_init_wbio_buffer(int param_1)

{
  BIO_METHOD *type;
  BIO *pBVar1;
  long lVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  if (*(int *)(param_1 + 0x10) == 0) {
    type = BIO_f_buffer();
    pBVar1 = BIO_new(type);
    if ((pBVar1 == (BIO *)0x0) || (lVar2 = BIO_int_ctrl(pBVar1,0x75,1,0), lVar2 == 0)) {
      BIO_free(pBVar1);
      ERR_put_error(0x14,0xb8,7,"ssl/ssl_lib.c",0xfcc);
      uVar3 = 0;
    }
    else {
      *(BIO **)(param_1 + 0x10) = pBVar1;
      pBVar1 = BIO_push(pBVar1,*(BIO **)(param_1 + 0xc));
      uVar3 = 1;
      *(BIO **)(param_1 + 0xc) = pBVar1;
    }
  }
  return uVar3;
}

