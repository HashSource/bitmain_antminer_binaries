
ASN1_VALUE * v2i_POLICY_CONSTRAINTS(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  ASN1_VALUE *val;
  int iVar1;
  CONF_VALUE *value;
  int iVar2;
  char *__s1;
  
  val = ASN1_item_new((ASN1_ITEM *)&POLICY_CONSTRAINTS_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x22,0x92,0x41,"v3_pcons.c",0x70);
  }
  else {
    iVar2 = 0;
    do {
      while( true ) {
        iVar1 = sk_num(param_3);
        if (iVar1 <= iVar2) {
          if (*(int *)(val + 4) != 0) {
            return val;
          }
          if (*(int *)val != 0) {
            return val;
          }
          ERR_put_error(0x22,0x92,0x97,"v3_pcons.c",0x83);
          goto LAB_000cc6ae;
        }
        value = (CONF_VALUE *)sk_value(param_3,iVar2);
        __s1 = value->name;
        iVar1 = strcmp(__s1,"requireExplicitPolicy");
        if (iVar1 == 0) break;
        iVar1 = strcmp(__s1,"inhibitPolicyMapping");
        if (iVar1 != 0) {
          ERR_put_error(0x22,0x92,0x6a,"v3_pcons.c",0x7c);
          ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value
                            );
          goto LAB_000cc6ae;
        }
        iVar1 = X509V3_get_value_int(value,(ASN1_INTEGER **)(val + 4));
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_000cc6ae;
      }
      iVar1 = X509V3_get_value_int(value,(ASN1_INTEGER **)val);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
LAB_000cc6ae:
    ASN1_item_free(val,(ASN1_ITEM *)&POLICY_CONSTRAINTS_it);
  }
  return (ASN1_VALUE *)0x0;
}

