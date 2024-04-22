
GENERAL_NAME *
a2i_GENERAL_NAME(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,int gen_type,
                char *value,int is_nc)

{
  ASN1_OBJECT *pAVar1;
  char *pcVar2;
  OTHERNAME *pOVar3;
  ASN1_TYPE *pAVar4;
  ASN1_STRING *str;
  size_t sVar5;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  ASN1_OCTET_STRING *pAVar6;
  GENERAL_NAME *a;
  int iVar7;
  int line;
  
  if (value == (char *)0x0) {
    ERR_put_error(0x22,0xa4,0x7c,DAT_000c8fb8,0x1b5);
    return (GENERAL_NAME *)0x0;
  }
  a = out;
  if ((out == (GENERAL_NAME *)0x0) && (a = GENERAL_NAME_new(), a == (GENERAL_NAME *)0x0)) {
    ERR_put_error(0x22,0xa4,0x41,DAT_000c8fb8,0x1be);
    return (GENERAL_NAME *)0x0;
  }
  switch(gen_type) {
  case 0:
    pcVar2 = strchr(value,0x3b);
    if (pcVar2 != (char *)0x0) {
      pOVar3 = OTHERNAME_new();
      (a->d).otherName = pOVar3;
      if (pOVar3 != (OTHERNAME *)0x0) {
        ASN1_TYPE_free(pOVar3->value);
        pOVar3 = (a->d).otherName;
        pAVar4 = ASN1_generate_v3(pcVar2 + 1,ctx);
        pOVar3->value = pAVar4;
        if (pAVar4 != (ASN1_TYPE *)0x0) {
          sVar5 = (int)pcVar2 - (int)value;
          pcVar2 = (char *)CRYPTO_malloc(sVar5 + 1,DAT_000c8fb8,0x23f);
          strncpy(pcVar2,value,sVar5);
          pcVar2[sVar5] = '\0';
          pOVar3 = (a->d).otherName;
          pAVar1 = OBJ_txt2obj(pcVar2,0);
          pOVar3->type_id = pAVar1;
          CRYPTO_free(pcVar2);
          if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) goto LAB_000c8dda;
        }
      }
    }
    ERR_put_error(0x22,0xa4,0x93,DAT_000c8fb8,0x1eb);
    break;
  case 1:
  case 2:
  case 6:
    str = ASN1_STRING_type_new(0x16);
    (a->d).otherName = (OTHERNAME *)str;
    if (str != (ASN1_STRING *)0x0) {
      sVar5 = strlen(value);
      iVar7 = ASN1_STRING_set(str,value,sVar5);
      if (iVar7 != 0) goto LAB_000c8dda;
    }
    ERR_put_error(0x22,0xa4,0x41,DAT_000c8fb8,0x1f8);
    break;
  default:
    ERR_put_error(0x22,0xa4,0xa7,DAT_000c8fb8,0x1f0);
    break;
  case 4:
    nm = X509_NAME_new();
    if (nm == (X509_NAME *)0x0) {
      dn_sk = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      dn_sk = X509V3_get_section(ctx,value);
      if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
        ERR_put_error(0x22,0x90,0x96,DAT_000c8fb8,0x252);
        ERR_add_error_data(2,DAT_000c8fc0,value);
      }
      else {
        iVar7 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
        if (iVar7 != 0) {
          (a->d).directoryName = nm;
          X509V3_section_free(ctx,dn_sk);
          goto LAB_000c8dda;
        }
      }
    }
    X509_NAME_free(nm);
    X509V3_section_free(ctx,dn_sk);
    ERR_put_error(0x22,0xa4,0x95,DAT_000c8fb8,0x1e4);
    break;
  case 7:
    if (is_nc == 0) {
      pAVar6 = a2i_IPADDRESS(value);
      (a->d).iPAddress = pAVar6;
    }
    else {
      pAVar6 = a2i_IPADDRESS_NC(value);
      (a->d).iPAddress = pAVar6;
    }
    if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_000c8dda:
      a->type = gen_type;
      return a;
    }
    iVar7 = 0x76;
    line = 0x1dc;
    goto LAB_000c8f18;
  case 8:
    pAVar1 = OBJ_txt2obj(value,0);
    if (pAVar1 != (ASN1_OBJECT *)0x0) {
      (a->d).registeredID = pAVar1;
      goto LAB_000c8dda;
    }
    line = 0x1ce;
    iVar7 = 0x77;
LAB_000c8f18:
    ERR_put_error(0x22,0xa4,iVar7,DAT_000c8fb8,line);
    ERR_add_error_data(2,DAT_000c8fbc,value);
  }
  if (out == (GENERAL_NAME *)0x0) {
    GENERAL_NAME_free(a);
  }
  return (GENERAL_NAME *)0x0;
}

