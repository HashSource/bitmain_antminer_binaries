
BIO * BIO_find_type(BIO *b,int bio_type)

{
  if (b != (BIO *)0x0) {
    if ((bio_type & 0xffU) == 0) {
      do {
        if ((b->method != (BIO_METHOD *)0x0) && ((bio_type & b->method->type) != 0)) {
          return b;
        }
        b = b->next_bio;
      } while (b != (bio_st *)0x0);
    }
    else {
      while ((b->method == (BIO_METHOD *)0x0 || (b->method->type != bio_type))) {
        b = b->next_bio;
        if (b == (bio_st *)0x0) {
          return (BIO *)0x0;
        }
      }
    }
  }
  return b;
}

