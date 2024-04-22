
stack_st_CONF_VALUE *
i2v_AUTHORITY_KEYID(undefined4 param_1,long **param_2,stack_st_CONF_VALUE *param_3)

{
  char *pcVar1;
  long *plVar2;
  stack_st_CONF_VALUE *local_14 [2];
  
  plVar2 = *param_2;
  local_14[0] = param_3;
  if (plVar2 != (long *)0x0) {
    pcVar1 = hex_to_string((uchar *)plVar2[2],*plVar2);
    X509V3_add_value(DAT_000c9880,pcVar1,local_14);
    CRYPTO_free(pcVar1);
  }
  if ((GENERAL_NAMES *)param_2[1] != (GENERAL_NAMES *)0x0) {
    local_14[0] = i2v_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,(GENERAL_NAMES *)param_2[1],local_14[0]
                                   );
  }
  plVar2 = param_2[2];
  if (plVar2 != (long *)0x0) {
    pcVar1 = hex_to_string((uchar *)plVar2[2],*plVar2);
    X509V3_add_value(DAT_000c9884,pcVar1,local_14);
    CRYPTO_free(pcVar1);
  }
  return local_14[0];
}

