
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_RAND(void)

{
  ENGINE *e;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if (*(int *)(e + 0x1c) != 0) {
      engine_table_register(DAT_000a7bb4,DAT_000a7bac,e,DAT_000a7bb0,1,0);
    }
  }
  return;
}

