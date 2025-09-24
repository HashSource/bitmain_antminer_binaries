
ulong BIO_number_written(BIO *bio)

{
  if (bio != (BIO *)0x0) {
    return (ulong)bio[1].method;
  }
  return 0;
}

