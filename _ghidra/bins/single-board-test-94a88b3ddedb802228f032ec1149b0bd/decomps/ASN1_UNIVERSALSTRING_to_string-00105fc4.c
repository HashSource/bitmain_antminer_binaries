
int ASN1_UNIVERSALSTRING_to_string(ASN1_UNIVERSALSTRING *s)

{
  uchar *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if ((s->type == 0x1c) && (uVar7 = s->length, (uVar7 & 3) == 0)) {
    puVar2 = s->data;
    puVar4 = puVar2;
    if ((int)uVar7 < 1) {
LAB_0010602c:
      *puVar4 = '\0';
      uVar6 = s->length;
      uVar7 = uVar6 & ~((int)uVar6 >> 0x20);
      if ((int)uVar6 < 0) {
        uVar7 = uVar6 + 3;
      }
      s->length = (int)uVar7 >> 2;
      iVar5 = ASN1_PRINTABLE_type(s->data,(int)uVar7 >> 2);
      s->type = iVar5;
      return 1;
    }
    if (((*puVar2 == '\0') && (puVar2[1] == '\0')) && (puVar2[2] == '\0')) {
      iVar5 = 0;
      puVar3 = puVar2;
      do {
        iVar5 = iVar5 + 4;
        if ((int)uVar7 <= iVar5) {
          if (3 < (int)uVar7) {
            iVar5 = 3;
            puVar3 = puVar2;
            while( true ) {
              puVar2 = puVar2 + iVar5;
              iVar5 = iVar5 + 4;
              puVar4 = puVar3 + 1;
              *puVar3 = *puVar2;
              if (s->length <= iVar5) break;
              puVar2 = s->data;
              puVar3 = puVar4;
            }
          }
          goto LAB_0010602c;
        }
      } while (((puVar2[iVar5] == '\0') && (puVar3[5] == '\0')) &&
              (puVar1 = puVar3 + 6, puVar3 = puVar3 + 4, *puVar1 == '\0'));
    }
  }
  return 0;
}

