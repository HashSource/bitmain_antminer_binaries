
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  int iVar1;
  
  iVar1 = evp_decodeblock_int(0,t,f,n);
  return iVar1;
}

