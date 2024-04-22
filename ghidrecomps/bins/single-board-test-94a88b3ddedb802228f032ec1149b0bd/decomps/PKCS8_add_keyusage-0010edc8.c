
int PKCS8_add_keyusage(PKCS8_PRIV_KEY_INFO *p8,int usage)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  uchar local_9 [9];
  
  local_9[0] = (uchar)usage;
  psVar1 = X509at_add1_attr_by_NID(&p8->attributes,0x53,3,local_9,1);
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar1 = (stack_st_X509_ATTRIBUTE *)0x1;
  }
  return (int)psVar1;
}

