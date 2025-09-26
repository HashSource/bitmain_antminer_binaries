
void RC4(RC4_KEY *key,size_t len,uchar *indata,uchar *outdata)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined1 uVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  byte *local_34;
  byte *local_30;
  
  uVar10 = (uint)(byte)key->x;
  uVar12 = (uint)*(byte *)((int)&key->x + 1);
  if ((((uint)outdata | (uint)indata) & 3) != 0) {
    uVar16 = len >> 3;
    pbVar8 = indata;
    pbVar14 = outdata;
    uVar7 = uVar10;
    uVar13 = uVar16;
    local_34 = outdata;
    local_30 = indata;
    if (uVar16 != 0) {
      do {
        uVar15 = uVar7 + 1 & 0xff;
        uVar5 = uVar7 + 2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar15 - 6));
        uVar18 = uVar7 + 3 & 0xff;
        uVar6 = uVar7 + 4 & 0xff;
        uVar13 = uVar13 - 1;
        uVar17 = uVar12 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar17 - 6));
        *(byte *)((int)key->data + (uVar15 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar17 - 6)) = bVar1;
        uVar12 = uVar7 + 5 & 0xff;
        *pbVar14 = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^ *pbVar8;
        bVar1 = *(byte *)((int)key->data + (uVar5 - 6));
        uVar17 = uVar17 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar17 - 6));
        *(byte *)((int)key->data + (uVar5 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar17 - 6)) = bVar1;
        uVar15 = uVar7 + 6 & 0xff;
        pbVar14[1] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar8[1];
        bVar1 = *(byte *)((int)key->data + (uVar18 - 6));
        uVar17 = uVar17 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar17 - 6));
        *(byte *)((int)key->data + (uVar18 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar17 - 6)) = bVar1;
        uVar5 = uVar7 + 7 & 0xff;
        uVar7 = uVar7 + 8 & 0xff;
        pbVar14[2] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar8[2];
        bVar1 = *(byte *)((int)key->data + (uVar6 - 6));
        uVar18 = uVar17 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar18 - 6));
        *(byte *)((int)key->data + (uVar6 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar18 - 6)) = bVar1;
        pbVar14[3] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar8[3];
        bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
        uVar18 = uVar18 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar18 - 6));
        *(byte *)((int)key->data + (uVar12 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar18 - 6)) = bVar1;
        pbVar14[4] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar8[4];
        bVar1 = *(byte *)((int)key->data + (uVar15 - 6));
        uVar12 = uVar18 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
        *(byte *)((int)key->data + (uVar15 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
        pbVar14[5] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar8[5];
        bVar1 = *(byte *)((int)key->data + (uVar5 - 6));
        uVar12 = uVar12 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
        *(byte *)((int)key->data + (uVar5 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
        pbVar14[6] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar8[6];
        bVar1 = *(byte *)((int)key->data + (uVar7 - 6));
        uVar12 = uVar12 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
        *(byte *)((int)key->data + (uVar7 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
        pbVar14[7] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar8[7];
        pbVar8 = pbVar8 + 8;
        pbVar14 = pbVar14 + 8;
      } while (uVar13 != 0);
      local_34 = outdata + uVar16 * 8;
      uVar10 = uVar10 + uVar16 * 8 & 0xff;
      local_30 = indata + uVar16 * 8;
    }
    uVar11 = (undefined1)uVar12;
    uVar9 = (undefined1)uVar10;
    uVar7 = len & 7;
    if (uVar7 != 0) {
      uVar13 = uVar10 + 1 & 0xff;
      bVar1 = *(byte *)((int)key->data + (uVar13 - 6));
      uVar12 = uVar12 + bVar1 & 0xff;
      bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
      *(byte *)((int)key->data + (uVar13 - 6)) = bVar2;
      *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
      *local_34 = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^ *local_30;
      if (uVar7 != 1) {
        uVar13 = uVar10 + 2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar13 - 6));
        uVar12 = uVar12 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
        *(byte *)((int)key->data + (uVar13 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
        local_34[1] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                      local_30[1];
        if (uVar7 != 2) {
          uVar13 = uVar10 + 3 & 0xff;
          bVar1 = *(byte *)((int)key->data + (uVar13 - 6));
          uVar12 = uVar12 + bVar1 & 0xff;
          bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
          *(byte *)((int)key->data + (uVar13 - 6)) = bVar2;
          *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
          local_34[2] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                        local_30[2];
          if (uVar7 != 3) {
            uVar13 = uVar10 + 4 & 0xff;
            bVar1 = *(byte *)((int)key->data + (uVar13 - 6));
            uVar12 = uVar12 + bVar1 & 0xff;
            bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
            *(byte *)((int)key->data + (uVar13 - 6)) = bVar2;
            *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
            local_34[3] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                          local_30[3];
            if (uVar7 != 4) {
              uVar13 = uVar10 + 5 & 0xff;
              bVar1 = *(byte *)((int)key->data + (uVar13 - 6));
              uVar12 = uVar12 + bVar1 & 0xff;
              bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
              *(byte *)((int)key->data + (uVar13 - 6)) = bVar2;
              *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
              local_34[4] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                            local_30[4];
              if (uVar7 != 5) {
                uVar13 = uVar10 + 6 & 0xff;
                bVar1 = *(byte *)((int)key->data + (uVar13 - 6));
                uVar12 = uVar12 + bVar1 & 0xff;
                bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
                *(byte *)((int)key->data + (uVar13 - 6)) = bVar2;
                *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
                local_34[5] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                              local_30[5];
                if (uVar7 != 6) {
                  uVar7 = uVar10 + 7 & 0xff;
                  uVar9 = (undefined1)(uVar10 + 7);
                  bVar1 = *(byte *)((int)key->data + (uVar7 - 6));
                  uVar12 = uVar12 + bVar1;
                  uVar10 = uVar12 & 0xff;
                  uVar11 = (undefined1)uVar12;
                  bVar2 = *(byte *)((int)key->data + (uVar10 - 6));
                  *(byte *)((int)key->data + (uVar7 - 6)) = bVar2;
                  *(byte *)((int)key->data + (uVar10 - 6)) = bVar1;
                  local_34[6] = local_30[6] ^
                                *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6))
                  ;
                  goto LAB_0017f6c0;
                }
              }
            }
          }
        }
      }
      uVar11 = (undefined1)uVar12;
      uVar9 = (undefined1)uVar13;
    }
    goto LAB_0017f6c0;
  }
  uVar7 = len & 0xfffffffc;
  while (uVar7 != 0) {
    uVar7 = uVar10 + 1 & 0xff;
    uVar13 = uVar10 + 2 & 0xff;
    uVar15 = *(uint *)indata;
    bVar1 = *(byte *)((int)key->data + (uVar7 - 6));
    uVar16 = uVar10 + 3 & 0xff;
    uVar10 = uVar10 + 4 & 0xff;
    uVar12 = uVar12 + bVar1 & 0xff;
    len = len - 4;
    bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
    *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar7 - 6)) = bVar2;
    bVar3 = *(byte *)((int)key->data + (uVar13 - 6));
    uVar9 = *(undefined1 *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6));
    uVar12 = uVar12 + bVar3 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
    *(byte *)((int)key->data + (uVar12 - 6)) = bVar3;
    *(byte *)((int)key->data + (uVar13 - 6)) = bVar1;
    bVar2 = *(byte *)((int)key->data + (uVar16 - 6));
    uVar11 = *(undefined1 *)((int)key->data + (((uint)bVar1 + (uint)bVar3 & 0xff) - 6));
    uVar12 = uVar12 + bVar2 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
    *(byte *)((int)key->data + (uVar12 - 6)) = bVar2;
    *(byte *)((int)key->data + (uVar16 - 6)) = bVar1;
    bVar3 = *(byte *)((int)key->data + (uVar10 - 6));
    uVar4 = *(undefined1 *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6));
    uVar12 = uVar12 + bVar3 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
    *(byte *)((int)key->data + (uVar12 - 6)) = bVar3;
    *(byte *)((int)key->data + (uVar10 - 6)) = bVar1;
    *(uint *)outdata =
         CONCAT13(*(undefined1 *)((int)key->data + (((uint)bVar3 + (uint)bVar1 & 0xff) - 6)),
                  CONCAT12(uVar4,CONCAT11(uVar11,uVar9))) ^ uVar15;
    indata = (uchar *)((int)indata + 4);
    outdata = (uchar *)((int)outdata + 4);
    uVar7 = len & 0xfffffffc;
  }
  uVar11 = (undefined1)uVar12;
  uVar9 = (undefined1)uVar10;
  if (len == 0) goto LAB_0017f6c0;
  uVar7 = len & 3;
  uVar13 = 0xffffffff >> ((4 - len) * 8 & 0xff);
  uVar16 = *(uint *)indata;
  uVar15 = *(uint *)outdata;
  if (uVar7 == 2) {
    iVar20 = 0;
    uVar7 = 0;
    iVar19 = 8;
LAB_0017fa40:
    uVar10 = uVar10 + 1 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar10 - 6));
    uVar12 = bVar1 + uVar12 & 0xff;
    bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
    *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar10 - 6)) = bVar2;
    uVar7 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) << iVar20 |
            uVar7;
