
int BIO_test_flags(BIO *b,int flags)

{
  return b->retry_reason & flags;
}

