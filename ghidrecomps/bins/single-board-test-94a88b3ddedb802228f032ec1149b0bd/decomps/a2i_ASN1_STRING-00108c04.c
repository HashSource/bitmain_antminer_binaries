
int a2i_ASN1_STRING(BIO *bp,ASN1_STRING *bs,char *buf,int size)

{
  byte *pbVar1;
  int iVar2;
  uchar *puVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  byte *pbVar11;
  uchar *addr;
  int iVar12;
  bool bVar13;
  bool bVar14;
  
  iVar2 = BIO_gets(bp,buf,size);
  if (iVar2 < 1) {
    iVar7 = 0;
    puVar3 = (uchar *)0x0;
LAB_00108de0:
    iVar2 = 1;
    bs->length = iVar7;
    bs->data = puVar3;
  }
  else {
    iVar12 = 0;
    iVar10 = 0;
    addr = (uchar *)0x0;
    do {
      cVar9 = buf[iVar2 + -1];
      if (cVar9 == '\n') {
        iVar7 = iVar2 + -1;
        buf[iVar7] = '\0';
        if (iVar7 == 0) break;
        cVar9 = buf[iVar2 + -2];
        iVar2 = iVar7;
      }
      iVar7 = iVar2;
      if (cVar9 == '\r') {
        iVar7 = iVar2 + -1;
        buf[iVar7] = '\0';
        if (iVar7 == 0) break;
        cVar9 = buf[iVar2 + -2];
      }
      iVar2 = iVar7 + -1;
      if (iVar2 != 0) {
        pbVar4 = (byte *)(buf + iVar2);
        do {
          uVar5 = (uint)*pbVar4;
          uVar8 = uVar5 - 0x61;
          bVar14 = 4 < uVar8;
          bVar13 = uVar8 == 5;
          if (5 < uVar8) {
            bVar14 = 8 < uVar5 - 0x30;
            bVar13 = uVar5 - 0x30 == 9;
          }
          if ((bVar14 && !bVar13) && (5 < uVar5 - 0x41)) goto LAB_00108c7c;
          iVar2 = iVar2 + -1;
          pbVar4 = pbVar4 + -1;
        } while (iVar2 != 0);
      }
      pbVar4 = (byte *)(buf + iVar7);
      iVar2 = iVar7;
LAB_00108c7c:
      *pbVar4 = 0;
      if (iVar2 == 1) break;
      iVar2 = iVar2 - (uint)(cVar9 == '\\');
      if (iVar2 * -0x80000000 < 0) {
        ERR_put_error(0xd,0x67,0x91,DAT_00108e10,0x9b);
        return 0;
      }
      iVar2 = iVar2 >> 1;
      iVar7 = iVar10 + iVar2;
      puVar3 = addr;
      if (iVar12 < iVar7) {
        iVar12 = iVar2 * 2;
        if (addr == (uchar *)0x0) {
          puVar3 = (uchar *)CRYPTO_malloc(iVar12 + iVar10,DAT_00108e10,0xa2);
        }
        else {
          puVar3 = (uchar *)CRYPTO_realloc(addr,iVar12 + iVar10,DAT_00108e10,0xa6);
        }
        if (puVar3 == (uchar *)0x0) {
          ERR_put_error(0xd,0x67,0x41,DAT_00108e10,0xa8);
          if (addr == (uchar *)0x0) {
            return 0;
          }
          CRYPTO_free(addr);
          return 0;
        }
        iVar12 = iVar12 + iVar10;
      }
      if (0 < iVar2) {
        pbVar4 = (byte *)buf;
        pbVar11 = puVar3 + iVar10;
        do {
          while( true ) {
            uVar8 = (uint)*pbVar4;
            uVar5 = uVar8 - 0x30;
            if (9 < uVar5) {
              if (uVar8 - 0x61 < 6) {
                uVar5 = uVar8 - 0x57;
              }
              else {
                if (5 < uVar8 - 0x41) goto LAB_00108d58;
                uVar5 = uVar8 - 0x37;
              }
            }
            uVar5 = uVar5 | (uint)*pbVar11 << 4;
            uVar8 = uVar5 & 0xff;
            *pbVar11 = (byte)uVar5;
            pbVar1 = pbVar4 + 1;
            uVar5 = (uint)*pbVar1;
            uVar6 = uVar5 - 0x30;
            if (9 < uVar6) break;
LAB_00108d06:
            pbVar4 = pbVar4 + 2;
            *pbVar11 = (byte)uVar6 | (byte)(uVar8 << 4);
            pbVar11 = pbVar11 + 1;
            if (pbVar4 == (byte *)(buf + iVar2 * 2)) goto LAB_00108d3e;
          }
          if (5 < uVar5 - 0x61) {
            if (5 < uVar5 - 0x41) {
LAB_00108d58:
              ERR_put_error(0xd,0x67,0x8d,DAT_00108e10,0xbb);
              return 0;
            }
            uVar6 = uVar5 - 0x37;
            goto LAB_00108d06;
          }
          pbVar4 = pbVar4 + 2;
          *pbVar11 = *pbVar1 + 0xa9 | (byte)(uVar8 << 4);
          pbVar11 = pbVar11 + 1;
        } while (pbVar4 != (byte *)(buf + iVar2 * 2));
      }
LAB_00108d3e:
      if ((cVar9 == '\\') == 0) goto LAB_00108de0;
      iVar2 = BIO_gets(bp,buf,size);
      iVar10 = iVar7;
      addr = puVar3;
    } while (0 < iVar2);
    ERR_put_error(0xd,0x67,0x96,DAT_00108e10,0xce);
    iVar2 = 0;
  }
  return iVar2;
}

