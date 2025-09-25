
char * X509_NAME_oneline(X509_NAME *a,char *buf,int size)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  char *__s;
  size_t __n;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  uint *puVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  char *pcVar16;
  int iVar17;
  BUF_MEM *local_a0;
  int local_90;
  char *local_8c;
  int local_88 [4];
  char acStack_78 [84];
  
  local_8c = buf;
  if (buf == (char *)0x0) {
    local_a0 = BUF_MEM_new();
    if ((local_a0 == (BUF_MEM *)0x0) || (iVar13 = BUF_MEM_grow(local_a0,200), iVar13 == 0)) {
LAB_00163808:
      ERR_put_error(0xb,0x74,0x41,"crypto/x509/x509_obj.c",0xb1);
LAB_001637a6:
      BUF_MEM_free(local_a0);
      return (char *)0x0;
    }
    *local_a0->data = '\0';
    if (a == (X509_NAME *)0x0) {
      iVar13 = 199;
      local_8c = local_a0->data;
      CRYPTO_free(local_a0);
      size = 200;
      goto LAB_001637f0;
    }
    local_90 = 200;
  }
  else {
    if (size == 0) {
      return (char *)0x0;
    }
    iVar13 = size + -1;
    if (a == (X509_NAME *)0x0) {
LAB_001637f0:
      strncpy(local_8c,"NO X509_NAME",size);
      local_8c[iVar13] = '\0';
      return local_8c;
    }
    local_a0 = (BUF_MEM *)0x0;
    local_90 = size;
  }
  iVar17 = 0;
  iVar2 = OPENSSL_sk_num(a->entries);
  iVar13 = 0;
  if (0 < iVar2) {
    do {
      puVar3 = (undefined4 *)OPENSSL_sk_value(a->entries,iVar17);
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)*puVar3);
      if ((iVar2 == 0) || (__s = OBJ_nid2sn(iVar2), __s == (char *)0x0)) {
        i2t_ASN1_OBJECT(acStack_78,0x50,(ASN1_OBJECT *)*puVar3);
        __s = acStack_78;
      }
      __n = strlen(__s);
      puVar10 = (uint *)puVar3[1];
      uVar14 = *puVar10;
      if (0x100000 < (int)uVar14) {
        iVar13 = 0x4a;
LAB_0016379a:
        ERR_put_error(0xb,0x74,0x86,"crypto/x509/x509_obj.c",iVar13);
        goto LAB_001637a6;
      }
      pcVar15 = (char *)puVar10[2];
      if ((puVar10[1] == 0x1b) && ((uVar14 & 3) == 0)) {
        if (0 < (int)uVar14) {
          local_88[0] = 0;
          local_88[1] = 0;
          local_88[2] = 0;
          pcVar16 = pcVar15;
          do {
            pcVar9 = pcVar16 + 1;
            if (*pcVar16 != '\0') {
              local_88[(int)pcVar16 - (int)pcVar15 & 3] = 1;
            }
            pcVar16 = pcVar9;
          } while (pcVar9 != pcVar15 + uVar14);
          if ((local_88[1] != 0 || local_88[0] != 0) || local_88[2] != 0) goto LAB_001635fa;
        }
        iVar2 = 0;
        local_88[2] = 0;
        local_88[1] = 0;
        local_88[0] = 0;
        local_88[3] = 1;
      }
      else {
LAB_001635fa:
        iVar2 = 1;
        local_88[3] = 1;
        local_88[2] = 1;
        local_88[1] = 1;
        local_88[0] = 1;
      }
      local_88[3] = 1;
      if ((int)uVar14 < 1) {
        iVar4 = 0;
      }
      else {
        uVar11 = 0;
        iVar4 = 0;
        iVar7 = iVar2;
        while( true ) {
          if (iVar7 != 0) {
            if ((byte)pcVar15[uVar11] - 0x20 < 0x5f) {
              iVar4 = iVar4 + 1;
            }
            else {
              iVar4 = iVar4 + 4;
            }
          }
          uVar11 = uVar11 + 1;
          if (uVar14 == uVar11) break;
          iVar7 = local_88[uVar11 & 3];
        }
      }
      iVar4 = __n + 2 + iVar4 + iVar13;
      if (0x100000 < iVar4) {
        iVar13 = 0x7b;
        goto LAB_0016379a;
      }
      if (local_a0 == (BUF_MEM *)0x0) {
        pcVar15 = buf;
        if (local_90 <= iVar4) goto LAB_0016370e;
      }
      else {
        iVar7 = BUF_MEM_grow(local_a0,iVar4 + 1);
        if (iVar7 == 0) goto LAB_00163808;
        pcVar15 = local_a0->data;
      }
      pcVar16 = pcVar15 + iVar13 + 1;
      pcVar15[iVar13] = '/';
      memcpy(pcVar16,__s,__n);
      pcVar16[__n] = '=';
      pbVar12 = (byte *)(pcVar16 + __n + 1);
      iVar13 = *(int *)(puVar3[1] + 8);
      if (0 < (int)uVar14) {
        uVar11 = 0;
        while( true ) {
          if (iVar2 != 0) {
            bVar1 = *(byte *)(iVar13 + uVar11);
            uVar8 = (uint)bVar1;
            uVar5 = uVar8 - 0x20;
            uVar6 = uVar5;
            if (0x5e < uVar5) {
              bVar1 = "0123456789ABCDEF"[uVar8 & 0xf];
              uVar6 = (uint)(byte)"0123456789ABCDEF"[(int)uVar8 >> 4];
              *pbVar12 = 0x5c;
            }
            if (0x5e < uVar5) {
              pbVar12[3] = bVar1;
            }
            if (uVar5 < 0x5f) {
              *pbVar12 = bVar1;
              pbVar12 = pbVar12 + 1;
            }
            else {
              pbVar12[2] = (byte)uVar6;
              pbVar12[1] = 0x78;
              pbVar12 = pbVar12 + 4;
            }
          }
          uVar11 = uVar11 + 1;
          if (uVar14 == uVar11) break;
          iVar2 = local_88[uVar11 & 3];
        }
      }
      iVar17 = iVar17 + 1;
      *pbVar12 = 0;
      iVar2 = OPENSSL_sk_num(a->entries);
      iVar13 = iVar4;
    } while (iVar17 < iVar2);
  }
  if (local_a0 != (BUF_MEM *)0x0) {
    local_8c = local_a0->data;
    CRYPTO_free(local_a0);
  }
LAB_0016370e:
  if (iVar17 == 0) {
    *local_8c = '\0';
  }
  return local_8c;
}

