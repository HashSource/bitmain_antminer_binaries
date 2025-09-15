
void sha256(uchar *message,uint len,uchar *digest)

{
  uchar *digest_local;
  uint len_local;
  uchar *message_local;
  sha256_ctx ctx;
  
  sha256_init(&ctx);
  sha256_update(&ctx,message,len);
  sha256_final(&ctx,digest);
  return;
}

