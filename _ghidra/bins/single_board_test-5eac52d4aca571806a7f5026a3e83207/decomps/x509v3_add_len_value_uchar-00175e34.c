
undefined4 x509v3_add_len_value_uchar(char *param_1,void *param_2,int param_3,int *param_4)

{
  char *ptr;
  void *pvVar1;
  undefined4 *ptr_00;
  int iVar2;
  
  iVar2 = *param_4;
  if (param_1 == (char *)0x0) {
    ptr = (char *)0x0;
LAB_00175e58:
    if (param_2 != (void *)0x0 && param_3 != 0) {
      pvVar1 = memchr(param_2,0,param_3 - 1);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = (void *)CRYPTO_strndup(param_2,param_3,"crypto/x509v3/v3_utl.c",0x36);
        if (pvVar1 != (void *)0x0) goto LAB_00175ec0;
      }
      else {
        pvVar1 = (void *)0x0;
      }
      goto LAB_00175e76;
    }
    pvVar1 = (void *)0x0;
LAB_00175ec0:
    ptr_00 = (undefined4 *)CRYPTO_malloc(0xc,"crypto/x509v3/v3_utl.c",0x3a);
    if (ptr_00 == (undefined4 *)0x0) goto LAB_00175e76;
    if (iVar2 != 0) {
      ptr_00[1] = ptr;
      ptr_00[2] = pvVar1;
      *ptr_00 = 0;
      iVar2 = OPENSSL_sk_push(*param_4,ptr_00);
      if (iVar2 != 0) {
        return 1;
      }
      ERR_put_error(0x22,0xae,0x41,"crypto/x509v3/v3_utl.c",0x45);
      goto LAB_00175e90;
    }
    iVar2 = OPENSSL_sk_new_null();
    *param_4 = iVar2;
    if (iVar2 != 0) {
      *ptr_00 = 0;
      ptr_00[1] = ptr;
      ptr_00[2] = pvVar1;
      iVar2 = OPENSSL_sk_push(*param_4,ptr_00);
      if (iVar2 != 0) {
        return 1;
      }
    }
    ERR_put_error(0x22,0xae,0x41,"crypto/x509v3/v3_utl.c",0x45);
  }
  else {
    ptr = CRYPTO_strdup(param_1,"crypto/x509v3/v3_utl.c",0x2d);
    if (ptr != (char *)0x0) goto LAB_00175e58;
    pvVar1 = (void *)0x0;
LAB_00175e76:
    ptr_00 = (undefined4 *)0x0;
    ERR_put_error(0x22,0xae,0x41,"crypto/x509v3/v3_utl.c",0x45);
    if (iVar2 != 0) goto LAB_00175e90;
    ptr_00 = (undefined4 *)0x0;
  }
  OPENSSL_sk_free(*param_4);
  *param_4 = 0;
LAB_00175e90:
  CRYPTO_free(ptr_00);
  CRYPTO_free(ptr);
  CRYPTO_free(pvVar1);
  return 0;
}

