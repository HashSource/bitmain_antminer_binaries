
undefined4 Curl_ossl_set_engine(int param_1,char *param_2)

{
  ENGINE *e;
  int iVar1;
  undefined4 uVar2;
  ulong e_00;
  char acStack_118 [260];
  
  e = ENGINE_by_id(param_2);
  if (e == (ENGINE *)0x0) {
    Curl_failf(param_1,DAT_0005996c,param_2);
    uVar2 = 0x35;
  }
  else {
    if (*(ENGINE **)(param_1 + 0x8648) != (ENGINE *)0x0) {
      ENGINE_finish(*(ENGINE **)(param_1 + 0x8648));
      ENGINE_free(*(ENGINE **)(param_1 + 0x8648));
      *(undefined4 *)(param_1 + 0x8648) = 0;
    }
    iVar1 = ENGINE_init(e);
    if (iVar1 == 0) {
      ENGINE_free(e);
      e_00 = ERR_get_error();
      ERR_error_string_n(e_00,acStack_118,0x100);
      Curl_failf(param_1,DAT_00059968,param_2,acStack_118);
      uVar2 = 0x42;
    }
    else {
      uVar2 = 0;
      *(ENGINE **)(param_1 + 0x8648) = e;
    }
  }
  return uVar2;
}

