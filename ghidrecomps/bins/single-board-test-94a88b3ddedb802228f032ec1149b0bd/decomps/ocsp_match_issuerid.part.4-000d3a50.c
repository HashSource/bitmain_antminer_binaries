
int ocsp_match_issuerid_part_4(X509 *param_1,undefined4 *param_2)

{
  int iVar1;
  char *name;
  EVP_MD *md;
  size_t __n;
  X509_NAME *data;
  uint uVar2;
  uchar auStack_58 [68];
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)*param_2);
  name = OBJ_nid2sn(iVar1);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x27,0x6d,0x77,DAT_000d3af0,0x13f);
    return -1;
  }
  __n = EVP_MD_size(md);
  if ((int)__n < 0) {
LAB_000d3ad0:
    iVar1 = -1;
  }
  else {
    if ((__n == *(size_t *)param_2[1]) && (__n == *(size_t *)param_2[2])) {
      data = X509_get_subject_name(param_1);
      iVar1 = X509_NAME_digest(data,md,auStack_58,(uint *)0x0);
      if (iVar1 == 0) goto LAB_000d3ad0;
      iVar1 = memcmp(auStack_58,*(void **)(param_2[1] + 8),__n);
      if (iVar1 == 0) {
        X509_pubkey_digest(param_1,md,auStack_58,(uint *)0x0);
        uVar2 = memcmp(auStack_58,*(void **)(param_2[2] + 8),__n);
        if (uVar2 < 2) {
          return 1 - uVar2;
        }
        return 0;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

