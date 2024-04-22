
BIO * BIO_new_fp(FILE *stream,int close_flag)

{
  BIO *b;
  
  b = BIO_new(DAT_000a9b98);
  if (b != (BIO *)0x0) {
    BIO_set_flags(b,0);
    BIO_ctrl(b,0x6a,close_flag,stream);
  }
  return b;
}

