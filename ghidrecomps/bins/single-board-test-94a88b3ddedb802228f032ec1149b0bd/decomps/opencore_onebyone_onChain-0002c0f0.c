
void opencore_onebyone_onChain(undefined4 param_1)

{
  int local_c;
  
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    open_core_onChain(param_1,0x72,local_c + 1,1);
    usleep(100000);
  }
  return;
}

