
_STACK * d2i_SCT_LIST(undefined4 param_1,uchar **param_2,long param_3)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  ASN1_OCTET_STRING *pAVar4;
  _STACK *st;
  char **data;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  uchar *puVar11;
  uchar *__src;
  char *pcVar12;
  uint uVar13;
  _STACK *p_Var14;
  ASN1_OCTET_STRING *local_2c [2];
  
  local_2c[0] = (ASN1_OCTET_STRING *)0x0;
  pAVar4 = d2i_ASN1_OCTET_STRING(local_2c,param_2,param_3);
  if (pAVar4 == (ASN1_OCTET_STRING *)0x0) {
    return (_STACK *)0x0;
  }
  if (1 < local_2c[0]->length) {
    puVar11 = local_2c[0]->data;
    uVar13 = (uint)CONCAT11(*puVar11,puVar11[1]);
    if (uVar13 == local_2c[0]->length - 2U) {
      st = sk_new_null();
      p_Var14 = st;
      if ((st != (_STACK *)0x0) && (uVar13 != 0)) {
        if (uVar13 != 1) {
          uVar13 = uVar13 - 2 & 0xffff;
          __src = puVar11 + 4;
          uVar9 = (uint)CONCAT11(puVar11[2],puVar11[3]);
          uVar8 = 1 - uVar9;
          if (1 < uVar9) {
            uVar8 = 0;
          }
          if (uVar13 < uVar9) {
            uVar8 = uVar8 | 1;
          }
          while (uVar8 == 0) {
            data = (char **)CRYPTO_malloc(0x28,DAT_000ce788,0xd8);
            uVar13 = uVar13 - uVar9 & 0xffff;
            if (data == (char **)0x0) break;
            iVar5 = sk_push(st,data);
            if (iVar5 == 0) {
              CRYPTO_free(data);
              break;
            }
            pcVar6 = (char *)CRYPTO_malloc(uVar9,DAT_000ce788,0xe0);
            *data = pcVar6;
            if (pcVar6 == (char *)0x0) break;
            memcpy(pcVar6,__src,uVar9);
            pcVar6 = *data;
            puVar11 = __src + uVar9;
            *(short *)(data + 1) = (short)uVar9;
            cVar1 = *pcVar6;
            *(char *)((int)data + 6) = cVar1;
            if (cVar1 == '\0') {
              if (uVar9 < 0x2b) break;
              *(undefined2 *)(data + 3) = 0x20;
              data[2] = pcVar6 + 1;
              bVar2 = pcVar6[0x21];
              uVar8 = uVar9 - 0x2b & 0xffff;
              pcVar7 = pcVar6 + 0x2b;
              data[4] = (char *)0x0;
              data[5] = (char *)((uint)bVar2 << 0x18);
              pcVar12 = (char *)((uint)(byte)pcVar6[0x22] << 0x10 |
                                (uint)(char *)((uint)bVar2 << 0x18));
              data[4] = (char *)0x0;
              data[5] = pcVar12;
              pcVar12 = (char *)((uint)pcVar12 | (uint)(byte)pcVar6[0x23] << 8);
              data[4] = (char *)0x0;
              data[5] = pcVar12;
              pcVar12 = (char *)((uint)pcVar12 | (uint)(byte)pcVar6[0x24]);
              data[4] = (char *)0x0;
              data[5] = pcVar12;
              bVar2 = pcVar6[0x25];
              data[4] = (char *)((uint)bVar2 << 0x18);
              data[5] = pcVar12;
              pcVar10 = (char *)((uint)(char *)((uint)bVar2 << 0x18) |
                                (uint)(byte)pcVar6[0x26] << 0x10);
              data[4] = pcVar10;
              data[5] = pcVar12;
              pcVar10 = (char *)((uint)pcVar10 | (uint)(byte)pcVar6[0x27] << 8);
              data[4] = pcVar10;
              data[5] = pcVar12;
              data[4] = (char *)((uint)(byte)pcVar6[0x28] | (uint)pcVar10);
              data[5] = pcVar12;
              cVar1 = pcVar6[0x29];
              cVar3 = pcVar6[0x2a];
              uVar9 = (uint)CONCAT11(cVar1,cVar3);
              if (uVar8 < uVar9) break;
              data[6] = pcVar7;
              uVar8 = uVar8 - uVar9 & 0xffff;
              *(ushort *)(data + 7) = CONCAT11(cVar1,cVar3);
              if (uVar8 < 4) break;
              uVar8 = uVar8 - 4;
              *(char *)((int)data + 0x1e) = pcVar7[uVar9];
              *(char *)((int)data + 0x1f) = pcVar7[uVar9 + 1];
              if ((uVar8 & 0xffff) != (uint)CONCAT11(pcVar7[uVar9 + 2],pcVar7[uVar9 + 3])) break;
              data[8] = pcVar7 + uVar9 + 4;
              *(short *)(data + 9) = (short)uVar8;
            }
            if (uVar13 == 0) goto LAB_000ce576;
            if (uVar13 == 1) break;
            uVar13 = uVar13 - 2 & 0xffff;
            __src = puVar11 + 2;
            uVar9 = (uint)CONCAT11(*puVar11,puVar11[1]);
            uVar8 = 1 - uVar9;
            if (1 < uVar9) {
              uVar8 = 0;
            }
            if (uVar13 < uVar9) {
              uVar8 = uVar8 | 1;
            }
          }
        }
        p_Var14 = (_STACK *)0x0;
        sk_pop_free(st,DAT_000ce78c);
      }
      goto LAB_000ce576;
    }
  }
  p_Var14 = (_STACK *)0x0;
LAB_000ce576:
  ASN1_OCTET_STRING_free(local_2c[0]);
  return p_Var14;
}

