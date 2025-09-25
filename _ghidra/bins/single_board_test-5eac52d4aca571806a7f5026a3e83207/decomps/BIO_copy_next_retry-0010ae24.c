
void BIO_copy_next_retry(BIO *b)

{
  int flags;
  
  flags = BIO_test_flags(b->prev_bio,0xf);
  BIO_set_flags(b,flags);
  b->num = b->prev_bio->num;
  return;
}

