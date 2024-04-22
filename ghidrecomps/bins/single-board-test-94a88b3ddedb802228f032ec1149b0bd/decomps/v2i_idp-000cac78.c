
ASN1_VALUE * v2i_idp(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  ASN1_VALUE *val;
  int iVar1;
  CONF_VALUE *value;
  int iVar2;
  char *__s1;
  ASN1_VALUE *pAVar3;
  char *pcVar4;
  
  val = ASN1_item_new(DAT_000cada0);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x22,0x9d,0x41,DAT_000cadb8,0x1cb);
LAB_000cad0a:
    pAVar3 = (ASN1_VALUE *)0x0;
    ASN1_item_free(val,DAT_000cada0);
  }
  else {
    for (iVar2 = 0; iVar1 = sk_num(param_3), pAVar3 = val, iVar2 < iVar1; iVar2 = iVar2 + 1) {
      value = (CONF_VALUE *)sk_value(param_3,iVar2);
      __s1 = value->name;
      pcVar4 = value->value;
      iVar1 = set_dist_point_name(val,param_2,value);
      if (iVar1 < 1) {
        if (iVar1 != 0) goto LAB_000cad0a;
        iVar1 = strcmp(__s1,DAT_000cada4);
        if (iVar1 == 0) {
          iVar1 = X509V3_get_value_bool(value,(int *)(val + 4));
        }
        else {
          iVar1 = strcmp(__s1,DAT_000cada8);
          if (iVar1 == 0) {
            iVar1 = X509V3_get_value_bool(value,(int *)(val + 8));
          }
          else {
            iVar1 = strcmp(__s1,DAT_000cadac);
            if (iVar1 == 0) {
              iVar1 = X509V3_get_value_bool(value,(int *)(val + 0x14));
              if (iVar1 != 0) goto LAB_000cac96;
              goto LAB_000cad0a;
            }
            iVar1 = strcmp(__s1,DAT_000cadb0);
            if (iVar1 == 0) {
              iVar1 = X509V3_get_value_bool(value,(int *)(val + 0x10));
            }
            else {
              iVar1 = strcmp(__s1,DAT_000cadb4);
              if (iVar1 != 0) {
                ERR_put_error(0x22,0x9d,0x6a,DAT_000cadb8,0x1c3);
                ERR_add_error_data(6,DAT_000cadc0,value->section,DAT_000cadc4,value->name,
                                   DAT_000cadbc,value->value);
                goto LAB_000cad0a;
              }
              iVar1 = set_reasons(val + 0xc,pcVar4);
            }
          }
        }
        if (iVar1 == 0) goto LAB_000cad0a;
      }
LAB_000cac96:
    }
  }
  return pAVar3;
}

