
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_ECDH(void)

{
  ENGINE *e;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if (*(int *)(e + 0x14) != 0) {
      engine_table_register(&ecdh_table,0xa7a55,e,&dummy_nid,1,0);
    }
  }
  return;
}

