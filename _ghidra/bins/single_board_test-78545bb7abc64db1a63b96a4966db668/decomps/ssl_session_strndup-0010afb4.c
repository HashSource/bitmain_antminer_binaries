
int ssl_session_strndup(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  CRYPTO_free((void *)*param_1);
  *param_1 = 0;
  if (param_2 != (undefined4 *)0x0) {
    iVar1 = CRYPTO_strndup(param_2[2],*param_2,"ssl/ssl_asn1.c",0xd9);
    *param_1 = iVar1;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 1;
}

