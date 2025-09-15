
void hwcrhk_log_message(undefined4 *param_1,undefined4 param_2)

{
  CRYPTO_lock(9,0x15,"e_chil.c",0x51f);
  if ((param_1 != (undefined4 *)0x0) && ((BIO *)*param_1 != (BIO *)0x0)) {
    BIO_printf((BIO *)*param_1,"%s\n",param_2);
  }
  CRYPTO_lock(10,0x15,"e_chil.c",0x525);
  return;
}

