
bool SSL_is_init_finished(int param_1)

{
  if (*(int *)(param_1 + 0x48) == 0) {
    return *(int *)(param_1 + 0x40) == 1;
  }
  return false;
}

