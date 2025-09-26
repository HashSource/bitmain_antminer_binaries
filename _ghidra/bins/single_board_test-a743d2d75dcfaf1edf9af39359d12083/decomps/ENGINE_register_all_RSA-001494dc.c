
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_RSA(void)

{
  ENGINE *e;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if (*(int *)(e + 8) != 0) {
      engine_table_register(&rsa_table,0x149491,e,&dummy_nid,1,0);
    }
  }
  return;
}

