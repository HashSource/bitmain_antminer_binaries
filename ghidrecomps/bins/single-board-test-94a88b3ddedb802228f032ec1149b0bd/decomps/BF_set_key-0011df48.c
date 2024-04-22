
void BF_set_key(BF_KEY *key,int len,uchar *data)

{
  uchar uVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  int iVar7;
  BF_KEY *pBVar8;
  uint *puVar9;
  int iVar10;
  uint local_20;
  uint local_1c;
  
  memcpy(key,DAT_0011e0c0,0x1048);
  if (len < 0x49) {
    puVar6 = data + len;
  }
  else {
    puVar6 = data + 0x48;
  }
  iVar7 = 0;
  puVar5 = data;
  do {
    uVar1 = *puVar5;
    puVar2 = puVar5 + 1;
    if (puVar6 <= puVar5 + 1) {
      puVar2 = data;
    }
    puVar3 = puVar2 + 1;
    if (puVar6 <= puVar2 + 1) {
      puVar3 = data;
    }
    puVar4 = puVar3 + 1;
    if (puVar6 <= puVar3 + 1) {
      puVar4 = data;
    }
    puVar5 = puVar4 + 1;
    if (puVar6 <= puVar4 + 1) {
      puVar5 = data;
    }
    *(uint *)((int)key->P + iVar7) =
         *(uint *)((int)key->P + iVar7) ^
         CONCAT31(CONCAT21(CONCAT11(uVar1,*puVar2),*puVar3),*puVar4);
    iVar7 = iVar7 + 4;
  } while (iVar7 != 0x48);
  local_20 = 0;
  iVar10 = 0;
  local_1c = 0;
  BF_encrypt(&local_20,key);
  iVar7 = 0x200;
  key->P[0] = local_20;
  key->P[1] = local_1c;
  BF_encrypt(&local_20,key);
  key->P[2] = local_20;
  key->P[3] = local_1c;
  BF_encrypt(&local_20,key);
  key->P[4] = local_20;
  key->P[5] = local_1c;
  BF_encrypt(&local_20,key);
  key->P[6] = local_20;
  key->P[7] = local_1c;
  BF_encrypt(&local_20,key);
  key->P[8] = local_20;
  key->P[9] = local_1c;
  BF_encrypt(&local_20,key);
  key->P[10] = local_20;
  key->P[0xb] = local_1c;
  BF_encrypt(&local_20,key);
  key->P[0xc] = local_20;
  key->P[0xd] = local_1c;
  BF_encrypt(&local_20,key);
  key->P[0xe] = local_20;
  key->P[0xf] = local_1c;
  BF_encrypt(&local_20,key);
  key->P[0x10] = local_20;
  key->P[0x11] = local_1c;
  pBVar8 = key;
  do {
    BF_encrypt(&local_20,key);
    HintPreloadData(key->S + iVar10 + 0x15);
    pBVar8->S[0] = local_20;
    iVar10 = iVar10 + 8;
    pBVar8->S[1] = local_1c;
    iVar7 = iVar7 + -4;
    BF_encrypt(&local_20,key);
    pBVar8->S[2] = local_20;
    pBVar8->S[3] = local_1c;
    BF_encrypt(&local_20,key);
    pBVar8->S[4] = local_20;
    pBVar8->S[5] = local_1c;
    BF_encrypt(&local_20,key);
    pBVar8->S[6] = local_20;
    pBVar8->S[7] = local_1c;
    pBVar8 = (BF_KEY *)(pBVar8->P + 8);
  } while (iVar10 != 0x3f8);
  puVar9 = key->S + 0x3f8;
  do {
    BF_encrypt(&local_20,key);
    iVar7 = iVar7 + -1;
    *puVar9 = local_20;
    puVar9[1] = local_1c;
    puVar9 = puVar9 + 2;
  } while (iVar7 != 0);
  return;
}

