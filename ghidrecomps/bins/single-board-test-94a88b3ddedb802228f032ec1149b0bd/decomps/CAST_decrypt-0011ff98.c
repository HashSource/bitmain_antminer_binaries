
void CAST_decrypt(uint *data,CAST_KEY *key)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = *data;
  uVar5 = data[1];
  iVar4 = DAT_001203ac;
  iVar1 = DAT_001203b8;
  iVar3 = DAT_001203b4;
  iVar2 = DAT_001203b0;
  if (key->short_key == 0) {
    uVar7 = uVar5 + key->data[0x1e];
    uVar6 = 0x20 - key->data[0x1f] & 0x1f;
    uVar6 = uVar7 >> uVar6 | uVar7 << 0x20 - uVar6;
    uVar8 = (*(int *)(DAT_001200b0 + ((uVar6 << 8) >> 0x18) * 4) -
            *(int *)(DAT_001200ac + (uVar6 >> 0x18) * 4)) +
            (*(uint *)(DAT_001200b8 + ((uVar6 << 0x10) >> 0x18) * 4) ^
            *(uint *)(DAT_001200b4 + (uVar6 & 0xff) * 4)) ^ uVar8;
    uVar7 = key->data[0x1c] - uVar8;
    uVar6 = 0x20 - key->data[0x1d] & 0x1f;
    uVar6 = uVar7 >> uVar6 | uVar7 << 0x20 - uVar6;
    uVar5 = (*(int *)(DAT_001200b4 + (uVar6 & 0xff) * 4) +
             *(int *)(DAT_001200b8 + ((uVar6 << 0x10) >> 0x18) * 4) ^
            *(uint *)(DAT_001200ac + (uVar6 >> 0x18) * 4)) -
            *(int *)(DAT_001200b0 + ((uVar6 << 8) >> 0x18) * 4) ^ uVar5;
    uVar7 = uVar5 ^ key->data[0x1a];
    uVar6 = 0x20 - key->data[0x1b] & 0x1f;
    uVar6 = uVar7 >> uVar6 | uVar7 << 0x20 - uVar6;
    uVar8 = uVar8 ^ *(uint *)(DAT_001200b0 + ((uVar6 << 8) >> 0x18) * 4) ^
            *(int *)(DAT_001200ac + (uVar6 >> 0x18) * 4) +
            (*(int *)(DAT_001200b8 + ((uVar6 << 0x10) >> 0x18) * 4) -
            *(int *)(DAT_001200b4 + (uVar6 & 0xff) * 4));
    uVar7 = uVar8 + key->data[0x18];
    uVar6 = 0x20 - key->data[0x19] & 0x1f;
    uVar6 = uVar7 >> uVar6 | uVar7 << 0x20 - uVar6;
    uVar5 = uVar5 ^ (*(int *)(DAT_001200b0 + ((uVar6 << 8) >> 0x18) * 4) -
                    *(int *)(DAT_001200ac + (uVar6 >> 0x18) * 4)) +
                    (*(uint *)(DAT_001200b8 + ((uVar6 << 0x10) >> 0x18) * 4) ^
                    *(uint *)(DAT_001200b4 + (uVar6 & 0xff) * 4));
    iVar4 = DAT_001200b0;
    iVar1 = DAT_001200b4;
    iVar3 = DAT_001200b8;
    iVar2 = DAT_001200ac;
  }
  uVar7 = key->data[0x16] - uVar5;
  uVar6 = 0x20 - key->data[0x17] & 0x1f;
  uVar6 = uVar7 >> uVar6 | uVar7 << 0x20 - uVar6;
  uVar8 = (*(int *)(iVar1 + (uVar6 & 0xff) * 4) + *(int *)(iVar3 + ((uVar6 << 0x10) >> 0x18) * 4) ^
          *(uint *)(iVar2 + (uVar6 >> 0x18) * 4)) - *(int *)(iVar4 + ((uVar6 << 8) >> 0x18) * 4) ^
          uVar8;
  uVar7 = uVar8 ^ key->data[0x14];
  uVar6 = 0x20 - key->data[0x15] & 0x1f;
  uVar6 = uVar7 >> uVar6 | uVar7 << 0x20 - uVar6;
  uVar7 = uVar5 ^ *(uint *)(iVar4 + ((uVar6 << 8) >> 0x18) * 4) ^
          *(int *)(iVar2 + (uVar6 >> 0x18) * 4) +
          (*(int *)(iVar3 + ((uVar6 << 0x10) >> 0x18) * 4) - *(int *)(iVar1 + (uVar6 & 0xff) * 4));
  uVar6 = uVar7 + key->data[0x12];
  uVar5 = 0x20 - key->data[0x13] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar8 = (*(int *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4) - *(int *)(iVar2 + (uVar5 >> 0x18) * 4)) +
          (*(uint *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) ^ *(uint *)(iVar1 + (uVar5 & 0xff) * 4))
          ^ uVar8;
  uVar6 = key->data[0x10] - uVar8;
  uVar5 = 0x20 - key->data[0x11] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar7 = uVar7 ^ (*(int *)(iVar1 + (uVar5 & 0xff) * 4) +
                   *(int *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) ^
                  *(uint *)(iVar2 + (uVar5 >> 0x18) * 4)) -
                  *(int *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4);
  uVar6 = uVar7 ^ key->data[0xe];
  uVar5 = 0x20 - key->data[0xf] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar8 = uVar8 ^ *(uint *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4) ^
          *(int *)(iVar2 + (uVar5 >> 0x18) * 4) +
          (*(int *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) - *(int *)(iVar1 + (uVar5 & 0xff) * 4));
  uVar6 = uVar8 + key->data[0xc];
  uVar5 = 0x20 - key->data[0xd] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar7 = (*(int *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4) - *(int *)(iVar2 + (uVar5 >> 0x18) * 4)) +
          (*(uint *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) ^ *(uint *)(iVar1 + (uVar5 & 0xff) * 4))
          ^ uVar7;
  uVar6 = key->data[10] - uVar7;
  uVar5 = 0x20 - key->data[0xb] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar8 = (*(int *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) + *(int *)(iVar1 + (uVar5 & 0xff) * 4) ^
          *(uint *)(iVar2 + (uVar5 >> 0x18) * 4)) - *(int *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4) ^
          uVar8;
  uVar6 = uVar8 ^ key->data[8];
  uVar5 = 0x20 - key->data[9] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar7 = uVar7 ^ *(uint *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4) ^
          (*(int *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) - *(int *)(iVar1 + (uVar5 & 0xff) * 4)) +
          *(int *)(iVar2 + (uVar5 >> 0x18) * 4);
  uVar6 = uVar7 + key->data[6];
  uVar5 = 0x20 - key->data[7] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar8 = (*(uint *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) ^ *(uint *)(iVar1 + (uVar5 & 0xff) * 4))
          + (*(int *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4) - *(int *)(iVar2 + (uVar5 >> 0x18) * 4)) ^
          uVar8;
  uVar6 = key->data[4] - uVar8;
  uVar5 = 0x20 - key->data[5] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar7 = (*(int *)(iVar1 + (uVar5 & 0xff) * 4) + *(int *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) ^
          *(uint *)(iVar2 + (uVar5 >> 0x18) * 4)) - *(int *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4) ^
          uVar7;
  uVar6 = uVar7 ^ key->data[2];
  uVar5 = 0x20 - key->data[3] & 0x1f;
  uVar5 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  uVar6 = uVar8 ^ *(uint *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4) ^
          (*(int *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4) - *(int *)(iVar1 + (uVar5 & 0xff) * 4)) +
          *(int *)(iVar2 + (uVar5 >> 0x18) * 4);
  uVar8 = key->data[0] + uVar6;
  uVar5 = 0x20 - key->data[1] & 0x1f;
  uVar5 = uVar8 >> uVar5 | uVar8 << 0x20 - uVar5;
  uVar8 = *(uint *)(iVar3 + ((uVar5 << 0x10) >> 0x18) * 4);
  iVar3 = *(int *)(iVar2 + (uVar5 >> 0x18) * 4);
  iVar4 = *(int *)(iVar4 + ((uVar5 << 8) >> 0x18) * 4);
  uVar5 = *(uint *)(iVar1 + (uVar5 & 0xff) * 4);
  data[1] = uVar6;
  *data = (iVar4 - iVar3) + (uVar8 ^ uVar5) ^ uVar7;
  return;
}

