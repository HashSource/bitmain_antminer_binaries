
void OPENSSL_cleanse(void *ptr,size_t len)

{
                    /* WARNING: Could not recover jumptable at 0x001343da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*memset_func)(ptr,0,len);
  return;
}

