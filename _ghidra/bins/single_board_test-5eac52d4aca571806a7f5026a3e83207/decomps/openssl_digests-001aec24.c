
int openssl_digests(undefined4 param_1,int *param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  EVP_MD *pEVar3;
  
  if (param_2 == (int *)0x0) {
    iVar1 = pos_23967;
    if (init_23968 == 0) {
      pEVar3 = sha1_md;
      if ((sha1_md == (EVP_MD *)0x0) &&
         ((((pEVar3 = (EVP_MD *)EVP_MD_meth_new(0x40,0x41), pEVar3 == (EVP_MD *)0x0 ||
            (iVar1 = EVP_MD_meth_set_result_size(pEVar3,0x14), iVar1 == 0)) ||
           (iVar1 = EVP_MD_meth_set_input_blocksize(pEVar3,0x40), iVar1 == 0)) ||
          (((iVar1 = EVP_MD_meth_set_app_datasize(pEVar3,100), iVar1 == 0 ||
            (iVar1 = EVP_MD_meth_set_flags(pEVar3,0), iVar1 == 0)) ||
           ((iVar1 = EVP_MD_meth_set_init(pEVar3,0x1ae9bd), iVar1 == 0 ||
            ((iVar1 = EVP_MD_meth_set_update(pEVar3,0x1ae9a5), iVar1 == 0 ||
             (iVar1 = EVP_MD_meth_set_final(pEVar3,0x1ae991), iVar1 == 0)))))))))) {
        EVP_MD_meth_free(pEVar3);
        sha1_md = (EVP_MD *)0x0;
      }
      else {
        sha1_md = pEVar3;
        iVar1 = pos_23967 * 4;
        pos_23967 = pos_23967 + 1;
        iVar2 = EVP_MD_type(sha1_md);
        *(int *)((int)&digest_nids_23966 + iVar1) = iVar2;
      }
      iVar1 = pos_23967;
      init_23968 = 1;
      *(undefined4 *)((int)&digest_nids_23966 + pos_23967 * 4) = 0;
    }
    *param_3 = &digest_nids_23966;
  }
  else if (param_4 == 0x40) {
    pEVar3 = sha1_md;
    if ((sha1_md == (EVP_MD *)0x0) &&
       (((((pEVar3 = (EVP_MD *)EVP_MD_meth_new(0x40,0x41), pEVar3 == (EVP_MD *)0x0 ||
           (iVar1 = EVP_MD_meth_set_result_size(pEVar3,0x14), iVar1 == 0)) ||
          (iVar1 = EVP_MD_meth_set_input_blocksize(pEVar3,0x40), iVar1 == 0)) ||
         ((iVar1 = EVP_MD_meth_set_app_datasize(pEVar3,100), iVar1 == 0 ||
          (iVar1 = EVP_MD_meth_set_flags(pEVar3,0), iVar1 == 0)))) ||
        ((iVar1 = EVP_MD_meth_set_init(pEVar3,0x1ae9bd), iVar1 == 0 ||
         ((iVar1 = EVP_MD_meth_set_update(pEVar3,0x1ae9a5), iVar1 == 0 ||
          (iVar1 = EVP_MD_meth_set_final(pEVar3,0x1ae991), iVar1 == 0)))))))) {
      EVP_MD_meth_free(pEVar3);
      pEVar3 = (EVP_MD *)0x0;
    }
    sha1_md = pEVar3;
    *param_2 = (int)sha1_md;
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
    *param_2 = 0;
  }
  return iVar1;
}

