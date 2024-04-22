
void saving_ideal_hash_rate(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined auStack_1c [4];
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      iVar1 = is_S9_Hydro();
      if (iVar1 == 0) {
        iVar1 = is_S9i();
        if (iVar1 == 0) {
          if (*(char *)(param_1 + 0x16176) == '\0') {
            *(int *)(local_c * 0x80 + *param_1 + 0x1a3fbbe) = param_1[local_c + 0x16166];
          }
          else {
            iVar2 = *param_1;
            iVar1 = iVar2 + 3;
            if (-1 < iVar2) {
              iVar1 = iVar2;
            }
            *(int *)(local_c * 0x80 + (iVar1 >> 2) + *param_1 + 0x1a3fbc3) =
                 param_1[local_c + 0x16166];
          }
        }
        else {
          chain_pic_buf[local_c * 0x80 + 0x1c] = (byte)param_1[local_c + 0x16166] & 0xf;
          chain_pic_buf[local_c * 0x80 + 0x1e] = (byte)(param_1[local_c + 0x16166] >> 4) & 0xf;
          chain_pic_buf[local_c * 0x80 + 0x20] = (byte)((uint)param_1[local_c + 0x16166] >> 8) & 0xf
          ;
          chain_pic_buf[local_c * 0x80 + 0x22] = (byte)(param_1[local_c + 0x16166] >> 0xc) & 0xf;
        }
      }
      else {
        local_10 = get_board_index_S9_Hydro(local_c,&local_14);
        getPICChainIndexOffset(local_10,&local_18,auStack_1c);
        *(int *)(local_18 * 0x80 + local_14 * 4 + *param_1 + 0x1a3fbbe) = param_1[local_c + 0x16166]
        ;
      }
    }
  }
  return;
}

