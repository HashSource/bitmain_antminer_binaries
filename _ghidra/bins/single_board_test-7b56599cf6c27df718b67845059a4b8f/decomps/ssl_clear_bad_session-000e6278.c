
undefined4 ssl_clear_bad_session(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x474) == 0) || (*(int *)(param_1 + 0x28) << 0x1f < 0)) {
    return 0;
  }
  iVar1 = SSL_in_init();
  if ((iVar1 == 0) && (iVar1 = SSL_in_before(param_1), iVar1 == 0)) {
    SSL_CTX_remove_session(*(SSL_CTX **)(param_1 + 0x5e0),*(SSL_SESSION **)(param_1 + 0x474));
    return 1;
  }
  return 0;
}

