
ulong BIO_number_written(BIO *bio)

{
  if (bio != (BIO *)0x0) {
    bio = (BIO *)bio->num_write;
  }
  return (ulong)bio;
}

