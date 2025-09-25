
/* WARNING: Type propagation algorithm not settling */

uint chacha20_poly1305_cipher(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  size_t len;
  byte *pbVar16;
  byte *pbVar17;
  int iVar18;
  uint uVar19;
  uint *local_e0;
  byte *local_dc;
  byte *local_d4;
  uint *local_d0;
  undefined1 auStack_c8 [48];
  byte abStack_98 [4];
  undefined4 auStack_94 [3];
  undefined4 uStack_88;
  uint auStack_84 [24];
  uint *puVar11;
  
  iVar14 = *(int *)(param_1 + 0x60);
  uVar15 = *(uint *)(iVar14 + 200);
  if (*(int *)(iVar14 + 0xbc) != 0) {
LAB_0012920e:
    if (param_3 == (uint *)0x0) {
      pbVar17 = (byte *)0x0;
      uVar7 = 0;
      local_e0 = param_2;
    }
    else {
      if (param_2 == (uint *)0x0) {
        Poly1305_Update(iVar14 + 0xd0,param_3,param_4);
        uVar15 = *(uint *)(iVar14 + 0xa8);
        *(undefined4 *)(iVar14 + 0xb8) = 1;
        *(uint *)(iVar14 + 0xa8) = uVar15 + param_4;
        *(uint *)(iVar14 + 0xac) = *(int *)(iVar14 + 0xac) + (uint)CARRY4(uVar15,param_4);
        return param_4;
      }
      if (*(int *)(iVar14 + 0xb8) != 0) {
        uVar7 = *(uint *)(iVar14 + 0xa8) & 0xf;
        if (uVar7 != 0) {
          Poly1305_Update(iVar14 + 0xd0,&zero,0x10 - uVar7);
        }
        *(undefined4 *)(iVar14 + 0xb8) = 0;
      }
      *(undefined4 *)(iVar14 + 200) = 0xffffffff;
      if (uVar15 == 0xffffffff) {
        uVar7 = 0;
        uVar15 = param_4;
      }
      else {
        if (param_4 != uVar15 + 0x10) {
          return 0xffffffff;
        }
        uVar7 = uVar15 - param_4;
        if (uVar7 != 0) {
          uVar7 = 1;
        }
      }
      if (*(int *)(param_1 + 8) == 0) {
        Poly1305_Update(iVar14 + 0xd0,param_3,uVar15);
        chacha_cipher(param_1,param_2,param_3,uVar15);
        uVar8 = *(uint *)(iVar14 + 0xb0);
        iVar12 = *(int *)(iVar14 + 0xb4);
      }
      else {
        chacha_cipher(param_1,param_2,param_3,uVar15);
        Poly1305_Update(iVar14 + 0xd0,param_2,uVar15);
        uVar8 = *(uint *)(iVar14 + 0xb0);
        iVar12 = *(int *)(iVar14 + 0xb4);
      }
      pbVar17 = (byte *)((int)param_3 + uVar15);
      local_e0 = (uint *)((int)param_2 + uVar15);
      *(uint *)(iVar14 + 0xb0) = uVar8 + uVar15;
      *(uint *)(iVar14 + 0xb4) = iVar12 + (uint)CARRY4(uVar8,uVar15);
      uVar8 = uVar7;
      if (pbVar17 == (byte *)0x0) {
        uVar8 = uVar7 | 1;
      }
      if (uVar8 == 0) {
        return param_4;
      }
      if (pbVar17 == (byte *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = uVar7 & 1;
      }
    }
    iVar12 = iVar14 + 0xd0;
    if (*(int *)(iVar14 + 0xb8) != 0) {
      uVar8 = *(uint *)(iVar14 + 0xa8) & 0xf;
      if (uVar8 != 0) {
        Poly1305_Update(iVar12,&zero,0x10 - uVar8);
      }
      *(undefined4 *)(iVar14 + 0xb8) = 0;
    }
    uVar8 = *(uint *)(iVar14 + 0xb0) & 0xf;
    if (uVar8 != 0) {
      Poly1305_Update(iVar12,&zero,0x10 - uVar8);
    }
    Poly1305_Update(iVar12,iVar14 + 0xa8,0x10);
    puVar4 = (undefined1 *)(iVar14 + 0x84);
    if (*(int *)(param_1 + 8) == 0) {
      puVar4 = auStack_c8;
    }
    Poly1305_Final(iVar12,puVar4);
    *(undefined4 *)(iVar14 + 0xbc) = 0;
    if (uVar7 == 0) {
      if (*(int *)(param_1 + 8) != 0) {
        return param_4;
      }
      iVar14 = CRYPTO_memcmp(auStack_c8,(void *)(iVar14 + 0x84),*(size_t *)(iVar14 + 0xc0));
      if (iVar14 == 0) {
        return param_4;
      }
    }
    else {
      if (*(int *)(param_1 + 8) != 0) {
        uVar15 = *(uint *)(iVar14 + 0x88);
        uVar7 = *(uint *)(iVar14 + 0x8c);
        uVar8 = *(uint *)(iVar14 + 0x90);
        *local_e0 = *(uint *)(iVar14 + 0x84);
        local_e0[1] = uVar15;
        local_e0[2] = uVar7;
        local_e0[3] = uVar8;
        return param_4;
      }
      iVar14 = CRYPTO_memcmp(auStack_c8,pbVar17,0x10);
      if (iVar14 == 0) {
        return param_4;
      }
      memset((void *)((int)local_e0 - uVar15),0,uVar15);
    }
    return 0xffffffff;
  }
  if (uVar15 == 0xffffffff || param_2 == (uint *)0x0) {
    *(undefined4 *)(iVar14 + 0x20) = 0;
    ChaCha20_ctr32(iVar14 + 0x30,&zero,0x40,iVar14,iVar14 + 0x20);
    Poly1305_Init(iVar14 + 0xd0,iVar14 + 0x30);
    *(undefined4 *)(iVar14 + 0xb0) = 0;
    *(undefined4 *)(iVar14 + 0xb4) = 0;
    *(undefined4 *)(iVar14 + 0xa8) = 0;
    *(undefined4 *)(iVar14 + 0xac) = 0;
    *(undefined4 *)(iVar14 + 0x70) = 0;
    *(undefined4 *)(iVar14 + 0x20) = 1;
    *(undefined4 *)(iVar14 + 0xbc) = 1;
    if (uVar15 != 0xffffffff) {
      Poly1305_Update(iVar14 + 0xd0,iVar14 + 0x94,0xd);
      *(undefined4 *)(iVar14 + 0xb8) = 1;
      *(undefined4 *)(iVar14 + 0xa8) = 0xd;
      *(undefined4 *)(iVar14 + 0xac) = 0;
    }
    goto LAB_0012920e;
  }
  if (param_4 != uVar15 + 0x10) {
    return 0xffffffff;
  }
  uVar7 = -(int)auStack_c8 & 0xf;
  puVar4 = auStack_c8 + uVar7;
  local_dc = (byte *)((int)&uStack_88 + uVar7);
  if (0x40 < uVar15) {
    puVar1 = (undefined4 *)(iVar14 + 0x20);
    *puVar1 = 0;
    iVar18 = iVar14 + 0xd0;
    ChaCha20_ctr32(puVar4,&zero,0x40,iVar14,puVar1);
    Poly1305_Init(iVar18,puVar4);
    *(undefined4 *)(iVar14 + 0x20) = 1;
    *(undefined4 *)(iVar14 + 0x70) = 0;
    Poly1305_Update(iVar18,iVar14 + 0x94,0x10);
    iVar12 = *(int *)(param_1 + 8);
    *(uint *)(iVar14 + 0xb0) = uVar15;
    *(undefined4 *)(iVar14 + 0xb4) = 0;
    *(undefined4 *)(iVar14 + 0xa8) = 0xd;
    *(undefined4 *)(iVar14 + 0xac) = 0;
    if (iVar12 == 0) {
      Poly1305_Update(iVar18,param_3,uVar15);
      ChaCha20_ctr32(param_2,param_3,uVar15,iVar14,puVar1);
    }
    else {
      ChaCha20_ctr32(param_2,param_3,uVar15,iVar14,puVar1);
      Poly1305_Update(iVar18,param_2,uVar15);
    }
    local_d0 = (uint *)((int)param_3 + uVar15);
    iVar12 = 0x10;
    len = 0x40;
    Poly1305_Update(iVar18,&zero,-uVar15 & 0xf);
    local_d4 = local_dc;
    goto LAB_00129598;
  }
  *(undefined4 *)(iVar14 + 0x20) = 0;
  ChaCha20_ctr32(puVar4,&zero,0x80,iVar14,(undefined4 *)(iVar14 + 0x20));
  Poly1305_Init(iVar14 + 0xd0,puVar4);
  *(undefined4 *)(iVar14 + 0x70) = 0;
  local_d4 = abStack_98 + uVar7;
  iVar12 = *(int *)(param_1 + 8);
  uVar5 = *(undefined4 *)(iVar14 + 0x98);
  uVar9 = *(undefined4 *)(iVar14 + 0x9c);
  uVar13 = *(undefined4 *)(iVar14 + 0xa0);
  *(undefined4 *)local_d4 = *(undefined4 *)(iVar14 + 0x94);
  *(undefined4 *)((int)auStack_94 + uVar7) = uVar5;
  *(undefined4 *)((int)auStack_94 + uVar7 + 4) = uVar9;
  *(undefined4 *)((int)auStack_94 + uVar7 + 8) = uVar13;
  *(uint *)(iVar14 + 0xb0) = uVar15;
  *(undefined4 *)(iVar14 + 0xb4) = 0;
  *(undefined4 *)(iVar14 + 0xa8) = 0xd;
  *(undefined4 *)(iVar14 + 0xac) = 0;
  if (iVar12 == 0) {
    if (uVar15 == 0) goto LAB_00129970;
    if ((((uint)param_2 | (uint)param_3) & 3) == 0 &&
        (5 < uVar15 && (param_3 + 1 <= param_2 || param_2 + 1 <= param_3))) {
      uVar8 = *param_3;
      uVar6 = *(uint *)(auStack_c8 + uVar7 + 0x40);
      iVar12 = (uVar15 - 4 >> 2) + 1;
      *(uint *)(auStack_c8 + uVar7 + 0x40) = uVar8;
      uVar19 = iVar12 * 4;
      *param_2 = uVar6 ^ uVar8;
      if (iVar12 != 1) {
        uVar8 = param_3[1];
        uVar6 = *(uint *)((int)auStack_84 + uVar7);
        *(uint *)((int)auStack_84 + uVar7) = uVar8;
        param_2[1] = uVar6 ^ uVar8;
        if (iVar12 != 2) {
          uVar8 = param_3[2];
          uVar6 = *(uint *)((int)auStack_84 + uVar7 + 4);
          *(uint *)((int)auStack_84 + uVar7 + 4) = uVar8;
          param_2[2] = uVar6 ^ uVar8;
          if (iVar12 != 3) {
            uVar8 = param_3[3];
            uVar6 = *(uint *)((int)auStack_84 + uVar7 + 8);
            *(uint *)((int)auStack_84 + uVar7 + 8) = uVar8;
            param_2[3] = uVar6 ^ uVar8;
            if (iVar12 != 4) {
              uVar8 = param_3[4];
              uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0xc);
              *(uint *)((int)auStack_84 + uVar7 + 0xc) = uVar8;
              param_2[4] = uVar6 ^ uVar8;
              if (iVar12 != 5) {
                uVar8 = param_3[5];
                uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x10);
                *(uint *)((int)auStack_84 + uVar7 + 0x10) = uVar8;
                param_2[5] = uVar6 ^ uVar8;
                if (iVar12 != 6) {
                  uVar8 = param_3[6];
                  uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x14);
                  *(uint *)((int)auStack_84 + uVar7 + 0x14) = uVar8;
                  param_2[6] = uVar6 ^ uVar8;
                  if (iVar12 != 7) {
                    uVar8 = param_3[7];
                    uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x18);
                    *(uint *)((int)auStack_84 + uVar7 + 0x18) = uVar8;
                    param_2[7] = uVar6 ^ uVar8;
                    if (iVar12 != 8) {
                      uVar8 = param_3[8];
                      uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x1c);
                      *(uint *)((int)auStack_84 + uVar7 + 0x1c) = uVar8;
                      param_2[8] = uVar6 ^ uVar8;
                      if (iVar12 != 9) {
                        uVar8 = param_3[9];
                        uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x20);
                        *(uint *)((int)auStack_84 + uVar7 + 0x20) = uVar8;
                        param_2[9] = uVar6 ^ uVar8;
                        if (iVar12 != 10) {
                          uVar8 = param_3[10];
                          uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x24);
                          *(uint *)((int)auStack_84 + uVar7 + 0x24) = uVar8;
                          param_2[10] = uVar6 ^ uVar8;
                          if (iVar12 != 0xb) {
                            uVar8 = param_3[0xb];
                            uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x28);
                            *(uint *)((int)auStack_84 + uVar7 + 0x28) = uVar8;
                            param_2[0xb] = uVar6 ^ uVar8;
                            if (iVar12 != 0xc) {
                              uVar8 = param_3[0xc];
                              uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x2c);
                              *(uint *)((int)auStack_84 + uVar7 + 0x2c) = uVar8;
                              param_2[0xc] = uVar6 ^ uVar8;
                              if (iVar12 != 0xd) {
                                uVar8 = param_3[0xd];
                                uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x30);
                                *(uint *)((int)auStack_84 + uVar7 + 0x30) = uVar8;
                                param_2[0xd] = uVar6 ^ uVar8;
                                if (iVar12 != 0xe) {
                                  uVar8 = param_3[0xe];
                                  uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x34);
                                  *(uint *)((int)auStack_84 + uVar7 + 0x34) = uVar8;
                                  param_2[0xe] = uVar6 ^ uVar8;
                                  if (iVar12 == 0x10) {
                                    uVar8 = param_3[0xf];
                                    uVar6 = *(uint *)((int)auStack_84 + uVar7 + 0x38);
                                    *(uint *)((int)auStack_84 + uVar7 + 0x38) = uVar8;
                                    param_2[0xf] = uVar8 ^ uVar6;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (uVar15 != uVar19) {
        uVar8 = uVar19 + 1;
        uVar7 = param_3[iVar12];
        bVar3 = local_dc[iVar12 * 4];
        local_dc[iVar12 * 4] = (byte)uVar7;
        *(byte *)(param_2 + iVar12) = bVar3 ^ (byte)uVar7;
        if (uVar8 < uVar15) {
          bVar3 = *(byte *)((int)param_3 + uVar8);
          uVar19 = uVar19 + 2;
          bVar2 = local_dc[uVar8];
          local_dc[uVar8] = bVar3;
          *(byte *)((int)param_2 + uVar8) = bVar2 ^ bVar3;
          if (uVar19 < uVar15) {
            bVar3 = *(byte *)((int)param_3 + uVar19);
            bVar2 = local_dc[uVar19];
            local_dc[uVar19] = bVar3;
            *(byte *)((int)param_2 + uVar19) = bVar2 ^ bVar3;
          }
        }
      }
    }
    else {
      pbVar17 = (byte *)((int)param_2 + -1);
      pbVar16 = local_dc;
      puVar11 = param_3;
      do {
        puVar10 = (uint *)((int)puVar11 + 1);
        uVar7 = *puVar11;
        bVar3 = *pbVar16;
        *pbVar16 = (byte)uVar7;
        pbVar17 = pbVar17 + 1;
        *pbVar17 = (byte)uVar7 ^ bVar3;
        pbVar16 = pbVar16 + 1;
        puVar11 = puVar10;
      } while (puVar10 != (uint *)((int)param_3 + uVar15));
    }
LAB_0012956e:
    param_3 = (uint *)((int)param_3 + uVar15);
    uVar8 = uVar15 + (-uVar15 & 0xf);
    iVar12 = uVar8 + 0x20;
    uVar7 = -uVar15 & 0xf;
  }
  else {
    if (uVar15 != 0) {
      if ((((uint)param_2 | (uint)param_3) & 3) == 0 &&
          (5 < uVar15 && (param_2 + 1 <= param_3 || param_3 + 1 <= param_2))) {
        iVar12 = (uVar15 - 4 >> 2) + 1;
        uVar8 = *param_3 ^ *(uint *)(auStack_c8 + uVar7 + 0x40);
        *(uint *)(auStack_c8 + uVar7 + 0x40) = uVar8;
        uVar6 = iVar12 * 4;
        *param_2 = uVar8;
        if (iVar12 != 1) {
          uVar8 = param_3[1] ^ *(uint *)((int)auStack_84 + uVar7);
          *(uint *)((int)auStack_84 + uVar7) = uVar8;
          param_2[1] = uVar8;
          if (iVar12 != 2) {
            uVar8 = param_3[2] ^ *(uint *)((int)auStack_84 + uVar7 + 4);
            *(uint *)((int)auStack_84 + uVar7 + 4) = uVar8;
            param_2[2] = uVar8;
            if (iVar12 != 3) {
              uVar8 = param_3[3] ^ *(uint *)((int)auStack_84 + uVar7 + 8);
              *(uint *)((int)auStack_84 + uVar7 + 8) = uVar8;
              param_2[3] = uVar8;
              if (iVar12 != 4) {
                uVar8 = param_3[4] ^ *(uint *)((int)auStack_84 + uVar7 + 0xc);
                *(uint *)((int)auStack_84 + uVar7 + 0xc) = uVar8;
                param_2[4] = uVar8;
                if (iVar12 != 5) {
                  uVar8 = param_3[5] ^ *(uint *)((int)auStack_84 + uVar7 + 0x10);
                  *(uint *)((int)auStack_84 + uVar7 + 0x10) = uVar8;
                  param_2[5] = uVar8;
                  if (iVar12 != 6) {
                    uVar8 = param_3[6] ^ *(uint *)((int)auStack_84 + uVar7 + 0x14);
                    *(uint *)((int)auStack_84 + uVar7 + 0x14) = uVar8;
                    param_2[6] = uVar8;
                    if (iVar12 != 7) {
                      uVar8 = param_3[7] ^ *(uint *)((int)auStack_84 + uVar7 + 0x18);
                      *(uint *)((int)auStack_84 + uVar7 + 0x18) = uVar8;
                      param_2[7] = uVar8;
                      if (iVar12 != 8) {
                        uVar8 = param_3[8] ^ *(uint *)((int)auStack_84 + uVar7 + 0x1c);
                        *(uint *)((int)auStack_84 + uVar7 + 0x1c) = uVar8;
                        param_2[8] = uVar8;
                        if (iVar12 != 9) {
                          uVar8 = param_3[9] ^ *(uint *)((int)auStack_84 + uVar7 + 0x20);
                          *(uint *)((int)auStack_84 + uVar7 + 0x20) = uVar8;
                          param_2[9] = uVar8;
                          if (iVar12 != 10) {
                            uVar8 = param_3[10] ^ *(uint *)((int)auStack_84 + uVar7 + 0x24);
                            *(uint *)((int)auStack_84 + uVar7 + 0x24) = uVar8;
                            param_2[10] = uVar8;
                            if (iVar12 != 0xb) {
                              uVar8 = param_3[0xb] ^ *(uint *)((int)auStack_84 + uVar7 + 0x28);
                              *(uint *)((int)auStack_84 + uVar7 + 0x28) = uVar8;
                              param_2[0xb] = uVar8;
                              if (iVar12 != 0xc) {
                                uVar8 = param_3[0xc] ^ *(uint *)((int)auStack_84 + uVar7 + 0x2c);
                                *(uint *)((int)auStack_84 + uVar7 + 0x2c) = uVar8;
                                param_2[0xc] = uVar8;
                                if (iVar12 != 0xd) {
                                  uVar8 = param_3[0xd] ^ *(uint *)((int)auStack_84 + uVar7 + 0x30);
                                  *(uint *)((int)auStack_84 + uVar7 + 0x30) = uVar8;
                                  param_2[0xd] = uVar8;
                                  if (iVar12 != 0xe) {
                                    uVar8 = param_3[0xe] ^ *(uint *)((int)auStack_84 + uVar7 + 0x34)
                                    ;
                                    *(uint *)((int)auStack_84 + uVar7 + 0x34) = uVar8;
                                    param_2[0xe] = uVar8;
                                    if (iVar12 == 0x10) {
                                      uVar8 = param_3[0xf] ^
                                              *(uint *)((int)auStack_84 + uVar7 + 0x38);
                                      *(uint *)((int)auStack_84 + uVar7 + 0x38) = uVar8;
                                      param_2[0xf] = uVar8;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if (uVar15 != uVar6) {
          uVar7 = uVar6 + 1;
          bVar3 = local_dc[iVar12 * 4] ^ (byte)param_3[iVar12];
          local_dc[iVar12 * 4] = bVar3;
          *(byte *)(param_2 + iVar12) = bVar3;
          if (uVar7 < uVar15) {
            uVar6 = uVar6 + 2;
            bVar3 = local_dc[uVar7] ^ *(byte *)((int)param_3 + uVar7);
            local_dc[uVar7] = bVar3;
            *(byte *)((int)param_2 + uVar7) = bVar3;
            if (uVar6 < uVar15) {
              bVar3 = local_dc[uVar6] ^ *(byte *)((int)param_3 + uVar6);
              local_dc[uVar6] = bVar3;
              *(byte *)((int)param_2 + uVar6) = bVar3;
            }
          }
        }
      }
      else {
        pbVar17 = (byte *)((int)param_2 + -1);
        pbVar16 = local_dc;
        puVar11 = param_3;
        do {
          puVar10 = (uint *)((int)puVar11 + 1);
          bVar3 = (byte)*puVar11 ^ *pbVar16;
          *pbVar16 = bVar3;
          pbVar17 = pbVar17 + 1;
          *pbVar17 = bVar3;
          pbVar16 = pbVar16 + 1;
          puVar11 = puVar10;
        } while (puVar10 != (uint *)((int)param_3 + uVar15));
      }
      goto LAB_0012956e;
    }
LAB_00129970:
    iVar12 = 0x20;
    uVar7 = uVar15;
    uVar8 = uVar15;
  }
  pbVar17 = local_dc + uVar15;
  local_dc = local_dc + uVar8;
  len = 0x80;
  memset(pbVar17,0,uVar7);
  local_d0 = param_3;
LAB_00129598:
  pbVar16 = (byte *)((int)param_2 + uVar15);
  uVar9 = *(undefined4 *)(iVar14 + 0xa8);
  uVar13 = *(undefined4 *)(iVar14 + 0xb0);
  uVar5 = *(undefined4 *)(iVar14 + 0xb4);
  *(undefined4 *)(local_dc + 4) = *(undefined4 *)(iVar14 + 0xac);
  *(undefined4 *)(local_dc + 8) = uVar13;
  *(undefined4 *)(local_dc + 0xc) = uVar5;
  *(undefined4 *)local_dc = uVar9;
  Poly1305_Update(iVar14 + 0xd0,local_d4,iVar12);
  OPENSSL_cleanse(puVar4,len);
  pbVar17 = (byte *)(iVar14 + 0x84);
  if (*(int *)(param_1 + 8) == 0) {
    pbVar17 = local_d4;
  }
  Poly1305_Final(iVar14 + 0xd0,pbVar17);
  *(undefined4 *)(iVar14 + 200) = 0xffffffff;
  if (*(int *)(param_1 + 8) == 0) {
    iVar14 = CRYPTO_memcmp(local_d4,local_d0,0x10);
    if (iVar14 != 0) {
      memset(pbVar16 + (0x10 - param_4),0,param_4 - 0x10);
      return 0xffffffff;
    }
    return param_4;
  }
  uVar5 = *(undefined4 *)(iVar14 + 0x88);
  uVar9 = *(undefined4 *)(iVar14 + 0x8c);
  uVar13 = *(undefined4 *)(iVar14 + 0x90);
  *(undefined4 *)pbVar16 = *(undefined4 *)(iVar14 + 0x84);
  *(undefined4 *)(pbVar16 + 4) = uVar5;
  *(undefined4 *)(pbVar16 + 8) = uVar9;
  *(undefined4 *)(pbVar16 + 0xc) = uVar13;
  return param_4;
}

