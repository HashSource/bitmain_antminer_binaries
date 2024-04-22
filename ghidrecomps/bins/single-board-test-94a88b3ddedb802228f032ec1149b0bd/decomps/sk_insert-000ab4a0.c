
int sk_insert(_STACK *sk,void *data,int where)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char **ppcVar5;
  int iVar6;
  int iVar7;
  char **ppcVar8;
  
  if (sk == (_STACK *)0x0) {
    return 0;
  }
  iVar2 = sk->num;
  iVar4 = iVar2 + 1;
  if (iVar4 < sk->num_alloc) {
    ppcVar8 = sk->data;
  }
  else {
    ppcVar8 = (char **)CRYPTO_realloc(sk->data,sk->num_alloc << 3,DAT_000ab570,0xbb);
    if (ppcVar8 == (char **)0x0) {
      return 0;
    }
    iVar2 = sk->num;
    sk->data = ppcVar8;
    iVar4 = iVar2 + 1;
    sk->num_alloc = sk->num_alloc << 1;
  }
  if ((where < iVar2) && (-1 < where)) {
    iVar7 = iVar2 + -1;
    iVar6 = iVar4;
    if (where < 0x7ffffffa && where + 6 < iVar7) {
      ppcVar5 = ppcVar8 + iVar2 + -0x19;
      do {
        iVar6 = iVar2;
        iVar7 = iVar6 + -9;
        HintPreloadData(ppcVar5);
        ppcVar5[0x1a] = ppcVar5[0x19];
        pcVar3 = ppcVar5[0x18];
        ppcVar5[0x18] = ppcVar5[0x17];
        ppcVar5[0x19] = pcVar3;
        ppcVar5[0x17] = ppcVar5[0x16];
        ppcVar5[0x16] = ppcVar5[0x15];
        ppcVar5[0x15] = ppcVar5[0x14];
        pcVar3 = ppcVar5[0x13];
        ppcVar5[0x13] = ppcVar5[0x12];
        ppcVar5[0x14] = pcVar3;
        ppcVar5 = ppcVar5 + -8;
        iVar2 = iVar6 + -8;
      } while (where + 6 < iVar7);
      iVar6 = iVar6 + -7;
    }
    ppcVar8 = ppcVar8 + iVar6;
    do {
      *ppcVar8 = ppcVar8[-1];
      bVar1 = where <= iVar7;
      iVar7 = iVar7 + -1;
      ppcVar8 = ppcVar8 + -1;
    } while (bVar1);
    sk->data[where] = (char *)data;
  }
  else {
    ppcVar8[iVar2] = (char *)data;
  }
  sk->num = iVar4;
  sk->sorted = 0;
  return iVar4;
}

