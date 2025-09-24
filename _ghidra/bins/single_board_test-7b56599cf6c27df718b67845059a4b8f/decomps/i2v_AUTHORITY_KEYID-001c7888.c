
stack_st_CONF_VALUE *
i2v_AUTHORITY_KEYID(undefined4 param_1,undefined4 *param_2,stack_st_CONF_VALUE *param_3)

{
  char *pcVar1;
  int iVar2;
  stack_st_CONF_VALUE *psVar3;
  undefined4 *puVar4;
  stack_st_CONF_VALUE *local_1c [2];
  
  puVar4 = (undefined4 *)*param_2;
  local_1c[0] = param_3;
  if (puVar4 == (undefined4 *)0x0) {
LAB_001c78d6:
    psVar3 = local_1c[0];
    if (((GENERAL_NAMES *)param_2[1] == (GENERAL_NAMES *)0x0) ||
       (psVar3 = i2v_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,(GENERAL_NAMES *)param_2[1],local_1c[0])
       , psVar3 != (stack_st_CONF_VALUE *)0x0)) {
      local_1c[0] = psVar3;
      puVar4 = (undefined4 *)param_2[2];
      if (puVar4 == (undefined4 *)0x0) {
        return local_1c[0];
      }
      pcVar1 = (char *)OPENSSL_buf2hexstr(puVar4[2],*puVar4);
      if (pcVar1 == (char *)0x0) {
        ERR_put_error(0x22,0xad,0x41,"crypto/x509v3/v3_akey.c",0x45);
        goto LAB_001c7926;
      }
      iVar2 = X509V3_add_value("serial",pcVar1,local_1c);
      if (iVar2 != 0) {
        CRYPTO_free(pcVar1);
        return local_1c[0];
      }
      CRYPTO_free(pcVar1);
      iVar2 = 0x4a;
    }
    else {
      iVar2 = 0x3d;
    }
  }
  else {
    pcVar1 = (char *)OPENSSL_buf2hexstr(puVar4[2],*puVar4);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x22,0xad,0x41,"crypto/x509v3/v3_akey.c",0x30);
      return (stack_st_CONF_VALUE *)0x0;
    }
    iVar2 = X509V3_add_value("keyid",pcVar1,local_1c);
    if (iVar2 != 0) {
      CRYPTO_free(pcVar1);
      goto LAB_001c78d6;
    }
    CRYPTO_free(pcVar1);
    iVar2 = 0x35;
  }
  ERR_put_error(0x22,0xad,0xb,"crypto/x509v3/v3_akey.c",iVar2);
LAB_001c7926:
  if (param_3 == (stack_st_CONF_VALUE *)0x0) {
    OPENSSL_sk_pop_free(local_1c[0],0x1794f9);
  }
  return (stack_st_CONF_VALUE *)0x0;
}

