
BIO * BIO_new(BIO_METHOD *type)

{
  BIO *obj;
  int iVar1;
  long lVar2;
  undefined1 *extraout_r2;
  char **ad;
  undefined8 uVar3;
  
  obj = (BIO *)CRYPTO_zalloc(0x50,"crypto/bio/bio_lib.c",0x49);
  if (obj == (BIO *)0x0) {
    ERR_put_error(0x20,0x6c,0x41,"crypto/bio/bio_lib.c",0x4c);
    return (BIO *)0x0;
  }
  ad = &obj[1].cb_arg;
  obj->method = type;
  obj->flags = 1;
  DataMemoryBarrier(0x1b);
  obj->num_read = 1;
  DataMemoryBarrier(0x1b);
  iVar1 = CRYPTO_new_ex_data(0xc,obj,(CRYPTO_EX_DATA *)ad);
  if (iVar1 != 0) {
    uVar3 = CRYPTO_THREAD_lock_new();
    obj[1].init = (int)uVar3;
    if ((int)uVar3 != 0) {
      if (type->callback_ctrl != (_func_744 *)0x0) {
        lVar2 = (*type->callback_ctrl)(obj,(int)((ulonglong)uVar3 >> 0x20),extraout_r2);
        if (lVar2 == 0) {
          ERR_put_error(0x20,0x6c,0x46,"crypto/bio/bio_lib.c",0x5f);
          CRYPTO_free_ex_data(0xc,obj,(CRYPTO_EX_DATA *)ad);
          CRYPTO_THREAD_lock_free(obj[1].init);
          goto LAB_0010a1ae;
        }
        if (type->callback_ctrl != (_func_744 *)0x0) {
          return obj;
        }
      }
      obj->shutdown = 1;
      return obj;
    }
    ERR_put_error(0x20,0x6c,0x41,"crypto/bio/bio_lib.c",0x59);
    CRYPTO_free_ex_data(0xc,obj,(CRYPTO_EX_DATA *)ad);
  }
LAB_0010a1ae:
  CRYPTO_free(obj);
  return (BIO *)0x0;
}

