
int tls_construct_server_done(int param_1)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x244) != 0) {
    return 1;
  }
  iVar1 = ssl3_digest_cached_records();
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

