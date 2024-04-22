
void ASN1_primitive_free_part_0(int *param_1,char *param_2)

{
  ASN1_STRING *pAVar1;
  int iVar2;
  
  if (param_2 == (char *)0x0) {
    pAVar1 = (ASN1_STRING *)*param_1;
    param_1 = &pAVar1->type;
    iVar2 = pAVar1->length;
    if (pAVar1->type == 0) {
      return;
    }
LAB_000b94c8:
    switch(iVar2) {
    case 1:
      if (param_2 == (char *)0x0) {
        *param_1 = -1;
        return;
      }
LAB_000b94f2:
      *param_1 = (int)*(ASN1_STRING **)(param_2 + 0x14);
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
      pAVar1 = (ASN1_STRING *)*param_1;
      goto LAB_000b94e4;
    }
  }
  else {
    if (*param_2 != '\x05') {
      iVar2 = *(int *)(param_2 + 4);
      if (iVar2 == 1) goto LAB_000b94f2;
      if ((ASN1_STRING *)*param_1 == (ASN1_STRING *)0x0) {
        return;
      }
      goto LAB_000b94c8;
    }
    pAVar1 = (ASN1_STRING *)*param_1;
    if (pAVar1 == (ASN1_STRING *)0x0) {
      return;
    }
LAB_000b94e4:
    ASN1_STRING_free(pAVar1);
    *param_1 = 0;
  }
  *param_1 = 0;
  return;
}

