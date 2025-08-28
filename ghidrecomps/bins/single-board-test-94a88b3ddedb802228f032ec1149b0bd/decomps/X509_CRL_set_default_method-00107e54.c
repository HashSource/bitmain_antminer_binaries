
void X509_CRL_set_default_method(undefined1 *param_1)

{
  if (param_1 == (undefined1 *)0x0) {
    param_1 = int_crl_meth;
  }
  default_crl_method = param_1;
  return;
}

