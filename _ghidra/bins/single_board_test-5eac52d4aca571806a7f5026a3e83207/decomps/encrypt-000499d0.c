
void encrypt(char *__block,int __edflag)

{
  uint8_t *plaintext;
  uint uVar1;
  int extraout_r1;
  int extraout_r1_00;
  ushort in_r2;
  uint8_t uVar2;
  uint8_t *in_r3;
  uint8_t *data_out_local;
  uint16_t len_local;
  uint8_t *data_in_local;
  eeprom_v1 *eeprom_local;
  uint8_t iv [16];
  uint8_t key [32];
  uint8_t *tmp;
  uint16_t i_2;
  uint8_t i_1;
  uint8_t i;
  
  plaintext = (uint8_t *)malloc((uint)in_r2);
  if (plaintext != (uint8_t *)0x0) {
    memcpy(plaintext,(void *)__edflag,(uint)in_r2);
    for (i = '\0'; i < 0x20; i = i + '\x01') {
      if ((i < 0x10) && (__aeabi_uidivmod(i,*(uint *)(__block + 0x148) % 3 + 2), extraout_r1 == 0))
      {
        uVar2 = __block[i + 0x16c];
      }
      else {
        uVar2 = __block[i + 0x14c];
      }
      key[i] = uVar2;
    }
    for (i_1 = '\0'; i_1 < 0x10; i_1 = i_1 + '\x01') {
      __aeabi_uidivmod(i_1,*(uint *)(__block + 0x148) % 3 + 2);
      if (extraout_r1_00 == 0) {
        uVar2 = __block[i_1 + 0x14c];
      }
      else {
        uVar2 = __block[i_1 + 0x16c];
      }
      iv[i_1] = uVar2;
    }
    for (i_2 = 0; i_2 < in_r2; i_2 = i_2 + 1) {
      plaintext[i_2] = __block[(byte)__block[0x44] + 0x14c] ^ plaintext[i_2];
    }
    uVar1 = aes256_encrypt(plaintext,(uint)in_r2,key,iv,in_r3);
    if (in_r2 == uVar1) {
      free(plaintext);
    }
    else {
      free(plaintext);
    }
  }
  return;
}

