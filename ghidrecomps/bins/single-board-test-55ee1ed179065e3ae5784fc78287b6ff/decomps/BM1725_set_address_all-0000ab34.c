
void BM1725_set_address_all(byte param_1)

{
  byte local_a;
  char local_9;
  
  local_9 = '\0';
  printf("\n--- %s: Chain : %d\n","BM1725_set_address_all",(uint)param_1);
  BM1725_chain_inactive(param_1);
  for (local_a = 0; (uint)local_a < (uint)Conf._108_4_; local_a = local_a + 1) {
    BM1725_set_address(param_1,local_9);
    local_9 = (char)gChain_Asic_Interval + local_9;
    usleep(5000);
  }
  return;
}

