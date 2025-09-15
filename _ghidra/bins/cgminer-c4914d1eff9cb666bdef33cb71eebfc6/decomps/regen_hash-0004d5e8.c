
void regen_hash(work *work)

{
  work *work_local;
  uchar hash1 [32];
  uchar swap [80];
  uint32_t *swap32;
  uint32_t *data32;
  
  flip80(swap,work);
  sha256(swap,0x50,hash1);
  sha256(hash1,0x20,work->hash);
  return;
}

