
char * X509_NAME_oneline(X509_NAME *a,char *buf,int size)

{
  byte bVar1;
  int iVar2;
  ASN1_OBJECT **ppAVar3;
  char *pcVar4;
  size_t __n;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  char *pcVar8;
  ASN1_OBJECT *pAVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  int iVar16;
  int iVar17;
  BUF_MEM *local_98;
  char *local_90;
  int local_8c;
  uint local_88 [4];
  char acStack_78 [84];
  
  if (buf == (char *)0x0) {
    local_98 = BUF_MEM_new();
    if (local_98 == (BUF_MEM *)0x0) {
      ERR_put_error(0xb,0x74,0x41,DAT_000c0a90,0xd0);
      return (char *)0x0;
    }
    iVar13 = BUF_MEM_grow(local_98,200);
    if (iVar13 == 0) {
LAB_000c08c2:
      ERR_put_error(0xb,0x74,0x41,DAT_000c0a90,0xd0);
      BUF_MEM_free(local_98);
      return (char *)0x0;
    }
    *local_98->data = '\0';
    if (a == (X509_NAME *)0x0) {
      local_90 = local_98->data;
      iVar13 = 199;
      CRYPTO_free(local_98);
      size = 200;
      goto LAB_000c0a5a;
    }
    local_8c = 200;
  }
  else {
    if (a == (X509_NAME *)0x0) {
      iVar13 = size + -1;
      local_90 = buf;
LAB_000c0a5a:
      strncpy(local_90,DAT_000c0a94,size);
      local_90[iVar13] = '\0';
      return local_90;
    }
    local_98 = (BUF_MEM *)0x0;
    local_8c = size;
  }
  iVar13 = DAT_000c0a8c;
  iVar14 = 0;
  iVar2 = sk_num(&a->entries->stack);
  iVar17 = 0;
  if (0 < iVar2) {
    do {
      ppAVar3 = (ASN1_OBJECT **)sk_value(&a->entries->stack,iVar14);
      iVar2 = OBJ_obj2nid(*ppAVar3);
      if ((iVar2 == 0) || (pcVar4 = OBJ_nid2sn(iVar2), pcVar4 == (char *)0x0)) {
        pcVar4 = acStack_78;
        i2t_ASN1_OBJECT(pcVar4,0x50,*ppAVar3);
      }
      __n = strlen(pcVar4);
      pAVar9 = ppAVar3[1];
      pcVar12 = pAVar9->sn;
      iVar2 = pAVar9->nid;
      if ((pAVar9->ln == (char **)0x1b) && (((uint)pcVar12 & 3) == 0)) {
        pcVar8 = (char *)0x0;
        local_88[0] = 0;
        local_88[1] = 0;
        local_88[2] = 0;
        if ((int)pcVar12 < 1) {
LAB_000c0a32:
          uVar10 = 0;
          local_88[3] = 1;
          local_88[2] = 0;
          local_88[1] = 0;
          local_88[0] = 0;
          goto LAB_000c088c;
        }
        do {
          pcVar15 = pcVar8 + iVar2;
          uVar10 = (uint)pcVar8 & 3;
          pcVar8 = pcVar8 + 1;
          if (*pcVar15 != '\0') {
            local_88[uVar10] = 1;
          }
        } while (pcVar8 != pcVar12);
        if ((local_88[2] | local_88[0] | local_88[1]) == 0) goto LAB_000c0a32;
        local_88[3] = 1;
        uVar10 = 1;
        local_88[2] = 1;
        local_88[1] = 1;
        local_88[0] = 1;
LAB_000c0892:
        pcVar8 = (char *)0x0;
        iVar16 = 0;
        uVar5 = uVar10;
        while( true ) {
          if (uVar5 != 0) {
            if ((byte)pcVar8[iVar2] - 0x20 < 0x5f) {
              iVar16 = iVar16 + 1;
            }
            else {
              iVar16 = iVar16 + 4;
            }
          }
          pcVar8 = pcVar8 + 1;
          if (pcVar8 == pcVar12) break;
          uVar5 = local_88[(uint)pcVar8 & 3];
        }
      }
      else {
        uVar10 = 1;
        local_88[3] = 1;
        local_88[2] = 1;
        local_88[1] = 1;
        local_88[0] = 1;
LAB_000c088c:
        if (0 < (int)pcVar12) goto LAB_000c0892;
        iVar16 = 0;
      }
      local_88[3] = 1;
      iVar2 = iVar16 + __n + 2 + iVar17;
      if (local_98 == (BUF_MEM *)0x0) {
        pcVar8 = buf;
        if (local_8c <= iVar2) goto LAB_000c09bc;
      }
      else {
        iVar16 = BUF_MEM_grow(local_98,iVar2 + 1);
        if (iVar16 == 0) goto LAB_000c08c2;
        pcVar8 = local_98->data;
      }
      pcVar15 = pcVar8 + iVar17 + 1;
      pcVar8[iVar17] = '/';
      memcpy(pcVar15,pcVar4,__n);
      pcVar15[__n] = '=';
      pbVar6 = (byte *)(pcVar15 + __n + 1);
      iVar17 = ppAVar3[1]->nid;
      if (0 < (int)pcVar12) {
        pcVar4 = (char *)0x0;
        pbVar7 = pbVar6;
        while( true ) {
          pbVar6 = pbVar7;
          if (uVar10 != 0) {
            bVar1 = pcVar4[iVar17];
            uVar11 = (uint)bVar1;
            uVar5 = uVar11 - 0x20;
            uVar10 = uVar5;
            if (0x5e < uVar5) {
              bVar1 = *(byte *)(iVar13 + (uVar11 & 0xf));
              uVar10 = (uint)*(byte *)(iVar13 + ((int)uVar11 >> 4));
              *pbVar7 = 0x5c;
            }
            if (0x5e < uVar5) {
              pbVar7[3] = bVar1;
            }
            if (uVar5 < 0x5f) {
              pbVar6 = pbVar7 + 1;
              *pbVar7 = bVar1;
            }
            else {
              pbVar7[2] = (byte)uVar10;
              pbVar7[1] = 0x78;
              pbVar6 = pbVar7 + 4;
            }
          }
          pcVar4 = pcVar4 + 1;
          if (pcVar4 == pcVar12) break;
          uVar10 = local_88[(uint)pcVar4 & 3];
          pbVar7 = pbVar6;
        }
      }
      *pbVar6 = 0;
      iVar14 = iVar14 + 1;
      iVar16 = sk_num(&a->entries->stack);
      iVar17 = iVar2;
    } while (iVar14 < iVar16);
  }
  if (local_98 != (BUF_MEM *)0x0) {
    buf = local_98->data;
    CRYPTO_free(local_98);
  }
LAB_000c09bc:
  if (iVar14 == 0) {
    *buf = '\0';
  }
  return buf;
}

