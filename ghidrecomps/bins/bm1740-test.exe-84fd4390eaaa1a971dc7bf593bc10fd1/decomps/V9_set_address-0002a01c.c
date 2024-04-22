
void V9_set_address(byte param_1)

{
  byte local_a;
  char local_9;
  
  local_9 = '\0';
  printf("\n--- %s: Chain : %d\n","V9_set_address",(uint)param_1);
  BM1385_chain_inactive(param_1);
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    BM1385_set_address(param_1,local_9);
    local_9 = (char)gChain_Asic_Interval + local_9;
    usleep(5000);
  }
  return;
}

