
int EVP_Digest(void *data,size_t count,uchar *md,uint *size,EVP_MD *type,ENGINE *impl)

{
  int iVar1;
  EVP_MD_CTX local_38;
  
  local_38.digest = (EVP_MD *)0x0;
  local_38.engine = (ENGINE *)0x0;
  local_38.flags = 0;
  local_38.md_data = (void *)0x0;
  local_38.pctx = (EVP_PKEY_CTX *)0x0;
  local_38.update = (_func_1230 *)0x0;
  EVP_MD_CTX_set_flags(&local_38,1);
  iVar1 = EVP_DigestInit_ex(&local_38,type,impl);
  if ((iVar1 == 0) || (iVar1 = (*local_38.update)(&local_38,data,count), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    if (0x40 < (local_38.digest)->md_size) {
      OpenSSLDie(DAT_000ae970,0x115,DAT_000ae974);
    }
    iVar1 = (*(local_38.digest)->final)(&local_38,md);
    if (size != (uint *)0x0) {
      *size = (local_38.digest)->md_size;
    }
    if ((local_38.digest)->cleanup != (_func_1224 *)0x0) {
      (*(local_38.digest)->cleanup)(&local_38);
      EVP_MD_CTX_set_flags(&local_38,2);
    }
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    memset(local_38.md_data,0,(local_38.digest)->ctx_size);
  }
  EVP_MD_CTX_cleanup(&local_38);
  return iVar1;
}

