
undefined1 * X509_VERIFY_PARAM_get0(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 < 5) {
    return &default_table + param_1 * 0x40;
  }
  puVar1 = (undefined1 *)OPENSSL_sk_value(param_table,param_1 + -5);
  return puVar1;
}

