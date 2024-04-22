
void sha256_transf(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_13c [8];
  uint local_11c [67];
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    iVar2 = param_2 + local_c * 0x40;
    for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
      local_11c[local_10] =
           CONCAT13(*(undefined *)(iVar2 + local_10 * 4),
                    CONCAT12(*(undefined *)(local_10 * 4 + 1 + iVar2),
                             CONCAT11(*(undefined *)(local_10 * 4 + 2 + iVar2),
                                      *(undefined *)(local_10 * 4 + 3 + iVar2))));
    }
    for (local_10 = 0x10; local_10 < 0x40; local_10 = local_10 + 1) {
      local_11c[local_10] =
           ((local_11c[local_10 + -2] >> 0x11 | local_11c[local_10 + -2] << 0xf) ^
            (local_11c[local_10 + -2] >> 0x13 | local_11c[local_10 + -2] << 0xd) ^
           local_11c[local_10 + -2] >> 10) + local_11c[local_10 + -7] +
           (local_11c[local_10 + -0xf] >> 3 ^
           (local_11c[local_10 + -0xf] >> 7 | local_11c[local_10 + -0xf] << 0x19) ^
           (local_11c[local_10 + -0xf] >> 0x12 | local_11c[local_10 + -0xf] << 0xe)) +
           local_11c[local_10 + -0x10];
    }
    for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
      local_13c[local_10] = *(uint *)(param_1 + (local_10 + 0x22) * 4);
    }
    for (local_10 = 0; local_10 < 0x40; local_10 = local_10 + 1) {
      iVar2 = local_11c[local_10] +
              local_13c[7] +
              ((local_13c[4] >> 0x19 | local_13c[4] << 7) ^
              (local_13c[4] >> 6 | local_13c[4] << 0x1a) ^
              (local_13c[4] >> 0xb | local_13c[4] << 0x15)) +
              (local_13c[6] & ~local_13c[4] ^ local_13c[4] & local_13c[5]) +
              *(int *)(sha256_k + local_10 * 4);
      uVar1 = local_13c[0] & local_13c[1];
      uVar3 = local_13c[2] & local_13c[0];
      uVar4 = local_13c[2] & local_13c[1];
      local_13c[7] = local_13c[6];
      local_13c[6] = local_13c[5];
      local_13c[5] = local_13c[4];
      local_13c[4] = local_13c[3] + iVar2;
      local_13c[3] = local_13c[2];
      local_13c[2] = local_13c[1];
      local_13c[1] = local_13c[0];
      local_13c[0] = iVar2 + (uVar4 ^ uVar1 ^ uVar3) +
                             ((local_13c[0] >> 2 | local_13c[0] << 0x1e) ^
                              (local_13c[0] >> 0xd | local_13c[0] << 0x13) ^
                             (local_13c[0] >> 0x16 | local_13c[0] << 10));
    }
    for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
      *(uint *)(param_1 + (local_10 + 0x22) * 4) =
           *(int *)(param_1 + (local_10 + 0x22) * 4) + local_13c[local_10];
    }
  }
  return;
}

