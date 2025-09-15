
void sha2(uchar *input,int ilen,uchar *output)

{
  uchar *output_local;
  int ilen_local;
  uchar *input_local;
  sha2_context ctx;
  
  sha2_starts(&ctx);
  sha2_update(&ctx,input,ilen);
  sha2_finish(&ctx,output);
  memset(&ctx,0,0xe8);
  return;
}

