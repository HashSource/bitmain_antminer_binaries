
int get_OpenCoreResult(int param_1,int param_2)

{
  int local_10;
  int local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < 0x72; local_c = local_c + 1) {
    if (0 < *(int *)(asic_core_nonce_num + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4)) {
      local_10 = local_10 + 1;
    }
  }
  return local_10;
}

