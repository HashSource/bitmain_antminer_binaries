
ulong BIO_number_read(BIO *bio)

{
  if (bio != (BIO *)0x0) {
    return (ulong)(bio->ex_data).sk;
  }
  return 0;
}

