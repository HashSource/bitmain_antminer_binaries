
int cms_DigestAlgorithm_find_ctx(EVP_MD_CTX *param_1,BIO *param_2,X509_ALGOR *param_3)

{
  int iVar1;
  EVP_MD *pEVar2;
  int iVar3;
  BIO *bp;
  ASN1_OBJECT *local_18;
  EVP_MD_CTX *local_14;
  
  X509_ALGOR_get0(&local_18,(int *)0x0,(void **)0x0,param_3);
  iVar1 = OBJ_obj2nid(local_18);
  while( true ) {
    bp = BIO_find_type(param_2,0x208);
    if (bp == (BIO *)0x0) {
      ERR_put_error(0x2e,0x73,0x83,DAT_0010fa84,0x188);
      return 0;
    }
    BIO_ctrl(bp,0x78,0,&local_14);
    pEVar2 = EVP_MD_CTX_md(local_14);
    iVar3 = EVP_MD_type(pEVar2);
    if (iVar3 == iVar1) break;
    pEVar2 = EVP_MD_CTX_md(local_14);
    iVar3 = EVP_MD_pkey_type(pEVar2);
    if (iVar3 == iVar1) break;
    param_2 = BIO_next(bp);
  }
  iVar1 = EVP_MD_CTX_copy_ex(param_1,local_14);
  return iVar1;
}

