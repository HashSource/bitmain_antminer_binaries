
void PostRateVoltageToServer(void)

{
  undefined4 uVar1;
  undefined4 local_4a0 [16];
  undefined4 local_460 [16];
  char acStack_420 [1024];
  int local_20;
  int local_1c;
  
  local_20 = 0;
  for (local_1c = 0; local_1c < 0x10; local_1c = local_1c + 1) {
    local_460[local_1c] = 0;
    local_4a0[local_1c] = 0;
  }
  for (local_1c = 0; local_1c < 0x10; local_1c = local_1c + 1) {
    if (*(int *)(cgpu + (local_1c + 0x9c638) * 4) != 0) {
      uVar1 = GetBoardRate(local_1c);
      local_460[local_20] = uVar1;
      local_4a0[local_20] = *(undefined4 *)(chain_vol_value + local_1c * 4);
      local_20 = local_20 + 1;
    }
  }
  sprintf(acStack_420,
          "postratevol.do?minertype=S9-PLUS&minerID=%s&hashrate1=%d&hashrate2=%d&hashrate3=%d&hashrate4=%d&voltage1=%d&voltage2=%d&voltage3=%d&voltage4=%d"
          ,FPGA_ID_str,local_460[0],local_460[1],local_460[2],local_460[3],local_4a0[0],local_4a0[1]
          ,local_4a0[2],local_4a0[3]);
  PostMsgToTestPlatform(acStack_420);
  return;
}

