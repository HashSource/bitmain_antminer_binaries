
bool SSL_in_before(int param_1)

{
  if (*(int *)(param_1 + 0x40) == 0) {
    return *(int *)(param_1 + 0x2c) == 0;
  }
  return false;
}

