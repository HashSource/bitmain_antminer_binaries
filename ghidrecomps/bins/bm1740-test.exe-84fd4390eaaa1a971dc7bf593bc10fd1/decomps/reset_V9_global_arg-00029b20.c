
void reset_V9_global_arg(void)

{
  bool bVar1;
  int iVar2;
  uint local_18;
  uint local_14;
  uint local_10;
  
  reset_global_arg();
  bVar1 = false;
  while (!bVar1) {
    cgpu[131836] = 0;
    gRepeated_Nonce_Id = 0;
    gValid_Nonce_Num = 0;
    gSend_Work_Num = 0;
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      iVar2 = *(int *)(cgpu + (local_10 + 0x402a) * 4 + 4);
      for (local_14 = 0; local_14 < 0x32; local_14 = local_14 + 1) {
        *(undefined4 *)(gAsic_Core_Nonce_Num + (local_10 * 0x80 + local_14) * 4) = 0;
        for (local_18 = 0; local_18 < (uint)Conf._64_4_; local_18 = local_18 + 1) {
          *(undefined4 *)(iVar2 + (local_14 * Conf._64_4_ + local_18) * 0x38 + 0x34) = 0;
        }
      }
    }
    bVar1 = true;
  }
  return;
}

