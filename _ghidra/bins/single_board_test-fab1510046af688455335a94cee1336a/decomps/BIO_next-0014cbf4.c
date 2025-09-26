
BIO * BIO_next(BIO *b)

{
  if (b != (BIO *)0x0) {
    b = b->next_bio;
  }
  return b;
}

