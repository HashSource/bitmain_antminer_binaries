
ASN1_VALUE * x509_name_canon_part_0(undefined4 *param_1)

{
  byte bVar1;
  _STACK *st;
  int iVar2;
  undefined4 *puVar3;
  ASN1_VALUE *val;
  ASN1_OBJECT *pAVar4;
  ulong uVar5;
  int iVar6;
  ushort **ppuVar7;
  __int32_t **pp_Var8;
  uint uVar9;
  byte *pbVar10;
  ASN1_STRING *in;
  byte *pbVar11;
  int iVar12;
  ASN1_STRING *dst;
  int iVar13;
  byte *pbVar14;
  _STACK *local_40;
  int local_38;
  uchar *local_30;
  ASN1_VALUE *local_2c [2];
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    val = (ASN1_VALUE *)0x0;
  }
  else {
    iVar13 = 0;
    local_38 = -1;
    local_40 = (_STACK *)0x0;
    iVar2 = sk_num((_STACK *)*param_1);
    if (0 < iVar2) {
      do {
        puVar3 = (undefined4 *)sk_value((_STACK *)*param_1,iVar13);
        if (puVar3[2] != local_38) {
          local_40 = sk_new_null();
          if ((local_40 == (_STACK *)0x0) || (iVar2 = sk_push(st,local_40), iVar2 == 0))
          goto LAB_00159eca;
          local_38 = puVar3[2];
        }
        val = ASN1_item_new((ASN1_ITEM *)&X509_NAME_ENTRY_it);
        if (val == (ASN1_VALUE *)0x0) goto LAB_00159ecc;
        pAVar4 = OBJ_dup((ASN1_OBJECT *)*puVar3);
        in = (ASN1_STRING *)puVar3[1];
        *(ASN1_OBJECT **)val = pAVar4;
        dst = *(ASN1_STRING **)(val + 4);
        uVar5 = ASN1_tag2bit(in->type);
        if ((uVar5 & 0x2956) != 0) {
          dst->type = 0xc;
          iVar2 = ASN1_STRING_to_UTF8(&dst->data,in);
          dst->length = iVar2;
          if (iVar2 != -1) {
            pbVar11 = dst->data;
            if (iVar2 < 1) {
              iVar2 = 0;
            }
            else {
              bVar1 = *pbVar11;
              pbVar10 = pbVar11;
              if ((bVar1 & 0x80) == 0) {
                ppuVar7 = __ctype_b_loc();
                do {
                  if (-1 < (int)((uint)(*ppuVar7)[bVar1] << 0x12)) {
                    pbVar14 = pbVar10 + iVar2 + -1;
                    goto LAB_00159ffa;
                  }
                  iVar2 = iVar2 + -1;
                  pbVar14 = pbVar10 + 1;
                  if (iVar2 == 0) goto LAB_00159ef8;
                  bVar1 = pbVar10[1];
                  pbVar10 = pbVar14;
                } while ((bVar1 & 0x80) == 0);
              }
              pbVar14 = pbVar10 + iVar2 + -1;
LAB_00159ffa:
              uVar9 = (uint)*pbVar14;
              if (-1 < (int)(uVar9 << 0x18)) {
                ppuVar7 = __ctype_b_loc();
                do {
                  if (-1 < (int)((uint)(*ppuVar7)[uVar9] << 0x12)) break;
                  iVar2 = iVar2 + -1;
                  if (iVar2 == 0) goto LAB_00159ef8;
                  pbVar14 = pbVar14 + -1;
                  uVar9 = (uint)*pbVar14;
                } while (-1 < (int)(uVar9 << 0x18));
              }
              iVar12 = 0;
              pbVar11 = pbVar11 + 1;
              do {
                while (pbVar14 = pbVar11, bVar1 = *pbVar10, (bVar1 & 0x80) == 0) {
                  ppuVar7 = __ctype_b_loc();
                  if ((int)((uint)(*ppuVar7)[(short)(ushort)bVar1] << 0x12) < 0) {
                    pbVar14[-1] = 0x20;
                    do {
                      pbVar10 = pbVar10 + 1;
                      iVar12 = iVar12 + 1;
                      if ((int)((uint)*pbVar10 << 0x18) < 0) goto LAB_00159ee8;
                    } while ((int)((uint)(*ppuVar7)[*pbVar10] << 0x12) < 0);
                  }
                  else {
                    pp_Var8 = __ctype_tolower_loc();
                    iVar12 = iVar12 + 1;
                    pbVar10 = pbVar10 + 1;
                    pbVar14[-1] = (byte)(*pp_Var8)[(short)(ushort)bVar1];
                  }
                  pbVar11 = pbVar14 + 1;
                  if (iVar2 <= iVar12) goto LAB_00159ef2;
                }
                pbVar10 = pbVar10 + 1;
                iVar12 = iVar12 + 1;
                pbVar14[-1] = bVar1;
LAB_00159ee8:
                pbVar11 = pbVar14 + 1;
              } while (iVar12 < iVar2);
LAB_00159ef2:
              iVar2 = (int)pbVar14 - (int)dst->data;
            }
LAB_00159ef8:
            dst->length = iVar2;
            goto LAB_00159efa;
          }
LAB_00159ec2:
          ASN1_item_free(val,(ASN1_ITEM *)&X509_NAME_ENTRY_it);
          goto LAB_00159eca;
        }
        iVar2 = ASN1_STRING_copy(dst,in);
        if (iVar2 == 0) goto LAB_00159ec2;
LAB_00159efa:
        iVar2 = sk_push(local_40,val);
        if (iVar2 == 0) goto LAB_00159ec2;
        iVar13 = iVar13 + 1;
        iVar2 = sk_num((_STACK *)*param_1);
      } while (iVar13 < iVar2);
    }
    iVar2 = 0;
    iVar13 = 0;
    do {
      iVar12 = iVar13;
      iVar13 = sk_num(st);
      if (iVar13 <= iVar2) break;
      local_2c[0] = (ASN1_VALUE *)sk_value(st,iVar2);
      iVar6 = ASN1_item_ex_i2d(local_2c,(uchar **)0x0,(ASN1_ITEM *)X509_NAME_ENTRIES_it,-1,-1);
      iVar13 = iVar12 + iVar6;
      iVar12 = iVar6;
      iVar2 = iVar2 + 1;
    } while (-1 < iVar6);
    param_1[4] = iVar12;
    local_30 = (uchar *)CRYPTO_malloc(iVar12,"x_name.c",0x17f);
    if (local_30 == (uchar *)0x0) {
LAB_00159eca:
      val = (ASN1_VALUE *)0x0;
    }
    else {
      param_1[3] = local_30;
      iVar2 = 0;
      do {
        iVar13 = sk_num(st);
        if (iVar13 <= iVar2) break;
        local_2c[0] = (ASN1_VALUE *)sk_value(st,iVar2);
        iVar13 = ASN1_item_ex_i2d(local_2c,&local_30,(ASN1_ITEM *)X509_NAME_ENTRIES_it,-1,-1);
        iVar2 = iVar2 + 1;
      } while (-1 < iVar13);
      val = (ASN1_VALUE *)0x1;
    }
LAB_00159ecc:
    sk_pop_free(st,(func *)0x159d7d);
  }
  return val;
}

