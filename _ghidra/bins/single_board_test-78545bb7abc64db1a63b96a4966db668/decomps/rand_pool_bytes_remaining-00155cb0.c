
int rand_pool_bytes_remaining(int param_1)

{
  return *(int *)(param_1 + 0x14) - *(int *)(param_1 + 4);
}

