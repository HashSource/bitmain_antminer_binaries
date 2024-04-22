
void single_BM1385_set_address(byte param_1)

{
  uint uVar1;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  printf("\n--- %s: Chain : %d\n","single_BM1385_set_address",(uint)param_1);
  BM1385_chain_inactive(param_1);
  for (local_10 = 0; uVar1 = __udivsi3(0x100,gChain_Asic_Interval), local_10 < uVar1;
      local_10 = local_10 + 1) {
    BM1385_set_address(param_1,local_c & 0xff);
    local_c = local_c + gChain_Asic_Interval;
    usleep(5000);
  }
  return;
}

