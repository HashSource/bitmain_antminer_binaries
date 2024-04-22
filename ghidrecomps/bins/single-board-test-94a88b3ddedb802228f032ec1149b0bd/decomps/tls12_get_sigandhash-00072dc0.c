
undefined4 tls12_get_sigandhash(undefined *param_1,int *param_2,EVP_MD *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_3 != (EVP_MD *)0x0) {
    iVar1 = EVP_MD_type(param_3);
    piVar2 = DAT_00072e54;
    if (iVar1 != *DAT_00072e54) {
      if (iVar1 == DAT_00072e54[2]) {
        piVar2 = DAT_00072e54 + 2;
      }
      else if (iVar1 == DAT_00072e54[4]) {
        piVar2 = DAT_00072e54 + 4;
      }
      else if (iVar1 == DAT_00072e54[6]) {
        piVar2 = DAT_00072e54 + 6;
      }
      else if (iVar1 == DAT_00072e54[8]) {
        piVar2 = DAT_00072e54 + 8;
      }
      else {
        if (iVar1 != DAT_00072e54[10]) {
          return 0;
        }
        piVar2 = DAT_00072e54 + 10;
      }
    }
    if (piVar2[1] != -1) {
      iVar1 = *param_2;
      if (iVar1 == DAT_00072e54[0xc]) {
        piVar3 = DAT_00072e54 + 0xc;
      }
      else if (iVar1 == DAT_00072e54[0xe]) {
        piVar3 = DAT_00072e54 + 0xe;
      }
      else {
        if (iVar1 != DAT_00072e54[0x10]) {
          return 0;
        }
        piVar3 = DAT_00072e54 + 0x10;
      }
      iVar1 = piVar3[1];
      if (iVar1 != -1) {
        *param_1 = (char)piVar2[1];
        param_1[1] = (char)iVar1;
        return 1;
      }
    }
  }
  return 0;
}

