
void CAST_decrypt(uint *data,CAST_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *data;
  uVar4 = data[1];
  if (key->short_key == 0) {
    uVar1 = key->data[0x1e] + uVar4;
    uVar2 = 0x20 - key->data[0x1f] & 0x1f;
    uVar2 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
    uVar3 = (*(int *)(CAST_S_table3 + ((uVar2 << 8) >> 0x18) * 4) -
            *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) +
            (*(uint *)(CAST_S_table0 + ((uVar2 << 0x10) >> 0x18) * 4) ^
            *(uint *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) ^ uVar3;
    uVar1 = key->data[0x1c] - uVar3;
    uVar2 = 0x20 - key->data[0x1d] & 0x1f;
    uVar2 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
    uVar4 = (*(int *)(CAST_S_table1 + (uVar2 & 0xff) * 4) +
             *(int *)(CAST_S_table0 + ((uVar2 << 0x10) >> 0x18) * 4) ^
            *(uint *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) -
            *(int *)(CAST_S_table3 + ((uVar2 << 8) >> 0x18) * 4) ^ uVar4;
    uVar1 = uVar4 ^ key->data[0x1a];
    uVar2 = 0x20 - key->data[0x1b] & 0x1f;
    uVar2 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
    uVar3 = *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4) +
            (*(int *)(CAST_S_table0 + ((uVar2 << 0x10) >> 0x18) * 4) -
            *(int *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) ^
            uVar3 ^ *(uint *)(CAST_S_table3 + ((uVar2 << 8) >> 0x18) * 4);
    uVar1 = uVar3 + key->data[0x18];
    uVar2 = 0x20 - key->data[0x19] & 0x1f;
    uVar2 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
    uVar4 = (*(int *)(CAST_S_table3 + ((uVar2 << 8) >> 0x18) * 4) -
            *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) +
            (*(uint *)(CAST_S_table0 + ((uVar2 << 0x10) >> 0x18) * 4) ^
            *(uint *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) ^ uVar4;
  }
  uVar1 = key->data[0x16] - uVar4;
  uVar2 = 0x20 - key->data[0x17] & 0x1f;
  uVar2 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
  uVar3 = (*(int *)(CAST_S_table1 + (uVar2 & 0xff) * 4) +
           *(int *)(CAST_S_table0 + ((uVar2 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + ((uVar2 << 8) >> 0x18) * 4) ^ uVar3;
  uVar1 = uVar3 ^ key->data[0x14];
  uVar2 = 0x20 - key->data[0x15] & 0x1f;
  uVar2 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
  uVar1 = *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4) +
          (*(int *)(CAST_S_table0 + ((uVar2 << 0x10) >> 0x18) * 4) -
          *(int *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) ^
          uVar4 ^ *(uint *)(CAST_S_table3 + ((uVar2 << 8) >> 0x18) * 4);
  uVar2 = uVar1 + key->data[0x12];
  uVar4 = 0x20 - key->data[0x13] & 0x1f;
  uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
  uVar3 = (*(uint *)(CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
          (*(int *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4) -
          *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) ^ uVar3;
  uVar2 = key->data[0x10] - uVar3;
  uVar4 = 0x20 - key->data[0x11] & 0x1f;
  uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
  uVar1 = (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
           *(int *)(CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4) ^ uVar1;
  uVar2 = uVar1 ^ key->data[0xe];
  uVar4 = 0x20 - key->data[0xf] & 0x1f;
  uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
  uVar2 = *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4) +
          (*(int *)(CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4) -
          *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) ^
          uVar3 ^ *(uint *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4);
  uVar4 = uVar2 + key->data[0xc];
  uVar3 = 0x20 - key->data[0xd] & 0x1f;
  uVar3 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  uVar1 = (*(int *)(CAST_S_table3 + ((uVar3 << 8) >> 0x18) * 4) -
          *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) +
          (*(uint *)(CAST_S_table0 + ((uVar3 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) ^ uVar1;
  uVar4 = key->data[10] - uVar1;
  uVar3 = 0x20 - key->data[0xb] & 0x1f;
  uVar3 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  uVar2 = (*(int *)(CAST_S_table1 + (uVar3 & 0xff) * 4) +
           *(int *)(CAST_S_table0 + ((uVar3 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + ((uVar3 << 8) >> 0x18) * 4) ^ uVar2;
  uVar4 = uVar2 ^ key->data[8];
  uVar3 = 0x20 - key->data[9] & 0x1f;
  uVar3 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  uVar1 = (*(int *)(CAST_S_table0 + ((uVar3 << 0x10) >> 0x18) * 4) -
          *(int *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4) ^
          uVar1 ^ *(uint *)(CAST_S_table3 + ((uVar3 << 8) >> 0x18) * 4);
  uVar4 = uVar1 + key->data[6];
  uVar3 = 0x20 - key->data[7] & 0x1f;
  uVar3 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  uVar2 = (*(uint *)(CAST_S_table0 + ((uVar3 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) +
          (*(int *)(CAST_S_table3 + ((uVar3 << 8) >> 0x18) * 4) -
          *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) ^ uVar2;
  uVar4 = key->data[4] - uVar2;
  uVar3 = 0x20 - key->data[5] & 0x1f;
  uVar3 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  uVar1 = (*(int *)(CAST_S_table0 + ((uVar3 << 0x10) >> 0x18) * 4) +
           *(int *)(CAST_S_table1 + (uVar3 & 0xff) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + ((uVar3 << 8) >> 0x18) * 4) ^ uVar1;
  uVar4 = uVar1 ^ key->data[2];
  uVar3 = 0x20 - key->data[3] & 0x1f;
  uVar3 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  uVar2 = (*(int *)(CAST_S_table0 + ((uVar3 << 0x10) >> 0x18) * 4) -
          *(int *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4) ^
          uVar2 ^ *(uint *)(CAST_S_table3 + ((uVar3 << 8) >> 0x18) * 4);
  uVar4 = uVar2 + key->data[0];
  uVar3 = 0x20 - key->data[1] & 0x1f;
  uVar3 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  data[1] = uVar2;
  *data = (*(uint *)(CAST_S_table0 + ((uVar3 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) +
          (*(int *)(CAST_S_table3 + ((uVar3 << 8) >> 0x18) * 4) -
          *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) ^ uVar1;
  return;
}

