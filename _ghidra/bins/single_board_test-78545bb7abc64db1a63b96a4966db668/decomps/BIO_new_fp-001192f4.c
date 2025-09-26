
BIO * BIO_new_fp(FILE *stream,int close_flag)

{
  BIO_METHOD *type;
  BIO *b;
  
  type = BIO_s_file();
  b = BIO_new(type);
  if (b != (BIO *)0x0) {
    BIO_set_flags(b,0);
    BIO_ctrl(b,0x6a,close_flag,stream);
  }
  return b;
}

