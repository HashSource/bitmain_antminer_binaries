
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509V3_EXT_cleanup(void)

{
  sk_pop_free(ext_list,ext_list_free + 1);
  ext_list = (_STACK *)0x0;
  return;
}

