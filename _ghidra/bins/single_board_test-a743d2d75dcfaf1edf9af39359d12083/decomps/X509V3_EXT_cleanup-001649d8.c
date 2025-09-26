
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509V3_EXT_cleanup(void)

{
  sk_pop_free(ext_list,(func *)0x1646c9);
  ext_list = (_STACK *)0x0;
  return;
}

