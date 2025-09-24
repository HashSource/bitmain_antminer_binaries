
void BIO_set_flags(BIO *b,int flags)

{
  b->retry_reason = flags | b->retry_reason;
  return;
}

