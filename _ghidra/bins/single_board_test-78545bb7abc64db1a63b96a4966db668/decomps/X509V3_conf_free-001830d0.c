
void X509V3_conf_free(CONF_VALUE *val)

{
  if (val != (CONF_VALUE *)0x0) {
    CRYPTO_free(val->name);
    CRYPTO_free(val->value);
    CRYPTO_free(val->section);
    CRYPTO_free(val);
    return;
  }
  return;
}

