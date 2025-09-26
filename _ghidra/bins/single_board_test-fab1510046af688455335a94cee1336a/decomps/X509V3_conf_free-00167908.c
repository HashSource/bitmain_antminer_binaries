
void X509V3_conf_free(CONF_VALUE *val)

{
  if (val != (CONF_VALUE *)0x0) {
    if (val->name != (char *)0x0) {
      CRYPTO_free(val->name);
    }
    if (val->value != (char *)0x0) {
      CRYPTO_free(val->value);
    }
    if (val->section != (char *)0x0) {
      CRYPTO_free(val->section);
    }
    CRYPTO_free(val);
    return;
  }
  return;
}

