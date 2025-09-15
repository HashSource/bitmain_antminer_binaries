
_STACK * d2i_SCT_LIST(undefined4 param_1,uchar **param_2,long param_3)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  ASN1_OCTET_STRING *pAVar4;
  _STACK *st;
  undefined4 *data;
  int iVar5;
  void *__dest;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uchar *puVar9;
  uchar *__src;
  uint uVar10;
  _STACK *p_Var11;
  uint uVar12;
  char *pcVar13;
  ASN1_OCTET_STRING *local_2c [2];
  
  local_2c[0] = (ASN1_OCTET_STRING *)0x0;
  pAVar4 = d2i_ASN1_OCTET_STRING(local_2c,param_2,param_3);
  if (pAVar4 == (ASN1_OCTET_STRING *)0x0) {
    return (_STACK *)0x0;
  }
  if (1 < local_2c[0]->length) {
    puVar9 = local_2c[0]->data;
    uVar10 = (uint)CONCAT11(*puVar9,puVar9[1]);
    if (uVar10 == local_2c[0]->length - 2U) {
      st = sk_new_null();
      p_Var11 = st;
      if ((st != (_STACK *)0x0) && (uVar10 != 0)) {
        if (uVar10 != 1) {
          uVar10 = uVar10 - 2 & 0xffff;
          __src = puVar9 + 4;
          uVar8 = (uint)CONCAT11(puVar9[2],puVar9[3]);
          uVar7 = 1 - uVar8;
          if (1 < uVar8) {
            uVar7 = 0;
          }
          if (uVar10 < uVar8) {
            uVar7 = uVar7 | 1;
          }
          while (uVar7 == 0) {
            data = (undefined4 *)CRYPTO_malloc(0x28,"v3_scts.c",0xd8);
            uVar10 = uVar10 - uVar8 & 0xffff;
            if (data == (undefined4 *)0x0) break;
            iVar5 = sk_push(st,data);
            if (iVar5 == 0) {
              CRYPTO_free(data);
              break;
            }
            __dest = CRYPTO_malloc(uVar8,"v3_scts.c",0xe0);
            *data = __dest;
            if (__dest == (void *)0x0) break;
            memcpy(__dest,__src,uVar8);
            pcVar13 = (char *)*data;
            puVar9 = __src + uVar8;
            *(short *)(data + 1) = (short)uVar8;
            cVar1 = *pcVar13;
            *(char *)((int)data + 6) = cVar1;
            if (cVar1 == '\0') {
              if (uVar8 < 0x2b) break;
              *(undefined2 *)(data + 3) = 0x20;
              data[2] = pcVar13 + 1;
              bVar2 = pcVar13[0x21];
              uVar12 = uVar8 - 0x2b & 0xffff;
              pcVar6 = pcVar13 + 0x2b;
              data[4] = 0;
              data[5] = (uint)bVar2 << 0x18;
              uVar7 = (uint)(byte)pcVar13[0x22] << 0x10 | (uint)bVar2 << 0x18;
              data[4] = 0;
              data[5] = uVar7;
              uVar7 = uVar7 | (uint)(byte)pcVar13[0x23] << 8;
              data[4] = 0;
              data[5] = uVar7;
              uVar7 = uVar7 | (byte)pcVar13[0x24];
              data[4] = 0;
              data[5] = uVar7;
              bVar2 = pcVar13[0x25];
              data[4] = (uint)bVar2 << 0x18;
              data[5] = uVar7;
              uVar8 = (uint)bVar2 << 0x18 | (uint)(byte)pcVar13[0x26] << 0x10;
              data[4] = uVar8;
              data[5] = uVar7;
              uVar8 = uVar8 | (uint)(byte)pcVar13[0x27] << 8;
              data[4] = uVar8;
              data[5] = uVar7;
              data[4] = (byte)pcVar13[0x28] | uVar8;
              data[5] = uVar7;
              cVar1 = pcVar13[0x29];
              cVar3 = pcVar13[0x2a];
              uVar8 = (uint)CONCAT11(cVar1,cVar3);
              if (uVar12 < uVar8) break;
              data[6] = pcVar6;
              uVar7 = uVar12 - uVar8 & 0xffff;
              *(ushort *)(data + 7) = CONCAT11(cVar1,cVar3);
              if (uVar7 < 4) break;
              uVar7 = uVar7 - 4;
              *(char *)((int)data + 0x1e) = pcVar6[uVar8];
              *(char *)((int)data + 0x1f) = pcVar6[uVar8 + 1];
              if ((uVar7 & 0xffff) != (uint)CONCAT11(pcVar6[uVar8 + 2],pcVar6[uVar8 + 3])) break;
              data[8] = pcVar6 + uVar8 + 4;
              *(short *)(data + 9) = (short)uVar7;
            }
            if (uVar10 == 0) goto LAB_000ce576;
            if (uVar10 == 1) break;
            uVar10 = uVar10 - 2 & 0xffff;
            __src = puVar9 + 2;
            uVar8 = (uint)CONCAT11(*puVar9,puVar9[1]);
            uVar7 = 1 - uVar8;
            if (1 < uVar8) {
              uVar7 = 0;
            }
            if (uVar10 < uVar8) {
              uVar7 = uVar7 | 1;
            }
          }
        }
        p_Var11 = (_STACK *)0x0;
        sk_pop_free(st,(func *)0xce51d);
      }
      goto LAB_000ce576;
    }
  }
  p_Var11 = (_STACK *)0x0;
LAB_000ce576:
  ASN1_OCTET_STRING_free(local_2c[0]);
  return p_Var11;
}

