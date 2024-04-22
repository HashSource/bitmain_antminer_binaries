
ASN1_STRING *
asn1_parse2(BIO *param_1,byte **param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ASN1_OBJECT *pAVar6;
  ASN1_OCTET_STRING *a;
  ASN1_INTEGER *a_00;
  byte *pbVar7;
  void *data;
  byte *pbVar8;
  ASN1_STRING *pAVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  byte *local_c0;
  byte *local_bc;
  int local_b8;
  uint local_b4;
  uint local_b0;
  ASN1_OBJECT *local_ac;
  char acStack_a8 [132];
  
  local_c0 = *param_2;
  pbVar7 = local_c0 + param_3;
  local_ac = (ASN1_OBJECT *)0x0;
  if (local_c0 < pbVar7) {
LAB_000bc374:
    pbVar12 = local_c0;
    uVar3 = ASN1_get_object(&local_c0,&local_b8,(int *)&local_b4,(int *)&local_b0,param_3);
    if ((uVar3 & 0x80) != 0) {
      BIO_write(param_1,DAT_000bc928,0x12);
      pAVar9 = (ASN1_STRING *)0x0;
      a = (ASN1_STRING *)0x0;
      goto LAB_000bc3f8;
    }
    iVar10 = (int)local_c0 - (int)pbVar12;
    iVar4 = BIO_printf(param_1,DAT_000bc5fc,pbVar12 + (param_4 - (int)*param_2));
    if (iVar4 < 1) goto LAB_000bc3f2;
    if (uVar3 == 0x21) {
      iVar4 = BIO_printf(param_1,DAT_000bc618,param_5,iVar10);
      if (0 < iVar4) goto LAB_000bc3c4;
      goto LAB_000bc3f2;
    }
    iVar4 = BIO_printf(param_1,DAT_000bc600,param_5,iVar10,local_b8);
    if (iVar4 < 1) goto LAB_000bc3f2;
LAB_000bc3c4:
    uVar2 = local_b0;
    uVar1 = local_b4;
    iVar4 = param_5;
    if (param_6 == 0) {
      iVar4 = 0;
    }
    data = DAT_000bc608;
    if ((uVar3 & 0x20) != 0) {
      data = DAT_000bc604;
    }
    iVar5 = BIO_write(param_1,data,6);
    if (iVar5 < 6) goto LAB_000bc3f2;
    BIO_indent(param_1,iVar4,0x80);
    if ((uVar2 & 0xc0) == 0xc0) {
      BIO_snprintf(acStack_a8,0x80,DAT_000bc924);
    }
    else if ((uVar2 & 0x80) == 0) {
      if ((uVar2 & 0x40) == 0) {
        if (0x1e < (int)uVar1) {
          BIO_snprintf(acStack_a8,0x80,DAT_000bc920);
        }
      }
      else {
        BIO_snprintf(acStack_a8,0x80,DAT_000bc91c);
      }
    }
    else {
      BIO_snprintf(acStack_a8,0x80,DAT_000bc620);
    }
    iVar4 = BIO_printf(param_1,DAT_000bc610);
    if (iVar4 < 1) goto LAB_000bc3f2;
    param_3 = param_3 - iVar10;
    if ((uVar3 & 0x20) != 0) {
      pbVar11 = local_c0 + local_b8;
      iVar4 = BIO_write(param_1,DAT_000bc614,1);
      if (iVar4 < 1) goto LAB_000bc3f2;
      if (local_b8 <= param_3) {
        if ((uVar3 == 0x21) && (local_b8 == 0)) {
          while( true ) {
            pAVar9 = (ASN1_STRING *)
                     asn1_parse2(param_1,&local_c0,(int)pbVar7 - (int)local_c0,
                                 local_c0 + (param_4 - (int)*param_2),param_5 + 1,param_6,param_7);
            a = pAVar9;
            if (pAVar9 == (ASN1_STRING *)0x0) goto LAB_000bc3f8;
            if (pAVar9 == (ASN1_STRING *)0x2) break;
            if (pbVar7 <= local_c0) goto LAB_000bc664;
          }
        }
        else {
          while (local_c0 < pbVar11) {
            pAVar9 = (ASN1_STRING *)
                     asn1_parse2(param_1,&local_c0,local_b8,local_c0 + (param_4 - (int)*param_2),
                                 param_5 + 1,param_6,param_7);
            a = pAVar9;
            if (pAVar9 == (ASN1_STRING *)0x0) goto LAB_000bc3f8;
          }
        }
        goto LAB_000bc53a;
      }
      BIO_printf(param_1,DAT_000bc934,param_3);
      pAVar9 = (ASN1_STRING *)0x0;
      a = (ASN1_STRING *)0x0;
      goto LAB_000bc3f8;
    }
    if (local_b0 != 0) {
      local_c0 = local_c0 + local_b8;
      iVar4 = BIO_write(param_1,DAT_000bc614,1);
      if (0 < iVar4) goto LAB_000bc53a;
      pAVar9 = (ASN1_STRING *)0x0;
      a = (ASN1_STRING *)0x0;
      goto LAB_000bc3f8;
    }
    bVar13 = 0x15 < local_b4;
    if (local_b4 != 0x16) {
      bVar13 = local_b4 != 0x13;
    }
    if (((((!bVar13 || (local_b4 == 0x16 || local_b4 == 0x14)) || (local_b4 == 0x1a)) ||
         (local_b4 == 0x12)) || ((local_b4 == 0xc || (local_b4 == 0x17)))) || (local_b4 == 0x18)) {
      iVar4 = BIO_write(param_1,DAT_000bc61c,1);
      if ((iVar4 < 1) ||
         ((0 < local_b8 && (iVar4 = BIO_write(param_1,local_c0,local_b8), iVar4 != local_b8))))
      goto LAB_000bc3f2;
      goto LAB_000bc514;
    }
    if (local_b4 != 6) {
      if (local_b4 == 1) {
        local_bc = pbVar12;
        iVar4 = d2i_ASN1_BOOLEAN((int *)0x0,&local_bc,iVar10 + local_b8);
        if ((iVar4 < 0) && (iVar10 = BIO_write(param_1,DAT_000bc940,0xc), iVar10 < 1))
        goto LAB_000bc3f2;
        BIO_printf(param_1,DAT_000bc930,iVar4);
        goto LAB_000bc514;
      }
      if (local_b4 == 0x1e) goto LAB_000bc514;
      if (local_b4 == 4) {
        local_bc = pbVar12;
        a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_bc,iVar10 + local_b8);
        if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_000bc514;
        if (0 < a->length) {
          local_bc = a->data;
          pbVar11 = local_bc;
          do {
            pbVar8 = pbVar11 + 1;
            uVar3 = (uint)*pbVar11;
            iVar4 = uVar3 - 10;
            if (iVar4 != 0) {
              iVar4 = 1;
            }
            if (0x1f < uVar3) {
              iVar4 = 0;
            }
            if (iVar4 == 0) {
              if (0x7e < uVar3) {
LAB_000bc77a:
                if (param_7 == 0) {
                  iVar4 = BIO_write(param_1,DAT_000bc938,0xb);
                  if (iVar4 < 1) {
                    pAVar9 = (ASN1_STRING *)0x0;
                    goto LAB_000bc3f8;
                  }
                  if (a->length < 1) goto LAB_000bc8aa;
                  iVar4 = 0;
                  goto LAB_000bc7a6;
                }
                iVar4 = BIO_write(param_1,DAT_000bc948,1);
                if (iVar4 < 1) goto LAB_000bc7b8;
                iVar4 = a->length;
                if ((param_7 != -1) && (param_7 <= iVar4)) {
                  iVar4 = param_7;
                }
                iVar4 = BIO_dump_indent(param_1,local_bc,iVar4,6);
                if (iVar4 < 1) goto LAB_000bc7b8;
                ASN1_STRING_free(a);
                goto LAB_000bc524;
              }
            }
            else if ((uVar3 != 0xd) && (uVar3 != 9)) goto LAB_000bc77a;
            pbVar11 = pbVar8;
          } while (pbVar8 != local_bc + a->length);
          iVar4 = BIO_write(param_1,DAT_000bc92c,1);
          if ((iVar4 < 1) || (iVar4 = BIO_write(param_1,local_bc,a->length), iVar4 < 1))
          goto LAB_000bc7b8;
        }
        goto LAB_000bc8aa;
      }
      if (local_b4 != 2) {
        if (local_b4 == 10) {
          local_bc = pbVar12;
          a_00 = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&local_bc,iVar10 + local_b8);
          if (a_00 != (ASN1_ENUMERATED *)0x0) {
            iVar4 = BIO_write(param_1,DAT_000bc92c,1);
            if ((0 < iVar4) &&
               ((a_00->type != 0x10a || (iVar4 = BIO_write(param_1,DAT_000bc9a8,1), 0 < iVar4)))) {
              iVar4 = a_00->length;
              if (0 < iVar4) {
                iVar10 = 0;
                do {
                  pbVar11 = a_00->data + iVar10;
                  iVar10 = iVar10 + 1;
                  iVar4 = BIO_printf(param_1,DAT_000bc93c,(uint)*pbVar11);
                  if (iVar4 < 1) goto LAB_000bc3f2;
                  iVar4 = a_00->length;
                } while (iVar10 < iVar4);
              }
              goto LAB_000bc820;
            }
            goto LAB_000bc3f2;
          }
          iVar4 = BIO_write(param_1,DAT_000bc9ac,0xe);
          goto joined_r0x000bc982;
        }
        if ((local_b8 < 1) || (param_7 == 0)) goto LAB_000bc514;
        iVar4 = BIO_write(param_1,DAT_000bc614,1);
        if (iVar4 < 1) goto LAB_000bc3f2;
        iVar4 = local_b8;
        if ((param_7 != -1) && (param_7 <= local_b8)) {
          iVar4 = param_7;
        }
        iVar4 = BIO_dump_indent(param_1,local_c0,iVar4,6);
        goto joined_r0x000bc4e8;
      }
      local_bc = pbVar12;
      a_00 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_bc,iVar10 + local_b8);
      if (a_00 != (ASN1_INTEGER *)0x0) {
        iVar4 = BIO_write(param_1,DAT_000bc92c,1);
        if ((0 < iVar4) &&
           ((a_00->type != 0x102 || (iVar4 = BIO_write(param_1,DAT_000bc9a8,1), 0 < iVar4)))) {
          iVar4 = a_00->length;
          if (0 < iVar4) {
            iVar10 = 0;
            do {
              pbVar11 = a_00->data + iVar10;
              iVar10 = iVar10 + 1;
              iVar4 = BIO_printf(param_1,DAT_000bc93c,(uint)*pbVar11);
              if (iVar4 < 1) goto LAB_000bc3f2;
              iVar4 = a_00->length;
            } while (iVar10 < iVar4);
          }
LAB_000bc820:
          if ((iVar4 != 0) || (iVar4 = BIO_write(param_1,DAT_000bc94c,2), 0 < iVar4))
          goto LAB_000bc824;
        }
        goto LAB_000bc3f2;
      }
      iVar4 = BIO_write(param_1,DAT_000bc9a4,0xb);
