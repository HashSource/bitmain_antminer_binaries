
void UpdateAsicCoreEnabledFlag(int chainIndex)

{
  int iVar1;
  _Bool _Var2;
  int chainIndex_local;
  int n;
  int k;
  int j;
  int m;
  int i;
  
  iVar1 = scanfreq_info.RequiredAsicNonce / 0xd0;
  for (j = 0; j < 0x100; j = j + 1) {
    for (k = 0; k < 0x100; k = k + 1) {
      scanfreq_info.asic_core_enabled_flag[chainIndex][j][k] = 1;
    }
  }
  for (i = 0; i < scanfreq_info.AsicNum; i = i + 1) {
    if (scanfreq_info.asic_nonce_num[chainIndex][i] < scanfreq_info.RequiredAsicNonce) {
      for (m = 0; m < 0xd0; m = m + 1) {
        if ((scanfreq_info.asic_core_nonce_num[chainIndex][i][m] < iVar1) &&
           (_Var2 = isDisabledChipCore(chainIndex,i,m), !_Var2)) {
          scanfreq_info.asic_core_enabled_flag[chainIndex][i][m] = 0;
        }
      }
    }
  }
  return;
}

