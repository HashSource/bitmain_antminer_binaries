
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIO_METHOD * BIO_s_mem(void)

{
  return (BIO_METHOD *)&mem_method;
}

