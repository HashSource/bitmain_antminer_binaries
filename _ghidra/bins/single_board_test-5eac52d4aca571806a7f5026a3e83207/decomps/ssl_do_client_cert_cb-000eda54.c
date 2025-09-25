
int ssl_do_client_cert_cb(SSL *param_1,X509 **param_2,EVP_PKEY **param_3)

{
  stack_st_X509_NAME *ca_dn;
  int iVar1;
  SSL_METHOD *pSVar2;
  ENGINE *e;
  
  pSVar2 = param_1[3].method;
  e = (ENGINE *)pSVar2[2].ssl_dispatch_alert;
  if (e != (ENGINE *)0x0) {
    ca_dn = SSL_get_client_CA_list(param_1);
    iVar1 = ENGINE_load_ssl_client_cert
                      (e,param_1,ca_dn,param_2,param_3,(stack_st_X509 **)0x0,(UI_METHOD *)0x0,
                       (void *)0x0);
    if (iVar1 != 0) {
      return iVar1;
    }
    pSVar2 = param_1[3].method;
  }
  if (pSVar2[1].ssl_new == (_func_3195 *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000eda9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*pSVar2[1].ssl_new)(param_1);
  return iVar1;
}

