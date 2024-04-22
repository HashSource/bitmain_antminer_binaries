
void Sha256_Transform(uint32_t *state,uint32_t *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint uVar10;
  uint32_t *data_local;
  uint32_t *state_local;
  uint32_t T [8];
  uint32_t W [16];
  uint i;
  uint j;
  
  for (j = 0; j < 8; j = j + 1) {
    T[j] = state[j];
  }
  for (j = 0; j < 0x40; j = j + 0x10) {
    for (i = 0; i < 0x10; i = i + 1) {
      uVar4 = T[4 - i & 7];
      uVar5 = T[4 - i & 7];
      uVar6 = T[4 - i & 7];
      uVar2 = T[6 - i & 7];
      uVar1 = T[4 - i & 7];
      uVar10 = T[5 - i & 7];
      uVar7 = T[6 - i & 7];
      uVar8 = K[i + j];
      if (j == 0) {
        W[i] = data[i];
        uVar9 = W[i];
      }
      else {
        uVar3 = i & 0xf;
        W[uVar3] = W[i & 0xf] +
                   (W[i - 0xf & 0xf] >> 3 ^
                   (W[i - 0xf & 0xf] >> 7 | W[i - 0xf & 0xf] << 0x19) ^
                   (W[i - 0xf & 0xf] >> 0x12 | W[i - 0xf & 0xf] << 0xe)) +
                   ((W[i - 2 & 0xf] >> 0x11 | W[i - 2 & 0xf] << 0xf) ^
                    (W[i - 2 & 0xf] >> 0x13 | W[i - 2 & 0xf] << 0xd) ^ W[i - 2 & 0xf] >> 10) +
                   W[i - 7 & 0xf];
        uVar9 = W[uVar3];
      }
      T[7 - i & 7] = ((uVar4 >> 6 | uVar4 << 0x1a) ^ (uVar5 >> 0xb | uVar5 << 0x15) ^
                     (uVar6 >> 0x19 | uVar6 << 7)) + ((uVar7 ^ uVar10) & uVar1 ^ uVar2) + uVar8 +
                     uVar9 + T[7 - i & 7];
      T[3 - i & 7] = T[3 - i & 7] + T[7 - i & 7];
      T[7 - i & 7] = T[7 - i & 7] +
                     ((T[1 - i & 7] | T[-i & 7]) & T[2 - i & 7] | T[-i & 7] & T[1 - i & 7]) +
                     ((T[-i & 7] >> 2 | T[-i & 7] << 0x1e) ^ (T[-i & 7] >> 0xd | T[-i & 7] << 0x13)
                     ^ (T[-i & 7] >> 0x16 | T[-i & 7] << 10));
    }
  }
  for (j = 0; j < 8; j = j + 1) {
    state[j] = T[j] + state[j];
  }
  return;
}

