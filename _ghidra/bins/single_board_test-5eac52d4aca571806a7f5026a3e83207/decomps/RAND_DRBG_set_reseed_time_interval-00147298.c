
bool RAND_DRBG_set_reseed_time_interval(int param_1,int param_2)

{
  if (param_2 < 0x100001) {
    *(int *)(param_1 + 0x4c) = param_2;
  }
  return param_2 < 0x100001;
}

