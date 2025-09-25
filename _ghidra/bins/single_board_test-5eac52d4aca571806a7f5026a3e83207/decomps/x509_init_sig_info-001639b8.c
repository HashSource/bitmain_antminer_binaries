
void x509_init_sig_info(int param_1)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  char *name;
  EVP_MD *md;
  int local_10;
  int local_c;
  
  *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)(param_1 + 0x48));
  iVar1 = OBJ_find_sigid_algs(iVar1,&local_c,&local_10);
  if ((iVar1 != 0) && (local_10 != 0)) {
    *(int *)(param_1 + 100) = local_10;
    if (local_c == 0) {
      pEVar2 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_10);
      if (((pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) && (*(code **)(pEVar2 + 0x70) != (code *)0x0)) &&
         (iVar1 = (**(code **)(pEVar2 + 0x70))(param_1 + 0x60,param_1 + 0x48,param_1 + 0x50),
         iVar1 != 0)) {
        *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
      }
    }
    else {
      *(int *)(param_1 + 0x60) = local_c;
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
      name = OBJ_nid2sn(local_c);
      md = EVP_get_digestbyname(name);
      if (md != (EVP_MD *)0x0) {
        iVar1 = EVP_MD_size(md);
        *(int *)(param_1 + 0x68) = iVar1 << 2;
        if ((local_c == 0x40) || ((0x3f < local_c && (local_c - 0x2a0U < 3)))) {
          *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 2;
        }
      }
    }
  }
  return;
}

