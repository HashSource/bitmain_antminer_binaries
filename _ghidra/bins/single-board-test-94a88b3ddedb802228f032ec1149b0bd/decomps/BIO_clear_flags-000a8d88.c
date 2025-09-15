
void BIO_clear_flags(BIO *b,int flags)

{
  b->flags = b->flags & ~flags;
  return;
}

