
void RC4(RC4_KEY *key,size_t len,uchar *indata,uchar *outdata)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined uVar8;
  uint uVar9;
  undefined uVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  byte *local_34;
  byte *local_30;
  
  uVar9 = (uint)*(byte *)&key->x;
  uVar11 = (uint)*(byte *)((int)&key->x + 1);
  if ((((uint)outdata | (uint)indata) & 3) != 0) {
    uVar12 = len >> 3;
    pbVar7 = indata;
    pbVar13 = outdata;
    uVar6 = uVar9;
    local_34 = outdata;
    local_30 = indata;
    if (uVar12 != 0) {
      do {
        uVar15 = uVar6 + 1 & 0xff;
        uVar14 = uVar6 + 2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar15 - 6));
        uVar17 = uVar6 + 3 & 0xff;
        uVar5 = uVar6 + 4 & 0xff;
        uVar12 = uVar12 - 1;
        uVar16 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar16 - 6));
        *(byte *)((int)key->data + (uVar15 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar16 - 6)) = bVar1;
        uVar11 = uVar6 + 5 & 0xff;
        *pbVar13 = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^ *pbVar7;
        bVar1 = *(byte *)((int)key->data + (uVar14 - 6));
        uVar16 = uVar16 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar16 - 6));
        *(byte *)((int)key->data + (uVar14 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar16 - 6)) = bVar1;
        uVar15 = uVar6 + 6 & 0xff;
        pbVar13[1] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar7[1];
        bVar1 = *(byte *)((int)key->data + (uVar17 - 6));
        uVar16 = uVar16 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar16 - 6));
        *(byte *)((int)key->data + (uVar17 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar16 - 6)) = bVar1;
        uVar14 = uVar6 + 7 & 0xff;
        uVar6 = uVar6 + 8 & 0xff;
        pbVar13[2] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar7[2];
        bVar1 = *(byte *)((int)key->data + (uVar5 - 6));
        uVar17 = uVar16 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar17 - 6));
        *(byte *)((int)key->data + (uVar5 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar17 - 6)) = bVar1;
        pbVar13[3] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar7[3];
        bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
        uVar17 = uVar17 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar17 - 6));
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar17 - 6)) = bVar1;
        pbVar13[4] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar7[4];
        bVar1 = *(byte *)((int)key->data + (uVar15 - 6));
        uVar11 = uVar17 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar15 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        pbVar13[5] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar7[5];
        bVar1 = *(byte *)((int)key->data + (uVar14 - 6));
        uVar11 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar14 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        pbVar13[6] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar7[6];
        bVar1 = *(byte *)((int)key->data + (uVar6 - 6));
        uVar11 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar6 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        pbVar13[7] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar7[7];
        pbVar7 = pbVar7 + 8;
        pbVar13 = pbVar13 + 8;
      } while (uVar12 != 0);
      local_34 = outdata + (len & 0xfffffff8);
      uVar9 = uVar9 + (len & 0xfffffff8) & 0xff;
      local_30 = indata + (len & 0xfffffff8);
    }
    uVar10 = (undefined)uVar11;
    uVar8 = (undefined)uVar9;
    uVar6 = len & 7;
    if (uVar6 != 0) {
      uVar12 = uVar9 + 1 & 0xff;
      bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
      uVar11 = uVar11 + bVar1 & 0xff;
      bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
      *(byte *)((int)key->data + (uVar12 - 6)) = bVar2;
      *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
      *local_34 = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^ *local_30;
      if (uVar6 != 1) {
        uVar12 = uVar9 + 2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
        uVar11 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar12 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        local_34[1] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                      local_30[1];
        if (uVar6 != 2) {
          uVar12 = uVar9 + 3 & 0xff;
          bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
          uVar11 = uVar11 + bVar1 & 0xff;
          bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
          *(byte *)((int)key->data + (uVar12 - 6)) = bVar2;
          *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
          local_34[2] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                        local_30[2];
          if (uVar6 != 3) {
            uVar12 = uVar9 + 4 & 0xff;
            bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
            uVar11 = uVar11 + bVar1 & 0xff;
            bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
            *(byte *)((int)key->data + (uVar12 - 6)) = bVar2;
            *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
            local_34[3] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                          local_30[3];
            if (uVar6 != 4) {
              uVar12 = uVar9 + 5 & 0xff;
              bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
              uVar11 = uVar11 + bVar1 & 0xff;
              bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
              *(byte *)((int)key->data + (uVar12 - 6)) = bVar2;
              *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
              local_34[4] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                            local_30[4];
              if (uVar6 != 5) {
                uVar12 = uVar9 + 6 & 0xff;
                bVar1 = *(byte *)((int)key->data + (uVar12 - 6));
                uVar11 = uVar11 + bVar1 & 0xff;
                bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
                *(byte *)((int)key->data + (uVar12 - 6)) = bVar2;
                *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
                local_34[5] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                              local_30[5];
                if (uVar6 != 6) {
                  uVar6 = uVar9 + 7 & 0xff;
                  uVar8 = (undefined)(uVar9 + 7);
                  bVar1 = *(byte *)((int)key->data + (uVar6 - 6));
                  uVar11 = uVar11 + bVar1;
                  uVar9 = uVar11 & 0xff;
                  uVar10 = (undefined)uVar11;
                  bVar2 = *(byte *)((int)key->data + (uVar9 - 6));
                  *(byte *)((int)key->data + (uVar6 - 6)) = bVar2;
                  *(byte *)((int)key->data + (uVar9 - 6)) = bVar1;
                  local_34[6] = local_30[6] ^
                                *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6))
                  ;
                  goto LAB_000e441c;
                }
              }
            }
          }
        }
      }
      uVar10 = (undefined)uVar11;
      uVar8 = (undefined)uVar12;
    }
    goto LAB_000e441c;
  }
  uVar6 = len & 0xfffffffc;
  while (uVar6 != 0) {
    uVar6 = uVar9 + 1 & 0xff;
    uVar12 = uVar9 + 2 & 0xff;
    uVar14 = *(uint *)indata;
    bVar1 = *(byte *)((int)key->data + (uVar6 - 6));
    uVar15 = uVar9 + 3 & 0xff;
    uVar9 = uVar9 + 4 & 0xff;
    uVar11 = uVar11 + bVar1 & 0xff;
    len = len - 4;
    bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar6 - 6)) = bVar2;
    bVar3 = *(byte *)((int)key->data + (uVar12 - 6));
    uVar8 = *(undefined *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6));
    uVar11 = uVar11 + bVar3 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar3;
    *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
    bVar2 = *(byte *)((int)key->data + (uVar15 - 6));
    uVar10 = *(undefined *)((int)key->data + (((uint)bVar1 + (uint)bVar3 & 0xff) - 6));
    uVar11 = uVar11 + bVar2 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar2;
    *(byte *)((int)key->data + (uVar15 - 6)) = bVar1;
    bVar3 = *(byte *)((int)key->data + (uVar9 - 6));
    uVar4 = *(undefined *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6));
    uVar11 = uVar11 + bVar3 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar3;
    *(byte *)((int)key->data + (uVar9 - 6)) = bVar1;
    *(uint *)outdata =
         CONCAT13(*(undefined *)((int)key->data + (((uint)bVar3 + (uint)bVar1 & 0xff) - 6)),
                  CONCAT12(uVar4,CONCAT11(uVar10,uVar8))) ^ uVar14;
    indata = (uchar *)((int)indata + 4);
    outdata = (uchar *)((int)outdata + 4);
    uVar6 = len & 0xfffffffc;
  }
  uVar10 = (undefined)uVar11;
  uVar8 = (undefined)uVar9;
  if (len == 0) goto LAB_000e441c;
  uVar6 = len & 3;
  uVar12 = 0xffffffff >> ((4 - len) * 8 & 0xff);
  uVar15 = *(uint *)indata;
  uVar14 = *(uint *)outdata;
  if (uVar6 == 2) {
    iVar19 = 0;
    uVar6 = 0;
    iVar18 = 8;
LAB_000e479c:
    uVar9 = uVar9 + 1 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar9 - 6));
    uVar11 = bVar1 + uVar11 & 0xff;
    bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar9 - 6)) = bVar2;
    uVar6 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) << iVar19 |
            uVar6;
LAB_000e47c0:
    uVar9 = uVar9 + 1 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar9 - 6));
    uVar11 = bVar1 + uVar11 & 0xff;
    bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar9 - 6)) = bVar2;
    uVar6 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) << iVar18 |
            uVar6;
  }
  else {
    if (uVar6 == 3) {
      iVar18 = 0x10;
      uVar9 = uVar9 + 1 & 0xff;
      iVar19 = 8;
      bVar1 = *(byte *)((int)key->data + (uVar9 - 6));
      uVar11 = bVar1 + uVar11 & 0xff;
      bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
      *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
      *(byte *)((int)key->data + (uVar9 - 6)) = bVar2;
      uVar6 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6));
      goto LAB_000e479c;
    }
    if (uVar6 == 1) {
      iVar18 = 0;
      uVar6 = 0;
      goto LAB_000e47c0;
    }
    uVar6 = 0;
  }
  uVar10 = (undefined)uVar11;
  uVar8 = (undefined)uVar9;
  *(uint *)outdata = (uVar6 ^ uVar15) & uVar12 | uVar14 & ~uVar12;
LAB_000e441c:
  *(undefined *)&key->x = uVar8;
  *(undefined *)((int)&key->x + 1) = uVar10;
  return;
}

