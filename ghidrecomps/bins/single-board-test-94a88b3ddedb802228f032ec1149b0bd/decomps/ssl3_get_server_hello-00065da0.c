
int ssl3_get_server_hello(uint *param_1)

{
  int iVar1;
  int iVar2;
  void *data;
  _STACK *st;
  SSL_METHOD *pSVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  undefined4 uVar11;
  code *pcVar12;
  undefined4 uVar13;
  bool bVar14;
  byte *local_2c;
  int local_28;
  int local_24;
  
  uVar8 = param_1[0x26];
  uVar5 = *(uint *)(*(int *)(param_1[2] + 100) + 0x38);
  bVar14 = (int)(uVar5 << 0x1c) < 0;
  if (bVar14) {
    uVar5 = 1;
  }
  if (bVar14) {
    param_1[0x43] = uVar5;
  }
  iVar1 = (**(code **)(param_1[2] + 0x30))(param_1,0x1120,0x1121,0xffffffff,20000,&local_28);
  if (local_28 == 0) {
    return iVar1;
  }
  uVar5 = param_1[0x16];
  if (((*(uint *)(((int *)param_1[2])[0x19] + 0x38) & 8) == 0) ||
     (param_1[0x43] = 0, *(int *)(uVar5 + 0x340) != 3)) {
    if (*(int *)(uVar5 + 0x340) != 2) {
      iVar1 = 0x3a8;
      goto LAB_00066176;
    }
    pbVar9 = (byte *)param_1[0x10];
    local_2c = pbVar9;
    if (*(int *)param_1[2] == 0x1ffff) {
      uVar5 = (uint)CONCAT11(*pbVar9,pbVar9[1]);
      if (uVar5 == 0xfefd) {
        if ((int)(param_1[0x40] << 4) < 0) {
          if ((*(uint *)(param_1[0x26] + 0x38) & 0x30000) == 0) goto LAB_00066158;
          goto LAB_00066216;
        }
        pSVar3 = (SSL_METHOD *)DTLSv1_2_client_method();
        param_1[2] = (uint)pSVar3;
LAB_0006609a:
        uVar5 = pSVar3->version;
        *param_1 = uVar5;
        *(uint *)param_1[0x30] = uVar5;
        goto LAB_00065e18;
      }
      if ((*(uint *)(param_1[0x26] + 0x38) & 0x30000) == 0) {
        if ((uVar5 == 0xfeff) && (-1 < (int)(param_1[0x40] << 5))) {
          pSVar3 = DTLSv1_client_method();
          param_1[2] = (uint)pSVar3;
          goto LAB_0006609a;
        }
LAB_00066158:
        ERR_put_error(0x14,0x92,0x10a,DAT_00066280,0x3bc);
        *param_1 = uVar5;
        uVar7 = 0x46;
      }
      else {
LAB_00066216:
        ERR_put_error(0x14,0x92,0x183,DAT_00066280,0x3b5);
        *param_1 = uVar5;
        uVar7 = 0x46;
      }
    }
    else {
      uVar5 = *param_1;
LAB_00065e18:
      if (((uint)*local_2c == (int)uVar5 >> 8) && ((uint)local_2c[1] == (uVar5 & 0xff))) {
        uVar5 = param_1[0x16];
        pbVar6 = local_2c + 0x23;
        uVar11 = *(undefined4 *)(local_2c + 6);
        uVar13 = *(undefined4 *)(local_2c + 10);
        uVar7 = *(undefined4 *)(local_2c + 0xe);
        *(undefined4 *)(uVar5 + 0xa0) = *(undefined4 *)(local_2c + 2);
        *(undefined4 *)(uVar5 + 0xa4) = uVar11;
        *(undefined4 *)(uVar5 + 0xa8) = uVar13;
        *(undefined4 *)(uVar5 + 0xac) = uVar7;
        uVar7 = *(undefined4 *)(local_2c + 0x1e);
        uVar11 = *(undefined4 *)(local_2c + 0x16);
        uVar13 = *(undefined4 *)(local_2c + 0x1a);
        *(undefined4 *)(uVar5 + 0xb0) = *(undefined4 *)(local_2c + 0x12);
        *(undefined4 *)(uVar5 + 0xb4) = uVar11;
        *(undefined4 *)(uVar5 + 0xb8) = uVar13;
        *(undefined4 *)(uVar5 + 0xbc) = uVar7;
        param_1[0x1b] = 0;
        uVar5 = (uint)local_2c[0x22];
        local_2c = pbVar6;
        if (uVar5 < 0x21) {
          if ((int)*param_1 < 0x301) {
            uVar10 = param_1[0x30];
LAB_00066018:
            uVar4 = *(uint *)(uVar10 + 0x44);
            if (uVar5 == 0) goto LAB_00065eea;
LAB_00066022:
            pbVar6 = local_2c;
            if (uVar4 != uVar5) goto LAB_00065eea;
            iVar2 = memcmp(local_2c,(void *)(uVar10 + 0x48),uVar5);
            if (iVar2 != 0) goto LAB_000660a8;
            if ((param_1[0x27] != *(size_t *)(uVar10 + 0x68)) ||
               (iVar2 = memcmp((void *)(uVar10 + 0x6c),param_1 + 0x28,param_1[0x27]), iVar2 != 0)) {
              ERR_put_error(0x14,0x92,0x110,DAT_00066280,0x401);
              uVar7 = 0x2f;
              goto LAB_000660e2;
            }
            param_1[0x1b] = 1;
LAB_00065f04:
            local_2c = pbVar6 + uVar5;
            data = (void *)ssl_get_cipher_by_char(param_1,local_2c);
            pbVar6 = local_2c;
            if (data == (void *)0x0) {
              ERR_put_error(0x14,0x92,0xf8,DAT_00066280,0x41a);
              uVar7 = 0x2f;
            }
            else {
              if ((((*(uint *)(uVar8 + 0x18) & *(uint *)((int)data + 0x1c)) == 0) &&
                  ((*(uint *)(uVar8 + 8) & *(uint *)((int)data + 0xc)) == 0)) &&
                 ((*(uint *)(uVar8 + 0xc) & *(uint *)((int)data + 0x10)) == 0)) {
                iVar2 = (**(code **)(param_1[2] + 0x4c))(0,0);
                local_2c = pbVar6 + iVar2;
                st = (_STACK *)ssl_get_ciphers_by_id(param_1);
                iVar2 = sk_find(st,data);
                if (-1 < iVar2) {
                  uVar5 = param_1[0x30];
                  if (*(int *)(uVar5 + 0xb4) != 0) {
                    *(undefined4 *)(uVar5 + 0xb8) = *(undefined4 *)(*(int *)(uVar5 + 0xb4) + 8);
                  }
                  uVar8 = param_1[0x1b];
                  if ((uVar8 == 0) || (*(int *)(uVar5 + 0xb8) == *(int *)((int)data + 8))) {
                    iVar2 = *(int *)(param_1[2] + 100);
                    *(void **)(param_1[0x16] + 0x344) = data;
                    if (-1 < *(int *)(iVar2 + 0x38) << 0x1e) {
                      iVar2 = ssl3_digest_cached_records(param_1);
                      if (iVar2 == 0) goto LAB_000661a8;
                      uVar8 = param_1[0x1b];
                    }
                    pbVar6 = local_2c + 1;
                    if ((uVar8 == 0) || (*(uint *)(param_1[0x30] + 0xb0) == (uint)*local_2c)) {
                      if (*local_2c == 0) {
                        iVar2 = 0;
                        local_2c = pbVar6;
LAB_00065fc4:
                        *(int *)(param_1[0x16] + 0x38c) = iVar2;
                        iVar2 = ssl_parse_serverhello_tlsext(param_1,&local_2c,pbVar9,iVar1);
                        if (iVar2 == 0) {
                          ERR_put_error(0x14,0x92,0xe3,DAT_00066280,0x47b);
                          goto LAB_000660ea;
                        }
                        if (local_2c == pbVar9 + iVar1) {
                          return 1;
                        }
                        ERR_put_error(0x14,0x92,0x73,DAT_00066280,0x483);
                        uVar7 = 0x32;
                      }
                      else if ((int)(param_1[0x40] << 0xe) < 0) {
                        local_2c = pbVar6;
                        ERR_put_error(0x14,0x92,0x157,DAT_00066280,0x469);
                        uVar7 = 0x2f;
                      }
                      else {
                        local_2c = pbVar6;
                        iVar2 = ssl3_comp_find(*(undefined4 *)(param_1[0x39] + 0x98));
                        if (iVar2 != 0) goto LAB_00065fc4;
                        ERR_put_error(0x14,0x92,0x101,DAT_00066280,0x471);
                        uVar7 = 0x2f;
                      }
                    }
                    else {
                      local_2c = pbVar6;
                      ERR_put_error(0x14,0x92,0x158,DAT_00066280,0x462);
                      uVar7 = 0x2f;
                    }
                  }
                  else {
                    ERR_put_error(0x14,0x92,0xc5,DAT_00066280,0x441);
                    uVar7 = 0x2f;
                  }
                  goto LAB_000660e2;
                }
                iVar1 = 0x42e;
              }
              else {
                iVar1 = 0x424;
              }
              ERR_put_error(0x14,0x92,0x105,DAT_00066280,iVar1);
              uVar7 = 0x2f;
            }
          }
          else {
            pcVar12 = (code *)param_1[0x5a];
            uVar10 = param_1[0x30];
            if ((pcVar12 == (code *)0x0) || (*(int *)(uVar10 + 0xe4) == 0)) goto LAB_00066018;
            uVar4 = param_1[0x5b];
            local_24 = 0;
            *(undefined4 *)(uVar10 + 0x10) = 0x30;
            iVar2 = (*pcVar12)(param_1,uVar10 + 0x14,uVar10 + 0x10,0,&local_24,uVar4);
            if (iVar2 == 0) {
              ERR_put_error(0x14,0x92,0x44,DAT_00066280,0x3f3);
              uVar7 = 0x50;
              goto LAB_000660e2;
            }
            uVar4 = param_1[0x30];
            iVar2 = local_24;
            uVar10 = uVar4;
            if (local_24 == 0) {
              iVar2 = ssl_get_cipher_by_char(param_1,local_2c + uVar5);
              uVar10 = param_1[0x30];
            }
            *(int *)(uVar4 + 0xb4) = iVar2;
            uVar4 = *(uint *)(uVar10 + 0x44);
            if (uVar5 != 0) goto LAB_00066022;
LAB_00065eea:
            if (uVar4 == 0) {
LAB_00065ef0:
              *(uint *)(uVar10 + 0x44) = uVar5;
              memcpy((void *)(uVar10 + 0x48),local_2c,uVar5);
              pbVar6 = local_2c;
              goto LAB_00065f04;
            }
LAB_000660a8:
            iVar2 = ssl_get_new_session(param_1,0);
            if (iVar2 != 0) {
              uVar10 = param_1[0x30];
              goto LAB_00065ef0;
            }
LAB_000661a8:
            uVar7 = 0x50;
          }
        }
        else {
          ERR_put_error(0x14,0x92,300,DAT_00066280,0x3d8);
          uVar7 = 0x2f;
        }
      }
      else {
        ERR_put_error(0x14,0x92,0x10a,DAT_00066280,0x3c5);
        uVar7 = 0x46;
        *param_1 = *param_1 & 0xff00 | (uint)local_2c[1];
      }
    }
  }
  else {
    if (*(int *)param_1[0x17] == 0) {
      *(undefined4 *)(uVar5 + 0x354) = 1;
      return 1;
    }
    iVar1 = 0x3a0;
LAB_00066176:
    ERR_put_error(0x14,0x92,0x72,DAT_00066280,iVar1);
    uVar7 = 10;
  }
LAB_000660e2:
  ssl3_send_alert(param_1,2,uVar7);
LAB_000660ea:
  param_1[0xd] = 5;
  return -1;
}

