
bool i2r_NAMING_AUTHORITY_isra_0(int *param_1,BIO *param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char acStack_a0 [132];
  
  if ((param_1 != (int *)0x0) && (((*param_1 != 0 || (param_1[2] != 0)) || (param_1[1] != 0)))) {
    pcVar5 = "";
    iVar1 = BIO_printf(param_2,"%*snamingAuthority: ",param_3,"");
    if (0 < iVar1) {
      if ((ASN1_OBJECT *)*param_1 != (ASN1_OBJECT *)0x0) {
        iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_1);
        pcVar2 = OBJ_nid2ln(iVar1);
        iVar1 = BIO_printf(param_2,"%*s  admissionAuthorityId: ",param_3,"");
        if (iVar1 < 1) {
          return false;
        }
        OBJ_obj2txt(acStack_a0,0x80,(ASN1_OBJECT *)*param_1,1);
        pcVar3 = pcVar5;
        pcVar4 = pcVar5;
        if (pcVar2 != (char *)0x0) {
          pcVar5 = ")";
          pcVar3 = pcVar2;
          pcVar4 = " (";
        }
        iVar1 = BIO_printf(param_2,"%s%s%s%s\n",pcVar3,pcVar4,acStack_a0,pcVar5);
        if (iVar1 < 1) {
          return false;
        }
      }
      if ((param_1[2] == 0) ||
         (((iVar1 = BIO_printf(param_2,"%*s  namingAuthorityText: ",param_3,""), 0 < iVar1 &&
           (iVar1 = ASN1_STRING_print(param_2,(ASN1_STRING *)param_1[2]), 0 < iVar1)) &&
          (iVar1 = BIO_printf(param_2,"\n"), 0 < iVar1)))) {
        if (param_1[1] == 0) {
          return true;
        }
        iVar1 = BIO_printf(param_2,"%*s  namingAuthorityUrl: ",param_3,"");
        if ((0 < iVar1) && (iVar1 = ASN1_STRING_print(param_2,(ASN1_STRING *)param_1[1]), 0 < iVar1)
           ) {
          iVar1 = BIO_printf(param_2,"\n");
          return 0 < iVar1;
        }
      }
    }
  }
  return false;
}

