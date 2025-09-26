
_STACK * v2i_issuer_alt(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  GENERAL_NAME *data;
  int iVar1;
  CONF_VALUE *cnf;
  X509_EXTENSION *ext;
  _STACK *p_Var2;
  void *data_00;
  int iVar3;
  int iVar4;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x99,0x41,"v3_alt.c",0xf7);
  }
  else {
    for (iVar4 = 0; iVar1 = sk_num(param_3), iVar4 < iVar1; iVar4 = iVar4 + 1) {
      cnf = (CONF_VALUE *)sk_value(param_3,iVar4);
      iVar1 = name_cmp(cnf->name,"issuer");
      if (((iVar1 == 0) && (cnf->value != (char *)0x0)) &&
         (iVar1 = strcmp(cnf->value,"copy"), iVar1 == 0)) {
        if (param_2 == (X509V3_CTX *)0x0) {
LAB_00169cea:
          ERR_put_error(0x22,0x7b,0x7f,"v3_alt.c",0x118);
LAB_00169cfc:
          sk_pop_free(st,(func *)0x169121);
          return (_STACK *)0x0;
        }
        if (param_2->flags != 1) {
          if (param_2->issuer_cert == (X509 *)0x0) goto LAB_00169cea;
          iVar1 = X509_get_ext_by_NID(param_2->issuer_cert,0x55,-1);
          if (-1 < iVar1) {
            ext = X509_get_ext(param_2->issuer_cert,iVar1);
            if ((ext == (X509_EXTENSION *)0x0) ||
               (p_Var2 = (_STACK *)X509V3_EXT_d2i(ext), p_Var2 == (_STACK *)0x0)) {
              ERR_put_error(0x22,0x7b,0x7e,"v3_alt.c",0x120);
              goto LAB_00169cfc;
            }
            iVar1 = 0;
            while( true ) {
              iVar3 = sk_num(p_Var2);
              if (iVar3 <= iVar1) break;
              data_00 = sk_value(p_Var2,iVar1);
              iVar3 = sk_push(st,data_00);
              iVar1 = iVar1 + 1;
              if (iVar3 == 0) {
                ERR_put_error(0x22,0x7b,0x41,"v3_alt.c",0x127);
                goto LAB_00169cfc;
              }
            }
            sk_free(p_Var2);
          }
        }
      }
      else {
        data = v2i_GENERAL_NAME_ex((GENERAL_NAME *)0x0,param_1,param_2,cnf,0);
        if (data == (GENERAL_NAME *)0x0) goto LAB_00169cfc;
        sk_push(st,data);
      }
    }
  }
  return st;
}

