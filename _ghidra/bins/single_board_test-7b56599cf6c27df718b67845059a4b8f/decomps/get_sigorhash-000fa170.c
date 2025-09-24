
void get_sigorhash(undefined4 *param_1,int *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_3;
  if (cVar1 == 'R') {
    if (((param_3[1] == 'S') && (param_3[2] == 'A')) && (param_3[3] == '\0')) {
      *param_1 = 6;
      return;
    }
    iVar2 = strcmp(param_3,"RSA-PSS");
    if (iVar2 != 0) goto LAB_000fa19a;
  }
  else {
    iVar2 = strcmp(param_3,"RSA-PSS");
    if (iVar2 != 0) {
      if (cVar1 == 'P') {
        if (((param_3[1] == 'S') && (param_3[2] == 'S')) && (param_3[3] == '\0')) goto LAB_000fa1c2;
      }
      else if (((cVar1 == 'D') && (param_3[1] == 'S')) &&
              ((param_3[2] == 'A' && (param_3[3] == '\0')))) {
        *param_1 = 0x74;
        return;
      }
LAB_000fa19a:
      iVar2 = strcmp(param_3,"ECDSA");
      if (iVar2 == 0) {
        *param_1 = 0x198;
        return;
      }
      iVar2 = OBJ_sn2nid(param_3);
      *param_2 = iVar2;
      if (iVar2 == 0) {
        iVar2 = OBJ_ln2nid(param_3);
        *param_2 = iVar2;
        return;
      }
      return;
    }
  }
LAB_000fa1c2:
  *param_1 = 0x390;
  return;
}

