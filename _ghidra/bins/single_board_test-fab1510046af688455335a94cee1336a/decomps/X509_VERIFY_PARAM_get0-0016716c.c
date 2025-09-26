
undefined1 * X509_VERIFY_PARAM_get0(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 < 5) {
    return &default_table + param_1 * 0x24;
  }
  puVar1 = (undefined1 *)sk_value(param_table,param_1 + -5);
  return puVar1;
}

