
void ASN1_primitive_free_part_0(int *param_1,char *param_2)

{
  ASN1_STRING *a;
  int iVar1;
  int *piVar2;
  
  if (param_2 == (char *)0x0) {
    piVar2 = (int *)*param_1;
    param_1 = piVar2 + 1;
    iVar1 = *piVar2;
    if (piVar2[1] == 0) {
      return;
    }
LAB_001583cc:
    switch(iVar1) {
    case 1:
      if (param_2 == (char *)0x0) {
        *param_1 = -1;
        return;
      }
LAB_001583f6:
      *param_1 = *(int *)(param_2 + 0x14);
      return;
    case 5:
      break;
    case 6:
      ASN1_OBJECT_free((ASN1_OBJECT *)*param_1);
      break;
    case -4:
      ASN1_primitive_free_part_0(param_1,0);
      CRYPTO_free((void *)*param_1);
      break;
    default:
      a = (ASN1_STRING *)*param_1;
      goto LAB_001583e8;
    }
  }
  else {
    if (*param_2 != '\x05') {
      iVar1 = *(int *)(param_2 + 4);
      if (iVar1 == 1) goto LAB_001583f6;
      if (*param_1 == 0) {
        return;
      }
      goto LAB_001583cc;
    }
    a = (ASN1_STRING *)*param_1;
    if (a == (ASN1_STRING *)0x0) {
      return;
    }
LAB_001583e8:
    ASN1_STRING_free(a);
    *param_1 = 0;
  }
  *param_1 = 0;
  return;
}

