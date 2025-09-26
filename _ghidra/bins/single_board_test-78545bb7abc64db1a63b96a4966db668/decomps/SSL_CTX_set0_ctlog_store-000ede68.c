
void SSL_CTX_set0_ctlog_store(int param_1,undefined4 param_2)

{
  CTLOG_STORE_free(*(undefined4 *)(param_1 + 0x108));
  *(undefined4 *)(param_1 + 0x108) = param_2;
  return;
}

