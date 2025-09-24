
void SSL_get_changed_async_fds(int param_1)

{
  if (*(int *)(param_1 + 0xf48) != 0) {
    ASYNC_WAIT_CTX_get_changed_fds();
    return;
  }
  return;
}

