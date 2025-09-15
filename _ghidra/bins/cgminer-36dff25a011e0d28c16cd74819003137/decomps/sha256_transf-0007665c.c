
void sha256_transf(sha256_ctx *ctx,uchar *message,uint block_nb)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint block_nb_local;
  uchar *message_local;
  sha256_ctx *ctx_local;
  uint32_t wv [8];
  uint32_t w [64];
  uint32_t t2;
  uint32_t t1;
  uchar *sub_block;
  int j;
  int i;
  
  for (i = 0; i < (int)block_nb; i = i + 1) {
    for (j = 0; j < 0x10; j = j + 1) {
      w[j] = CONCAT13(message[j * 4 + i * 0x40],
                      CONCAT12(message[j * 4 + 1 + i * 0x40],
                               CONCAT11(message[j * 4 + 2 + i * 0x40],message[j * 4 + 3 + i * 0x40])
                              ));
    }
    for (j = 0x10; j < 0x40; j = j + 1) {
      w[j] = ((w[j + -2] >> 0x11 | w[j + -2] << 0xf) ^ (w[j + -2] >> 0x13 | w[j + -2] << 0xd) ^
             w[j + -2] >> 10) + w[j + -7] +
             (w[j + -0xf] >> 3 ^
             (w[j + -0xf] >> 7 | w[j + -0xf] << 0x19) ^ (w[j + -0xf] >> 0x12 | w[j + -0xf] << 0xe))
             + w[j + -0x10];
    }
    for (j = 0; j < 8; j = j + 1) {
      wv[j] = ctx->h[j];
    }
    for (j = 0; j < 0x40; j = j + 1) {
      iVar1 = wv[7] + ((wv[4] >> 0x19 | wv[4] << 7) ^
                      (wv[4] >> 6 | wv[4] << 0x1a) ^ (wv[4] >> 0xb | wv[4] << 0x15)) +
              (wv[6] & ~wv[4] ^ wv[4] & wv[5]) + sha256_k[j] + w[j];
      uVar2 = wv[2] ^ wv[1];
      uVar3 = wv[2] & wv[1];
      wv[7] = wv[6];
      wv[6] = wv[5];
      wv[5] = wv[4];
      wv[4] = wv[3] + iVar1;
      wv[3] = wv[2];
      wv[2] = wv[1];
      wv[1] = wv[0];
      wv[0] = iVar1 + ((wv[0] >> 2 | wv[0] << 0x1e) ^ (wv[0] >> 0xd | wv[0] << 0x13) ^
                      (wv[0] >> 0x16 | wv[0] << 10)) + (uVar3 ^ wv[0] & uVar2);
    }
    for (j = 0; j < 8; j = j + 1) {
      ctx->h[j] = ctx->h[j] + wv[j];
    }
  }
  return;
}

