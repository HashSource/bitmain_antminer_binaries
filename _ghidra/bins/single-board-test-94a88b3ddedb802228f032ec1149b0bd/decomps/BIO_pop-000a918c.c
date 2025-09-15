
BIO * BIO_pop(BIO *b)

{
  bio_st *pbVar1;
  bio_st *pbVar2;
  
  if (b == (BIO *)0x0) {
    pbVar2 = (bio_st *)0x0;
  }
  else {
    pbVar2 = b->next_bio;
    BIO_ctrl(b,7,0,b);
    pbVar1 = b->prev_bio;
    if (pbVar1 != (bio_st *)0x0) {
      pbVar1->next_bio = b->next_bio;
    }
    if (b->next_bio != (bio_st *)0x0) {
      b->next_bio->prev_bio = pbVar1;
    }
    b->next_bio = (bio_st *)0x0;
    b->prev_bio = (bio_st *)0x0;
  }
  return pbVar2;
}

