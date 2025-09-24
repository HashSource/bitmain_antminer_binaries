
bool RAND_DRBG_set_reseed_interval(int param_1,uint param_2)

{
  if (param_2 < 0x1000001) {
    *(uint *)(param_1 + 0x44) = param_2;
  }
  return param_2 < 0x1000001;
}

