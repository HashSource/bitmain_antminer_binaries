
ulong BIO_number_read(BIO *bio)

{
  if (bio != (BIO *)0x0) {
    bio = (BIO *)bio->num_read;
  }
  return (ulong)bio;
}

