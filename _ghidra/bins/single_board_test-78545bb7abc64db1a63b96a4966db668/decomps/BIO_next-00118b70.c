
BIO * BIO_next(BIO *b)

{
  if (b != (BIO *)0x0) {
    b = b->prev_bio;
  }
  return b;
}

