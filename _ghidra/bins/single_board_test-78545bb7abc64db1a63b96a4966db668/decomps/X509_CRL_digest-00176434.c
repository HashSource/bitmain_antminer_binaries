
int X509_CRL_digest(X509_CRL *data,EVP_MD *type,uchar *md,uint *len)

{
  EVP_MD *pEVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  ASN1_INTEGER *pAVar4;
  int iVar5;
  
  pEVar1 = EVP_sha1();
  if ((type == pEVar1) && (((uint)data->meth_data & 0x180) == 0x100)) {
    if (len != (uint *)0x0) {
      *len = 0x14;
    }
    iVar2 = 1;
    iVar5 = data[1].idp_reasons;
    pAVar3 = data[1].crl_number;
    pAVar4 = data[1].base_crl_number;
    *(int *)md = data[1].idp_flags;
    *(int *)(md + 4) = iVar5;
    *(ASN1_INTEGER **)(md + 8) = pAVar3;
    *(ASN1_INTEGER **)(md + 0xc) = pAVar4;
    *(undefined4 *)(md + 0x10) = *(undefined4 *)data[1].sha1_hash;
  }
  else {
    iVar2 = ASN1_item_digest((ASN1_ITEM *)&X509_CRL_it,type,data,md,len);
  }
  return iVar2;
}

