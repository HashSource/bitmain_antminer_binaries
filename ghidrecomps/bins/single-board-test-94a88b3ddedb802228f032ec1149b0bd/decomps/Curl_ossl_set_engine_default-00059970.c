
ENGINE * Curl_ossl_set_engine_default(int param_1)

{
  ENGINE *e;
  int iVar1;
  char *pcVar2;
  
  e = *(ENGINE **)(param_1 + 0x8648);
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_default(e,0xffff);
    if (0 < iVar1) {
      pcVar2 = ENGINE_get_id(*(ENGINE **)(param_1 + 0x8648));
      Curl_infof(param_1,DAT_000599b0,pcVar2);
      return (ENGINE *)0x0;
    }
    pcVar2 = ENGINE_get_id(*(ENGINE **)(param_1 + 0x8648));
    Curl_failf(param_1,DAT_000599b4,pcVar2);
    e = (ENGINE *)0x36;
  }
  return e;
}

