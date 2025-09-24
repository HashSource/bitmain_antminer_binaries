
void EC_KEY_set_default_method(undefined1 *param_1)

{
  if (param_1 == (undefined1 *)0x0) {
    param_1 = &openssl_ec_key_method;
  }
  default_ec_key_meth = param_1;
  return;
}

