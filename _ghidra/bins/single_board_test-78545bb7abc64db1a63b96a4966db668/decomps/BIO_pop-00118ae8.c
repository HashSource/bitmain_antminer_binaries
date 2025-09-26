
BIO * BIO_pop(BIO *b)

{
  int iVar1;
  bio_st *pbVar2;
  
  if (b != (BIO *)0x0) {
    pbVar2 = b->prev_bio;
    BIO_ctrl(b,7,0,b);
    iVar1 = b->references;
    if (iVar1 != 0) {
      *(bio_st **)(iVar1 + 0x28) = b->prev_bio;
    }
    if (b->prev_bio != (bio_st *)0x0) {
      b->prev_bio->references = iVar1;
    }
    b->prev_bio = (bio_st *)0x0;
    b->references = 0;
    return pbVar2;
  }
  return (BIO *)0x0;
}

