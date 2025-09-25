
undefined4 tls_post_process_client_key_exchange(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x58) == 0) && (*(int *)(*(int *)(param_1 + 0x474) + 0x19c) != 0)) {
    if (*(int *)(*(int *)(param_1 + 0x7c) + 0xd4) == 0) {
      ossl_statem_fatal(param_1,0x50,0x180,0x44,"ssl/statem/statem_srvr.c",0xdf7);
      return 0;
    }
    iVar1 = ssl3_digest_cached_records(param_1,1);
  }
  else {
    iVar1 = ssl3_digest_cached_records(param_1,0);
  }
  if (iVar1 != 0) {
    return 2;
  }
  return 0;
}

