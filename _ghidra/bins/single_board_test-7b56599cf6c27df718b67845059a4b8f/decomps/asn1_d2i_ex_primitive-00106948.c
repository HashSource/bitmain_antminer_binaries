
int asn1_d2i_ex_primitive
              (ASN1_TYPE *param_1,undefined4 *param_2,int param_3,char *param_4,uint param_5,
              int param_6,byte param_7,byte *param_8)

{
  uint uVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_INTEGER *pAVar3;
  ASN1_TYPE *pAVar4;
  int iVar5;
  byte *pbVar6;
  ASN1_TYPE *a;
  byte *pbVar7;
  byte *omax;
  code *pcVar8;
  ASN1_STRING *str;
  byte *pbVar9;
  byte *pbVar10;
  ASN1_TYPE *a_00;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  char local_51;
  uint local_50;
  byte *local_4c;
  uint local_48;
  int local_44;
  byte *local_40;
  byte *local_3c;
  BUF_MEM local_38;
  undefined4 local_2c;
  
  local_51 = '\0';
  local_38.length = 0;
  local_38.data = (char *)0x0;
  local_38.max = 0;
  local_2c = 0;
  pbVar9 = (byte *)(uint)param_7;
  if (param_1 == (ASN1_TYPE *)0x0) {
    ERR_put_error(0xd,0x6c,0x7d,"crypto/asn1/tasn_dec.c",0x2a0);
    return 0;
  }
  if (*param_4 == '\x05') {
    local_50 = param_5;
    if (param_5 == 0xfffffffc) {
      param_5 = 0xffffffff;
LAB_00106b48:
      if (pbVar9 != (byte *)0x0) {
        ERR_put_error(0xd,0x6c,0x7e,"crypto/asn1/tasn_dec.c",0x2b3);
        return 0;
      }
      local_4c = (byte *)*param_2;
      iVar5 = asn1_check_tlen_constprop_1(0,&local_50,&local_3c,0,0,&local_4c,param_3,0,param_8);
      if (iVar5 == 0) {
        iVar5 = 0x2ba;
        goto LAB_001069f4;
      }
      if ((char)local_3c != '\0') {
        local_50 = 0xfffffffd;
      }
      goto LAB_00106982;
    }
LAB_00106a66:
    param_6 = 0;
    param_5 = local_50;
  }
  else {
    local_50 = *(uint *)(param_4 + 4);
    if (local_50 == 0xfffffffc) {
      if (-1 < (int)param_5) {
        ERR_put_error(0xd,0x6c,0x7f,"crypto/asn1/tasn_dec.c",0x2ae);
        return 0;
      }
      goto LAB_00106b48;
    }
LAB_00106982:
    if (param_5 == 0xffffffff) goto LAB_00106a66;
  }
  pbVar7 = (byte *)*param_2;
  local_4c = pbVar7;
  local_3c = pbVar7;
  if (param_8 == (byte *)0x0) {
    uVar1 = ASN1_get_object(&local_3c,(long *)&local_40,(int *)&local_48,&local_44,param_3);
    if (-1 < (int)(uVar1 << 0x18)) goto LAB_001069b8;
    ERR_put_error(0xd,0x68,0x66,"crypto/asn1/tasn_dec.c",0x471);
LAB_001069ea:
    iVar5 = 0x2c9;
LAB_001069f4:
    ERR_put_error(0xd,0x6c,0x3a,"crypto/asn1/tasn_dec.c",iVar5);
    return 0;
  }
  if (*param_8 == 0) {
    uVar1 = ASN1_get_object(&local_3c,(long *)&local_40,(int *)&local_48,&local_44,param_3);
    *(int *)(param_8 + 0x10) = local_44;
    *(uint *)(param_8 + 4) = uVar1;
    *(int *)(param_8 + 0x14) = (int)local_3c - (int)pbVar7;
    *(uint *)(param_8 + 0xc) = local_48;
    *(byte **)(param_8 + 8) = local_40;
    *param_8 = 1;
    if (((uVar1 & 0x81) == 0) && (param_3 < (int)(local_40 + ((int)local_3c - (int)pbVar7)))) {
      ERR_put_error(0xd,0x68,0x9b,"crypto/asn1/tasn_dec.c",0x469);
      *param_8 = 0;
      goto LAB_001069ea;
    }
  }
  else {
    local_48 = *(uint *)(param_8 + 0xc);
    local_40 = *(byte **)(param_8 + 8);
    uVar1 = *(uint *)(param_8 + 4);
    local_3c = pbVar7 + *(int *)(param_8 + 0x14);
    local_44 = *(int *)(param_8 + 0x10);
  }
  if ((int)(uVar1 << 0x18) < 0) {
    ERR_put_error(0xd,0x68,0x66,"crypto/asn1/tasn_dec.c",0x471);
    *param_8 = 0;
    goto LAB_001069ea;
  }
LAB_001069b8:
  if (-1 < (int)param_5) {
    if ((param_5 != local_48) || (param_6 != local_44)) {
      if (pbVar9 != (byte *)0x0) {
        return -1;
      }
      if (param_8 != (byte *)0x0) {
        *param_8 = param_7;
      }
      ERR_put_error(0xd,0x68,0xa8,"crypto/asn1/tasn_dec.c",0x47d);
      goto LAB_001069ea;
    }
    if (param_8 != (byte *)0x0) {
      *param_8 = 0;
    }
  }
  pbVar6 = (byte *)(uVar1 << 0x1f);
  pbVar10 = local_3c;
  if (-1 < (int)pbVar6) {
    pbVar9 = local_3c;
    pbVar10 = pbVar6;
  }
  omax = local_40;
  if (-1 >= (int)pbVar6) {
    omax = (byte *)(param_3 - ((int)pbVar10 - (int)pbVar7));
    pbVar9 = pbVar10;
  }
  iVar5 = local_50 - 0x10;
  bVar13 = 0xfffffffc < local_50;
  bVar11 = local_50 == 0xfffffffd;
  if (!bVar11) {
    bVar13 = iVar5 != 0;
  }
  bVar12 = iVar5 != 1;
  if (!bVar13 || (bVar11 || !bVar12)) {
    iVar5 = 1;
  }
  if (bVar13 && (!bVar11 && bVar12)) {
    iVar5 = 0;
  }
  local_4c = pbVar9;
  if (!bVar13 || (bVar11 || !bVar12)) {
    if (local_50 == 0xfffffffd) {
      if (param_8 != (byte *)0x0) {
        *param_8 = 0;
      }
    }
    else if ((uVar1 & 0x20) == 0) {
      ERR_put_error(0xd,0x6c,0x9c,"crypto/asn1/tasn_dec.c",0x2db);
      return 0;
    }
    pbVar7 = (byte *)*param_2;
    if ((uVar1 & 1) == 0) {
      local_4c = pbVar9 + (int)omax;
      omax = pbVar9 + ((int)omax - (int)pbVar7);
      pbVar9 = pbVar7;
      goto LAB_00106af6;
    }
    if (0 < (int)omax) {
      iVar5 = 1;
      do {
        if (((omax == (byte *)0x1) || (*pbVar9 != 0)) || (pbVar9[1] != 0)) {
          local_3c = pbVar9;
          uVar1 = ASN1_get_object(&local_3c,(long *)&local_40,(int *)&local_48,&local_44,(long)omax)
          ;
          if ((int)(uVar1 << 0x18) < 0) {
            ERR_put_error(0xd,0x68,0x66,"crypto/asn1/tasn_dec.c",0x471);
            iVar5 = 0x3c5;
LAB_00106eca:
            ERR_put_error(0xd,0xbe,0x3a,"crypto/asn1/tasn_dec.c",iVar5);
            goto LAB_00106c8c;
          }
          if ((uVar1 & 1) == 0) {
            pbVar10 = local_3c + (int)local_40;
          }
          else {
            if (iVar5 == -1) {
              iVar5 = 0x3ca;
              goto LAB_00106eca;
            }
            iVar5 = iVar5 + 1;
            pbVar10 = local_3c;
          }
          omax = omax + -((int)pbVar10 - (int)pbVar9);
        }
        else {
          iVar5 = iVar5 + -1;
          pbVar10 = pbVar9 + 2;
          if (iVar5 == 0) {
            omax = pbVar10 + -(int)pbVar7;
            pbVar9 = pbVar7;
            local_4c = pbVar10;
            goto LAB_00106af6;
          }
          omax = omax + -2;
        }
        pbVar9 = pbVar10;
      } while (0 < (int)omax);
    }
    ERR_put_error(0xd,0xbe,0x89,"crypto/asn1/tasn_dec.c",0x3d4);
    goto LAB_00106c8c;
  }
  if ((uVar1 & 0x20) == 0) {
    local_4c = pbVar9 + (int)omax;
  }
  else {
    bVar13 = 9 < local_50;
    if (local_50 != 10) {
      bVar13 = (local_50 & 0xfffffffb) != 1;
    }
    if (!bVar13 || (local_50 == 10 || (local_50 & 0xfffffffb) == 2)) {
      ERR_put_error(0xd,0x6c,0xc3,"crypto/asn1/tasn_dec.c",0x2ed);
      return iVar5;
    }
    local_51 = '\x01';
    iVar5 = asn1_collect_constprop_0(&local_38,&local_4c,omax,uVar1 & 1,0);
    omax = (byte *)local_38.length;
    if (iVar5 == 0) goto LAB_00106b22;
    iVar5 = BUF_MEM_grow_clean(&local_38,(size_t)(local_38.length + 1));
    if (iVar5 == 0) {
      ERR_put_error(0xd,0x6c,0x41,"crypto/asn1/tasn_dec.c",0x2ff);
      iVar5 = 0;
      goto LAB_00106b22;
    }
    local_38.data[(int)omax] = 0;
    pbVar9 = (byte *)local_38.data;
  }
LAB_00106af6:
  uVar1 = local_50;
  local_3c = pbVar9;
  if ((*(int *)(param_4 + 0x10) != 0) &&
     (pcVar8 = *(code **)(*(int *)(param_4 + 0x10) + 0x14), pcVar8 != (code *)0x0)) {
    iVar5 = (*pcVar8)(param_1,pbVar9,omax,local_50,&local_51,param_4);
    if (iVar5 == 0) goto LAB_00106b22;
    goto LAB_00106c0c;
  }
  if (*(int *)(param_4 + 4) == -4) {
    a = (ASN1_TYPE *)param_1->type;
    if (a == (ASN1_TYPE *)0x0) {
      a = ASN1_TYPE_new();
      if (a == (ASN1_TYPE *)0x0) {
        ASN1_TYPE_free((ASN1_TYPE *)0x0);
        goto LAB_00106c8c;
      }
      param_1->type = (int)a;
    }
    if (a->type != uVar1) {
      ASN1_TYPE_set(a,uVar1,(void *)0x0);
    }
    a_00 = (ASN1_TYPE *)&a->value;
    pAVar4 = param_1;
  }
  else {
    a = (ASN1_TYPE *)0x0;
    pAVar4 = a;
    a_00 = param_1;
  }
  switch(uVar1) {
  case 1:
    if (omax == (byte *)0x1) {
      a_00->type = (uint)*local_3c;
      goto LAB_00106c0c;
    }
    ERR_put_error(0xd,0xcc,0x6a,"crypto/asn1/tasn_dec.c",0x345);
    break;
  case 2:
  case 10:
    pAVar3 = c2i_ASN1_INTEGER((ASN1_INTEGER **)a_00,&local_3c,(long)omax);
    if (pAVar3 != (ASN1_INTEGER *)0x0) {
      *(uint *)(a_00->type + 4) = *(uint *)(a_00->type + 4) & 0x100 | uVar1;
LAB_00106ca4:
      pAVar4 = a;
      if (a != (ASN1_TYPE *)0x0) {
        pAVar4 = (ASN1_TYPE *)0x1;
      }
      if (uVar1 != 5) {
        pAVar4 = (ASN1_TYPE *)0x0;
      }
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        (a->value).ptr = (char *)0x0;
      }
      goto LAB_00106c0c;
    }
    break;
  case 3:
    pAVar2 = (ASN1_OBJECT *)c2i_ASN1_BIT_STRING((ASN1_BIT_STRING **)a_00,&local_3c,(long)omax);
    goto joined_r0x00106c7e;
  default:
    if (uVar1 == 0x1e) {
      if (-1 < (int)omax << 0x1f) goto LAB_00106d20;
      ERR_put_error(0xd,0xcc,0xd6,"crypto/asn1/tasn_dec.c",0x36f);
    }
    else {
      if ((uVar1 != 0x1c) || (((uint)omax & 3) == 0)) {
LAB_00106d20:
        str = (ASN1_STRING *)a_00->type;
        if (str == (ASN1_STRING *)0x0) {
          str = ASN1_STRING_type_new(uVar1);
          if (str == (ASN1_STRING *)0x0) {
            ERR_put_error(0xd,0xcc,0x41,"crypto/asn1/tasn_dec.c",0x37b);
            break;
          }
          a_00->type = (int)str;
        }
        else {
          str->type = uVar1;
        }
        if (local_51 == '\0') {
          iVar5 = ASN1_STRING_set(str,local_3c,(int)omax);
          if (iVar5 == 0) {
            ERR_put_error(0xd,0xcc,0x41,"crypto/asn1/tasn_dec.c",0x38b);
            ASN1_STRING_free(str);
            a_00->type = 0;
            break;
          }
        }
        else {
          CRYPTO_free(str->data);
          str->length = (int)omax;
          local_51 = '\0';
          str->data = local_3c;
        }
        goto LAB_00106ca4;
      }
      ERR_put_error(0xd,0xcc,0xd7,"crypto/asn1/tasn_dec.c",0x374);
    }
    break;
  case 5:
    if (omax == (byte *)0x0) {
      a_00->type = 1;
      goto LAB_00106ca4;
    }
    ERR_put_error(0xd,0xcc,0x90,"crypto/asn1/tasn_dec.c",0x33d);
    break;
  case 6:
    pAVar2 = c2i_ASN1_OBJECT((ASN1_OBJECT **)a_00,&local_3c,(long)omax);
joined_r0x00106c7e:
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
LAB_00106c0c:
      iVar5 = 1;
      *param_2 = local_4c;
      goto LAB_00106b22;
    }
  }
  ASN1_TYPE_free(a);
  if (pAVar4 != (ASN1_TYPE *)0x0) {
    pAVar4->type = 0;
  }
LAB_00106c8c:
  iVar5 = 0;
LAB_00106b22:
  if (local_51 != '\0') {
    CRYPTO_free(local_38.data);
    return iVar5;
  }
  return iVar5;
}

