
ASN1_STRING *
asn1_parse2(BIO *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_STRING *a;
  byte *pbVar9;
  byte *pbVar10;
  ASN1_STRING *a_00;
  ASN1_STRING *pAVar11;
  int iVar12;
  byte *pbVar13;
  ASN1_STRING *a_01;
  byte *pbVar14;
  int local_f0;
  uint local_ec;
  char *local_c8;
  byte *local_c0;
  byte *local_bc;
  int local_b8;
  int local_b4;
  uint local_b0;
  ASN1_OBJECT *local_ac;
  char acStack_a8 [132];
  
  a_00 = (ASN1_STRING *)0x0;
  local_ac = (ASN1_OBJECT *)0x0;
  if (0x80 < param_5) {
    BIO_puts(param_1,"BAD RECURSION DEPTH\n");
    return (ASN1_STRING *)0x0;
  }
  local_c0 = (byte *)*param_2;
  pbVar10 = local_c0 + param_3;
  if (0 < param_3) {
    local_c8 = "cons: ";
LAB_0018e444:
    pbVar9 = local_c0;
    uVar4 = ASN1_get_object(&local_c0,&local_b8,&local_b4,(int *)&local_b0,param_3);
    pbVar14 = local_c0;
    if ((uVar4 & 0x80) != 0) {
      a_00 = (ASN1_STRING *)0x0;
      a = (ASN1_STRING *)0x0;
      a_01 = (ASN1_STRING *)0x0;
      pAVar11 = (ASN1_STRING *)0x0;
      BIO_write(param_1,"Error in encoding\n",0x12);
      goto LAB_0018e4d8;
    }
    iVar12 = (int)local_c0 - (int)pbVar9;
    param_3 = param_3 - iVar12;
    iVar5 = BIO_printf(param_1,"%5ld:",pbVar9 + (param_4 - *param_2));
    if (iVar5 < 1) {
LAB_0018e7d8:
      a_00 = (ASN1_STRING *)0x0;
      pAVar11 = (ASN1_STRING *)0x0;
      a = (ASN1_STRING *)0x0;
      a_01 = (ASN1_STRING *)0x0;
      goto LAB_0018e4d8;
    }
    local_f0 = 0;
    if (uVar4 == 0x21) {
      iVar5 = BIO_printf(param_1,"d=%-2d hl=%ld l=inf  ",param_5,iVar12);
      if (iVar5 < 1) goto LAB_0018e7d8;
      if (param_6 == 0) {
        local_ec = 0x20;
        pcVar7 = "cons: ";
      }
      else {
        local_f0 = param_5;
        local_ec = 0x20;
        pcVar7 = local_c8;
      }
    }
    else {
      iVar5 = BIO_printf(param_1,"d=%-2d hl=%ld l=%4ld ",param_5,iVar12,local_b8);
      if (iVar5 < 1) goto LAB_0018e7d8;
      if (param_6 != 0) {
        local_f0 = param_5;
      }
      local_ec = uVar4 & 0x20;
      if (local_ec == 0) {
        pcVar7 = "prim: ";
      }
      else {
        pcVar7 = "cons: ";
      }
    }
    uVar3 = local_b0;
    iVar5 = local_b4;
    iVar6 = BIO_write(param_1,pcVar7,6);
    if (iVar6 < 6) goto LAB_0018e4ce;
    BIO_indent(param_1,local_f0,0x80);
    if ((uVar3 & 0xc0) == 0xc0) {
      pcVar7 = acStack_a8;
      BIO_snprintf(pcVar7,0x80,"priv [ %d ] ",iVar5);
    }
    else if ((int)(uVar3 << 0x18) < 0) {
      pcVar7 = acStack_a8;
      BIO_snprintf(pcVar7,0x80,"cont [ %d ]",iVar5);
    }
    else if ((uVar3 & 0x40) == 0) {
      if (iVar5 < 0x1f) {
        pcVar7 = ASN1_tag2str(iVar5);
      }
      else {
        pcVar7 = acStack_a8;
        BIO_snprintf(pcVar7,0x80,"<ASN1 %d>");
      }
    }
    else {
      pcVar7 = acStack_a8;
      BIO_snprintf(pcVar7,0x80,"appl [ %d ]");
    }
    iVar6 = BIO_printf(param_1,"%-18s",pcVar7);
    iVar5 = local_b8;
    pbVar13 = local_c0;
    if (iVar6 < 1) goto LAB_0018e4ce;
    if (local_ec != 0) {
      iVar12 = BIO_write(param_1,"\n",1);
      if (iVar12 < 1) goto LAB_0018e4ce;
      if (local_b8 <= param_3) {
        if (local_b8 == 0 && uVar4 == 0x21) {
          do {
            iVar5 = asn1_parse2(param_1,&local_c0,(int)pbVar10 - (int)local_c0,
                                local_c0 + (param_4 - *param_2),param_5 + 1,param_6,param_7);
            if (iVar5 == 0) goto LAB_0018e4ce;
          } while ((iVar5 != 2) && (local_c0 < pbVar10));
          local_b8 = (int)local_c0 - (int)pbVar13;
        }
        else {
          pbVar13 = pbVar13 + iVar5;
          if (local_c0 < pbVar13) {
            iVar5 = local_b8;
            do {
              pbVar14 = local_c0;
              iVar12 = asn1_parse2(param_1,&local_c0,iVar5,local_c0 + (param_4 - *param_2),
                                   param_5 + 1,param_6,param_7);
              if (iVar12 == 0) goto LAB_0018e4ce;
              iVar5 = iVar5 - ((int)local_c0 - (int)pbVar14);
            } while (local_c0 < pbVar13);
          }
        }
        goto LAB_0018e67e;
      }
      a_00 = (ASN1_STRING *)0x0;
      a = (ASN1_STRING *)0x0;
      a_01 = (ASN1_STRING *)0x0;
      pAVar11 = (ASN1_STRING *)0x0;
      BIO_printf(param_1,"length is greater than %ld\n",param_3);
      goto LAB_0018e4d8;
    }
    if (local_b0 != 0) {
      local_c0 = local_c0 + local_b8;
      iVar5 = BIO_write(param_1,"\n",1);
      if (0 < iVar5) goto LAB_0018e67e;
      goto LAB_0018e4ce;
    }
    if ((local_b4 - 0x12U & 0xfffffffb) < 3 || (local_b4 == 0x1a || local_b4 == 0xc)) {
      iVar5 = BIO_write(param_1,":",1);
      if ((0 < iVar5) &&
         ((local_b8 < 1 || (iVar5 = BIO_write(param_1,local_c0,local_b8), iVar5 == local_b8))))
      goto LAB_0018e656;
      goto LAB_0018e4ce;
    }
    if (local_b4 == 6) {
      local_bc = pbVar9;
      pAVar8 = d2i_ASN1_OBJECT(&local_ac,&local_bc,local_b8 + iVar12);
      if (pAVar8 == (ASN1_OBJECT *)0x0) {
        iVar5 = BIO_puts(param_1,":BAD OBJECT");
        if (0 < iVar5) goto LAB_0018e8c8;
      }
      else {
        iVar5 = BIO_write(param_1,":",1);
        if (0 < iVar5) {
          i2a_ASN1_OBJECT(param_1,local_ac);
          goto LAB_0018e656;
        }
      }
      goto LAB_0018e4ce;
    }
    if (local_b4 == 1) {
      if (local_b8 == 1) {
        bVar2 = false;
      }
      else {
        iVar5 = BIO_puts(param_1,":BAD BOOLEAN");
        if (iVar5 < 1) {
          a_00 = (ASN1_STRING *)0x0;
          pAVar11 = (ASN1_STRING *)0x0;
          a = (ASN1_STRING *)0x0;
          a_01 = (ASN1_STRING *)0x0;
          goto LAB_0018e4d8;
        }
        bVar2 = true;
        if (local_b8 < 1) goto LAB_0018e8c8;
      }
      BIO_printf(param_1,":%u",(uint)*local_c0);
LAB_0018e8c2:
      if (bVar2) {
LAB_0018e8c8:
        iVar5 = BIO_puts(param_1,":[");
        if (0 < iVar5) {
          if (0 < local_b8) {
            iVar5 = 0;
            pbVar14 = pbVar14 + -1;
            do {
              pbVar14 = pbVar14 + 1;
              iVar5 = iVar5 + 1;
              iVar12 = BIO_printf(param_1,"%02X",(uint)*pbVar14);
              if (iVar12 < 1) goto LAB_0018e4ce;
            } while (iVar5 < local_b8);
          }
          iVar5 = BIO_puts(param_1,"]");
          if (0 < iVar5) goto LAB_0018e656;
        }
        goto LAB_0018e4ce;
      }
      goto LAB_0018e656;
    }
    if (local_b4 == 0x1e) goto LAB_0018e656;
    if (local_b4 != 4) {
      if (local_b4 != 2) {
        if (local_b4 != 10) {
          iVar5 = param_7;
          if (param_7 != 0) {
            iVar5 = local_b8;
          }
          if ((param_7 == 0 || local_b8 == 0) || iVar5 < 0) goto LAB_0018e656;
          iVar5 = BIO_write(param_1,"\n",1);
          if (iVar5 < 1) goto LAB_0018e4ce;
          if ((param_7 == -1) || (iVar5 = param_7, local_b8 < param_7)) {
            iVar5 = local_b8;
          }
          iVar5 = BIO_dump_indent(param_1,(char *)local_c0,iVar5,6);
          goto joined_r0x0018e628;
        }
        local_bc = pbVar9;
        a_00 = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&local_bc,local_b8 + iVar12);
        if (a_00 == (ASN1_ENUMERATED *)0x0) {
          iVar5 = BIO_puts(param_1,":BAD ENUMERATED");
          if (iVar5 < 1) {
            pAVar11 = (ASN1_STRING *)0x0;
            a = (ASN1_STRING *)0x0;
            a_01 = (ASN1_STRING *)0x0;
            goto LAB_0018e4d8;
          }
          bVar2 = true;
        }
        else {
          iVar5 = BIO_write(param_1,":",1);
          if ((iVar5 < 1) ||
             ((a_00->type == 0x10a && (iVar5 = BIO_write(param_1,&DAT_0022aea4,1), iVar5 < 1)))) {
LAB_0018e88c:
            pAVar11 = (ASN1_STRING *)0x0;
            a_01 = (ASN1_STRING *)0x0;
            a = pAVar11;
            goto LAB_0018e4d8;
          }
          iVar5 = a_00->length;
          if (0 < iVar5) {
            iVar12 = 0;
            do {
              pbVar9 = a_00->data + iVar12;
              iVar12 = iVar12 + 1;
              iVar5 = BIO_printf(param_1,"%02X",(uint)*pbVar9);
              if (iVar5 < 1) goto LAB_0018e88c;
              iVar5 = a_00->length;
            } while (iVar12 < iVar5);
          }
          if ((iVar5 == 0) && (iVar5 = BIO_write(param_1,"00",2), iVar5 < 1)) {
            pAVar11 = (ASN1_STRING *)0x0;
            a = (ASN1_STRING *)0x0;
            a_01 = (ASN1_STRING *)0x0;
            goto LAB_0018e4d8;
          }
          bVar2 = false;
        }
        ASN1_ENUMERATED_free(a_00);
        goto LAB_0018e8c2;
      }
      local_bc = pbVar9;
      a = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_bc,local_b8 + iVar12);
      if (a == (ASN1_INTEGER *)0x0) {
        iVar5 = BIO_puts(param_1,":BAD INTEGER");
        if (0 < iVar5) {
          bVar2 = true;
LAB_0018ea7c:
          ASN1_INTEGER_free(a);
          goto LAB_0018e8c2;
        }
      }
      else {
        iVar5 = BIO_write(param_1,":",1);
        if ((0 < iVar5) &&
           ((a->type != 0x102 || (iVar5 = BIO_write(param_1,&DAT_0022aea4,1), 0 < iVar5)))) {
          iVar5 = a->length;
          if (0 < iVar5) {
            iVar12 = 0;
            do {
              pbVar9 = a->data + iVar12;
              iVar12 = iVar12 + 1;
              iVar5 = BIO_printf(param_1,"%02X",(uint)*pbVar9);
              if (iVar5 < 1) goto LAB_0018ea46;
              iVar5 = a->length;
            } while (iVar12 < iVar5);
          }
          if ((iVar5 != 0) || (iVar5 = BIO_write(param_1,"00",2), 0 < iVar5)) {
            bVar2 = false;
            goto LAB_0018ea7c;
          }
        }
      }
LAB_0018ea46:
      a_00 = (ASN1_STRING *)0x0;
      a_01 = (ASN1_STRING *)0x0;
      pAVar11 = (ASN1_STRING *)0x0;
      goto LAB_0018e4d8;
    }
    local_bc = pbVar9;
    a_01 = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_bc,local_b8 + iVar12);
    if ((a_01 != (ASN1_OCTET_STRING *)0x0) && (0 < a_01->length)) {
      local_bc = a_01->data;
      pbVar14 = local_bc;
      do {
        pbVar9 = pbVar14 + 1;
        bVar1 = *pbVar14;
        if (bVar1 == 10 || 0x1f < bVar1) {
          if (0x7e < bVar1) {
LAB_0018e99e:
            if (param_7 == 0) {
              iVar5 = BIO_write(param_1,"[HEX DUMP]:",0xb);
              if (iVar5 < 1) {
                a_00 = (ASN1_STRING *)0x0;
                pAVar11 = (ASN1_STRING *)0x0;
                a = (ASN1_STRING *)0x0;
                goto LAB_0018e4d8;
              }
              if (a_01->length < 1) goto LAB_0018ea70;
              iVar5 = 0;
              goto LAB_0018e9ca;
            }
            iVar5 = BIO_write(param_1,"\n",1);
            if (iVar5 < 1) goto LAB_0018e9dc;
            iVar5 = a_01->length;
            if ((param_7 != -1) && (param_7 <= iVar5)) {
              iVar5 = param_7;
            }
            iVar5 = BIO_dump_indent(param_1,(char *)local_bc,iVar5,6);
            if (iVar5 < 1) goto LAB_0018e9dc;
            ASN1_OCTET_STRING_free(a_01);
            goto LAB_0018e66a;
          }
        }
        else if ((bVar1 & 0xfb) != 9) goto LAB_0018e99e;
        pbVar14 = pbVar9;
      } while (pbVar9 != local_bc + a_01->length);
      iVar5 = BIO_write(param_1,":",1);
      if ((0 < iVar5) && (iVar5 = BIO_write(param_1,local_bc,a_01->length), 0 < iVar5))
      goto LAB_0018ea70;
LAB_0018e9dc:
      a_00 = (ASN1_STRING *)0x0;
      a = (ASN1_STRING *)0x0;
      pAVar11 = (ASN1_STRING *)0x0;
      goto LAB_0018e4d8;
    }
    goto LAB_0018ea70;
  }
  pAVar11 = (ASN1_STRING *)0x1;
  a = (ASN1_STRING *)0x0;
  a_01 = (ASN1_STRING *)0x0;
