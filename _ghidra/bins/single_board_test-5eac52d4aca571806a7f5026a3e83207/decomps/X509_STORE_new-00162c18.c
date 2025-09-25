
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_STORE * X509_STORE_new(void)

{
  X509_STORE *obj;
  stack_st_X509_OBJECT *psVar1;
  stack_st_X509_LOOKUP *psVar2;
  X509_VERIFY_PARAM *pXVar3;
  int iVar4;
  int iVar5;
  
  obj = (X509_STORE *)CRYPTO_zalloc(0x4c,"crypto/x509/x509_lu.c",0xa2);
  if (obj == (X509_STORE *)0x0) {
    ERR_put_error(0xb,0x9e,0x41,"crypto/x509/x509_lu.c",0xa5);
    return (X509_STORE *)0x0;
  }
  psVar1 = (stack_st_X509_OBJECT *)OPENSSL_sk_new(0x1629e1);
  iVar5 = 0xa9;
  obj->objs = psVar1;
  if (psVar1 != (stack_st_X509_OBJECT *)0x0) {
    obj->cache = 1;
    psVar2 = (stack_st_X509_LOOKUP *)OPENSSL_sk_new_null();
    iVar5 = 0xae;
    obj->get_cert_methods = psVar2;
    if (psVar2 != (stack_st_X509_LOOKUP *)0x0) {
      pXVar3 = X509_VERIFY_PARAM_new();
      iVar5 = 0xb3;
      obj->param = pXVar3;
      if (pXVar3 != (X509_VERIFY_PARAM *)0x0) {
        iVar4 = CRYPTO_new_ex_data(4,obj,(CRYPTO_EX_DATA *)&(obj->ex_data).dummy);
        iVar5 = 0xb7;
        if (iVar4 != 0) {
          iVar5 = CRYPTO_THREAD_lock_new();
          obj[1].cache = iVar5;
          if (iVar5 != 0) {
            DataMemoryBarrier(0x1b);
            obj->references = 1;
            DataMemoryBarrier(0x1b);
            return obj;
          }
          iVar5 = 0xbd;
        }
      }
    }
  }
  ERR_put_error(0xb,0x9e,0x41,"crypto/x509/x509_lu.c",iVar5);
  X509_VERIFY_PARAM_free(obj->param);
  OPENSSL_sk_free(obj->objs);
  OPENSSL_sk_free(obj->get_cert_methods);
  CRYPTO_free(obj);
  return (X509_STORE *)0x0;
}

