
int decrypt(EVP_PKEY_CTX *ctx,uchar *out,size_t *outlen,uchar *in,size_t inlen)

{
  uint uVar1;
  int extraout_r1;
  int extraout_r1_00;
  EVP_PKEY_CTX EVar2;
  int iVar3;
  uint8_t *data_out_local;
  uint16_t len_local;
  uint8_t *data_in_local;
  eeprom_v1 *eeprom_local;
  uint8_t iv [16];
  uint8_t key [32];
  uint16_t i_2;
  uint8_t i_1;
  uint8_t i;
  
  for (i = '\0'; i < 0x20; i = i + '\x01') {
    if ((i < 0x10) && (__aeabi_uidivmod(i,*(uint *)(ctx + 0x148) % 3 + 2), extraout_r1 == 0)) {
      EVar2 = ctx[i + 0x16c];
    }
    else {
      EVar2 = ctx[i + 0x14c];
    }
    *(EVP_PKEY_CTX *)(key + i) = EVar2;
  }
  for (i_1 = '\0'; i_1 < 0x10; i_1 = i_1 + '\x01') {
    __aeabi_uidivmod(i_1,*(uint *)(ctx + 0x148) % 3 + 2);
    if (extraout_r1_00 == 0) {
      EVar2 = ctx[i_1 + 0x14c];
    }
    else {
      EVar2 = ctx[i_1 + 0x16c];
    }
    *(EVP_PKEY_CTX *)(iv + i_1) = EVar2;
  }
  uVar1 = aes256_decrypt(out,(uint)outlen & 0xffff,key,iv,in);
  if (((uint)outlen & 0xffff) == uVar1) {
    for (i_2 = 0; i_2 < (ushort)outlen; i_2 = i_2 + 1) {
      in[i_2] = (byte)ctx[(byte)ctx[0x44] + 0x14c] ^ in[i_2];
    }
    iVar3 = 0;
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}

