
void hwcrhk_log_message(BIO **param_1,undefined4 param_2)

{
  CRYPTO_lock(9,0x15,DAT_000dbb3c,0x51f);
  if ((param_1 != (BIO **)0x0) && (*param_1 != (BIO *)0x0)) {
    BIO_printf(*param_1,DAT_000dbb40,param_2);
  }
  CRYPTO_lock(10,0x15,DAT_000dbb3c,0x525);
  return;
}

