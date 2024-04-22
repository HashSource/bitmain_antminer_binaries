
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ASN1_add_oid_module(void)

{
  CONF_module_add("oid_section",oid_module_init + 1,oid_module_finish + 1);
  return;
}

