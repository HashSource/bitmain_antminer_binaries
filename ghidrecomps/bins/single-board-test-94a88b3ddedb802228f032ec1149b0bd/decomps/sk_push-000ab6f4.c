
int sk_push(_STACK *st,void *data)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char **ppcVar5;
  int iVar6;
  char **ppcVar7;
  int iVar8;
  
  iVar6 = st->num;
  iVar2 = iVar6 + 1;
  if (iVar2 < st->num_alloc) {
    ppcVar7 = st->data;
    iVar8 = iVar6;
  }
  else {
    ppcVar7 = (char **)CRYPTO_realloc(st->data,st->num_alloc << 3,DAT_000ab7d0,0xbb);
    if (ppcVar7 == (char **)0x0) {
      return 0;
    }
    iVar8 = st->num;
    st->data = ppcVar7;
    st->num_alloc = st->num_alloc << 1;
    if ((iVar6 < iVar8) && (-1 < iVar6)) {
      iVar4 = iVar8 + -1;
      iVar2 = iVar8;
      if (iVar6 < 0x7ffffffa && iVar6 + 6 < iVar4) {
        ppcVar5 = ppcVar7 + iVar8 + -0x19;
        iVar3 = iVar8;
        do {
          iVar2 = iVar3 + -8;
          iVar4 = iVar3 + -9;
          HintPreloadData(ppcVar5);
          ppcVar5[0x1a] = ppcVar5[0x19];
          ppcVar5[0x19] = ppcVar5[0x18];
          ppcVar5[0x18] = ppcVar5[0x17];
          ppcVar5[0x17] = ppcVar5[0x16];
          ppcVar5[0x16] = ppcVar5[0x15];
          ppcVar5[0x15] = ppcVar5[0x14];
          ppcVar5[0x14] = ppcVar5[0x13];
          ppcVar5[0x13] = ppcVar5[0x12];
          ppcVar5 = ppcVar5 + -8;
          iVar3 = iVar2;
        } while (iVar6 + 6 < iVar4);
      }
      ppcVar7 = ppcVar7 + iVar2 + 1;
      do {
        *ppcVar7 = ppcVar7[-1];
        bVar1 = iVar6 <= iVar4;
        iVar4 = iVar4 + -1;
        ppcVar7 = ppcVar7 + -1;
      } while (bVar1);
      iVar2 = iVar8 + 1;
      st->data[iVar6] = (char *)data;
      goto LAB_000ab70e;
    }
    iVar2 = iVar8 + 1;
  }
  ppcVar7[iVar8] = (char *)data;
LAB_000ab70e:
  st->num = iVar2;
  st->sorted = 0;
  return iVar2;
}

