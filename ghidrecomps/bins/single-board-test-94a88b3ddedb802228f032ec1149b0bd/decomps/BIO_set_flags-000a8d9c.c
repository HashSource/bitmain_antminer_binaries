
void BIO_set_flags(BIO *b,int flags)

{
  b->flags = flags | b->flags;
  return;
}

