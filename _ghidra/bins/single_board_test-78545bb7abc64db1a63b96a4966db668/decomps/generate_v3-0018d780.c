
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ASN1_TYPE * generate_v3(char *param_1,X509V3_CTX *param_2,int param_3,undefined4 *param_4)

{
  uchar *puVar1;
  uchar *puVar2;
  ASN1_TYPE *pAVar3;
  ASN1_SEQUENCE_ANY *a;
  int iVar4;
  int iVar5;
  ASN1_STRING *pAVar6;
  size_t omax;
  ASN1_TIME *t;
  ulong mask;
  ASN1_OBJECT *pAVar7;
  ASN1_INTEGER *pAVar8;
  long *plVar9;
  int *piVar10;
  stack_st_CONF_VALUE *psVar11;
  uint local_204;
  size_t local_200;
  uchar *local_1f4;
  uchar *local_1f0;
  uchar *local_1ec;
  uchar *local_1e8;
  long local_1e4;
  int local_1e0;
  CONF_VALUE local_1dc;
  int local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c4;
  stack_st_CONF_VALUE *local_1c0;
  int local_2c;
  
  local_1c4 = 1;
  local_1f4 = (uchar *)0x0;
  local_1d0 = -1;
  local_1cc = -1;
  local_2c = 0;
  local_1e4 = 0;
  puVar2 = (uchar *)CONF_parse_list(param_1,0x2c,1,(list_cb *)0x18df61,&local_1d0);
  iVar5 = local_1c4;
  if (puVar2 != (uchar *)0x0) {
    *param_4 = 0xc2;
    return (ASN1_TYPE *)0x0;
  }
  if (local_1c8 - 0x10U < 2) {
    if (param_2 == (X509V3_CTX *)0x0) {
      *param_4 = 0xc0;
      return (ASN1_TYPE *)0x0;
    }
    if (0x31 < param_3) {
      *param_4 = 0xb5;
      return (ASN1_TYPE *)0x0;
    }
    local_1dc.section = (char *)puVar2;
    a = (ASN1_SEQUENCE_ANY *)OPENSSL_sk_new_null();
    if (a == (ASN1_SEQUENCE_ANY *)0x0) {
      pAVar3 = (ASN1_TYPE *)0x0;
      psVar11 = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      psVar11 = local_1c0;
      if (local_1c0 == (stack_st_CONF_VALUE *)0x0) {
LAB_0018d8b8:
        if (local_1c8 == 0x11) {
          iVar5 = i2d_ASN1_SET_ANY(a,(uchar **)&local_1dc);
        }
        else {
          iVar5 = i2d_ASN1_SEQUENCE_ANY(a,(uchar **)&local_1dc);
        }
        if (-1 < iVar5) {
          pAVar3 = ASN1_TYPE_new();
          if (pAVar3 != (ASN1_TYPE *)0x0) {
            pAVar6 = ASN1_STRING_type_new(local_1c8);
            (pAVar3->value).asn1_string = pAVar6;
            if (pAVar6 != (ASN1_STRING *)0x0) {
              pAVar3->type = local_1c8;
              pAVar6->length = iVar5;
              pAVar6->data = (uchar *)local_1dc.section;
              local_1dc.section = (char *)0x0;
            }
          }
          goto LAB_0018d902;
        }
      }
      else {
        psVar11 = X509V3_get_section(param_2,(char *)local_1c0);
        if (psVar11 != (stack_st_CONF_VALUE *)0x0) {
          iVar5 = 0;
          do {
            iVar4 = OPENSSL_sk_num(psVar11);
            if (iVar4 <= iVar5) goto LAB_0018d8b8;
            iVar4 = OPENSSL_sk_value(psVar11,iVar5);
            iVar4 = generate_v3(*(undefined4 *)(iVar4 + 8),param_2,param_3 + 1,param_4);
          } while ((iVar4 != 0) && (iVar4 = OPENSSL_sk_push(a,iVar4), iVar5 = iVar5 + 1, iVar4 != 0)
                  );
        }
      }
      pAVar3 = (ASN1_TYPE *)0x0;
    }
LAB_0018d902:
    CRYPTO_free(local_1dc.section);
    OPENSSL_sk_pop_free(a,(undefined *)0x113e1d);
    X509V3_section_free(param_2,psVar11);
    goto LAB_0018d928;
  }
  pAVar3 = ASN1_TYPE_new();
  if (pAVar3 == (ASN1_TYPE *)0x0) {
    ERR_put_error(0xd,0xb3,0x41,"crypto/asn1/asn1_gen.c",0x24b);
    return (ASN1_TYPE *)0x0;
  }
  psVar11 = local_1c0;
  if (local_1c0 == (stack_st_CONF_VALUE *)0x0) {
    psVar11 = (stack_st_CONF_VALUE *)0x20a58c;
  }
  switch(local_1c8) {
  case 1:
    if (iVar5 != 1) {
      ERR_put_error(0xd,0xb3,0xbe,"crypto/asn1/asn1_gen.c",0x25d);
      goto LAB_0018dc2e;
    }
    local_1dc.name = (char *)0x0;
    local_1dc.section = (char *)0x0;
    local_1dc.value = (char *)psVar11;
    iVar5 = X509V3_get_value_bool(&local_1dc,&(pAVar3->value).boolean);
    if (iVar5 != 0) goto LAB_0018dc08;
    ERR_put_error(0xd,0xb3,0xb0,"crypto/asn1/asn1_gen.c",0x264);
    break;
  case 2:
  case 10:
    if (iVar5 != 1) {
      ERR_put_error(0xd,0xb3,0xb9,"crypto/asn1/asn1_gen.c",0x26c);
      goto LAB_0018dc2e;
    }
    pAVar8 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(char *)psVar11);
    (pAVar3->value).integer = pAVar8;
    if (pAVar8 != (ASN1_INTEGER *)0x0) goto LAB_0018dc08;
    ERR_put_error(0xd,0xb3,0xb4,"crypto/asn1/asn1_gen.c",0x271);
    break;
  case 3:
  case 4:
    pAVar6 = ASN1_STRING_new();
    (pAVar3->value).asn1_string = pAVar6;
    if (pAVar6 == (ASN1_STRING *)0x0) {
      ERR_put_error(0xd,0xb3,0x41,"crypto/asn1/asn1_gen.c",0x2b4);
      goto LAB_0018dc2e;
    }
    if (iVar5 == 3) {
      puVar2 = (uchar *)OPENSSL_hexstr2buf(psVar11,&local_1e0);
      if (puVar2 != (uchar *)0x0) {
        pAVar6 = (pAVar3->value).asn1_string;
        pAVar6->length = local_1e0;
        pAVar6->data = puVar2;
        pAVar6->type = local_1c8;
        goto LAB_0018dcc6;
      }
      ERR_put_error(0xd,0xb3,0xb2,"crypto/asn1/asn1_gen.c",0x2ba);
    }
    else {
      if (iVar5 == 1) {
        ASN1_STRING_set(pAVar6,psVar11,-1);
LAB_0018dcc6:
        if (local_1c8 == 3) {
          ((pAVar3->value).asn1_string)->flags =
               ((pAVar3->value).asn1_string)->flags & 0xfffffff0U | 8;
        }
        goto LAB_0018dc08;
      }
      if (iVar5 != 4 || local_1c8 != 3) {
        ERR_put_error(0xd,0xb3,0xaf,"crypto/asn1/asn1_gen.c",0x2cc);
        goto LAB_0018dc2e;
      }
      iVar5 = CONF_parse_list((char *)psVar11,0x2c,1,(list_cb *)0x18de2d,pAVar6);
      if (iVar5 != 0) goto LAB_0018dc08;
      ERR_put_error(0xd,0xb3,0xbc,"crypto/asn1/asn1_gen.c",0x2c6);
    }
    break;
  case 5:
    if ((char)(psVar11->stack).num != '\0') {
      ERR_put_error(0xd,0xb3,0xb6,"crypto/asn1/asn1_gen.c",0x256);
      goto LAB_0018dc2e;
    }
    goto LAB_0018dc08;
  case 6:
    if (iVar5 != 1) {
      ERR_put_error(0xd,0xb3,0xbf,"crypto/asn1/asn1_gen.c",0x278);
      goto LAB_0018dc2e;
    }
    pAVar7 = OBJ_txt2obj((char *)psVar11,0);
    (pAVar3->value).object = pAVar7;
    if (pAVar7 != (ASN1_OBJECT *)0x0) goto LAB_0018dc08;
    ERR_put_error(0xd,0xb3,0xb7,"crypto/asn1/asn1_gen.c",0x27c);
    break;
  default:
    ERR_put_error(0xd,0xb3,0xc4,"crypto/asn1/asn1_gen.c",0x2d9);
    break;
  case 0xc:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x16:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1e:
    if (iVar5 == 1) {
      iVar5 = 0x1001;
    }
    else {
      if (iVar5 != 2) {
        ERR_put_error(0xd,0xb3,0xb1,"crypto/asn1/asn1_gen.c",0x2a5);
        goto LAB_0018dc2e;
      }
      iVar5 = 0x1000;
    }
    mask = ASN1_tag2bit(local_1c8);
    iVar5 = ASN1_mbstring_copy(&(pAVar3->value).asn1_string,(uchar *)psVar11,-1,iVar5,mask);
    if (iVar5 < 1) {
      iVar5 = 0x2ab;
      goto LAB_0018db26;
    }
LAB_0018dc08:
    pAVar3->type = local_1c8;
LAB_0018d928:
    if (pAVar3 == (ASN1_TYPE *)0x0) {
      return (ASN1_TYPE *)0x0;
    }
    if ((local_1d0 == -1) && (local_2c == 0)) {
      return pAVar3;
    }
    omax = i2d_ASN1_TYPE(pAVar3,&local_1f4);
    ASN1_TYPE_free(pAVar3);
    local_1f0 = local_1f4;
    if (local_1d0 == -1) {
      local_204 = 0;
      local_200 = omax;
LAB_0018d9a8:
      if (0 < local_2c) {
        iVar5 = 0;
        plVar9 = &local_1e4 + local_2c * 5;
        do {
          iVar5 = iVar5 + 1;
          plVar9[9] = omax + plVar9[8];
          omax = ASN1_object_size(0,omax + plVar9[8],plVar9[5]);
          plVar9 = plVar9 + -5;
        } while (iVar5 < local_2c);
      }
      puVar2 = (uchar *)CRYPTO_malloc(omax,"crypto/asn1/asn1_gen.c",0xc3);
      if (puVar2 != (uchar *)0x0) {
        local_1ec = puVar2;
        if (0 < local_2c) {
          iVar5 = 0;
          piVar10 = &local_1d0;
          do {
            iVar5 = iVar5 + 1;
            HintPreloadData(piVar10 + 0x29);
            ASN1_put_object(&local_1ec,piVar10[7],piVar10[9],piVar10[5],piVar10[6]);
            puVar1 = local_1ec;
            if (piVar10[8] != 0) {
              local_1ec = local_1ec + 1;
              *puVar1 = '\0';
            }
            piVar10 = piVar10 + 5;
          } while (iVar5 < local_2c);
        }
        if (local_1d0 != -1) {
          if ((local_1cc == 0) && (local_1d0 - 0x10U < 2)) {
            local_204 = 0x20;
          }
          ASN1_put_object(&local_1ec,local_204,local_1e4,local_1d0,local_1cc);
        }
        memcpy(local_1ec,local_1f0,local_200);
        local_1e8 = puVar2;
        pAVar3 = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_1e8,omax);
        goto LAB_0018da88;
      }
    }
    else {
      local_204 = ASN1_get_object(&local_1f0,&local_1e4,&local_1e0,(int *)&local_1dc,omax);
      if ((local_204 & 0x80) == 0) {
        local_200 = omax - ((int)local_1f0 - (int)local_1f4);
        if ((int)(local_204 << 0x1f) < 0) {
          local_1e4 = 0;
          local_204 = 2;
        }
        else {
          local_204 = local_204 & 0x20;
        }
        omax = ASN1_object_size(0,local_1e4,local_1d0);
        goto LAB_0018d9a8;
      }
    }
    puVar2 = (uchar *)0x0;
    pAVar3 = (ASN1_TYPE *)0x0;
