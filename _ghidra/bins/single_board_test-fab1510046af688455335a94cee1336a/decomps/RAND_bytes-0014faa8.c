
int RAND_bytes(uchar *buf,int num)

{
  int iVar1;
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_0014fab4;
      ENGINE_finish(e);
    }
    default_RAND_meth = RAND_SSLeay();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) {
      return -1;
    }
  }
LAB_0014fab4:
  funct_ref = e;
  if (default_RAND_meth->bytes == (_func_3913 *)0x0) {
    return -1;
  }
  iVar1 = (*default_RAND_meth->bytes)(buf,num);
  return iVar1;
}

