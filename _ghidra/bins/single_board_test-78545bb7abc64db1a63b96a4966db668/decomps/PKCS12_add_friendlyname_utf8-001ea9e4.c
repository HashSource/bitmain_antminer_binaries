
stack_st_X509_ATTRIBUTE * PKCS12_add_friendlyname_utf8(int param_1,uchar *param_2,int param_3)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_NID
                     ((stack_st_X509_ATTRIBUTE **)(param_1 + 8),0x9c,0x1000,param_2,param_3);
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar1 = (stack_st_X509_ATTRIBUTE *)0x1;
  }
  return psVar1;
}