joined_r0x000bc982:
      if (0 < iVar4) {
LAB_000bc824:
        ASN1_STRING_free(a_00);
        goto LAB_000bc514;
      }
      pAVar9 = (ASN1_STRING *)0x0;
      a = pAVar9;
      goto LAB_000bc3f8;
    }
    local_bc = pbVar12;
    pAVar6 = d2i_ASN1_OBJECT(&local_ac,&local_bc,iVar10 + local_b8);
    if (pAVar6 != (ASN1_OBJECT *)0x0) {
      iVar4 = BIO_write(param_1,DAT_000bc92c,1);
      if (iVar4 < 1) goto LAB_000bc3f2;
      i2a_ASN1_OBJECT(param_1,local_ac);
      goto LAB_000bc514;
    }
    iVar4 = BIO_write(param_1,DAT_000bc944,0xb);
    if (iVar4 < 1) {
      a = (ASN1_OCTET_STRING *)0x0;
LAB_000bc7b8:
      pAVar9 = (ASN1_STRING *)0x0;
      goto LAB_000bc3f8;
    }
    goto LAB_000bc514;
  }
  pAVar9 = (ASN1_STRING *)0x1;
  goto LAB_000bc406;
  while (iVar4 < a->length) {
LAB_000bc7a6:
    pbVar11 = local_bc + iVar4;
    iVar4 = iVar4 + 1;
    iVar10 = BIO_printf(param_1,DAT_000bc93c,(uint)*pbVar11);
    if (iVar10 < 1) goto LAB_000bc7b8;
  }
LAB_000bc8aa:
  ASN1_STRING_free(a);
LAB_000bc514:
  iVar4 = BIO_write(param_1,DAT_000bc614,1);
joined_r0x000bc4e8:
  if (iVar4 < 1) {
LAB_000bc3f2:
    pAVar9 = (ASN1_STRING *)0x0;
    a = (ASN1_STRING *)0x0;
    goto LAB_000bc3f8;
  }
LAB_000bc524:
  local_c0 = local_c0 + local_b8;
  if ((local_b4 == 0) && (local_b0 == 0)) {
    pAVar9 = (ASN1_STRING *)0x2;
    a = (ASN1_STRING *)0x0;
    goto LAB_000bc3f8;
  }
LAB_000bc53a:
  param_3 = param_3 - local_b8;
  if (pbVar7 <= local_c0 || local_c0 <= pbVar12) goto LAB_000bc664;
  goto LAB_000bc374;
LAB_000bc664:
  pAVar9 = (ASN1_STRING *)0x1;
  a = (ASN1_STRING *)0x0;
LAB_000bc3f8:
  if (local_ac != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(local_ac);
  }
  if (a != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(a);
  }
LAB_000bc406:
  *param_2 = local_c0;
  return pAVar9;
}

