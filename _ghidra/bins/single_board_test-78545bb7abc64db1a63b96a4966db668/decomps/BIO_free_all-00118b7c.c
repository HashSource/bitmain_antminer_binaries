
void BIO_free_all(BIO *a)

{
  bio_st *pbVar1;
  ulong uVar2;
  
  if (a == (BIO *)0x0) {
    return;
  }
  do {
    DataMemoryBarrier(0x1b);
    uVar2 = a->num_read;
    DataMemoryBarrier(0x1b);
    pbVar1 = a->prev_bio;
    BIO_free(a);
    if (1 < (int)uVar2) {
      return;
    }
    a = pbVar1;
  } while (pbVar1 != (bio_st *)0x0);
  return;
}

