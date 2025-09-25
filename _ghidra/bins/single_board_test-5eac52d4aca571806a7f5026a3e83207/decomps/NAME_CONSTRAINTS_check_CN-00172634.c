
int NAME_CONSTRAINTS_check_CN(X509 *param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  size_t sVar3;
  byte *ptr;
  X509_NAME *name;
  X509_NAME_ENTRY *ne;
  ASN1_STRING *in;
  size_t __n;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  size_t sVar8;
  int lastpos;
  bool bVar9;
  byte *local_44;
  undefined4 local_40;
  size_t *local_3c;
  size_t local_38 [2];
  byte *local_30;
  undefined4 local_2c;
  
  lastpos = -1;
  name = X509_get_subject_name(param_1);
  local_40 = 2;
  local_3c = local_38;
  local_2c = 0;
  local_38[1] = 0x16;
  do {
    while( true ) {
      lastpos = X509_NAME_get_index_by_NID(name,0xd,lastpos);
      if (lastpos == -1) {
        return 0;
      }
      ne = X509_NAME_get_entry(name,lastpos);
      in = X509_NAME_ENTRY_get_data(ne);
      __n = ASN1_STRING_to_UTF8(&local_44,in);
      ptr = local_44;
      if ((int)__n < 0) {
        return 0x11;
      }
      if (__n != 0) break;
LAB_001726aa:
      pvVar4 = memchr(local_44,0,0);
      if (pvVar4 != (void *)0x0) {
LAB_001726b8:
        CRYPTO_free(ptr);
        return 0x35;
      }
LAB_00172736:
      CRYPTO_free(ptr);
    }
    sVar8 = __n - 1;
    pbVar7 = local_44 + sVar8;
    bVar1 = local_44[sVar8];
    while (sVar3 = sVar8, bVar1 == 0) {
      if (sVar3 == 0) goto LAB_001726aa;
      pbVar7 = pbVar7 + -1;
      sVar8 = sVar3 - 1;
      __n = sVar3;
      bVar1 = *pbVar7;
    }
    pvVar4 = memchr(local_44,0,__n);
    if (pvVar4 != (void *)0x0) goto LAB_001726b8;
    bVar2 = false;
    sVar8 = 0;
    pbVar7 = ptr;
    do {
      uVar6 = (uint)*pbVar7;
      if (0x19 < (uVar6 & 0xffffffdf) - 0x41) {
        bVar9 = 0x5e < uVar6;
        if (uVar6 != 0x5f) {
          bVar9 = 8 < uVar6 - 0x30;
        }
        if ((bVar9 && (uVar6 != 0x5f && uVar6 - 0x30 != 9)) &&
           (((sVar8 == 0 || ((int)(__n - 1) <= (int)sVar8)) ||
            ((uVar6 != 0x2d &&
             (((bVar2 = true, uVar6 != 0x2e || (bVar1 = pbVar7[1], bVar1 == 0x2e)) ||
              (pbVar7[-1] == 0x2d || bVar1 == 0x2d)))))))) goto LAB_00172736;
      }
      sVar8 = sVar8 + 1;
      pbVar7 = pbVar7 + 1;
    } while (sVar8 != __n);
    if (!bVar2) goto LAB_00172736;
    local_30 = ptr;
    local_38[0] = sVar8;
    iVar5 = nc_match(&local_40,param_2);
    CRYPTO_free(ptr);
    if (iVar5 != 0) {
      return iVar5;
    }
  } while( true );
}

