
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_STORE * X509_STORE_new(void)

{
  X509_STORE *obj;
  _STACK *p_Var1;
  X509_VERIFY_PARAM *pXVar2;
  int iVar3;
  
  obj = (X509_STORE *)CRYPTO_malloc(0x48,DAT_000c3a80,0xba);
  if (obj != (X509_STORE *)0x0) {
    p_Var1 = sk_new(DAT_000c3a84);
    obj->objs = (stack_st_X509_OBJECT *)p_Var1;
    obj->cache = 1;
    p_Var1 = sk_new_null();
    obj->verify = (_func_1985 *)0x0;
    obj->get_cert_methods = (stack_st_X509_LOOKUP *)p_Var1;
    obj->verify_cb = (_func_1986 *)0x0;
    pXVar2 = X509_VERIFY_PARAM_new();
    obj->param = pXVar2;
    if (pXVar2 != (X509_VERIFY_PARAM *)0x0) {
      obj->get_issuer = (_func_1987 *)0x0;
      obj->check_issued = (_func_1988 *)0x0;
      obj->check_revocation = (_func_1989 *)0x0;
      obj->get_crl = (_func_1990 *)0x0;
      obj->check_crl = (_func_1991 *)0x0;
      obj->cert_crl = (_func_1992 *)0x0;
      obj->lookup_certs = (_func_1993 *)0x0;
      obj->lookup_crls = (_func_1994 *)0x0;
      obj->cleanup = (_func_1995 *)0x0;
      iVar3 = CRYPTO_new_ex_data(4,obj,&obj->ex_data);
      if (iVar3 != 0) {
        obj->references = 1;
        return obj;
      }
      sk_free(&obj->objs->stack);
      CRYPTO_free(obj);
      return (X509_STORE *)0x0;
    }
  }
  return (X509_STORE *)0x0;
}

