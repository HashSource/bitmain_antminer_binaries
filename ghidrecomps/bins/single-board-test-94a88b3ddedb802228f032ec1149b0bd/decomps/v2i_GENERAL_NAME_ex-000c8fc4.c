
GENERAL_NAME *
v2i_GENERAL_NAME_ex(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf,
                   int is_nc)

{
  int iVar1;
  int iVar2;
  GENERAL_NAME *pGVar3;
  char *value;
  char *name;
  
  value = cnf->value;
  name = cnf->name;
  if (value == (char *)0x0) {
    ERR_put_error(0x22,0x75,0x7c,DAT_000c90a0,0x213);
    pGVar3 = (GENERAL_NAME *)0x0;
  }
  else {
    iVar1 = name_cmp(name,DAT_000c9084);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar2 = name_cmp(name,DAT_000c9088);
      iVar1 = 6;
      if (iVar2 != 0) {
        iVar2 = name_cmp(name,DAT_000c908c);
        iVar1 = 2;
        if (iVar2 != 0) {
          iVar2 = name_cmp(name,DAT_000c9090);
          iVar1 = 8;
          if (iVar2 != 0) {
            iVar2 = name_cmp(name,DAT_000c9094);
            iVar1 = 7;
            if (iVar2 != 0) {
              iVar2 = name_cmp(name,DAT_000c9098);
              iVar1 = 4;
              if ((iVar2 != 0) && (iVar1 = name_cmp(name,DAT_000c909c), iVar1 != 0)) {
                ERR_put_error(0x22,0x75,0x75,DAT_000c90a0,0x226);
                ERR_add_error_data(2,DAT_000c90a4,name);
                return (GENERAL_NAME *)0x0;
              }
            }
          }
        }
      }
    }
    pGVar3 = a2i_GENERAL_NAME(out,method,ctx,iVar1,value,is_nc);
  }
  return pGVar3;
}

