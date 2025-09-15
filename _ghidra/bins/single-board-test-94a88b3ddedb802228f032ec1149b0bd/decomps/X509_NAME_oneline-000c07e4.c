
char * X509_NAME_oneline(X509_NAME *a,char *buf,int size)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  char *buf_00;
  size_t __n;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  char *__dest;
  int iVar15;
  int iVar16;
  BUF_MEM *local_98;
  char *local_90;
  int local_8c;
  int local_88 [4];
  char acStack_78 [84];
  
  if (buf == (char *)0x0) {
    local_98 = BUF_MEM_new();
    if (local_98 == (BUF_MEM *)0x0) {
      ERR_put_error(0xb,0x74,0x41,"x509_obj.c",0xd0);
      return (char *)0x0;
    }
    iVar16 = BUF_MEM_grow(local_98,200);
    if (iVar16 == 0) {
LAB_000c08c2:
      ERR_put_error(0xb,0x74,0x41,"x509_obj.c",0xd0);
      BUF_MEM_free(local_98);
      return (char *)0x0;
    }
    *local_98->data = '\0';
    if (a == (X509_NAME *)0x0) {
      local_90 = local_98->data;
      iVar16 = 199;
      CRYPTO_free(local_98);
      size = 200;
      goto LAB_000c0a5a;
    }
    local_8c = 200;
  }
  else {
    if (a == (X509_NAME *)0x0) {
      iVar16 = size + -1;
      local_90 = buf;
LAB_000c0a5a:
      strncpy(local_90,"NO X509_NAME",size);
      local_90[iVar16] = '\0';
      return local_90;
    }
    local_98 = (BUF_MEM *)0x0;
    local_8c = size;
  }
  iVar14 = 0;
  iVar3 = sk_num(&a->entries->stack);
  iVar16 = 0;
  if (0 < iVar3) {
    do {
      puVar4 = (undefined4 *)sk_value(&a->entries->stack,iVar14);
      iVar3 = OBJ_obj2nid((ASN1_OBJECT *)*puVar4);
      if ((iVar3 == 0) || (buf_00 = OBJ_nid2sn(iVar3), buf_00 == (char *)0x0)) {
        buf_00 = acStack_78;
        i2t_ASN1_OBJECT(buf_00,0x50,(ASN1_OBJECT *)*puVar4);
      }
      __n = strlen(buf_00);
      puVar11 = (uint *)puVar4[1];
      uVar13 = *puVar11;
      uVar5 = puVar11[2];
      if ((puVar11[1] == 0x1b) && ((uVar13 & 3) == 0)) {
        uVar10 = 0;
        local_88[0] = 0;
        local_88[1] = 0;
        local_88[2] = 0;
        if ((int)uVar13 < 1) {
LAB_000c0a32:
          iVar3 = 0;
          local_88[3] = 1;
          local_88[2] = 0;
          local_88[1] = 0;
          local_88[0] = 0;
          goto LAB_000c088c;
        }
        do {
          pcVar1 = (char *)(uVar5 + uVar10);
          uVar6 = uVar10 & 3;
          uVar10 = uVar10 + 1;
          if (*pcVar1 != '\0') {
            local_88[uVar6] = 1;
          }
        } while (uVar10 != uVar13);
        if (local_88[2] == 0 && (local_88[0] == 0 && local_88[1] == 0)) goto LAB_000c0a32;
        local_88[3] = 1;
        iVar3 = 1;
        local_88[2] = 1;
        local_88[1] = 1;
        local_88[0] = 1;
LAB_000c0892:
        uVar10 = 0;
        iVar15 = 0;
        iVar7 = iVar3;
        while( true ) {
          if (iVar7 != 0) {
            if (*(byte *)(uVar5 + uVar10) - 0x20 < 0x5f) {
              iVar15 = iVar15 + 1;
            }
            else {
              iVar15 = iVar15 + 4;
            }
          }
          uVar10 = uVar10 + 1;
          if (uVar10 == uVar13) break;
          iVar7 = local_88[uVar10 & 3];
        }
      }
      else {
        iVar3 = 1;
        local_88[3] = 1;
        local_88[2] = 1;
        local_88[1] = 1;
        local_88[0] = 1;
LAB_000c088c:
        if (0 < (int)uVar13) goto LAB_000c0892;
        iVar15 = 0;
      }
      local_88[3] = 1;
      iVar15 = iVar15 + __n + 2 + iVar16;
      if (local_98 == (BUF_MEM *)0x0) {
        pcVar1 = buf;
        if (local_8c <= iVar15) goto LAB_000c09bc;
      }
      else {
        iVar7 = BUF_MEM_grow(local_98,iVar15 + 1);
        if (iVar7 == 0) goto LAB_000c08c2;
        pcVar1 = local_98->data;
      }
      __dest = pcVar1 + iVar16 + 1;
      pcVar1[iVar16] = '/';
      memcpy(__dest,buf_00,__n);
      __dest[__n] = '=';
      pbVar8 = (byte *)(__dest + __n + 1);
      iVar16 = *(int *)(puVar4[1] + 8);
      if (0 < (int)uVar13) {
        uVar5 = 0;
        pbVar9 = pbVar8;
        while( true ) {
          pbVar8 = pbVar9;
          if (iVar3 != 0) {
            bVar2 = *(byte *)(iVar16 + uVar5);
            uVar12 = (uint)bVar2;
            uVar6 = uVar12 - 0x20;
            uVar10 = uVar6;
            if (0x5e < uVar6) {
              bVar2 = "0123456789ABCDEF"[uVar12 & 0xf];
              uVar10 = (uint)(byte)"0123456789ABCDEF"[(int)uVar12 >> 4];
              *pbVar9 = 0x5c;
            }
            if (0x5e < uVar6) {
              pbVar9[3] = bVar2;
            }
            if (uVar6 < 0x5f) {
              pbVar8 = pbVar9 + 1;
              *pbVar9 = bVar2;
            }
            else {
              pbVar9[2] = (byte)uVar10;
              pbVar9[1] = 0x78;
              pbVar8 = pbVar9 + 4;
            }
          }
          uVar5 = uVar5 + 1;
          if (uVar5 == uVar13) break;
          iVar3 = local_88[uVar5 & 3];
          pbVar9 = pbVar8;
        }
      }
      *pbVar8 = 0;
      iVar14 = iVar14 + 1;
      iVar3 = sk_num(&a->entries->stack);
      iVar16 = iVar15;
    } while (iVar14 < iVar3);
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

