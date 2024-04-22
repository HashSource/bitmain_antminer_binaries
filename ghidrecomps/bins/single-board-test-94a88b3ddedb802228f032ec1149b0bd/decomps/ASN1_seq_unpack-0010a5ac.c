
stack_st_OPENSSL_BLOCK * ASN1_seq_unpack(uchar *buf,int len,undefined1 *d2i,free_func *free_func)

{
  stack_st_OPENSSL_BLOCK *psVar1;
  uchar *local_1c [2];
  
  local_1c[0] = buf;
  psVar1 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,local_1c,len,d2i,free_func,0x10,0);
  if (psVar1 == (stack_st_OPENSSL_BLOCK *)0x0) {
    ERR_put_error(0xd,0x7f,0x6e,DAT_0010a5ec,0x4f);
  }
  return psVar1;
}

