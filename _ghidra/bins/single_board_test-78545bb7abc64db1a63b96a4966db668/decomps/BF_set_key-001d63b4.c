
void BF_set_key(BF_KEY *key,int len,uchar *data)

{
  uchar *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  int iVar7;
  BF_KEY *pBVar8;
  int iVar9;
  uint *puVar10;
  uint local_28;
  uint local_24;
  
  memcpy(key,&bf_init,0x1048);
  puVar2 = data;
  pBVar8 = key;
  if (len < 0x49) {
    puVar1 = data + len;
  }
  else {
    puVar1 = data + 0x48;
  }
  do {
    puVar4 = puVar2 + 1;
    if (puVar1 <= puVar2 + 1) {
      puVar4 = data;
    }
    puVar5 = puVar4 + 1;
    if (puVar1 <= puVar4 + 1) {
      puVar5 = data;
    }
    puVar6 = puVar5 + 1;
    if (puVar1 <= puVar5 + 1) {
      puVar6 = data;
    }
    puVar3 = puVar6 + 1;
    if (puVar1 <= puVar6 + 1) {
      puVar3 = data;
    }
    puVar10 = pBVar8->P;
    pBVar8->P[0] = pBVar8->P[0] ^ CONCAT31(CONCAT21(CONCAT11(*puVar2,*puVar4),*puVar5),*puVar6);
    puVar2 = puVar3;
    pBVar8 = (BF_KEY *)(puVar10 + 1);
  } while ((BF_KEY *)(puVar10 + 1) != (BF_KEY *)key->S);
  local_28 = 0;
  local_24 = 0;
  pBVar8 = key;
  do {
    BF_encrypt(&local_28,key);
    pBVar8->P[0] = local_28;
    pBVar8->P[1] = local_24;
    pBVar8 = (BF_KEY *)(pBVar8->P + 2);
  } while (pBVar8 != (BF_KEY *)key->S);
  iVar7 = 0x200;
  iVar9 = 0;
  puVar10 = key->S + 0x11;
  do {
    BF_encrypt(&local_28,key);
    HintPreloadData(puVar10);
    iVar9 = iVar9 + 8;
    puVar10[-0x11] = local_28;
    iVar7 = iVar7 + -4;
    puVar10[-0x10] = local_24;
    BF_encrypt(&local_28,key);
    puVar10[-0xf] = local_28;
    puVar10[-0xe] = local_24;
    BF_encrypt(&local_28,key);
    puVar10[-0xd] = local_28;
    puVar10[-0xc] = local_24;
    BF_encrypt(&local_28,key);
    puVar10[-0xb] = local_28;
    puVar10[-10] = local_24;
    puVar10 = puVar10 + 8;
  } while (iVar9 != 0x3f8);
  puVar10 = key->S + 0x3f8;
  do {
    BF_encrypt(&local_28,key);
    iVar7 = iVar7 + -1;
    *puVar10 = local_28;
    puVar10[1] = local_24;
    puVar10 = puVar10 + 2;
  } while (iVar7 != 0);
  return;
}

