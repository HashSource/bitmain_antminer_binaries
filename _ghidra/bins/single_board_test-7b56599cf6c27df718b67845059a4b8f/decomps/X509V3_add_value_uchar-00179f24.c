
int X509V3_add_value_uchar(char *name,uchar *value,stack_st_CONF_VALUE **extlist)

{
  size_t sVar1;
  char *pcVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *ptr;
  stack_st_CONF_VALUE *psVar5;
  
  pcVar2 = name;
  if (value == (uchar *)0x0) {
    psVar5 = *extlist;
    if (name != (char *)0x0) {
      sVar1 = 0;
      goto LAB_00179f44;
    }
LAB_00179fbe:
    ptr = (undefined4 *)CRYPTO_malloc(0xc,"crypto/x509v3/v3_utl.c",0x3a);
    if (ptr == (undefined4 *)0x0) goto LAB_00179f74;
    if (psVar5 != (stack_st_CONF_VALUE *)0x0) {
      ptr[1] = pcVar2;
      ptr[2] = name;
      *ptr = 0;
      iVar4 = OPENSSL_sk_push(*extlist,ptr);
      if (iVar4 != 0) {
        return 1;
      }
      ERR_put_error(0x22,0xae,0x41,"crypto/x509v3/v3_utl.c",0x45);
      goto LAB_00179f8e;
    }
    psVar5 = (stack_st_CONF_VALUE *)OPENSSL_sk_new_null();
    *extlist = psVar5;
    if (psVar5 != (stack_st_CONF_VALUE *)0x0) {
      *ptr = 0;
      ptr[1] = pcVar2;
      ptr[2] = name;
      iVar4 = OPENSSL_sk_push(*extlist,ptr);
      if (iVar4 != 0) {
        return 1;
      }
    }
    ERR_put_error(0x22,0xae,0x41,"crypto/x509v3/v3_utl.c",0x45);
  }
  else {
    sVar1 = strlen((char *)value);
    psVar5 = *extlist;
    if (name == (char *)0x0) {
LAB_00179f56:
      if (value == (uchar *)0x0 || sVar1 == 0) {
        name = (char *)0x0;
        goto LAB_00179fbe;
      }
      pvVar3 = memchr(value,0,sVar1 - 1);
      if (pvVar3 == (void *)0x0) {
        name = (char *)CRYPTO_strndup(value,sVar1,"crypto/x509v3/v3_utl.c",0x36);
        if (name != (char *)0x0) goto LAB_00179fbe;
      }
      else {
        name = (char *)0x0;
      }
    }
    else {
LAB_00179f44:
      pcVar2 = CRYPTO_strdup(name,"crypto/x509v3/v3_utl.c",0x2d);
      if (pcVar2 != (char *)0x0) goto LAB_00179f56;
      name = (char *)0x0;
    }
LAB_00179f74:
    ptr = (undefined4 *)0x0;
    ERR_put_error(0x22,0xae,0x41,"crypto/x509v3/v3_utl.c",0x45);
    if (psVar5 != (stack_st_CONF_VALUE *)0x0) goto LAB_00179f8e;
    ptr = (undefined4 *)0x0;
  }
  OPENSSL_sk_free(*extlist);
  *extlist = (stack_st_CONF_VALUE *)0x0;
LAB_00179f8e:
  CRYPTO_free(ptr);
  CRYPTO_free(pcVar2);
  CRYPTO_free(name);
  return 0;
}

