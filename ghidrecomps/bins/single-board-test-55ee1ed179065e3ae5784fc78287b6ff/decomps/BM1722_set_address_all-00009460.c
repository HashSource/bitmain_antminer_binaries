
void BM1722_set_address_all(byte param_1)

{
  uint uVar1;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  printf("\n--- %s: Chain : %d\n","BM1722_set_address_all",(uint)param_1);
  BM1722_chain_inactive(param_1);
  for (local_10 = 0; uVar1 = __udivsi3(0x100,gChain_Asic_Interval), local_10 < uVar1;
      local_10 = local_10 + 1) {
    BM1722_set_address(param_1,local_c & 0xff);
    local_c = local_c + gChain_Asic_Interval;
    usleep(5000);
  }
  return;
}

