
long TXT_DB_write(BIO *out,TXT_DB *db)

{
  BUF_MEM *str;
  int iVar1;
  undefined4 *puVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  size_t len;
  undefined4 *puVar7;
  int iVar9;
  int iVar10;
  int iVar11;
  int len_00;
  undefined4 *puVar8;
  
  str = BUF_MEM_new();
  if (str != (BUF_MEM *)0x0) {
    iVar10 = 0;
    iVar1 = OPENSSL_sk_num(db->data);
    len = db->num_fields;
    if (0 < iVar1) {
      iVar9 = 0;
      do {
        puVar2 = (undefined4 *)OPENSSL_sk_value(db->data,iVar9);
        if ((int)len < 1) {
          iVar11 = BUF_MEM_grow_clean(str,len);
          if (iVar11 == 0) goto LAB_00160630;
          pcVar5 = str->data;
        }
        else {
          iVar11 = 0;
          puVar7 = puVar2;
          do {
            puVar8 = puVar7 + 1;
            if ((char *)*puVar7 != (char *)0x0) {
              sVar3 = strlen((char *)*puVar7);
              iVar11 = iVar11 + sVar3;
            }
            puVar7 = puVar8;
          } while (puVar2 + len != puVar8);
          iVar11 = BUF_MEM_grow_clean(str,len + iVar11 * 2);
          if (iVar11 == 0) goto LAB_00160630;
          pcVar5 = str->data;
          puVar7 = puVar2;
          do {
            puVar8 = puVar7 + 1;
            pcVar4 = (char *)*puVar7;
            if (pcVar4 != (char *)0x0) {
              cVar6 = *pcVar4;
              while (cVar6 != '\0') {
                if (cVar6 == '\t') {
                  *pcVar5 = '\\';
                  pcVar5 = pcVar5 + 1;
                  cVar6 = *pcVar4;
                }
                *pcVar5 = cVar6;
                pcVar4 = pcVar4 + 1;
                pcVar5 = pcVar5 + 1;
                cVar6 = *pcVar4;
              }
            }
            *pcVar5 = '\t';
            pcVar5 = pcVar5 + 1;
            puVar7 = puVar8;
          } while (puVar2 + len != puVar8);
        }
        pcVar5[-1] = '\n';
        len_00 = (int)pcVar5 - (int)str->data;
        iVar11 = BIO_write(out,str->data,len_00);
        if (len_00 != iVar11) goto LAB_00160630;
        iVar9 = iVar9 + 1;
        iVar10 = iVar10 + len_00;
      } while (iVar9 != iVar1);
    }
    BUF_MEM_free(str);
    return iVar10;
  }
LAB_00160630:
  BUF_MEM_free(str);
  return -1;
}

