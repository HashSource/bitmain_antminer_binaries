
int ASN1_TIME_print(BIO *fp,ASN1_TIME *a)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  uchar *puVar6;
  uchar *puVar7;
  uchar *puVar8;
  uchar *puVar9;
  uchar *puVar10;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  
  iVar2 = asn1_time_to_tm(&local_4c);
  if (iVar2 == 0) {
    BIO_write(fp,"Bad time value",0xe);
    return 0;
  }
  iVar2 = a->length;
  puVar6 = a->data;
  if (puVar6[iVar2 + -1] == 'Z') {
    if (a->type != 0x18) {
      pcVar3 = " GMT";
      goto LAB_0018cce6;
    }
    if (iVar2 < 0x10) {
      puVar9 = (uchar *)0x0;
      puVar6 = (uchar *)0x0;
      puVar5 = _asn1_mon + local_3c * 4;
      local_38 = local_38 + 0x76c;
      pcVar3 = " GMT";
      goto LAB_0018cd64;
    }
    bVar1 = true;
  }
  else {
    if (a->type != 0x18) {
      pcVar3 = "";
LAB_0018cce6:
      iVar2 = BIO_printf(fp,"%s %2d %02d:%02d:%02d %d%s",_asn1_mon + local_3c * 4,local_40,local_44,
                         local_48,local_4c,local_38 + 0x76c,pcVar3);
      return (uint)(0 < iVar2);
    }
    if (iVar2 < 0x10) {
      puVar6 = (uchar *)0x0;
      puVar5 = _asn1_mon + local_3c * 4;
      local_38 = local_38 + 0x76c;
      pcVar3 = "";
      puVar9 = puVar6;
      goto LAB_0018cd64;
    }
    bVar1 = false;
  }
  if (puVar6[0xe] == '.') {
    puVar6 = puVar6 + 0xe;
    puVar9 = (uchar *)0x1;
    puVar10 = puVar6;
    do {
      puVar10 = puVar10 + 1;
      iVar4 = ascii_isdigit(*puVar10);
      if (iVar4 == 0) break;
      puVar8 = puVar9 + 1;
      puVar7 = puVar9 + 0xf;
      puVar9 = puVar8;
    } while ((int)puVar7 < iVar2);
  }
  else {
    puVar6 = (uchar *)0x0;
    puVar9 = (uchar *)0x0;
  }
  puVar5 = _asn1_mon + local_3c * 4;
  local_38 = local_38 + 0x76c;
  if (bVar1) {
    pcVar3 = " GMT";
  }
  else {
    pcVar3 = "";
  }
LAB_0018cd64:
  iVar2 = BIO_printf(fp,"%s %2d %02d:%02d:%02d%.*s %d%s",puVar5,local_40,local_44,local_48,local_4c,
                     puVar9,puVar6,local_38,pcVar3);
  return (uint)(0 < iVar2);
}

