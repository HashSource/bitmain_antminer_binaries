
int i2r_ASIdentifiers(undefined4 param_1,undefined4 *param_2,BIO *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  
  piVar2 = (int *)*param_2;
  if (piVar2 != (int *)0x0) {
    pcVar3 = "Autonomous System Numbers";
    BIO_printf(param_3,"%*s%s:\n",param_4,"","Autonomous System Numbers");
    if (*piVar2 == 0) {
      BIO_printf(param_3,"%*sinherit\n",param_4 + 2,"",pcVar3);
      piVar2 = (int *)param_2[1];
      goto joined_r0x0017bda6;
    }
    if (*piVar2 != 1) {
      return 0;
    }
    iVar1 = i2r_ASIdentifierChoice_part_2(param_3,piVar2,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  piVar2 = (int *)param_2[1];
joined_r0x0017bda6:
  if (piVar2 == (int *)0x0) {
    return 1;
  }
  pcVar3 = "Routing Domain Identifiers";
  BIO_printf(param_3,"%*s%s:\n",param_4,"","Routing Domain Identifiers");
  if (*piVar2 != 0) {
    if (*piVar2 != 1) {
      return 0;
    }
    iVar1 = i2r_ASIdentifierChoice_part_2(param_3,piVar2,param_4);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  BIO_printf(param_3,"%*sinherit\n",param_4 + 2,"",pcVar3);
  return 1;
}

