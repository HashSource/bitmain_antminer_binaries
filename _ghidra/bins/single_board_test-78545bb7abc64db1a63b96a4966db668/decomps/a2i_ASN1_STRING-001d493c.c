
int a2i_ASN1_STRING(BIO *bp,ASN1_STRING *bs,char *buf,int size)

{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  byte *pbVar4;
  int iVar5;
  char *pcVar6;
  char cVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int local_44;
  uchar *local_40;
  int local_3c;
  
  iVar1 = BIO_gets(bp,buf,size);
  if (iVar1 < 1) {
    iVar5 = 0;
    local_40 = (uchar *)0x0;
LAB_001d4aea:
    bs->length = iVar5;
    bs->data = local_40;
    return 1;
  }
  pcVar9 = buf + iVar1;
  cVar7 = pcVar9[-1];
  local_44 = 0;
  local_40 = (uchar *)0x0;
  local_3c = 0;
  do {
    if (cVar7 == '\n') {
      iVar1 = iVar1 + -1;
      buf[iVar1] = '\0';
      if (iVar1 == 0) {
LAB_001d4a9e:
        ERR_put_error(0xd,0x67,0x96,"crypto/asn1/f_string.c",0x85);
        CRYPTO_free(local_40);
        return 0;
      }
      pcVar9 = buf + iVar1;
      cVar7 = pcVar9[-1];
    }
    if (cVar7 == '\r') {
      iVar1 = iVar1 + -1;
      buf[iVar1] = '\0';
      if (iVar1 == 0) goto LAB_001d4a9e;
      pcVar9 = buf + iVar1;
      cVar7 = pcVar9[-1];
    }
    iVar5 = iVar1 + -1;
    iVar8 = iVar1;
    pcVar6 = pcVar9;
    if (iVar5 != 0) {
      pcVar10 = buf + iVar5;
      do {
        iVar2 = ossl_ctype_check(*pcVar10,0x10);
        iVar8 = iVar5;
        pcVar6 = pcVar10;
        if (iVar2 == 0) break;
        iVar5 = iVar5 + -1;
        iVar8 = iVar1;
        pcVar6 = pcVar9;
        pcVar10 = pcVar10 + -1;
      } while (iVar5 != 0);
    }
    *pcVar6 = '\0';
    if (iVar8 == 1) goto LAB_001d4a9e;
    iVar8 = iVar8 - (uint)(cVar7 == '\\');
    if (iVar8 * -0x80000000 < 0) {
      ERR_put_error(0xd,0x67,0x91,"crypto/asn1/f_string.c",0x5e);
      CRYPTO_free(local_40);
      return 0;
    }
    iVar8 = iVar8 >> 1;
    iVar5 = iVar8 + local_44;
    if (local_3c < iVar5) {
      puVar3 = (uchar *)CRYPTO_realloc(local_40,local_44 + iVar8 * 2,"crypto/asn1/f_string.c",100);
      if (puVar3 == (uchar *)0x0) {
        ERR_put_error(0xd,0x67,0x41,"crypto/asn1/f_string.c",0x66);
        CRYPTO_free(local_40);
        return 0;
      }
      local_3c = iVar8 + iVar5;
      local_40 = puVar3;
    }
    if (iVar8 != 0) {
      pbVar4 = local_40 + local_44;
      pcVar9 = buf;
      do {
        pcVar10 = pcVar9 + 2;
        pcVar6 = pcVar9;
        do {
          pcVar9 = pcVar6 + 1;
          iVar1 = OPENSSL_hexchar2int(*pcVar6);
          if (iVar1 < 0) {
            ERR_put_error(0xd,0x67,0x8d,"crypto/asn1/f_string.c",0x72);
            CRYPTO_free(local_40);
            return 0;
          }
          *pbVar4 = (byte)iVar1 | *pbVar4 << 4;
          pcVar6 = pcVar9;
        } while (pcVar10 != pcVar9);
        pbVar4 = pbVar4 + 1;
      } while (pcVar9 != buf + iVar8 * 2);
    }
    if (cVar7 != '\\') goto LAB_001d4aea;
    iVar1 = BIO_gets(bp,buf,size);
    if (iVar1 < 1) goto LAB_001d4a9e;
    pcVar9 = buf + iVar1;
    cVar7 = pcVar9[-1];
    local_44 = iVar5;
  } while( true );
}

