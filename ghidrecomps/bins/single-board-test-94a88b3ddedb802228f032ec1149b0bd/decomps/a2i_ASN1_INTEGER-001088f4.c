
int a2i_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *bs,char *buf,int size)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  uchar *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  char cVar13;
  int old_num;
  bool bVar14;
  bool bVar15;
  uchar *local_38;
  
  bs->type = 2;
  iVar3 = BIO_gets(bp,buf,size);
  if (0 < iVar3) {
    old_num = 0;
    bVar2 = true;
    local_38 = (uchar *)0x0;
    iVar11 = 0;
    do {
      cVar13 = buf[iVar3 + -1];
      if (cVar13 == '\n') {
        iVar10 = iVar3 + -1;
        buf[iVar10] = '\0';
        if (iVar10 == 0) break;
        cVar13 = buf[iVar3 + -2];
        iVar3 = iVar10;
      }
      iVar10 = iVar3;
      if (cVar13 == '\r') {
        iVar10 = iVar3 + -1;
        buf[iVar10] = '\0';
        if (iVar10 == 0) break;
        cVar13 = buf[iVar3 + -2];
      }
      iVar3 = 0;
      pbVar5 = (byte *)buf;
      do {
        uVar6 = (uint)*pbVar5;
        uVar9 = uVar6 - 0x61;
        bVar15 = 4 < uVar9;
        bVar14 = uVar9 == 5;
        if (5 < uVar9) {
          bVar15 = 8 < uVar6 - 0x30;
          bVar14 = uVar6 - 0x30 == 9;
        }
        if ((bVar15 && !bVar14) && (5 < uVar6 - 0x41)) goto LAB_00108978;
        iVar3 = iVar3 + 1;
        pbVar5 = pbVar5 + 1;
      } while (iVar3 < iVar10);
      pbVar5 = (byte *)(buf + iVar10);
      iVar3 = iVar10;
LAB_00108978:
      *pbVar5 = 0;
      if (iVar3 < 2) break;
      pbVar5 = (byte *)buf;
      if (((bVar2) && (*buf == '0')) && (buf[1] == '0')) {
        iVar3 = iVar3 + -2;
        pbVar5 = (byte *)(buf + 2);
      }
      iVar3 = iVar3 - (uint)(cVar13 == '\\');
      if (iVar3 * -0x80000000 < 0) {
        ERR_put_error(0xd,0x66,0x91,DAT_00108b3c,0xa3);
        return 0;
      }
      iVar3 = iVar3 / 2;
      iVar10 = iVar11 + iVar3;
      if (old_num < iVar10) {
        if (local_38 == (uchar *)0x0) {
          puVar4 = (uchar *)CRYPTO_malloc(iVar3 * 2 + iVar11,DAT_00108b3c,0xaa);
        }
        else {
          puVar4 = (uchar *)CRYPTO_realloc_clean
                                      (local_38,old_num,iVar3 * 2 + iVar11,DAT_00108b3c,0xac);
        }
        if (puVar4 == (uchar *)0x0) {
          ERR_put_error(0xd,0x66,0x41,DAT_00108b3c,0xae);
          if (local_38 == (uchar *)0x0) {
            return 0;
          }
          CRYPTO_free(local_38);
          return 0;
        }
        old_num = iVar3 * 2 + iVar11;
        local_38 = puVar4;
      }
      if (iVar3 != 0) {
        pbVar8 = pbVar5 + iVar3 * 2;
        pbVar12 = local_38 + iVar11;
        do {
          while( true ) {
            uVar9 = (uint)*pbVar5;
            uVar6 = uVar9 - 0x30;
            if (9 < uVar6) {
              if (uVar9 - 0x61 < 6) {
                uVar6 = uVar9 - 0x57;
              }
              else {
                if (5 < uVar9 - 0x41) goto LAB_00108a70;
                uVar6 = uVar9 - 0x37;
              }
            }
            uVar6 = uVar6 | (uint)*pbVar12 << 4;
            uVar7 = uVar6 & 0xff;
            *pbVar12 = (byte)uVar6;
            pbVar1 = pbVar5 + 1;
            uVar9 = (uint)*pbVar1;
            uVar6 = uVar9 - 0x30;
            if (9 < uVar6) break;
LAB_00108a18:
            pbVar5 = pbVar5 + 2;
            *pbVar12 = (byte)uVar6 | (byte)(uVar7 << 4);
            pbVar12 = pbVar12 + 1;
            if (pbVar5 == pbVar8) goto LAB_00108a50;
          }
          if (5 < uVar9 - 0x61) {
            if (5 < uVar9 - 0x41) {
LAB_00108a70:
              ERR_put_error(0xd,0x66,0x8d,DAT_00108b3c,0xc1);
              return 0;
            }
            uVar6 = uVar9 - 0x37;
            goto LAB_00108a18;
          }
          pbVar5 = pbVar5 + 2;
          *pbVar12 = *pbVar1 + 0xa9 | (byte)(uVar7 << 4);
          pbVar12 = pbVar12 + 1;
        } while (pbVar5 != pbVar8);
      }
LAB_00108a50:
      if ((cVar13 == '\\') == 0) {
        bs->length = iVar10;
        bs->data = local_38;
        return 1;
      }
      iVar3 = BIO_gets(bp,buf,size);
      bVar2 = false;
      iVar11 = iVar10;
    } while (0 < iVar3);
  }
  ERR_put_error(0xd,0x66,0x96,DAT_00108b3c,0xd4);
  return 0;
}

