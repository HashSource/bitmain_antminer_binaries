
void san_freq_clear_nonce_return_back_flag(int chain)

{
  int iVar1;
  SCAN_FREQ_WORK *pSVar2;
  int chain_local;
  SCAN_FREQ_WORK *work;
  SCAN_FREQ_WORK *works;
  int n;
  int j;
  int i;
  
  for (i = 0; i < scanfreq_info.AsicNum; i = i + 1) {
    pSVar2 = scanfreq_info.works[i];
    for (n = 0; n < scanfreq_info.CoreNum; n = n + 1) {
      for (j = 0; iVar1 = __aeabi_idiv(scanfreq_info.AsicWorkCount,scanfreq_info.CoreNum), j < iVar1
          ; j = j + 1) {
        iVar1 = __aeabi_idiv(scanfreq_info.AsicWorkCount,scanfreq_info.CoreNum);
        pSVar2[j + n * iVar1].is_nonce_return_back[chain] = 0;
      }
    }
  }
  return;
}

