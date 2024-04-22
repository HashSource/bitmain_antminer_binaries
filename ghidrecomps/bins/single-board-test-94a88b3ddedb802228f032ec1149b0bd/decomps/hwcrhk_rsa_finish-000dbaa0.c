
undefined4 hwcrhk_rsa_finish(RSA *param_1)

{
  int *piVar1;
  undefined4 *ptr;
  
  piVar1 = DAT_000dbad0;
  ptr = (undefined4 *)RSA_get_ex_data(param_1,*DAT_000dbad0);
  if (ptr != (undefined4 *)0x0) {
    (**DAT_000dbad4)(*ptr,0);
    CRYPTO_free(ptr);
    RSA_set_ex_data(param_1,*piVar1,(void *)0x0);
  }
  return 1;
}

