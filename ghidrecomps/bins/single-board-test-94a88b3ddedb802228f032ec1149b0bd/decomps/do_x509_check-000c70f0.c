
char ** do_x509_check(X509 *param_1,char *param_2,size_t param_3,uint param_4,int param_5,
                     char **param_6)

{
  bool bVar1;
  char **ppcVar2;
  _STACK *a;
  int iVar3;
  int *piVar4;
  void *__s1;
  char *pcVar5;
  X509_NAME *name;
  X509_NAME_ENTRY *ne;
  ASN1_STRING *in;
  size_t sVar6;
  char **ppcVar7;
  int iVar8;
  size_t *psVar9;
  size_t sVar10;
  int nid;
  uint local_3c;
  code *local_34;
  uchar *local_2c [2];
  
  local_3c = param_4 & 0xffff7fff;
  if (param_5 == 1) {
    sVar10 = 0x16;
    nid = 0x30;
    local_34 = DAT_000c72b8;
  }
  else if (param_5 == 2) {
    if ((1 < param_3) && (*param_2 == '.')) {
      local_3c = local_3c | 0x8000;
    }
    sVar10 = 0x16;
    nid = 0xd;
    local_34 = DAT_000c72c0;
    if ((local_3c & 2) == 0) {
      local_34 = DAT_000c72bc;
    }
  }
  else {
    sVar10 = 4;
    nid = 0;
    local_34 = DAT_000c72b4;
  }
  if (param_3 == 0) {
    param_3 = strlen(param_2);
  }
  a = (_STACK *)X509_get_ext_d2i(param_1,0x55,(int *)0x0,(int *)0x0);
  if (a != (_STACK *)0x0) {
    bVar1 = false;
    for (iVar8 = 0; iVar3 = sk_num(a), iVar8 < iVar3; iVar8 = iVar8 + 1) {
      piVar4 = (int *)sk_value(a,iVar8);
      if (*piVar4 == param_5) {
        psVar9 = (size_t *)piVar4[1];
        __s1 = (void *)psVar9[2];
        if (((__s1 != (void *)0x0) && (sVar6 = *psVar9, sVar6 != 0)) && (sVar10 == psVar9[1])) {
          if (sVar10 == 0x16) {
            ppcVar7 = (char **)(*local_34)(__s1,sVar6,param_2,param_3,local_3c);
            ppcVar2 = param_6;
            if (param_6 != (char **)0x0) {
              ppcVar2 = ppcVar7;
            }
            if ((param_6 != (char **)0x0 && ppcVar7 != (char **)0x0) && -1 < (int)ppcVar2)
            goto LAB_000c7192;
            if (ppcVar7 != (char **)0x0) goto LAB_000c71a2;
          }
          else if ((sVar6 == param_3) && (iVar3 = memcmp(__s1,param_2,param_3), iVar3 == 0)) {
            ppcVar7 = (char **)0x1;
            if (param_6 == (char **)0x0) goto LAB_000c71a2;
LAB_000c7192:
            pcVar5 = BUF_strndup((char *)psVar9[2],*psVar9);
            *param_6 = pcVar5;
LAB_000c71a2:
            GENERAL_NAMES_free((GENERAL_NAMES *)a);
            return ppcVar7;
          }
        }
        bVar1 = true;
      }
    }
    GENERAL_NAMES_free((GENERAL_NAMES *)a);
    if (nid == 0) {
      return (char **)0x0;
    }
    if ((bVar1) && (-1 < (int)(local_3c << 0x1f))) {
      return (char **)0x0;
    }
  }
  iVar8 = -1;
  name = X509_get_subject_name(param_1);
  while( true ) {
    do {
      iVar8 = X509_NAME_get_index_by_NID(name,nid,iVar8);
      if (iVar8 < 0) {
        return (char **)0x0;
      }
      ne = X509_NAME_get_entry(name,iVar8);
      in = X509_NAME_ENTRY_get_data(ne);
    } while ((in->data == (uchar *)0x0) || (in->length == 0));
    sVar10 = ASN1_STRING_to_UTF8(local_2c,in);
    if ((int)sVar10 < 0) break;
    ppcVar7 = (char **)(*local_34)(local_2c[0],sVar10,param_2,param_3,local_3c);
    ppcVar2 = param_6;
    if (param_6 != (char **)0x0) {
      ppcVar2 = ppcVar7;
    }
    if ((param_6 != (char **)0x0 && ppcVar7 != (char **)0x0) && -1 < (int)ppcVar2) {
      pcVar5 = BUF_strndup((char *)local_2c[0],sVar10);
      *param_6 = pcVar5;
      CRYPTO_free(local_2c[0]);
      return ppcVar7;
    }
    CRYPTO_free(local_2c[0]);
    if (ppcVar7 != (char **)0x0) {
      return ppcVar7;
    }
  }
  return (char **)0xffffffff;
}

