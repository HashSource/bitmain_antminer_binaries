
long TXT_DB_write(BIO *out,TXT_DB *db)

{
  BUF_MEM *str;
  int iVar1;
  undefined4 *puVar2;
  size_t sVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int len;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int local_3c;
  
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    local_3c = -1;
  }
  else {
    iVar1 = sk_num(&db->data->stack);
    iVar5 = db->num_fields;
    if (iVar1 < 1) {
      local_3c = 0;
    }
    else {
      iVar9 = 0;
      local_3c = 0;
      do {
        puVar2 = (undefined4 *)sk_value(&db->data->stack,iVar9);
        if (iVar5 < 1) {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          puVar10 = puVar2;
          do {
            puVar11 = puVar10 + 1;
            if ((char *)*puVar10 != (char *)0x0) {
              sVar3 = strlen((char *)*puVar10);
              iVar12 = iVar12 + sVar3;
            }
            puVar10 = puVar11;
          } while (puVar11 != puVar2 + iVar5);
          iVar12 = iVar12 << 1;
        }
        iVar12 = BUF_MEM_grow_clean(str,iVar12 + iVar5);
        if (iVar12 == 0) {
LAB_0010e8c2:
          local_3c = -1;
          break;
        }
        pcVar6 = str->data;
        if (0 < iVar5) {
          pcVar8 = pcVar6;
          puVar10 = puVar2;
          do {
            puVar11 = puVar10 + 1;
            pcVar6 = (char *)*puVar10;
            if ((pcVar6 != (char *)0x0) && (cVar4 = *pcVar6, cVar4 != '\0')) {
              pcVar6 = pcVar6 + -1;
              do {
                pcVar7 = pcVar8;
                if (cVar4 == '\t') {
                  pcVar7 = pcVar8 + 1;
                  *pcVar8 = '\\';
                }
                pcVar8 = pcVar7 + 1;
                *pcVar7 = pcVar6[1];
                cVar4 = pcVar6[2];
                pcVar6 = pcVar6 + 1;
              } while (cVar4 != '\0');
            }
            pcVar6 = pcVar8 + 1;
            *pcVar8 = '\t';
            pcVar8 = pcVar6;
            puVar10 = puVar11;
          } while (puVar11 != puVar2 + iVar5);
        }
        pcVar6[-1] = '\n';
        len = (int)pcVar6 - (int)str->data;
        iVar12 = BIO_write(out,str->data,len);
        if (iVar12 != len) goto LAB_0010e8c2;
        iVar9 = iVar9 + 1;
        local_3c = local_3c + iVar12;
      } while (iVar9 != iVar1);
    }
    BUF_MEM_free(str);
  }
  return local_3c;
}

