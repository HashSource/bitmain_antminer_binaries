
BIO * BIO_push(BIO *b,BIO *append)

{
  BIO *pBVar1;
  BIO *parg;
  
  pBVar1 = b;
  if (b != (BIO *)0x0) {
    do {
      parg = pBVar1;
      pBVar1 = parg->next_bio;
    } while (parg->next_bio != (bio_st *)0x0);
    parg->next_bio = append;
    if (append != (BIO *)0x0) {
      append->prev_bio = parg;
    }
    BIO_ctrl(b,6,0,parg);
    append = b;
  }
  return append;
}

