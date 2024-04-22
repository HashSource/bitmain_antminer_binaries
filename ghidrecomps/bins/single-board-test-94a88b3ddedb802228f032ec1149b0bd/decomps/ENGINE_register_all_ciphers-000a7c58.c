
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_ciphers(void)

{
  ENGINE *e;
  int iVar1;
  undefined4 local_14;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if ((*(code **)(e + 0x24) != (code *)0x0) &&
       (iVar1 = (**(code **)(e + 0x24))(e,0,&local_14,0), 0 < iVar1)) {
      engine_table_register(DAT_000a7c9c,DAT_000a7c98,e,local_14,iVar1,0);
    }
  }
  return;
}

