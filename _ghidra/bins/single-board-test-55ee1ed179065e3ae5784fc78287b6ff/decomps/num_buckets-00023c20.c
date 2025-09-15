
undefined4 num_buckets(int param_1)

{
  return *(undefined4 *)(&primes + *(int *)(param_1 + 8) * 4);
}

