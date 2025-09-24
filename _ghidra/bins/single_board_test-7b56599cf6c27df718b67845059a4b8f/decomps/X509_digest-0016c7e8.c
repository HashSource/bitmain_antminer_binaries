
int X509_digest(X509 *data,EVP_MD *type,uchar *md,uint *len)

{
  EVP_MD *pEVar1;
  int iVar2;
  stack_st_GENERAL_NAME *psVar3;
  NAME_CONSTRAINTS *pNVar4;
  stack_st_DIST_POINT *psVar5;
  
  pEVar1 = EVP_sha1();
  if ((type == pEVar1) && ((data[1].references & 0x100100U) == 0x100)) {
    if (len != (uint *)0x0) {
      *len = 0x14;
    }
    iVar2 = 1;
    psVar5 = data[1].crldp;
    psVar3 = data[1].altname;
    pNVar4 = data[1].nc;
    *(X509_POLICY_CACHE **)md = data[1].policy_cache;
    *(stack_st_DIST_POINT **)(md + 4) = psVar5;
    *(stack_st_GENERAL_NAME **)(md + 8) = psVar3;
    *(NAME_CONSTRAINTS **)(md + 0xc) = pNVar4;
    *(stack_st_IPAddressFamily **)(md + 0x10) = data[1].rfc3779_addr;
  }
  else {
    iVar2 = ASN1_item_digest((ASN1_ITEM *)&X509_it,type,data,md,len);
  }
  return iVar2;
}

