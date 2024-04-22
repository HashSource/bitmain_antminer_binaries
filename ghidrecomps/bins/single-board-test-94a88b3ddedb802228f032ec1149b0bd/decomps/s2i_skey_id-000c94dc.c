
ASN1_STRING * s2i_skey_id(undefined4 param_1,int *param_2,char *param_3)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  EVP_MD *type;
  uchar *puVar3;
  size_t *psVar4;
  void *data;
  size_t count;
  int local_58;
  uint local_54;
  uchar auStack_50 [64];
  
  iVar1 = strcmp(param_3,DAT_000c95d4);
  if (iVar1 != 0) {
    pAVar2 = ASN1_STRING_type_new(4);
    if (pAVar2 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x22,0x70,0x41,DAT_000c95d8,0x57);
      return (ASN1_STRING *)0x0;
    }
    puVar3 = string_to_hex(param_3,&local_58);
    pAVar2->data = puVar3;
    if (puVar3 != (uchar *)0x0) {
      pAVar2->length = local_58;
      return pAVar2;
    }
    ASN1_STRING_free(pAVar2);
    return (ASN1_STRING *)0x0;
  }
  pAVar2 = ASN1_STRING_type_new(4);
  if (pAVar2 == (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x73,0x41,DAT_000c95d8,0x72);
    return (ASN1_STRING *)0x0;
  }
  if (param_2 == (int *)0x0) {
LAB_000c95b2:
    iVar1 = 0x7a;
  }
  else {
    if (*param_2 == 1) {
      return pAVar2;
    }
    if ((int *)param_2[3] == (int *)0x0) {
      if ((int *)param_2[2] == (int *)0x0) goto LAB_000c95b2;
      psVar4 = *(size_t **)(*(int *)(*(int *)param_2[2] + 0x18) + 4);
    }
    else {
      psVar4 = *(size_t **)(*(int *)(*(int *)param_2[3] + 0x14) + 4);
    }
    if (psVar4 != (size_t *)0x0) {
      data = (void *)psVar4[2];
      count = *psVar4;
      type = EVP_sha1();
      iVar1 = EVP_Digest(data,count,auStack_50,&local_54,type,(ENGINE *)0x0);
      if (iVar1 != 0) {
        iVar1 = ASN1_STRING_set(pAVar2,auStack_50,local_54);
        if (iVar1 != 0) {
          return pAVar2;
        }
        ERR_put_error(0x22,0x73,0x41,DAT_000c95d8,0x8d);
      }
      goto LAB_000c9578;
    }
    iVar1 = 0x84;
  }
  ERR_put_error(0x22,0x73,0x72,DAT_000c95d8,iVar1);
LAB_000c9578:
  ASN1_STRING_free(pAVar2);
  return (ASN1_STRING *)0x0;
}

