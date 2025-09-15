
void regen_hash(work *work)

{
  work *work_local;
  uchar hash1 [32];
  uchar swap [80];
  uint *swap32;
  uint *data32;
  
  flip80(swap,work);
  sha256(swap,0x50,hash1);
  sha256(hash1,0x20,work->hash);
  return;
}

