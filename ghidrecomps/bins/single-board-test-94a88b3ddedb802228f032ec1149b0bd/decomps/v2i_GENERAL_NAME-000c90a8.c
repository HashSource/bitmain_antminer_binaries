
GENERAL_NAME * v2i_GENERAL_NAME(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf)

{
  GENERAL_NAME *pGVar1;
  
  pGVar1 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)0x0,method,ctx,cnf,0);
  return pGVar1;
}

