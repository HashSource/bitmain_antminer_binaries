
int a2i_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *bs,char *buf,int size)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char cVar10;
  char *pcVar11;
  uint uVar12;
  char *pcVar13;
  char *pcVar14;
  uchar *local_48;
  int local_44;
  
  bs->type = 2;
  iVar3 = BIO_gets(bp,buf,size);
  if (0 < iVar3) {
    pcVar11 = buf + iVar3;
    cVar10 = pcVar11[-1];
    local_44 = 0;
    local_48 = (uchar *)0x0;
    bVar1 = true;
    iVar2 = 0;
    do {
      if (cVar10 == '\n') {
        iVar3 = iVar3 + -1;
        buf[iVar3] = '\0';
        if (iVar3 == 0) goto LAB_0018efaa;
        pcVar11 = buf + iVar3;
        cVar10 = pcVar11[-1];
      }
      if (cVar10 == '\r') {
        iVar3 = iVar3 + -1;
        buf[iVar3] = '\0';
        if (iVar3 == 0) goto LAB_0018efaa;
        pcVar11 = buf + iVar3;
        cVar10 = pcVar11[-1];
      }
      iVar7 = 0;
      pcVar13 = buf;
      do {
        iVar4 = ossl_ctype_check(*pcVar13,0x10);
        iVar8 = iVar7;
        pcVar9 = pcVar13;
        if (iVar4 == 0) break;
        iVar7 = iVar7 + 1;
        iVar8 = iVar3;
        pcVar9 = pcVar11;
        pcVar13 = pcVar13 + 1;
      } while (iVar7 < iVar3);
      *pcVar9 = '\0';
      if (iVar8 < 2) goto LAB_0018efaa;
      pcVar11 = buf;
      if (((bVar1) && (*buf == '0')) && (buf[1] == '0')) {
        iVar8 = iVar8 + -2;
        pcVar11 = buf + 2;
      }
      uVar12 = iVar8 - (uint)(cVar10 == '\\');
      if ((uVar12 & 1) != 0) {
        ERR_put_error(0xd,0x66,0x91,"crypto/asn1/f_int.c",0x67);
        CRYPTO_free(local_48);
        return 0;
      }
      iVar3 = (int)uVar12 >> 1;
      iVar8 = iVar3 + local_44;
      iVar7 = iVar2;
      puVar5 = local_48;
      if (iVar2 < iVar8) {
        iVar7 = iVar3 + iVar8;
        puVar5 = (uchar *)CRYPTO_clear_realloc(local_48,iVar2,iVar7,"crypto/asn1/f_int.c",0x6d);
        if (puVar5 == (uchar *)0x0) {
          ERR_put_error(0xd,0x66,0x41,"crypto/asn1/f_int.c",0x6f);
          CRYPTO_free(local_48);
          return 0;
        }
      }
      local_48 = puVar5;
      if (iVar3 != 0) {
        pcVar13 = pcVar11 + iVar3 * 2;
        pbVar6 = local_48 + local_44;
        do {
          pcVar14 = pcVar11 + 2;
          pcVar9 = pcVar11;
          do {
            pcVar11 = pcVar9 + 1;
            iVar3 = OPENSSL_hexchar2int(*pcVar9);
            if (iVar3 < 0) {
              ERR_put_error(0xd,0x66,0x8d,"crypto/asn1/f_int.c",0x7b);
              goto LAB_0018efaa;
            }
            *pbVar6 = (byte)iVar3 | *pbVar6 << 4;
            pcVar9 = pcVar11;
          } while (pcVar14 != pcVar11);
          pbVar6 = pbVar6 + 1;
        } while (pcVar11 != pcVar13);
      }
      if (cVar10 != '\\') {
        bs->length = iVar8;
        bs->data = local_48;
        return 1;
      }
      bVar1 = false;
      iVar3 = BIO_gets(bp,buf,size);
      if (iVar3 < 1) goto LAB_0018efaa;
      pcVar11 = buf + iVar3;
      cVar10 = pcVar11[-1];
      iVar2 = iVar7;
      local_44 = iVar8;
    } while( true );
  }
  local_48 = (uchar *)0x0;
LAB_0018efaa:
  ERR_put_error(0xd,0x66,0x96,"crypto/asn1/f_int.c",0x8c);
  CRYPTO_free(local_48);
  return 0;
}

