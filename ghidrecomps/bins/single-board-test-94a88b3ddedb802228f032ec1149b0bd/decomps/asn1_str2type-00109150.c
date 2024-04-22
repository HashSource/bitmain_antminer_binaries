
ASN1_TYPE * asn1_str2type(uchar *param_1,int param_2,int param_3)

{
  ASN1_TYPE *a;
  ASN1_STRING *pAVar1;
  ASN1_TIME *t;
  ASN1_INTEGER *pAVar2;
  ASN1_OBJECT *pAVar3;
  ulong mask;
  uchar *puVar4;
  int iVar5;
  int local_28;
  CONF_VALUE local_24;
  
  a = ASN1_TYPE_new();
  if (a == (ASN1_TYPE *)0x0) {
    ERR_put_error(0xd,0xb3,0x41,DAT_00109420,0x289);
    return (ASN1_TYPE *)0x0;
  }
  if (param_1 == (uchar *)0x0) {
    param_1 = DAT_0010941c;
  }
  switch(param_3) {
  case 1:
    if (param_2 != 1) {
      ERR_put_error(0xd,0xb3,0xbe,DAT_00109420,0x29b);
      goto LAB_00109208;
    }
    local_24.name = (char *)0x0;
    local_24.section = (char *)0x0;
    local_24.value = (char *)param_1;
    iVar5 = X509V3_get_value_bool(&local_24,&(a->value).boolean);
    if (iVar5 != 0) goto LAB_001091e4;
    ERR_put_error(0xd,0xb3,0xb0,DAT_00109420,0x2a2);
    break;
  case 2:
  case 10:
    if (param_2 != 1) {
      ERR_put_error(0xd,0xb3,0xb9,DAT_00109420,0x2aa);
      goto LAB_00109208;
    }
    pAVar2 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(char *)param_1);
    (a->value).integer = pAVar2;
    if (pAVar2 != (ASN1_INTEGER *)0x0) goto LAB_001091e4;
    ERR_put_error(0xd,0xb3,0xb4,DAT_00109420,0x2ae);
    break;
  case 3:
  case 4:
    pAVar1 = ASN1_STRING_new();
    (a->value).asn1_string = pAVar1;
    if (pAVar1 == (ASN1_STRING *)0x0) {
      ERR_put_error(0xd,0xb3,0x41,DAT_00109454,0x2f4);
      goto LAB_00109208;
    }
    if (param_2 == 3) {
      puVar4 = string_to_hex((char *)param_1,&local_28);
      if (puVar4 != (uchar *)0x0) {
        pAVar1 = (a->value).asn1_string;
        pAVar1->data = puVar4;
        pAVar1->length = local_28;
        pAVar1->type = param_3;
        goto LAB_0010939c;
      }
      ERR_put_error(0xd,0xb3,0xb2,DAT_00109454,0x2fb);
    }
    else {
      if (param_2 == 1) {
        ASN1_STRING_set(pAVar1,param_1,-1);
LAB_0010939c:
        if (param_3 == 3) {
          ((a->value).asn1_string)->flags = ((a->value).asn1_string)->flags & 0xfffffff0U | 8;
        }
LAB_001091e4:
        a->type = param_3;
        return a;
      }
      if (param_3 != 3 || param_2 != 4) {
        ERR_put_error(0xd,0xb3,0xaf,DAT_00109420,0x30f);
        goto LAB_00109208;
      }
      iVar5 = CONF_parse_list((char *)param_1,0x2c,1,DAT_00109428,pAVar1);
      if (iVar5 != 0) goto LAB_001091e4;
      ERR_put_error(0xd,0xb3,0xbc,DAT_00109420,0x309);
    }
    break;
  case 5:
    if (*param_1 != '\0') {
      ERR_put_error(0xd,0xb3,0xb6,DAT_00109420,0x294);
      goto LAB_00109208;
    }
    goto LAB_001091e4;
  case 6:
    if (param_2 != 1) {
      ERR_put_error(0xd,0xb3,0xbf,DAT_00109420,0x2b5);
      goto LAB_00109208;
    }
    pAVar3 = OBJ_txt2obj((char *)param_1,0);
    (a->value).object = pAVar3;
    if (pAVar3 != (ASN1_OBJECT *)0x0) goto LAB_001091e4;
    ERR_put_error(0xd,0xb3,0xb7,DAT_00109420,0x2b9);
    break;
  default:
    ERR_put_error(0xd,0xb3,0xc4,DAT_00109420,0x31c);
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
    if (param_2 == 1) {
      iVar5 = 0x1001;
    }
    else {
      if (param_2 != 2) {
        ERR_put_error(0xd,0xb3,0xb1,DAT_00109420,0x2e3);
        goto LAB_00109208;
      }
      iVar5 = 0x1000;
    }
    mask = ASN1_tag2bit(param_3);
    iVar5 = ASN1_mbstring_copy(&(a->value).asn1_string,param_1,-1,iVar5,mask);
    if (0 < iVar5) goto LAB_001091e4;
    iVar5 = 0x2e9;
    goto LAB_00109304;
  case 0x17:
  case 0x18:
    if (param_2 != 1) {
      ERR_put_error(0xd,0xb3,0xc1,DAT_00109420,0x2c1);
      goto LAB_00109208;
    }
    pAVar1 = ASN1_STRING_new();
    (a->value).asn1_string = pAVar1;
    if (pAVar1 == (ASN1_STRING *)0x0) {
      iVar5 = 0x2c5;
    }
    else {
      iVar5 = ASN1_STRING_set(pAVar1,param_1,-1);
      if (iVar5 != 0) {
        t = (a->value).asn1_string;
        t->type = param_3;
        iVar5 = ASN1_TIME_check(t);
        if (iVar5 != 0) goto LAB_001091e4;
        ERR_put_error(0xd,0xb3,0xb8,DAT_00109420,0x2ce);
        break;
      }
      iVar5 = 0x2c9;
    }
LAB_00109304:
    ERR_put_error(0xd,0xb3,0x41,DAT_00109420,iVar5);
  }
  ERR_add_error_data(2,DAT_00109424,param_1);
LAB_00109208:
  ASN1_TYPE_free(a);
  return (ASN1_TYPE *)0x0;
}