LAB_0018e4d8:
  ASN1_OBJECT_free(local_ac);
  ASN1_OCTET_STRING_free(a_01);
  ASN1_INTEGER_free(a);
  ASN1_ENUMERATED_free(a_00);
  *param_2 = (int)local_c0;
  return pAVar11;
  while (iVar5 < a_01->length) {
LAB_0018e9ca:
    pbVar14 = local_bc + iVar5;
    iVar5 = iVar5 + 1;
    iVar12 = BIO_printf(param_1,"%02X",(uint)*pbVar14);
    if (iVar12 < 1) goto LAB_0018e9dc;
  }
LAB_0018ea70:
  ASN1_OCTET_STRING_free(a_01);
LAB_0018e656:
  iVar5 = BIO_write(param_1,"\n",1);
joined_r0x0018e628:
  if (iVar5 < 1) {
LAB_0018e4ce:
    a_00 = (ASN1_STRING *)0x0;
    pAVar11 = (ASN1_STRING *)0x0;
    a = (ASN1_STRING *)0x0;
    a_01 = (ASN1_STRING *)0x0;
    goto LAB_0018e4d8;
  }
LAB_0018e66a:
  local_c0 = local_c0 + local_b8;
  if ((local_b4 == 0) && (local_b0 == 0)) {
    pAVar11 = (ASN1_STRING *)0x2;
    a_00 = (ASN1_STRING *)0x0;
    a_01 = (ASN1_STRING *)0x0;
    a = (ASN1_STRING *)0x0;
    goto LAB_0018e4d8;
  }
LAB_0018e67e:
  param_3 = param_3 - local_b8;
  if (param_3 < 1) goto LAB_0018e914;
  goto LAB_0018e444;
LAB_0018e914:
  a_00 = (ASN1_STRING *)0x0;
  pAVar11 = (ASN1_STRING *)0x1;
  a = a_00;
  a_01 = a_00;
  goto LAB_0018e4d8;
}

