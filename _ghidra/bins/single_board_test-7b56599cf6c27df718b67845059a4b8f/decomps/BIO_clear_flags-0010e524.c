
void BIO_clear_flags(BIO *b,int flags)

{
  b->retry_reason = b->retry_reason & ~flags;
  return;
}

