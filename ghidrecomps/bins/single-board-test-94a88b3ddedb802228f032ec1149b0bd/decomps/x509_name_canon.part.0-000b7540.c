
ASN1_OBJECT ** x509_name_canon_part_0(_STACK **param_1)

{
  byte bVar1;
  int *piVar2;
  char *file;
  _STACK *p_Var3;
  _STACK *st;
  int iVar4;
  ASN1_OBJECT **ppAVar5;
  ASN1_OBJECT **val;
  ASN1_OBJECT *pAVar6;
  ulong uVar7;
  _STACK *p_Var8;
  _STACK *num;
  byte *pbVar9;
  ushort **ppuVar10;
  __int32_t **pp_Var11;
  uint uVar12;
  byte *pbVar13;
  ASN1_OBJECT *in;
  byte *pbVar14;
  int iVar15;
  byte *pbVar16;
  _STACK *local_40;
  ASN1_OBJECT *local_38;
  _STACK *local_30;
  ASN1_VALUE *local_2c [2];
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    val = (ASN1_OBJECT **)0x0;
  }
  else {
    iVar15 = 0;
    local_38 = (ASN1_OBJECT *)0xffffffff;
    local_40 = (_STACK *)0x0;
    iVar4 = sk_num(*param_1);
    if (0 < iVar4) {
      do {
        ppAVar5 = (ASN1_OBJECT **)sk_value(*param_1,iVar15);
        if (ppAVar5[2] != local_38) {
          local_40 = sk_new_null();
          if ((local_40 == (_STACK *)0x0) || (iVar4 = sk_push(st,local_40), iVar4 == 0))
          goto LAB_000b75ce;
          local_38 = ppAVar5[2];
        }
        val = (ASN1_OBJECT **)ASN1_item_new(DAT_000b77b0);
        if (val == (ASN1_OBJECT **)0x0) goto LAB_000b75d0;
        pAVar6 = OBJ_dup(*ppAVar5);
        in = ppAVar5[1];
        *val = pAVar6;
        pAVar6 = val[1];
        uVar7 = ASN1_tag2bit((int)in->ln);
        if ((uVar7 & 0x2956) != 0) {
          pAVar6->ln = (char **)0xc;
          pbVar9 = (byte *)ASN1_STRING_to_UTF8((uchar **)&pAVar6->nid,(ASN1_STRING *)in);
          pAVar6->sn = (char *)pbVar9;
          if (pbVar9 != (byte *)0xffffffff) {
            pbVar14 = (byte *)pAVar6->nid;
            if ((int)pbVar9 < 1) {
              pbVar9 = (byte *)0x0;
            }
            else {
              bVar1 = *pbVar14;
              pbVar13 = pbVar14;
              if ((bVar1 & 0x80) == 0) {
                ppuVar10 = __ctype_b_loc();
                do {
                  if (-1 < (int)((uint)(*ppuVar10)[bVar1] << 0x12)) {
                    pbVar16 = pbVar13 + (int)(pbVar9 + -1);
                    goto LAB_000b76fe;
                  }
                  pbVar9 = pbVar9 + -1;
                  pbVar16 = pbVar13 + 1;
                  if (pbVar9 == (byte *)0x0) goto LAB_000b75fc;
                  bVar1 = pbVar13[1];
                  pbVar13 = pbVar16;
                } while ((bVar1 & 0x80) == 0);
              }
              pbVar16 = pbVar13 + (int)(pbVar9 + -1);
LAB_000b76fe:
              uVar12 = (uint)*pbVar16;
              if (-1 < (int)(uVar12 << 0x18)) {
                ppuVar10 = __ctype_b_loc();
                do {
                  if (-1 < (int)((uint)(*ppuVar10)[uVar12] << 0x12)) break;
                  pbVar9 = pbVar9 + -1;
                  if (pbVar9 == (byte *)0x0) goto LAB_000b75fc;
                  pbVar16 = pbVar16 + -1;
                  uVar12 = (uint)*pbVar16;
                } while (-1 < (int)(uVar12 << 0x18));
              }
              iVar4 = 0;
              pbVar14 = pbVar14 + 1;
              do {
                while (pbVar16 = pbVar14, bVar1 = *pbVar13, (bVar1 & 0x80) == 0) {
                  ppuVar10 = __ctype_b_loc();
                  if ((int)((uint)(*ppuVar10)[(short)(ushort)bVar1] << 0x12) < 0) {
                    pbVar16[-1] = 0x20;
                    do {
                      pbVar13 = pbVar13 + 1;
                      iVar4 = iVar4 + 1;
                      if ((int)((uint)*pbVar13 << 0x18) < 0) goto LAB_000b75ec;
                    } while ((int)((uint)(*ppuVar10)[*pbVar13] << 0x12) < 0);
                  }
                  else {
                    pp_Var11 = __ctype_tolower_loc();
                    iVar4 = iVar4 + 1;
                    pbVar13 = pbVar13 + 1;
                    pbVar16[-1] = (byte)(*pp_Var11)[(short)(ushort)bVar1];
                  }
                  pbVar14 = pbVar16 + 1;
                  if ((int)pbVar9 <= iVar4) goto LAB_000b75f6;
                }
                pbVar13 = pbVar13 + 1;
                iVar4 = iVar4 + 1;
                pbVar16[-1] = bVar1;
LAB_000b75ec:
                pbVar14 = pbVar16 + 1;
              } while (iVar4 < (int)pbVar9);
LAB_000b75f6:
              pbVar9 = pbVar16 + -pAVar6->nid;
            }
LAB_000b75fc:
            pAVar6->sn = (char *)pbVar9;
            goto LAB_000b75fe;
          }
LAB_000b75c6:
          ASN1_item_free((ASN1_VALUE *)val,DAT_000b77b0);
          goto LAB_000b75ce;
        }
        iVar4 = ASN1_STRING_copy((ASN1_STRING *)pAVar6,(ASN1_STRING *)in);
        if (iVar4 == 0) goto LAB_000b75c6;
LAB_000b75fe:
        iVar4 = sk_push(local_40,val);
        if (iVar4 == 0) goto LAB_000b75c6;
        iVar15 = iVar15 + 1;
        iVar4 = sk_num(*param_1);
      } while (iVar15 < iVar4);
    }
    iVar4 = 0;
    p_Var3 = (_STACK *)0x0;
    do {
      num = p_Var3;
      iVar15 = sk_num(st);
      if (iVar15 <= iVar4) break;
      local_2c[0] = (ASN1_VALUE *)sk_value(st,iVar4);
      p_Var8 = (_STACK *)ASN1_item_ex_i2d(local_2c,(uchar **)0x0,DAT_000b77b8,-1,-1);
      piVar2 = &num->num;
      num = p_Var8;
      iVar4 = iVar4 + 1;
      p_Var3 = (_STACK *)((int)&p_Var8->num + (int)piVar2);
    } while (-1 < (int)p_Var8);
    file = DAT_000b77bc;
    param_1[4] = num;
    local_30 = (_STACK *)CRYPTO_malloc((int)num,file,0x17f);
    if (local_30 == (_STACK *)0x0) {
LAB_000b75ce:
      val = (ASN1_OBJECT **)0x0;
    }
    else {
      param_1[3] = local_30;
      iVar4 = 0;
      do {
        iVar15 = sk_num(st);
        if (iVar15 <= iVar4) break;
        local_2c[0] = (ASN1_VALUE *)sk_value(st,iVar4);
        iVar15 = ASN1_item_ex_i2d(local_2c,(uchar **)&local_30,DAT_000b77b8,-1,-1);
        iVar4 = iVar4 + 1;
      } while (-1 < iVar15);
      val = (ASN1_OBJECT **)0x1;
    }
LAB_000b75d0:
    sk_pop_free(st,DAT_000b77b4);
  }
  return val;
}

