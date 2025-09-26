
int OBJ_create_objects(BIO *in)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *ln;
  int iVar6;
  byte abStack_221 [513];
  
  ln = (byte *)0x0;
  iVar6 = 0;
  do {
    iVar2 = BIO_gets(in,(char *)(abStack_221 + 1),0x200);
    if (iVar2 < 1) {
      return iVar6;
    }
    abStack_221[iVar2] = 0;
    iVar2 = ossl_ctype_check(abStack_221[1],7);
    pbVar4 = abStack_221 + 1;
    if (iVar2 == 0) {
      return iVar6;
    }
    for (; (iVar2 = ossl_ctype_check(*pbVar4,4), iVar2 != 0 ||
           (pbVar3 = (byte *)(uint)*pbVar4, pbVar3 == (byte *)0x2e)); pbVar4 = pbVar4 + 1) {
    }
    if (pbVar3 != (byte *)0x0) {
      *pbVar4 = 0;
      do {
        pbVar4 = pbVar4 + 1;
        iVar2 = ossl_ctype_check(*pbVar4,8);
      } while (iVar2 != 0);
      bVar1 = *pbVar4;
      pbVar5 = pbVar4;
      if (bVar1 == 0) {
        pbVar3 = (byte *)0x0;
      }
      else {
        do {
          iVar2 = ossl_ctype_check(bVar1,8);
          pbVar3 = pbVar4;
          if (iVar2 != 0) {
            ln = (byte *)(uint)*pbVar5;
            if (ln != (byte *)0x0) {
              *pbVar5 = 0;
              do {
                pbVar5 = pbVar5 + 1;
                iVar2 = ossl_ctype_check(*pbVar5,8);
              } while (iVar2 != 0);
              ln = pbVar5;
              if (*pbVar5 == 0) {
                ln = (byte *)0x0;
              }
            }
            goto joined_r0x0014cc68;
          }
          pbVar5 = pbVar5 + 1;
          bVar1 = *pbVar5;
        } while (bVar1 != 0);
        ln = (byte *)0x0;
      }
    }
joined_r0x0014cc68:
    if (abStack_221[1] == '\0') {
      return iVar6;
    }
    iVar2 = OBJ_create((char *)(abStack_221 + 1),(char *)pbVar3,(char *)ln);
    if (iVar2 == 0) {
      return iVar6;
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

