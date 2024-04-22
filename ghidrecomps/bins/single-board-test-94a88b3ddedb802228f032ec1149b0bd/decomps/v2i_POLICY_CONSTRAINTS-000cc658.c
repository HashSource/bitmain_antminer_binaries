
ASN1_INTEGER ** v2i_POLICY_CONSTRAINTS(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  ASN1_INTEGER **aint;
  int iVar1;
  CONF_VALUE *value;
  int iVar2;
  char *__s1;
  
  aint = (ASN1_INTEGER **)ASN1_item_new(DAT_000cc730);
  if (aint == (ASN1_INTEGER **)0x0) {
    ERR_put_error(0x22,0x92,0x41,DAT_000cc73c,0x70);
  }
  else {
    iVar2 = 0;
    do {
      while( true ) {
        iVar1 = sk_num(param_3);
        if (iVar1 <= iVar2) {
          if (aint[1] != (ASN1_INTEGER *)0x0) {
            return aint;
          }
          if (*aint != (ASN1_INTEGER *)0x0) {
            return aint;
          }
          ERR_put_error(0x22,0x92,0x97,DAT_000cc73c,0x83);
          goto LAB_000cc6ae;
        }
        value = (CONF_VALUE *)sk_value(param_3,iVar2);
        __s1 = value->name;
        iVar1 = strcmp(__s1,DAT_000cc734);
        if (iVar1 == 0) break;
        iVar1 = strcmp(__s1,DAT_000cc738);
        if (iVar1 != 0) {
          ERR_put_error(0x22,0x92,0x6a,DAT_000cc73c,0x7c);
          ERR_add_error_data(6,DAT_000cc744,value->section,DAT_000cc748,value->name,DAT_000cc740,
                             value->value);
          goto LAB_000cc6ae;
        }
        iVar1 = X509V3_get_value_int(value,aint + 1);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_000cc6ae;
      }
      iVar1 = X509V3_get_value_int(value,aint);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
LAB_000cc6ae:
    ASN1_item_free((ASN1_VALUE *)aint,DAT_000cc730);
  }
  return (ASN1_INTEGER **)0x0;
}

