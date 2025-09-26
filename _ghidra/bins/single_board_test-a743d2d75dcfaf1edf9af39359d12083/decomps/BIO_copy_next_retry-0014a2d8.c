
void BIO_copy_next_retry(BIO *b)

{
  uint uVar1;
  
  uVar1 = b->next_bio->flags;
  b->retry_reason = b->next_bio->retry_reason;
  b->flags = b->flags | uVar1 & 0xf;
  return;
}

