
undefined4
do_ext_nconf(CONF *param_1,v3_ext_ctx *param_2,int param_3,undefined4 param_4,char *param_5)

{
  X509V3_EXT_METHOD *method;
  _STACK *st;
  int iVar1;
  ASN1_VALUE *val;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_3 == 0) {
    ERR_put_error(0x22,0x97,0x82,DAT_0010c658,0x7d);
    return 0;
  }
  method = X509V3_EXT_get_nid(param_3);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    ERR_put_error(0x22,0x97,0x81,DAT_0010c658,0x81);
    return 0;
  }
  if (method->v2i == (X509V3_EXT_V2I)0x0) {
    if (method->s2i == (X509V3_EXT_S2I)0x0) {
      if (method->r2i == (X509V3_EXT_R2I)0x0) {
        ERR_put_error(0x22,0x97,0x67,DAT_0010c658,0xa2);
        pcVar3 = OBJ_nid2sn(param_3);
        ERR_add_error_data(2,DAT_0010c65c,pcVar3);
        return 0;
      }
      if ((param_2->db == (void *)0x0) || (param_2->db_meth == (X509V3_CONF_METHOD *)0x0)) {
        ERR_put_error(0x22,0x97,0x88,DAT_0010c658,0x9b);
        return 0;
      }
      val = (ASN1_VALUE *)(*method->r2i)(method,param_2,param_5);
    }
    else {
      val = (ASN1_VALUE *)(*method->s2i)(method,param_2,param_5);
    }
  }
  else {
    if (*param_5 == '@') {
      st = &NCONF_get_section(param_1,param_5 + 1)->stack;
    }
    else {
      st = &X509V3_parse_list(param_5)->stack;
    }
    iVar1 = sk_num(st);
    if (iVar1 < 1) {
      ERR_put_error(0x22,0x97,0x69,DAT_0010c658,0x8c);
      pcVar3 = OBJ_nid2sn(param_3);
      ERR_add_error_data(4,DAT_0010c65c,pcVar3,DAT_0010c660,param_5);
      return 0;
    }
    val = (ASN1_VALUE *)(*method->v2i)(method,param_2,(stack_st_CONF_VALUE *)st);
    if (*param_5 != '@') {
      sk_pop_free(st,DAT_0010c654);
    }
  }
  if (val == (ASN1_VALUE *)0x0) {
    return 0;
  }
  uVar2 = do_ext_i2d(method,param_3,param_4,val);
  if (method->it == (ASN1_ITEM *)0x0) {
    (*method->ext_free)(val);
    return uVar2;
  }
  ASN1_item_free(val,method->it);
  return uVar2;
}

