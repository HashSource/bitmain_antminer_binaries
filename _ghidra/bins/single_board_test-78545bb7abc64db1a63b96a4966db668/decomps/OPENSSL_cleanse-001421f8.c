
void OPENSSL_cleanse(void *ptr,size_t len)

{
                    /* WARNING: Could not recover jumptable at 0x00142202. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*memset_func)(ptr,0,len);
  return;
}

