
void gost_param_free(void)

{
  void **ppvVar1;
  
  ppvVar1 = DAT_00117704;
  if (*DAT_00117704 != (void *)0x0) {
    CRYPTO_free(*DAT_00117704);
    *ppvVar1 = (void *)0x0;
  }
  return;
}

