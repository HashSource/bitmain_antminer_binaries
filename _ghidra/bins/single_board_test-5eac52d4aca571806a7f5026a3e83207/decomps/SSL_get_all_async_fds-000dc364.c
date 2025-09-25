
void SSL_get_all_async_fds(int param_1)

{
  if (*(int *)(param_1 + 0xf48) != 0) {
    ASYNC_WAIT_CTX_get_all_fds();
    return;
  }
  return;
}

