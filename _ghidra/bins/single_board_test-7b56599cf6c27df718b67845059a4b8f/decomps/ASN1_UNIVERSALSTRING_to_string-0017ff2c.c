
int ASN1_UNIVERSALSTRING_to_string(ASN1_UNIVERSALSTRING *s)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  int iVar5;
  uchar *puVar6;
  uchar *puVar7;
  uint uVar8;
  
  if (s->type != 0x1c) {
    return 0;
  }
  uVar8 = s->length;
  if ((uVar8 & 3) != 0) {
    return 0;
  }
  puVar6 = s->data;
  puVar7 = puVar6;
  if ((int)uVar8 < 1) {
LAB_0017ff86:
    *puVar7 = '\0';
    uVar3 = s->length;
    uVar8 = uVar3 & ~((int)uVar3 >> 0x20);
    if ((int)uVar3 < 0) {
      uVar8 = uVar3 + 3;
    }
    s->length = (int)uVar8 >> 2;
    iVar2 = ASN1_PRINTABLE_type(s->data,(int)uVar8 >> 2);
    iVar5 = 1;
    s->type = iVar2;
  }
  else {
    iVar5 = 0;
    if (*puVar6 == '\0') {
      if (puVar6[1] == '\0') {
        uVar3 = (uint)puVar6[2];
        puVar4 = puVar6;
        if (uVar3 == 0) {
          do {
            uVar3 = uVar3 + 4;
            if ((int)uVar8 <= (int)uVar3) {
              if (3 < (int)uVar8) {
                iVar5 = 3;
                puVar4 = puVar6;
                while( true ) {
                  puVar6 = puVar6 + iVar5;
                  iVar5 = iVar5 + 4;
                  puVar7 = puVar4 + 1;
                  *puVar4 = *puVar6;
                  if (s->length <= iVar5) break;
                  puVar6 = s->data;
                  puVar4 = puVar7;
                }
              }
              goto LAB_0017ff86;
            }
            if (puVar4[4] != '\0') {
              return 0;
            }
            if (puVar4[5] != '\0') {
              return 0;
            }
            puVar1 = puVar4 + 6;
            iVar5 = 0;
            puVar4 = puVar4 + 4;
          } while (*puVar1 == '\0');
        }
        else {
          iVar5 = 0;
        }
      }
      else {
        iVar5 = 0;
      }
    }
  }
  return iVar5;
}

