
void X509_VERIFY_PARAM_set1_ip_asc(undefined4 param_1,char *param_2)

{
  int iVar1;
  uchar auStack_20 [20];
  
  iVar1 = a2i_ipadd(auStack_20,param_2);
  if (iVar1 != 0) {
    X509_VERIFY_PARAM_set1_ip(param_1,auStack_20,iVar1);
  }
  return;
}

