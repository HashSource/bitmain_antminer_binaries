
ASN1_OBJECT * pkey_dh_copy(int param_1,int param_2)

{
  undefined1 uVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT *pAVar3;
  void *pvVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  
  pAVar2 = (ASN1_OBJECT *)CRYPTO_malloc(0x38,"dh_pmeth.c",0x65);
  pAVar3 = pAVar2;
  if (pAVar2 != (ASN1_OBJECT *)0x0) {
    pAVar2->length = -1;
    *(undefined1 *)&pAVar2[1].nid = 1;
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
    puVar8 = *(undefined4 **)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x24) = 2;
    *(ASN1_OBJECT **)(param_1 + 0x20) = pAVar2 + 1;
    pcVar10 = (char *)*puVar8;
    iVar5 = puVar8[2];
    iVar9 = puVar8[3];
    puVar6 = (uchar *)puVar8[4];
    iVar7 = puVar8[5];
    uVar1 = *(undefined1 *)(puVar8 + 8);
    pAVar2->ln = (char **)puVar8[1];
    pAVar2->sn = pcVar10;
    pAVar2->length = iVar9;
    pAVar2->nid = iVar5;
    pAVar2->data = puVar6;
    pAVar2->flags = iVar7;
    *(undefined1 *)&pAVar2[1].nid = uVar1;
    pAVar3 = OBJ_dup((ASN1_OBJECT *)puVar8[9]);
    pAVar2[1].length = (int)pAVar3;
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      pAVar2[1].data = (uchar *)puVar8[10];
      if (pAVar2[1].flags != 0) {
        pvVar4 = BUF_memdup((void *)puVar8[0xb],puVar8[0xc]);
        pcVar10 = (char *)puVar8[0xc];
        pAVar2[1].flags = (int)pvVar4;
        pAVar2[2].sn = pcVar10;
      }
      pAVar2[2].ln = (char **)puVar8[0xd];
      return (ASN1_OBJECT *)0x1;
    }
  }
  return pAVar3;
}