LAB_0017fa64:
    uVar10 = uVar10 + 1 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar10 - 6));
    uVar12 = bVar1 + uVar12 & 0xff;
    bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
    *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar10 - 6)) = bVar2;
    uVar7 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) << iVar19 |
            uVar7;
  }
  else {
    if (uVar7 == 3) {
      iVar19 = 0x10;
      uVar10 = uVar10 + 1 & 0xff;
      iVar20 = 8;
      bVar1 = *(byte *)((int)key->data + (uVar10 - 6));
      uVar12 = bVar1 + uVar12 & 0xff;
      bVar2 = *(byte *)((int)key->data + (uVar12 - 6));
      *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
      *(byte *)((int)key->data + (uVar10 - 6)) = bVar2;
      uVar7 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6));
      goto LAB_0017fa40;
    }
    if (uVar7 == 1) {
      iVar19 = 0;
      uVar7 = 0;
      goto LAB_0017fa64;
    }
    uVar7 = 0;
  }
  uVar11 = (undefined1)uVar12;
  uVar9 = (undefined1)uVar10;
  *(uint *)outdata = (uVar7 ^ uVar16) & uVar13 | uVar15 & ~uVar13;
LAB_0017f6c0:
  *(undefined1 *)&key->x = uVar9;
  *(undefined1 *)((int)&key->x + 1) = uVar11;
  return;
}

