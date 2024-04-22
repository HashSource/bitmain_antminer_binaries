
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_ECDSA(void)

{
  ENGINE *e;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if (*(int *)(e + 0x18) != 0) {
      engine_table_register(DAT_000a792c,DAT_000a7924,e,DAT_000a7928,1,0);
    }
  }
  return;
}