LAB_0018da88:
    CRYPTO_free(local_1f4);
    CRYPTO_free(puVar2);
    return pAVar3;
  case 0x17:
  case 0x18:
    if (iVar5 != 1) {
      ERR_put_error(0xd,0xb3,0xc1,"crypto/asn1/asn1_gen.c",0x284);
      goto LAB_0018dc2e;
    }
    pAVar6 = ASN1_STRING_new();
    (pAVar3->value).asn1_string = pAVar6;
    if (pAVar6 == (ASN1_STRING *)0x0) {
      iVar5 = 0x288;
    }
    else {
      iVar5 = ASN1_STRING_set(pAVar6,psVar11,-1);
      if (iVar5 != 0) {
        t = (pAVar3->value).asn1_string;
        t->type = local_1c8;
        iVar5 = ASN1_TIME_check(t);
        if (iVar5 != 0) goto LAB_0018dc08;
        ERR_put_error(0xd,0xb3,0xb8,"crypto/asn1/asn1_gen.c",0x291);
        break;
      }
      iVar5 = 0x28c;
    }
LAB_0018db26:
    ERR_put_error(0xd,0xb3,0x41,"crypto/asn1/asn1_gen.c",iVar5);
  }
  ERR_add_error_data(2,"string=",psVar11);
LAB_0018dc2e:
  ASN1_TYPE_free(pAVar3);
  return (ASN1_TYPE *)0x0;
}

