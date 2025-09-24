
int EVP_PBE_alg_add(int nid,EVP_CIPHER *cipher,EVP_MD *md,undefined1 *keygen)

{
  int md_nid;
  int iVar1;
  
  iVar1 = -1;
  if (cipher != (EVP_CIPHER *)0x0) {
    iVar1 = EVP_CIPHER_nid(cipher);
  }
  md_nid = -1;
  if (md != (EVP_MD *)0x0) {
    md_nid = EVP_MD_type(md);
  }
  iVar1 = EVP_PBE_alg_add_type(0,nid,iVar1,md_nid,keygen);
  return iVar1;
}

