
int EVP_EncodeBlock(uchar *t,uchar *f,int n)

{
  int iVar1;
  
  iVar1 = evp_encodeblock_int(0,t,f,n);
  return iVar1;
}

