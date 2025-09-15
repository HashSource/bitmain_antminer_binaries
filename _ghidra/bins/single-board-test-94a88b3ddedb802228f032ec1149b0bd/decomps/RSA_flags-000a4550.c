
int RSA_flags(RSA *r)

{
  if (r != (RSA *)0x0) {
    r = (RSA *)r->meth->flags;
  }
  return (int)r;
}

