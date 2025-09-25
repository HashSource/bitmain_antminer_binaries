
int X509V3_EXT_add_nconf_sk(CONF *conf,X509V3_CTX *ctx,char *section,stack_st_X509_EXTENSION **sk)

{
  stack_st_CONF_VALUE *psVar1;
  int iVar2;
  X509_EXTENSION *ex;
  ASN1_OBJECT *obj;
  X509_EXTENSION *a;
  stack_st_X509_EXTENSION *psVar3;
  int iVar4;
  
  psVar1 = NCONF_get_section(conf,section);
  if (psVar1 != (stack_st_CONF_VALUE *)0x0) {
    iVar4 = 0;
    while( true ) {
      iVar2 = OPENSSL_sk_num(psVar1);
      if (iVar2 <= iVar4) {
        return 1;
      }
      iVar2 = OPENSSL_sk_value(psVar1,iVar4);
      ex = X509V3_EXT_nconf(conf,ctx,*(char **)(iVar2 + 4),*(char **)(iVar2 + 8));
      if (ex == (X509_EXTENSION *)0x0) break;
      if (ctx->flags == 2) {
        psVar3 = *sk;
        obj = X509_EXTENSION_get_object(ex);
        while (iVar2 = X509v3_get_ext_by_OBJ(psVar3,obj,-1), -1 < iVar2) {
          a = X509v3_get_ext(psVar3,iVar2);
          X509v3_delete_ext(psVar3,iVar2);
          X509_EXTENSION_free(a);
        }
        psVar3 = X509v3_add_ext(sk,ex,-1);
joined_r0x0016f5c6:
        if (psVar3 == (stack_st_X509_EXTENSION *)0x0) {
          X509_EXTENSION_free(ex);
          return 0;
        }
      }
      else if (sk != (stack_st_X509_EXTENSION **)0x0) {
        psVar3 = X509v3_add_ext(sk,ex,-1);
        goto joined_r0x0016f5c6;
      }
      iVar4 = iVar4 + 1;
      X509_EXTENSION_free(ex);
    }
  }
  return 0;
}

