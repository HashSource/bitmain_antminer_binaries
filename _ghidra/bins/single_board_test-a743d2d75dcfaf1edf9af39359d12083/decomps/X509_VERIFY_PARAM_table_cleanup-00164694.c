
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_VERIFY_PARAM_table_cleanup(void)

{
  if (param_table != (_STACK *)0x0) {
    sk_pop_free(param_table,(func *)0x163edd);
  }
  param_table = (_STACK *)0x0;
  return;
}

