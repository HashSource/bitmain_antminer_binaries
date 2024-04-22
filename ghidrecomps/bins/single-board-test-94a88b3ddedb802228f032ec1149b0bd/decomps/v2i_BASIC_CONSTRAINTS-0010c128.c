
int * v2i_BASIC_CONSTRAINTS(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  int *asn1_bool;
  int iVar1;
  CONF_VALUE *value;
  char *__s1;
  int iVar2;
  
  asn1_bool = (int *)ASN1_item_new(DAT_0010c1dc);
  if (asn1_bool == (int *)0x0) {
    ERR_put_error(0x22,0x66,0x41,DAT_0010c1e4,0x6f);
  }
  else {
    iVar2 = 0;
    do {
      while( true ) {
        iVar1 = sk_num(param_3);
        if (iVar1 <= iVar2) {
          return asn1_bool;
        }
        value = (CONF_VALUE *)sk_value(param_3,iVar2);
        __s1 = value->name;
        if (((*__s1 != 'C') || (__s1[1] != 'A')) || (__s1[2] != '\0')) break;
        iVar1 = X509V3_get_value_bool(value,asn1_bool);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_0010c176;
      }
      iVar1 = strcmp(__s1,DAT_0010c1e0);
      if (iVar1 != 0) {
        ERR_put_error(0x22,0x66,0x6a,DAT_0010c1e4,0x7b);
        ERR_add_error_data(6,DAT_0010c1ec,value->section,DAT_0010c1f0,value->name,DAT_0010c1e8,
                           value->value);
        break;
      }
      iVar1 = X509V3_get_value_int(value,(ASN1_INTEGER **)(asn1_bool + 1));
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
LAB_0010c176:
    ASN1_item_free((ASN1_VALUE *)asn1_bool,DAT_0010c1dc);
  }
  return (int *)0x0;
}

