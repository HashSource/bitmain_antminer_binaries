
void CAST_encrypt(uint *data,CAST_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = data[1] + key->data[0];
  uVar1 = 0x20 - key->data[1] & 0x1f;
  uVar1 = uVar3 >> uVar1 | uVar3 << 0x20 - uVar1;
  uVar3 = (*(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) -
          *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) +
          (*(uint *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
          *(uint *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) ^ *data;
  uVar2 = uVar3 ^ key->data[2];
  uVar1 = 0x20 - key->data[3] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar4 = data[1] ^ *(uint *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^
          (*(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) -
          *(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) +
          *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4);
  uVar2 = key->data[4] - uVar4;
  uVar1 = 0x20 - key->data[5] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar3 = (*(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4) +
           *(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
          *(uint *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) -
          *(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^ uVar3;
  uVar2 = uVar3 + key->data[6];
  uVar1 = 0x20 - key->data[7] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar4 = (*(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) -
          *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) +
          (*(uint *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
          *(uint *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) ^ uVar4;
  uVar2 = uVar4 ^ key->data[8];
  uVar1 = 0x20 - key->data[9] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar3 = uVar3 ^ *(uint *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^
          (*(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) -
          *(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) +
          *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4);
  uVar2 = key->data[10] - uVar3;
  uVar1 = 0x20 - key->data[0xb] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar4 = (*(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4) +
           *(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
          *(uint *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) -
          *(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^ uVar4;
  uVar2 = uVar4 + key->data[0xc];
  uVar1 = 0x20 - key->data[0xd] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar3 = (*(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) -
          *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) +
          (*(uint *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
          *(uint *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) ^ uVar3;
  uVar2 = uVar3 ^ key->data[0xe];
  uVar1 = 0x20 - key->data[0xf] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar4 = uVar4 ^ *(uint *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^
          (*(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) -
          *(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) +
          *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4);
  uVar2 = key->data[0x10] - uVar4;
  uVar1 = 0x20 - key->data[0x11] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar3 = (*(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) +
           *(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) -
          *(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^ uVar3;
  uVar2 = uVar3 + key->data[0x12];
  uVar1 = 0x20 - key->data[0x13] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar4 = (*(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) -
          *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) +
          (*(uint *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
          *(uint *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) ^ uVar4;
  uVar2 = uVar4 ^ key->data[0x14];
  uVar1 = 0x20 - key->data[0x15] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar3 = uVar3 ^ *(uint *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^
          *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4) +
          (*(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) -
          *(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4));
  uVar2 = key->data[0x16] - uVar3;
  uVar1 = 0x20 - key->data[0x17] & 0x1f;
  uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  uVar4 = (*(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4) +
           *(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
          *(uint *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) -
          *(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^ uVar4;
  if (key->short_key == 0) {
    uVar2 = uVar4 + key->data[0x18];
    uVar1 = 0x20 - key->data[0x19] & 0x1f;
    uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
    uVar3 = (*(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) -
            *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) +
            (*(uint *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
            *(uint *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) ^ uVar3;
    uVar2 = uVar3 ^ key->data[0x1a];
    uVar1 = 0x20 - key->data[0x1b] & 0x1f;
    uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
    uVar4 = uVar4 ^ *(uint *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) ^
            *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4) +
            (*(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) -
            *(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4));
    uVar2 = key->data[0x1c] - uVar4;
    uVar1 = 0x20 - key->data[0x1d] & 0x1f;
    uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
    uVar3 = uVar3 ^ (*(int *)(DAT_0011fe90 + (uVar1 & 0xff) * 4) +
                     *(int *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
                    *(uint *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) -
                    *(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4);
    uVar2 = key->data[0x1e] + uVar3;
    uVar1 = 0x20 - key->data[0x1f] & 0x1f;
    uVar1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
    uVar4 = (*(int *)(DAT_0011fe88 + ((uVar1 << 8) >> 0x18) * 4) -
            *(int *)(DAT_0011fe84 + (uVar1 >> 0x18) * 4)) +
            (*(uint *)(DAT_0011fe8c + ((uVar1 << 0x10) >> 0x18) * 4) ^
            *(uint *)(DAT_0011fe90 + (uVar1 & 0xff) * 4)) ^ uVar4;
  }
  data[1] = uVar3;
  *data = uVar4;
  return;
}

