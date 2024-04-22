
int * get_encryption_params(ASN1_OBJECT *param_1)

{
  int *piVar1;
  int iVar2;
  char *s;
  int *piVar3;
  
  if (param_1 == (ASN1_OBJECT *)0x0) {
    s = (char *)get_gost_engine_param();
    if ((s == (char *)0x0) || (*s == '\0')) {
      return DAT_001176ec;
    }
    iVar2 = OBJ_txt2nid(s);
    if (iVar2 == 0) {
      ERR_GOST_error(0x67,0x6b,DAT_001176e8,0x97);
      return (int *)0x0;
    }
  }
  else {
    iVar2 = OBJ_obj2nid(param_1);
  }
  if (DAT_001176e4[1] != 0) {
    piVar3 = DAT_001176e4;
    if (*DAT_001176e4 == iVar2) {
      return DAT_001176e4;
    }
    while (piVar1 = piVar3 + 4, piVar3 = piVar3 + 3, *piVar1 != 0) {
      if (*piVar3 == iVar2) {
        return piVar3;
      }
    }
  }
  ERR_GOST_error(0x67,0x6a,DAT_001176e8,0xa0);
  return (int *)0x0;
}

