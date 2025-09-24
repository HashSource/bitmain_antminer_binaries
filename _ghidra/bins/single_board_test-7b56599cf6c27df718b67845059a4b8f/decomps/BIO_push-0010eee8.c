
BIO * BIO_push(BIO *b,BIO *append)

{
  BIO *pBVar1;
  BIO *parg;
  
  pBVar1 = b;
  if (b == (BIO *)0x0) {
    return append;
  }
  do {
    parg = pBVar1;
    pBVar1 = parg->prev_bio;
  } while (parg->prev_bio != (bio_st *)0x0);
  parg->prev_bio = append;
  if (append != (BIO *)0x0) {
    append->references = (int)parg;
  }
  BIO_ctrl(b,6,0,parg);
  return b;
}

