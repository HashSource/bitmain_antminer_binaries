
/* WARNING: Removing unreachable block (ram,0x00176240) */

int X509V3_get_value_bool(CONF_VALUE *value,int *asn1_bool)

{
  char cVar1;
  int iVar2;
  char *__s1;
  
  __s1 = value->value;
  if (__s1 == (char *)0x0) goto LAB_0017625a;
  iVar2 = strcmp(__s1,"TRUE");
  if (((iVar2 == 0) || (iVar2 = strcmp(__s1,"true"), iVar2 == 0)) ||
     ((cVar1 = *__s1, cVar1 == 'Y' && (__s1[1] == '\0')))) goto LAB_001761ea;
  if (cVar1 == 'y') {
    if (__s1[1] == '\0') goto LAB_001761ea;
    if ((__s1[1] == 'e') && (__s1[2] == 's')) goto LAB_00176208;
  }
  else if ((cVar1 == 'Y') && ((__s1[1] == 'E' && (__s1[2] == 'S')))) {
LAB_00176208:
    if (__s1[3] == '\0') {
LAB_001761ea:
      *asn1_bool = 0xff;
      return 1;
    }
  }
  iVar2 = strcmp(__s1,"FALSE");
  if (((iVar2 != 0) && (iVar2 = strcmp(__s1,"false"), iVar2 != 0)) &&
     ((cVar1 != 'N' || (__s1[1] != '\0')))) {
    if (cVar1 == 'n') {
      if (__s1[1] == '\0') goto LAB_00176230;
      if (__s1[1] != 'o') goto LAB_0017625a;
    }
    else if ((cVar1 != 'N') || (__s1[1] != 'O')) goto LAB_0017625a;
    if (__s1[2] != '\0') {
LAB_0017625a:
      ERR_put_error(0x22,0x6e,0x68,"crypto/x509v3/v3_utl.c",0x121);
      ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value);
      return 0;
    }
  }
LAB_00176230:
  *asn1_bool = 0;
  return 1;
}

