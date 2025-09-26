
int BIO_get_retry_reason(BIO *bio)

{
  return bio->num;
}

