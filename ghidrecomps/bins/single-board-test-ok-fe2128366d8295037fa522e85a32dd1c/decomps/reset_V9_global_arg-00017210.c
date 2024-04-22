
void reset_V9_global_arg(void)

{
  int iVar1;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  reset_global_arg();
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    cgpu[local_c + 0x20338] = 0;
    *(undefined4 *)(gRepeated_Nonce_Id + local_c * 4) = 0;
    *(undefined4 *)(gValid_Nonce_Num + local_c * 4) = 0;
    *(undefined4 *)(gSend_Work_Num + local_c * 4) = 0;
    for (local_10 = 0; local_10 < 0x2d; local_10 = local_10 + 1) {
      iVar1 = *(int *)(cgpu + (local_10 + 0x402a) * 4 + 4);
      for (local_14 = 0; local_14 < 0x32; local_14 = local_14 + 1) {
        *(undefined4 *)(gAsic_Core_Nonce_Num + ((local_c * 0x80 + local_10) * 0x80 + local_14) * 4)
             = 0;
        for (local_18 = 0; local_18 < (uint)Conf._64_4_; local_18 = local_18 + 1) {
          *(undefined4 *)
           (iVar1 + (local_14 * Conf._64_4_ + local_18) * 0x74 + (local_c + 0xc) * 4 + 4) = 0;
        }
      }
    }
  }
  return;
}

