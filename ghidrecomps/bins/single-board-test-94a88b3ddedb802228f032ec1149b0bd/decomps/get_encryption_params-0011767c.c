
int * get_encryption_params(ASN1_OBJECT *param_1)

{
  int *piVar1;
  int iVar2;
  char *s;
  int *piVar3;
  
  if (param_1 == (ASN1_OBJECT *)0x0) {
    s = (char *)get_gost_engine_param();
    if ((s == (char *)0x0) || (*s == '\0')) {
      return &DAT_0019e524;
    }
    iVar2 = OBJ_txt2nid(s);
    if (iVar2 == 0) {
      ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x97);
      return (int *)0x0;
    }
  }
  else {
    iVar2 = OBJ_obj2nid(param_1);
  }
  piVar3 = &gost_cipher_list;
  if (DAT_0019e51c != 0) {
    if (gost_cipher_list == iVar2) {
      return &gost_cipher_list;
    }
    while (piVar1 = piVar3 + 4, piVar3 = piVar3 + 3, *piVar1 != 0) {
      if (*piVar3 == iVar2) {
        return piVar3;
      }
    }
  }
  ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0xa0);
  return (int *)0x0;
}

