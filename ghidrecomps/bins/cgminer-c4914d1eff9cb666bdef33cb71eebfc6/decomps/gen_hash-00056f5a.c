
void gen_hash(uchar *data,uchar *hash,int len)

{
  int len_local;
  uchar *hash_local;
  uchar *data_local;
  uchar hash1 [32];
  
  sha256(data,len,hash1);
  sha256(hash1,0x20,hash);
  return;
}

