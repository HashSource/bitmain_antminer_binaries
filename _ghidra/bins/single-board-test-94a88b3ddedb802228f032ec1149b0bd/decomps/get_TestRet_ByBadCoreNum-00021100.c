
bool get_TestRet_ByBadCoreNum(int param_1,int param_2,int param_3)

{
  return param_3 - (param_3 / 0x72) * *(int *)(chain_badcore_num + (param_2 + param_1 * 0x100) * 4)
         <= *(int *)(asic_nonce_num + (param_2 + param_1 * 0x100) * 4);
}

