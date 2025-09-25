
X509_EXTENSION *
do_ext_nconf(CONF *param_1,v3_ext_ctx *param_2,int param_3,int param_4,char *param_5)

{
  uchar *puVar1;
  X509V3_EXT_METHOD *method;
  stack_st_CONF_VALUE *values;
  int iVar2;
  ASN1_VALUE *val;
  ASN1_OCTET_STRING *data;
  X509_EXTENSION *pXVar3;
  char *pcVar4;
  uchar *local_28;
  uchar *local_24;
  
  if (param_3 == 0) {
    ERR_put_error(0x22,0x97,0x82,"crypto/x509v3/v3_conf.c",0x4e);
    return (X509_EXTENSION *)0x0;
  }
  method = X509V3_EXT_get_nid(param_3);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    ERR_put_error(0x22,0x97,0x81,"crypto/x509v3/v3_conf.c",0x52);
    return (X509_EXTENSION *)0x0;
  }
  if (method->v2i == (X509V3_EXT_V2I)0x0) {
    if (method->s2i == (X509V3_EXT_S2I)0x0) {
      if (method->r2i == (X509V3_EXT_R2I)0x0) {
        ERR_put_error(0x22,0x97,0x67,"crypto/x509v3/v3_conf.c",0x75);
        pcVar4 = OBJ_nid2sn(param_3);
        ERR_add_error_data(2,"name=",pcVar4);
        return (X509_EXTENSION *)0x0;
      }
      if ((param_2->db == (void *)0x0) || (param_2->db_meth == (X509V3_CONF_METHOD *)0x0)) {
        ERR_put_error(0x22,0x97,0x88,"crypto/x509v3/v3_conf.c",0x6e);
        return (X509_EXTENSION *)0x0;
      }
      val = (ASN1_VALUE *)(*method->r2i)(method,param_2,param_5);
    }
    else {
      val = (ASN1_VALUE *)(*method->s2i)(method,param_2,param_5);
    }
  }
  else {
    if (*param_5 == '@') {
      values = NCONF_get_section(param_1,param_5 + 1);
    }
    else {
      values = X509V3_parse_list(param_5);
    }
    if ((values == (stack_st_CONF_VALUE *)0x0) || (iVar2 = OPENSSL_sk_num(values), iVar2 < 1)) {
      ERR_put_error(0x22,0x97,0x69,"crypto/x509v3/v3_conf.c",0x5d);
      pcVar4 = OBJ_nid2sn(param_3);
      ERR_add_error_data(4,"name=",pcVar4,",section=",param_5);
      if (*param_5 == '@') {
        return (X509_EXTENSION *)0x0;
      }
      OPENSSL_sk_pop_free(values,0x1752a9);
      return (X509_EXTENSION *)0x0;
    }
    val = (ASN1_VALUE *)(*method->v2i)(method,param_2,values);
    if (*param_5 != '@') {
      OPENSSL_sk_pop_free(values,0x1752a9);
    }
  }
  if (val == (ASN1_VALUE *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  local_28 = (uchar *)0x0;
  if (method->it == (ASN1_ITEM *)0x0) {
    iVar2 = (*method->i2d)(val,(uchar **)0x0);
    local_28 = (uchar *)CRYPTO_malloc(iVar2,"crypto/x509v3/v3_conf.c",0x95);
    if (local_28 != (uchar *)0x0) {
      local_24 = local_28;
      (*method->i2d)(val,&local_24);
      goto LAB_0016f128;
    }
    data = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    iVar2 = ASN1_item_i2d(val,&local_28,method->it);
    if (-1 < iVar2) {
LAB_0016f128:
      data = ASN1_OCTET_STRING_new();
      puVar1 = local_28;
      if (data != (ASN1_OCTET_STRING *)0x0) {
        local_28 = (uchar *)0x0;
        data->length = iVar2;
        data->data = puVar1;
        pXVar3 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,param_3,param_4,data);
        if (pXVar3 != (X509_EXTENSION *)0x0) goto LAB_0016f14c;
        goto LAB_0016f22e;
      }
    }
    data = (ASN1_OCTET_STRING *)0x0;
  }
LAB_0016f22e:
  pXVar3 = (X509_EXTENSION *)0x0;
  ERR_put_error(0x22,0x87,0x41,"crypto/x509v3/v3_conf.c",0xa8);
  CRYPTO_free(local_28);
LAB_0016f14c:
  ASN1_OCTET_STRING_free(data);
  if (method->it == (ASN1_ITEM *)0x0) {
    (*method->ext_free)(val);
    return pXVar3;
  }
  ASN1_item_free(val,method->it);
  return pXVar3;
}

