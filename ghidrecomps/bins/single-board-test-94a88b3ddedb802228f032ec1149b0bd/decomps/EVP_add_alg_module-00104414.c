
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EVP_add_alg_module(void)

{
  CONF_module_add("alg_section",alg_module_init + 1,(undefined1 *)0x0);
  return;
}

