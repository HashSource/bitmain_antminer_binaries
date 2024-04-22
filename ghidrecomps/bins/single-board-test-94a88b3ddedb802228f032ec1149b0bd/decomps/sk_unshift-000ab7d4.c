
int sk_unshift(_STACK *st,void *data)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char **ppcVar4;
  char **ppcVar5;
  int iVar6;
  
  if (st == (_STACK *)0x0) {
    return 0;
  }
  uVar2 = st->num;
  iVar6 = uVar2 + 1;
  if (iVar6 < st->num_alloc) {
    ppcVar5 = st->data;
  }
  else {
    ppcVar5 = (char **)CRYPTO_realloc(st->data,st->num_alloc << 3,DAT_000ab894,0xbb);
    if (ppcVar5 == (char **)0x0) {
      return 0;
    }
    uVar2 = st->num;
    st->data = ppcVar5;
    iVar6 = uVar2 + 1;
    st->num_alloc = st->num_alloc << 1;
  }
  if ((int)uVar2 < 1) {
    ppcVar5[uVar2] = (char *)data;
  }
  else {
    iVar3 = iVar6;
    if (7 < (int)uVar2) {
      ppcVar4 = ppcVar5 + (uVar2 - 0x19);
      iVar3 = uVar2 - (uVar2 - 8 & 0xfffffff8);
      uVar1 = uVar2 - 8;
      do {
        uVar2 = uVar1;
        HintPreloadData(ppcVar4);
        ppcVar4[0x1a] = ppcVar4[0x19];
        ppcVar4[0x19] = ppcVar4[0x18];
        ppcVar4[0x18] = ppcVar4[0x17];
        ppcVar4[0x17] = ppcVar4[0x16];
        ppcVar4[0x16] = ppcVar4[0x15];
        ppcVar4[0x15] = ppcVar4[0x14];
        ppcVar4[0x14] = ppcVar4[0x13];
        ppcVar4[0x13] = ppcVar4[0x12];
        ppcVar4 = ppcVar4 + -8;
        uVar1 = uVar2 - 8;
      } while (uVar2 != iVar3 - 8U);
      iVar3 = iVar3 + -7;
    }
    ppcVar5 = ppcVar5 + iVar3;
    do {
      uVar2 = uVar2 - 1;
      *ppcVar5 = ppcVar5[-1];
      ppcVar5 = ppcVar5 + -1;
    } while (-1 < (int)uVar2);
    *st->data = (char *)data;
  }
  st->num = iVar6;
  st->sorted = 0;
  return iVar6;
}

