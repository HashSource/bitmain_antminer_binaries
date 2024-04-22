
int OBJ_create_objects(BIO *in)

{
  byte *pbVar1;
  int iVar2;
  ushort **ppuVar3;
  ushort *puVar4;
  uint uVar5;
  byte *sn;
  byte *pbVar6;
  byte *ln;
  int iVar7;
  uint uVar8;
  byte abStack_219 [513];
  
  ln = (byte *)0x0;
  iVar7 = 0;
  do {
    iVar2 = BIO_gets(in,(char *)(abStack_219 + 1),0x200);
    if (iVar2 < 1) {
      return iVar7;
    }
    abStack_219[iVar2] = 0;
    ppuVar3 = __ctype_b_loc();
    uVar8 = (uint)abStack_219[1];
    puVar4 = *ppuVar3;
    uVar5 = (uint)puVar4[uVar8];
    if (-1 < (int)(uVar5 << 0x1c)) {
      return iVar7;
    }
    pbVar6 = abStack_219;
    while( true ) {
      pbVar1 = pbVar6 + 1;
      sn = (byte *)(uint)*pbVar1;
      if (((uVar5 & 0x800) == 0) && (sn != (byte *)0x2e)) break;
      uVar5 = (uint)puVar4[pbVar6[2]];
      pbVar6 = pbVar1;
    }
    if (sn == (byte *)0x0) {
LAB_0008ce4e:
      if (uVar8 == 0) {
        return iVar7;
      }
    }
    else {
      sn = pbVar6 + 2;
      *pbVar1 = 0;
      uVar5 = (uint)pbVar6[2];
      if ((int)((uint)puVar4[uVar5] << 0x12) < 0) {
        pbVar6 = pbVar6 + 3;
        do {
          sn = pbVar6;
          uVar5 = (uint)*sn;
          pbVar6 = sn + 1;
        } while ((puVar4[uVar5] & 0x2000) != 0);
      }
      if (uVar5 == 0) {
        uVar8 = (uint)abStack_219[1];
        sn = (byte *)0x0;
        goto LAB_0008ce4e;
      }
      pbVar6 = sn;
      if (*sn == 0) {
        ln = (byte *)0x0;
      }
      else {
        do {
          pbVar1 = pbVar6;
          pbVar6 = pbVar1 + 1;
          ln = (byte *)(uint)*pbVar6;
          if (ln == (byte *)0x0) goto LAB_0008ce80;
        } while (-1 < (int)((uint)puVar4[(int)ln] << 0x12));
        ln = pbVar1 + 2;
        *pbVar6 = 0;
        uVar5 = (uint)pbVar1[2];
        if ((int)((uint)puVar4[uVar5] << 0x12) < 0) {
          pbVar6 = pbVar1 + 3;
          do {
            ln = pbVar6;
            uVar5 = (uint)*ln;
            pbVar6 = ln + 1;
          } while ((puVar4[uVar5] & 0x2000) != 0);
        }
        if (uVar5 == 0) {
          ln = (byte *)0x0;
        }
      }
LAB_0008ce80:
      if (abStack_219[1] == 0) {
        return iVar7;
      }
    }
    iVar2 = OBJ_create((char *)(abStack_219 + 1),(char *)sn,(char *)ln);
    if (iVar2 == 0) {
      return iVar7;
    }
    iVar7 = iVar7 + 1;
  } while( true );
}

