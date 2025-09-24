
undefined4 alg_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  char *section;
  stack_st_CONF_VALUE *psVar1;
  int iVar2;
  CONF_VALUE *value;
  int iVar3;
  int local_24;
  
  section = CONF_imodule_get_value(param_1);
  psVar1 = NCONF_get_section(param_2,section);
  if (psVar1 == (stack_st_CONF_VALUE *)0x0) {
    ERR_put_error(6,0xb1,0xa5,"crypto/evp/evp_cnf.c",0x1c);
  }
  else {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = OPENSSL_sk_num(psVar1);
        if (iVar2 <= iVar3) {
          return 1;
        }
        value = (CONF_VALUE *)OPENSSL_sk_value(psVar1,iVar3);
        iVar2 = strcmp(value->name,"fips_mode");
        if (iVar2 == 0) break;
        ERR_put_error(6,0xb1,0xa9,"crypto/evp/evp_cnf.c",0x2c);
        ERR_add_error_data(4,"name=",value->name,", value=",value->value);
        iVar3 = iVar3 + 1;
      }
      iVar2 = X509V3_get_value_bool(value,&local_24);
      if (iVar2 == 0) {
        ERR_put_error(6,0xb1,0xa8,"crypto/evp/evp_cnf.c",0x24);
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (local_24 < 1);
    ERR_put_error(6,0xb1,0xa7,"crypto/evp/evp_cnf.c",0x28);
  }
  return 0;
}

