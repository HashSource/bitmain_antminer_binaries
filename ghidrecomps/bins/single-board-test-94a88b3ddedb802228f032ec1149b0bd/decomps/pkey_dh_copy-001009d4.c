
ASN1_OBJECT * pkey_dh_copy(int param_1,int param_2)

{
  undefined uVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT *pAVar3;
  void *pvVar4;
  char *pcVar5;
  uchar *puVar6;
  char *pcVar7;
  char **ppcVar8;
  char *pcVar9;
  char *pcVar10;
  
  pAVar2 = (ASN1_OBJECT *)CRYPTO_malloc(0x38,DAT_00100a68,0x65);
  pAVar3 = pAVar2;
  if (pAVar2 != (ASN1_OBJECT *)0x0) {
    pAVar2->length = -1;
    *(undefined *)&pAVar2[1].nid = 1;
    pAVar2->ln = (char **)0x2;
    pAVar2->nid = 0;
    pAVar2->data = (uchar *)0x0;
    pAVar2->sn = (char *)0x400;
    pAVar2->flags = 0;
    pAVar2[1].length = 0;
    pAVar2[1].data = (uchar *)0x0;
    pAVar2[1].flags = 0;
    pAVar2[2].sn = (char *)0x0;
    pAVar2[2].ln = (char **)0x0;
    *(ASN1_OBJECT **)(param_1 + 0x14) = pAVar2;
    ppcVar8 = *(char ***)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x24) = 2;
    *(ASN1_OBJECT **)(param_1 + 0x20) = pAVar2 + 1;
    pcVar10 = *ppcVar8;
    pcVar5 = ppcVar8[2];
    pcVar9 = ppcVar8[3];
    puVar6 = (uchar *)ppcVar8[4];
    pcVar7 = ppcVar8[5];
    uVar1 = *(undefined *)(ppcVar8 + 8);
    pAVar2->ln = (char **)ppcVar8[1];
    pAVar2->sn = pcVar10;
    pAVar2->length = (int)pcVar9;
    pAVar2->nid = (int)pcVar5;
    pAVar2->data = puVar6;
    pAVar2->flags = (int)pcVar7;
    *(undefined *)&pAVar2[1].nid = uVar1;
    pAVar3 = OBJ_dup((ASN1_OBJECT *)ppcVar8[9]);
    pAVar2[1].length = (int)pAVar3;
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      pAVar2[1].data = (uchar *)ppcVar8[10];
      if (pAVar2[1].flags != 0) {
        pvVar4 = BUF_memdup(ppcVar8[0xb],(size_t)ppcVar8[0xc]);
        pcVar5 = ppcVar8[0xc];
        pAVar2[1].flags = (int)pvVar4;
        pAVar2[2].sn = pcVar5;
      }
      pAVar2[2].ln = (char **)ppcVar8[0xd];
      return (ASN1_OBJECT *)0x1;
    }
  }
  return pAVar3;
}

