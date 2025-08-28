
int EVP_MD_size(EVP_MD *md)

{
  int iVar1;
  
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(6,0xa2,0x9f,"evp_lib.c",0x121);
    iVar1 = -1;
  }
  else {
    iVar1 = md->md_size;
  }
  return iVar1;
}

