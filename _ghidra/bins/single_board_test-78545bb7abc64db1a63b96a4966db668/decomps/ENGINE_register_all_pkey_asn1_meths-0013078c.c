
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_pkey_asn1_meths(void)

{
  ENGINE *e;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    ENGINE_register_pkey_asn1_meths(e);
  }
  return;
}

