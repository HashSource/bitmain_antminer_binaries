
undefined4 Curl_setopt(int param_1,uint param_2,uint *param_3)

{
  size_t *psVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  void *__dest;
  int *piVar7;
  uint *puVar8;
  char *pcVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  undefined4 unaff_r4;
  uint uVar15;
  void *__src;
  bool bVar16;
  
  if (param_2 == 0x2717) {
    uVar4 = setstropt(param_1 + 900,*param_3);
    return uVar4;
  }
  if (param_2 < 0x2718) {
    if (param_2 == 0x72) {
      uVar14 = *param_3;
      *(uint *)(param_1 + 0x2e0) = uVar14;
      *(int *)(param_1 + 0x2e4) = (int)uVar14 >> 0x1f;
      return 0;
    }
    if (param_2 < 0x73) {
      if (param_2 == 0x3c) {
        uVar14 = *param_3;
        iVar5 = *(int *)(param_1 + 0x19c);
        iVar11 = (int)uVar14 >> 0x1f;
        bVar16 = *(uint *)(param_1 + 0x198) < uVar14;
        if (((int)((iVar5 - iVar11) - (uint)bVar16) < 0 !=
             (SBORROW4(iVar5,iVar11) != SBORROW4(iVar5 - iVar11,(uint)bVar16))) &&
           (*(int *)(param_1 + 0x18c) == *(int *)(param_1 + 0x3f4))) {
          setstropt(param_1 + 0x3f4,0);
          *(undefined4 *)(param_1 + 0x18c) = 0;
        }
        *(uint *)(param_1 + 0x198) = uVar14;
        *(int *)(param_1 + 0x19c) = iVar11;
        return 0;
      }
      if (param_2 < 0x3d) {
        if (param_2 == 0x2b) {
          uVar14 = *param_3;
          if (uVar14 != 0) {
            uVar14 = 1;
          }
          *(char *)(param_1 + 0x2ff) = (char)uVar14;
          if (uVar14 == 0) {
            *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) & 0xffffffef;
            return 0;
          }
          *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) | 0x10;
          return 0;
        }
        if (param_2 < 0x2c) {
          if (param_2 == 0x15) {
            uVar14 = *param_3;
            *(uint *)(param_1 + 0x238) = uVar14;
            *(int *)(param_1 + 0x23c) = (int)uVar14 >> 0x1f;
            return 0;
          }
          if (param_2 < 0x16) {
            if (param_2 == 0xe) {
              uVar14 = *param_3;
              *(uint *)(param_1 + 0x218) = uVar14;
              *(int *)(param_1 + 0x21c) = (int)uVar14 >> 0x1f;
              return 0;
            }
            if (param_2 < 0xf) {
              if (param_2 == 3) {
                *(uint *)(param_1 + 0x170) = *param_3;
                return 0;
              }
              if (param_2 == 0xd) {
                *(uint *)(param_1 + 0x200) = *param_3 * 1000;
                return 0;
              }
            }
            else {
              if (param_2 == 0x13) {
                *(uint *)(param_1 + 0x220) = *param_3;
                return 0;
              }
              if (param_2 == 0x14) {
                *(uint *)(param_1 + 0x224) = *param_3;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x21) {
              *(uint *)(param_1 + 0x270) = *param_3;
              return 0;
            }
            if (param_2 < 0x22) {
              if (param_2 == 0x1b) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x24e) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x20) {
                *(uint *)(param_1 + 0x280) = *param_3;
                return 0;
              }
            }
            else {
              if (param_2 == 0x29) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x310) = (char)uVar14;
                return 0;
              }
              if (0x29 < param_2) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x304) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x22) {
                *(uint *)(param_1 + 0x274) = *param_3;
                return 0;
              }
            }
          }
        }
        else {
          if (param_2 == 0x32) {
            uVar14 = *param_3;
            if (uVar14 != 0) {
              uVar14 = 1;
            }
            *(char *)(param_1 + 0x2fc) = (char)uVar14;
            return 0;
          }
          if (param_2 < 0x33) {
            if (param_2 == 0x2e) {
LAB_0004449a:
              uVar14 = *param_3;
              if (uVar14 != 0) {
                uVar14 = 1;
              }
              *(char *)(param_1 + 0x309) = (char)uVar14;
              if (uVar14 == 0) {
                *(undefined4 *)(param_1 + 0x278) = 1;
                return 0;
              }
              *(undefined4 *)(param_1 + 0x278) = 4;
              *(undefined1 *)(param_1 + 0x307) = 0;
              return 0;
            }
            if (param_2 < 0x2f) {
              if (param_2 == 0x2c) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x307) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x2d) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x300) = (char)uVar14;
                return 0;
              }
            }
            else {
              if (param_2 == 0x2f) {
                if (*param_3 == 0) {
                  *(undefined4 *)(param_1 + 0x278) = 1;
                  return 0;
                }
                *(undefined4 *)(param_1 + 0x278) = 2;
                *(undefined1 *)(param_1 + 0x307) = 0;
                return 0;
              }
              if (param_2 == 0x30) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x2fd) = (char)uVar14;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x35) {
              uVar14 = *param_3;
              if (uVar14 != 0) {
                uVar14 = 1;
              }
              *(char *)(param_1 + 0x2fb) = (char)uVar14;
              return 0;
            }
            if (param_2 < 0x36) {
              if (param_2 == 0x33) {
                *(uint *)(param_1 + 0x30c) = *param_3;
                return 0;
              }
              if (param_2 == 0x34) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x301) = (char)uVar14;
                return 0;
              }
            }
            else {
              if (param_2 == 0x3a) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x306) = (char)uVar14;
                return 0;
              }
              if (0x3a < param_2) {
                *(uint *)(param_1 + 0x15c) = *param_3;
                return 0;
              }
              if (param_2 == 0x36) goto LAB_0004449a;
            }
          }
        }
      }
      else {
        if (param_2 == 0x5a) {
          uVar4 = Curl_ssl_set_engine_default();
          return uVar4;
        }
        if (param_2 < 0x5b) {
          if (param_2 == 0x4a) {
            uVar14 = *param_3;
            if (uVar14 != 0) {
              uVar14 = 1;
            }
            *(char *)(param_1 + 0x313) = (char)uVar14;
            return 0;
          }
          if (param_2 < 0x4b) {
            if (param_2 == 0x44) {
              *(uint *)(param_1 + 0x180) = *param_3;
              return 0;
            }
            if (param_2 < 0x45) {
              if (param_2 == 0x3d) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x2fa) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x40) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x288) = (char)uVar14;
                return 0;
              }
            }
            else {
              if (param_2 == 0x45) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x2f9) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x47) {
                *(uint *)(param_1 + 0x438) = *param_3;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x50) {
              if (*param_3 == 0) {
                return 0;
              }
              *(undefined4 *)(param_1 + 0x278) = 1;
              *(undefined1 *)(param_1 + 0x309) = 0;
              *(undefined1 *)(param_1 + 0x307) = 0;
              return 0;
            }
            if (param_2 < 0x51) {
              if (param_2 == 0x4b) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x312) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x4e) {
                *(uint *)(param_1 + 0x204) = *param_3 * 1000;
                return 0;
              }
            }
            else {
              if (param_2 == 0x54) {
                if ((int)*param_3 < 3) {
                  *(uint *)(param_1 + 0x27c) = *param_3;
                  return 0;
                }
                return 1;
              }
              if (param_2 == 0x55) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x314) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x51) {
                uVar14 = *param_3;
                if (uVar14 == 1) {
                  Curl_failf(param_1,"CURLOPT_SSL_VERIFYHOST no longer supports 1 as value!");
                  return 0x2b;
                }
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x289) = (char)uVar14;
                return 0;
              }
            }
          }
        }
        else {
          if (param_2 == 0x69) {
            uVar14 = *param_3;
            if (uVar14 != 0) {
              uVar14 = 1;
            }
            *(char *)(param_1 + 0x303) = (char)uVar14;
            return 0;
          }
          if (0x69 < param_2) {
            if (param_2 == 0x6e) {
              uVar14 = *param_3;
              if (uVar14 == 1) {
                *(undefined4 *)(param_1 + 0x2ec) = 1;
                return 0;
              }
              if (uVar14 == 2) {
                *(undefined4 *)(param_1 + 0x2ec) = 2;
                return 0;
              }
              if (uVar14 != 0) {
                return 0x30;
              }
              *(undefined4 *)(param_1 + 0x2ec) = 0;
              return 0;
            }
            if (param_2 < 0x6f) {
              if (param_2 == 0x6a) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x315) = (char)uVar14;
                return 0;
              }
              if (param_2 != 0x6b) {
                return 0x30;
              }
              uVar14 = *param_3;
              if (uVar14 == 0) {
                *(undefined4 *)(param_1 + 0x174) = 0;
                return 0;
              }
              *(byte *)(param_1 + 0x862e) = (byte)((uVar14 << 0x1b) >> 0x1f);
              if ((int)(uVar14 << 0x1b) < 0) {
                uVar14 = uVar14 & 0xffffffef | 2;
              }
              uVar15 = 0;
              do {
                uVar2 = uVar15 & 0xff;
                uVar15 = uVar15 + 1;
                if ((int)(((uVar14 & 0xfffffffb) >> uVar2) << 0x1f) < 0) {
                  *(uint *)(param_1 + 0x174) = uVar14 & 0xfffffffb;
                  return 0;
                }
              } while (uVar15 != 0x1f);
            }
            else {
              if (param_2 == 0x70) {
                *(uint *)(param_1 + 0x20c) = *param_3 * 1000;
                return 0;
              }
              if (0x70 < param_2) {
                *(uint *)(param_1 + 0x2d8) = *param_3;
                return 0;
              }
              uVar14 = *param_3;
              if (uVar14 == 0) {
                *(undefined4 *)(param_1 + 0x178) = 0;
                return 0;
              }
              *(byte *)(param_1 + 0x863e) = (byte)((uVar14 << 0x1b) >> 0x1f);
              if ((int)(uVar14 << 0x1b) < 0) {
                uVar14 = uVar14 & 0xffffffef | 2;
              }
              uVar15 = 0;
              do {
                uVar2 = uVar15 & 0xff;
                uVar15 = uVar15 + 1;
                if ((int)(((uVar14 & 0xfffffffb) >> uVar2) << 0x1f) < 0) {
                  *(uint *)(param_1 + 0x178) = uVar14 & 0xfffffffb;
                  return 0;
                }
              } while (uVar15 != 0x1f);
            }
            return 4;
          }
          if (param_2 == 0x60) {
            uVar14 = *param_3;
            if (uVar14 != 0) {
              uVar14 = 1;
            }
            *(char *)(param_1 + 0x24d) = (char)uVar14;
            return 0;
          }
          if (param_2 < 0x61) {
            if (param_2 == 0x5b) {
              uVar14 = *param_3;
              if (uVar14 != 0) {
                uVar14 = 1;
              }
              *(char *)(param_1 + 0x325) = (char)uVar14;
              return 0;
            }
            if (param_2 == 0x5c) {
              *(uint *)(param_1 + 0x2c8) = *param_3;
              return 0;
            }
          }
          else {
            if (param_2 == 99) {
              uVar14 = *param_3;
              if (uVar14 != 0) {
                uVar14 = 1;
              }
              *(char *)(param_1 + 0x324) = (char)uVar14;
              return 0;
            }
            if (param_2 == 0x65) {
              *(uint *)(param_1 + 0x2c4) = *param_3;
              return 0;
            }
            if (param_2 == 0x62) {
              uVar14 = *param_3 - 1;
              *(uint *)(param_1 + 0x2cc) = *param_3;
              if (0x3ffe < uVar14) {
                unaff_r4 = 0;
              }
              if (uVar14 < 0x3fff) {
                return 0;
              }
              *(undefined4 *)(param_1 + 0x2cc) = unaff_r4;
              return unaff_r4;
            }
          }
        }
      }
    }
    else {
      if (param_2 == 0xbd) {
        if (*param_3 - 1 < 0xb) {
          uVar4 = (&CSWTCH_162)[*param_3 - 1];
        }
        else {
          uVar4 = 0;
        }
        *(undefined4 *)(param_1 + 0x40c) = uVar4;
        return 0;
      }
      if (param_2 < 0xbe) {
        if (param_2 == 0x9c) {
          *(uint *)(param_1 + 0x204) = *param_3;
          return 0;
        }
        if (param_2 < 0x9d) {
          if (param_2 == 0x8a) {
            *(uint *)(param_1 + 0x2e8) = *param_3;
            return 0;
          }
          if (param_2 < 0x8b) {
            if (param_2 == 0x81) {
              *(uint *)(param_1 + 0x31c) = *param_3;
              return 0;
            }
            if (param_2 < 0x82) {
              if (param_2 == 0x77) {
                *(uint *)(param_1 + 0x318) = *param_3;
                return 0;
              }
              if (param_2 == 0x79) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x326) = (char)uVar14;
                return 0;
              }
            }
            else {
              if (param_2 == 0x88) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x327) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x89) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x328) = (char)uVar14;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x8d) {
              uVar14 = *param_3;
              if (uVar14 != 0) {
                uVar14 = 1;
              }
              *(char *)(param_1 + 0x329) = (char)uVar14;
              return 0;
            }
            if (param_2 < 0x8e) {
              if (param_2 == 0x8b) {
                uVar3 = curlx_sltous(*param_3);
                *(undefined2 *)(param_1 + 0x1a0) = uVar3;
                return 0;
              }
              if (param_2 == 0x8c) {
                uVar4 = curlx_sltosi(*param_3);
                *(undefined4 *)(param_1 + 0x1a4) = uVar4;
                return 0;
              }
            }
            else {
              if (param_2 == 0x9a) {
                *(uint *)(param_1 + 800) = *param_3;
                return 0;
              }
              if (0x9a < param_2) {
                *(uint *)(param_1 + 0x200) = *param_3;
                return 0;
              }
              if (param_2 == 0x96) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x2b4) = (char)uVar14;
                return 0;
              }
            }
          }
        }
        else {
          if (param_2 == 0xa6) {
            if (*param_3 == 0) {
              *(undefined1 *)(param_1 + 0x33c) = 0;
              return 0;
            }
            if (*param_3 != 1) {
              return 0x30;
            }
            *(undefined1 *)(param_1 + 0x33c) = 1;
            return 0;
          }
          if (param_2 < 0xa7) {
            if (param_2 == 0x9f) {
              *(uint *)(param_1 + 0x334) = *param_3;
              return 0;
            }
            if (param_2 < 0xa0) {
              if (param_2 == 0x9d) {
                *(bool *)(param_1 + 0x330) = *param_3 == 0;
                return 0;
              }
              if (param_2 == 0x9e) {
                *(bool *)(param_1 + 0x331) = *param_3 == 0;
                return 0;
              }
            }
            else {
              if (param_2 == 0xa0) {
                *(uint *)(param_1 + 0x338) = *param_3;
                return 0;
              }
              if (param_2 == 0xa1) {
                uVar14 = curlx_sltosi(*param_3);
                *(uint *)(param_1 + 0x184) = uVar14 & 7;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0xb2) {
              *(uint *)(param_1 + 0x210) = *param_3;
              return 0;
            }
            if (param_2 < 0xb3) {
              if (param_2 == 0xab) {
                uVar4 = curlx_sltoui(*param_3);
                *(undefined4 *)(param_1 + 0x3f8) = uVar4;
                return 0;
              }
              if (param_2 == 0xac) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x2b5) = (char)uVar14;
                return 0;
              }
            }
            else {
              if (param_2 == 0xb6) {
                *(uint *)(param_1 + 0x400) = *param_3;
                return 0;
              }
              if (param_2 == 0xbc) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x316) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0xb5) {
                *(uint *)(param_1 + 0x3fc) = *param_3;
                return 0;
              }
            }
          }
        }
      }
      else {
        if (param_2 == 0xe2) {
          uVar14 = *param_3;
          if (uVar14 != 0) {
            uVar14 = 1;
          }
          *(char *)(param_1 + 0x43d) = (char)uVar14;
          return 0;
        }
        if (param_2 < 0xe3) {
          if (param_2 == 0xd4) {
            *(uint *)(param_1 + 0x208) = *param_3;
            return 0;
          }
          if (param_2 < 0xd5) {
            if (param_2 == 0xc5) {
              uVar14 = *param_3;
              if (uVar14 != 0) {
                uVar14 = 1;
              }
              *(char *)(param_1 + 0x414) = (char)uVar14;
              return 0;
            }
            if (param_2 < 0xc6) {
              if (param_2 == 0xc1) {
                *(uint *)(param_1 + 0x86a0) = *param_3;
                return 0;
              }
              if (param_2 == 0xc2) {
                *(uint *)(param_1 + 0x86a0) = *param_3;
                return 0;
              }
            }
            else {
              if (param_2 == 0xcf) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x302) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0xd2) {
                *(uint *)(param_1 + 0x428) = *param_3;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0xd7) {
              *(uint *)(param_1 + 0x434) = *param_3;
              return 0;
            }
            if (param_2 < 0xd8) {
              if (param_2 == 0xd5) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x42c) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0xd6) {
                *(uint *)(param_1 + 0x430) = *param_3;
                return 0;
              }
            }
            else {
              if (param_2 == 0xda) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x408) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0xe1) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x43c) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0xd8) {
                uVar14 = *param_3;
                *(byte *)(param_1 + 0x32a) = (byte)uVar14 & 1;
                *(byte *)(param_1 + 0x32b) = (byte)((uVar14 << 0x1e) >> 0x1f);
                return 0;
              }
            }
          }
        }
        else {
          if (param_2 == 0xef) {
            return 4;
          }
          if (param_2 < 0xf0) {
            if (param_2 == 0xe8) {
              iVar5 = Curl_ssl_cert_status_request();
              if (iVar5 == 0) {
                return 4;
              }
              uVar14 = *param_3;
              if (uVar14 != 0) {
                uVar14 = 1;
              }
              *(char *)(param_1 + 0x28a) = (char)uVar14;
              return 0;
            }
            if (param_2 < 0xe9) {
              if (param_2 == 0xe3) {
                *(uint *)(param_1 + 0x440) = *param_3;
                return 0;
              }
              if (param_2 == 0xe5) {
                *(byte *)(param_1 + 0x24c) = (byte)*param_3 & 1;
                return 0;
              }
            }
            else {
              if (param_2 == 0xea) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x43e) = (char)uVar14;
                return 0;
              }
              if (param_2 < 0xea) {
                iVar5 = Curl_ssl_false_start();
                if (iVar5 == 0) {
                  return 4;
                }
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x2b6) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0xed) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x43f) = (char)uVar14;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x2712) {
              if (*(char *)(param_1 + 0x454) != '\0') {
                (*Curl_cfree)(*(undefined4 *)(param_1 + 0x450));
                *(undefined4 *)(param_1 + 0x450) = 0;
                *(undefined1 *)(param_1 + 0x454) = 0;
              }
              uVar4 = setstropt(param_1 + 0x38c,*param_3);
              *(undefined4 *)(param_1 + 0x450) = *(undefined4 *)(param_1 + 0x38c);
              return uVar4;
            }
            if (param_2 < 0x2713) {
              if (param_2 == 0xf2) {
                uVar14 = *param_3;
                if (uVar14 != 0) {
                  uVar14 = 1;
                }
                *(char *)(param_1 + 0x214) = (char)uVar14;
                return 0;
              }
              if (param_2 == 0x2711) {
                *(uint *)(param_1 + 0x160) = *param_3;
                return 0;
              }
            }
            else {
              if (param_2 == 0x2715) {
                uVar4 = setstropt_userpwd(*param_3,param_1 + 0x3b4,param_1 + 0x3b8);
                return uVar4;
              }
              if (0x2715 < param_2) {
                uVar4 = setstropt_userpwd(*param_3,param_1 + 0x3c0,param_1 + 0x3c4);
                return uVar4;
              }
              if (param_2 == 0x2714) {
                uVar4 = setstropt(param_1 + 0x380,*param_3);
                return uVar4;
              }
            }
          }
        }
      }
    }
    return 0x30;
  }
  if (param_2 == 0x27c0) {
    uVar4 = setstropt(param_1 + 0x3c4,*param_3);
    return uVar4;
  }
  if (0x27c0 < param_2) {
    if (0x2801 < param_2) {
      if (param_2 == 0x4ec7) {
        *(uint *)(param_1 + 400) = *param_3;
        return 0;
      }
      if (0x4ec7 < param_2) {
        if (param_2 == 0x4efb) {
          uVar14 = *param_3;
          *(uint *)(param_1 + 0x1c4) = uVar14;
          if (uVar14 == 0) {
            *(undefined1 *)(param_1 + 0x4a0) = 0;
            return 0;
          }
          *(undefined1 *)(param_1 + 0x4a0) = 1;
          return 0;
        }
        if (0x4efb < param_2) {
          if (param_2 == 0x75a5) {
            puVar10 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
            uVar4 = puVar10[1];
            *(undefined4 *)(param_1 + 0x2e0) = *puVar10;
            *(undefined4 *)(param_1 + 0x2e4) = uVar4;
            return 0;
          }
          if (0x75a5 < param_2) {
            if (param_2 == 0x75c1) {
              puVar10 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
              uVar4 = puVar10[1];
              *(undefined4 *)(param_1 + 0x228) = *puVar10;
              *(undefined4 *)(param_1 + 0x22c) = uVar4;
              return 0;
            }
            if (param_2 != 0x75c2) {
              if (param_2 != 0x75a8) {
                return 0x30;
              }
              puVar8 = (uint *)((int)param_3 + 7U & 0xfffffff8);
              iVar5 = *(int *)(param_1 + 0x19c);
              uVar14 = *puVar8;
              uVar15 = puVar8[1];
              bVar16 = *(uint *)(param_1 + 0x198) < uVar14;
              if (((int)((iVar5 - uVar15) - (uint)bVar16) < 0 !=
                   (SBORROW4(iVar5,uVar15) != SBORROW4(iVar5 - uVar15,(uint)bVar16))) &&
                 (*(int *)(param_1 + 0x18c) == *(int *)(param_1 + 0x3f4))) {
                setstropt(param_1 + 0x3f4,0);
                *(undefined4 *)(param_1 + 0x18c) = 0;
              }
              *(uint *)(param_1 + 0x198) = uVar14;
              *(uint *)(param_1 + 0x19c) = uVar15;
              return 0;
            }
            puVar10 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
            uVar4 = puVar10[1];
            *(undefined4 *)(param_1 + 0x230) = *puVar10;
            *(undefined4 *)(param_1 + 0x234) = uVar4;
            return 0;
          }
          if (param_2 == 0x75a3) {
            puVar10 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
            uVar4 = puVar10[1];
            *(undefined4 *)(param_1 + 0x218) = *puVar10;
            *(undefined4 *)(param_1 + 0x21c) = uVar4;
            return 0;
          }
          if (param_2 != 0x75a4) {
            return 0x30;
          }
          puVar10 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
          uVar4 = puVar10[1];
          *(undefined4 *)(param_1 + 0x238) = *puVar10;
          *(undefined4 *)(param_1 + 0x23c) = uVar4;
          return 0;
        }
        if (param_2 == 0x4ee7) {
          *(uint *)(param_1 + 0x41c) = *param_3;
          return 0;
        }
        if (0x4ee7 < param_2) {
          if (param_2 == 0x4ee8) {
            *(uint *)(param_1 + 0x420) = *param_3;
            return 0;
          }
          if (param_2 != 0x4ef0) {
            return 0x30;
          }
          *(uint *)(param_1 + 0x1e0) = *param_3;
          return 0;
        }
        if (param_2 == 0x4ee4) {
          *(uint *)(param_1 + 0x1b0) = *param_3;
          return 0;
        }
        if (param_2 != 0x4ee6) {
          return 0x30;
        }
        *(uint *)(param_1 + 0x418) = *param_3;
        return 0;
      }
      if (param_2 == 0x4e8c) {
        *(uint *)(param_1 + 0x2ac) = *param_3;
        return 0;
      }
      if (0x4e8c < param_2) {
        if (param_2 == 0x4eaf) {
          *(uint *)(param_1 + 0x1f0) = *param_3;
          return 0;
        }
        if (0x4eaf < param_2) {
          if (param_2 == 0x4eb4) {
            *(uint *)(param_1 + 0x1d0) = *param_3;
            return 0;
          }
          if (param_2 != 0x4ec3) {
            if (param_2 != 0x4eb0) {
              return 0x30;
            }
            *(uint *)(param_1 + 500) = *param_3;
            return 0;
          }
          *(uint *)(param_1 + 0x1d8) = *param_3;
          return 0;
        }
        if (param_2 == 0x4ea2) {
          *(uint *)(param_1 + 0x1cc) = *param_3;
          return 0;
        }
        if (param_2 != 0x4eae) {
          return 0x30;
        }
        *(uint *)(param_1 + 0x1ec) = *param_3;
        return 0;
      }
      if (param_2 == 0x4e58) {
        uVar14 = *param_3;
        *(uint *)(param_1 + 0x1c0) = uVar14;
        if (uVar14 == 0) {
          *(undefined1 *)(param_1 + 0x4a0) = 0;
          return 0;
        }
        *(undefined1 *)(param_1 + 0x4a0) = 1;
        return 0;
      }
      if (0x4e58 < param_2) {
        if (param_2 == 0x4e6f) {
          *(uint *)(param_1 + 0x1ac) = *param_3;
          return 0;
        }
        if (param_2 != 0x4e7e) {
          return 0x30;
        }
        *(uint *)(param_1 + 0x1c8) = *param_3;
        return 0;
      }
      if (param_2 == 0x4e2b) {
        uVar14 = *param_3;
        *(uint *)(param_1 + 0x1a8) = uVar14;
        if (uVar14 == 0) {
          *(undefined4 *)(param_1 + 0x1bc) = 0;
          *(code **)(param_1 + 0x1a8) = fwrite;
          return 0;
        }
        *(undefined4 *)(param_1 + 0x1bc) = 1;
        return 0;
      }
      if (param_2 != 0x4e2c) {
        return 0x30;
      }
      uVar14 = *param_3;
      *(uint *)(param_1 + 0x1b4) = uVar14;
      if (uVar14 == 0) {
        *(undefined4 *)(param_1 + 0x1b8) = 0;
        *(code **)(param_1 + 0x1b4) = fread;
        return 0;
      }
      *(undefined4 *)(param_1 + 0x1b8) = 1;
      return 0;
    }
    if (0x27ff < param_2) {
      return 4;
    }
    if (param_2 == 0x27de) {
      iVar5 = curl_strnequal(*param_3,&DAT_001367e0,3);
      if (iVar5 == 0) {
        *(undefined4 *)(param_1 + 0x2c0) = 0;
        return 0;
      }
      *(undefined4 *)(param_1 + 0x2c0) = 1;
      return 0;
    }
    if (param_2 < 0x27df) {
      if (param_2 == 0x27d0) {
        uVar4 = setstropt(param_1 + 0x3d4,*param_3);
        return uVar4;
      }
      if (0x27d0 < param_2) {
        if (param_2 == 0x27da) {
          *(uint *)(param_1 + 0x424) = *param_3;
          return 0;
        }
        if (param_2 < 0x27db) {
          if (param_2 == 0x27d3) {
            *(uint *)(param_1 + 0x16c) = *param_3;
            return 0;
          }
          if (param_2 != 0x27d9) {
            return 0x30;
          }
          *(uint *)(param_1 + 0x86f0) = *param_3;
          return 0;
        }
        if (param_2 == 0x27dc) {
          uVar4 = setstropt(param_1 + 0x3e0,*param_3);
          if (*(int *)(param_1 + 0x3e0) == 0) {
            return uVar4;
          }
          if (*(int *)(param_1 + 0x2c0) == 0) {
            *(undefined4 *)(param_1 + 0x2c0) = 1;
            return uVar4;
          }
          return uVar4;
        }
        if (param_2 < 0x27dd) {
          uVar14 = *param_3;
          *(uint *)(param_1 + 0x26c) = uVar14;
          *(uint *)(param_1 + 0x464) = uVar14;
          return 0;
        }
        uVar4 = setstropt(param_1 + 0x3e4,*param_3);
        if (*(int *)(param_1 + 0x3e0) != 0) {
          if (*(int *)(param_1 + 0x2c0) == 0) {
            *(undefined4 *)(param_1 + 0x2c0) = 1;
            return uVar4;
          }
          return uVar4;
        }
        return uVar4;
      }
      if (param_2 == 0x27cb) {
        *(uint *)(param_1 + 0x404) = *param_3;
        return 0;
      }
      if (0x27cb < param_2) {
        if (param_2 == 0x27ce) {
          uVar4 = setstropt(param_1 + 0x3cc,*param_3);
          return uVar4;
        }
        if (param_2 != 0x27cf) {
          return 0x30;
        }
        uVar4 = setstropt(param_1 + 0x3d0,*param_3);
        return uVar4;
      }
      if (param_2 == 0x27c1) {
        uVar4 = setstropt(param_1 + 0x3c8,*param_3);
        return uVar4;
      }
      if (param_2 != 0x27ca) {
        return 0x30;
      }
      uVar4 = setstropt(param_1 + 0x3d8,*param_3);
      return uVar4;
    }
    if (param_2 == 0x27ee) {
      uVar4 = Curl_set_dns_local_ip4(param_1,*param_3);
      return uVar4;
    }
    if (param_2 < 0x27ef) {
      if (param_2 == 0x27e9) {
        uVar4 = setstropt(param_1 + 0x3dc,*param_3);
        return uVar4;
      }
      if (0x27e9 < param_2) {
        if (param_2 == 0x27ec) {
          uVar4 = setstropt(param_1 + 1000,*param_3);
          return uVar4;
        }
        if (param_2 != 0x27ed) {
          return 0x30;
        }
        uVar4 = Curl_set_dns_interface(param_1,*param_3);
        return uVar4;
      }
      if (param_2 == 0x27e1) {
        *(uint *)(param_1 + 0x1e4) = *param_3;
        return 0;
      }
      if (param_2 != 0x27e3) {
        return 0x30;
      }
      uVar4 = Curl_set_dns_servers(param_1,*param_3);
      return uVar4;
    }
    if (param_2 == 0x27f4) {
      *(uint *)(param_1 + 0x244) = *param_3;
      return 0;
    }
    if (param_2 < 0x27f5) {
      if (param_2 == 0x27ef) {
        uVar4 = Curl_set_dns_local_ip6(param_1,*param_3);
        return uVar4;
      }
      if (param_2 != 0x27f0) {
        return 0x30;
      }
      uVar4 = setstropt(param_1 + 0x3bc,*param_3);
      return uVar4;
    }
    if (param_2 != 0x27f7) {
      if (param_2 == 0x27fe) {
        uVar4 = setstropt(param_1 + 0x354,*param_3);
        return uVar4;
      }
      if (param_2 != 0x27f6) {
        return 0x30;
      }
      uVar4 = setstropt(param_1 + 0x398,*param_3);
      return uVar4;
    }
    param_1 = param_1 + 0x3ec;
    pcVar9 = (char *)*param_3;
LAB_00044576:
    uVar4 = setstropt(param_1,pcVar9);
    return uVar4;
  }
  if (param_2 == 0x2763) {
    uVar4 = setstropt(param_1 + 0x39c,*param_3);
    return uVar4;
  }
  if (param_2 < 0x2764) {
    if (param_2 == 0x272d) {
      *(uint *)(param_1 + 0x168) = *param_3;
      return 0;
    }
    if (0x272d < param_2) {
      if (param_2 == 0x274e) {
        uVar4 = setstropt(param_1 + 0x358,*param_3);
        return uVar4;
      }
      if (0x274e < param_2) {
        if (param_2 == 0x2756) {
          *(uint *)(param_1 + 0x268) = *param_3;
          return 0;
        }
        if (0x2756 < param_2) {
          if (param_2 == 0x275d) {
            uVar4 = setstropt(param_1 + 0x3a0,*param_3);
            return uVar4;
          }
          if (param_2 != 0x2762) {
            if (param_2 != 0x275c) {
              return 0x30;
            }
            uVar4 = setstropt(param_1 + 0x3a4,*param_3);
            return uVar4;
          }
          uVar4 = setstropt(param_1 + 0x34c,*param_3);
          iVar5 = Curl_cookie_init(param_1,0,*(undefined4 *)(param_1 + 0x468),
                                   *(undefined1 *)(param_1 + 0x24d));
          if (iVar5 == 0) {
            uVar4 = 0x1b;
          }
          *(int *)(param_1 + 0x468) = iVar5;
          return uVar4;
        }
        if (param_2 == 0x274f) {
          uVar4 = setstropt(param_1 + 0x378,*param_3);
          iVar5 = *(int *)(param_1 + 0x378);
          if (iVar5 != 0) {
            iVar5 = 1;
          }
          *(char *)(param_1 + 0x311) = (char)iVar5;
          return uVar4;
        }
        if (param_2 != 0x2751) {
          return 0x30;
        }
        uVar4 = setstropt(param_1 + 0x394,*param_3);
        return uVar4;
      }
      if (param_2 == 0x2735) {
        uVar14 = *param_3;
        *(uint *)(param_1 + 0x150) = uVar14;
        if (uVar14 != 0) {
          return 0;
        }
        *(undefined4 *)(param_1 + 0x150) = stderr;
        return 0;
      }
      if (0x2735 < param_2) {
        if (param_2 == 0x2737) {
          *(uint *)(param_1 + 0x254) = *param_3;
          return 0;
        }
        if (param_2 != 0x2749) {
          return 0x30;
        }
        *(uint *)(param_1 + 0x1f8) = *param_3;
        return 0;
      }
      if (param_2 != 0x272f) {
        if (param_2 != 0x2734) {
          return 0x30;
        }
        uVar4 = setstropt(param_1 + 0x350,*param_3);
        return uVar4;
      }
      if (*param_3 == 0) {
        return 0;
      }
      iVar5 = curl_slist_append(*(undefined4 *)(param_1 + 0x460));
      if (iVar5 == 0) {
        curl_slist_free_all(*(undefined4 *)(param_1 + 0x460));
        *(undefined4 *)(param_1 + 0x460) = 0;
        return 0x1b;
      }
      *(int *)(param_1 + 0x460) = iVar5;
      return 0;
    }
    if (param_2 == 0x2722) {
      uVar4 = setstropt(param_1 + 0x3a8,*param_3);
      return uVar4;
    }
    if (0x2722 < param_2) {
      if (param_2 == 0x2728) {
        uVar14 = *param_3;
        *(undefined1 *)(param_1 + 0x307) = 0;
        *(undefined4 *)(param_1 + 0x278) = 3;
        *(uint *)(param_1 + 0x248) = uVar14;
        return 0;
      }
      if (0x2728 < param_2) {
        if (param_2 == 0x272a) {
          uVar4 = setstropt(param_1 + 0x370,*param_3);
          return uVar4;
        }
        if (0x2729 < param_2) {
          if (param_2 != 0x272c) {
            return 0x30;
          }
          *(uint *)(param_1 + 0x250) = *param_3;
          return 0;
        }
        uVar4 = setstropt(param_1 + 0x340,*param_3);
        return uVar4;
      }
      if (param_2 == 0x2726) {
        uVar4 = setstropt(param_1 + 0x348,*param_3);
        return uVar4;
      }
      if (param_2 != 0x2727) {
        return 0x30;
      }
      *(uint *)(param_1 + 0x240) = *param_3;
      return 0;
    }
    if (param_2 == 0x271f) {
      *(uint *)(param_1 + 0x18c) = *param_3;
      setstropt(param_1 + 0x3f4);
      *(undefined4 *)(param_1 + 0x278) = 2;
      return 0;
    }
    if (0x271f < param_2) {
      if (param_2 == 0x2720) {
        if (*(char *)(param_1 + 0x45c) != '\0') {
          (*Curl_cfree)(*(undefined4 *)(param_1 + 0x458));
          *(undefined4 *)(param_1 + 0x458) = 0;
          *(undefined1 *)(param_1 + 0x45c) = 0;
        }
        uVar4 = setstropt(param_1 + 0x388,*param_3);
        *(undefined4 *)(param_1 + 0x458) = *(undefined4 *)(param_1 + 0x388);
        return uVar4;
      }
      if (param_2 != 0x2721) {
        return 0x30;
      }
      uVar4 = setstropt(param_1 + 0x368,*param_3);
      iVar5 = *(int *)(param_1 + 0x368);
      if (iVar5 != 0) {
        iVar5 = 1;
      }
      *(char *)(param_1 + 0x2fe) = (char)iVar5;
      return uVar4;
    }
    if (param_2 == 0x2719) {
      *(uint *)(param_1 + 0x164) = *param_3;
      return 0;
    }
    if (param_2 != 0x271a) {
      return 0x30;
    }
    *(uint *)(param_1 + 0x158) = *param_3;
    return 0;
  }
  if (param_2 == 0x2786) {
    uVar4 = setstropt(param_1 + 0x37c,*param_3);
    return uVar4;
  }
  if (param_2 < 0x2787) {
    if (param_2 == 0x276f) {
      *(uint *)(param_1 + 0x154) = *param_3;
      return 0;
    }
    if (param_2 < 0x2770) {
      if (param_2 == 0x2768) {
        uVar4 = setstropt(param_1 + 0x374,*param_3);
        return uVar4;
      }
      if (0x2768 < param_2) {
        if (param_2 != 0x2769) {
          if (param_2 != 0x276d) {
            return 0x30;
          }
          *(uint *)(param_1 + 600) = *param_3;
          return 0;
        }
        if ((char *)*param_3 == (char *)0x0) {
          return 0;
        }
        if (*(char *)*param_3 == '\0') {
          return 0;
        }
        uVar4 = Curl_ssl_set_engine();
        return uVar4;
      }
      if (param_2 == 0x2766) {
        uVar4 = setstropt(param_1 + 0x344,*param_3);
        return uVar4;
      }
      if (param_2 != 0x2767) {
        return 0x30;
      }
      uVar4 = setstropt(param_1 + 0x36c,*param_3);
      return uVar4;
    }
    if (param_2 != 0x2776) {
      if (0x2776 < param_2) {
        if (param_2 == 0x2778) {
          *(uint *)(param_1 + 0x2d4) = *param_3;
          return 0;
        }
        if (0x2777 < param_2) {
          if (param_2 != 0x277d) {
            return 0x30;
          }
          *(uint *)(param_1 + 0x2b0) = *param_3;
          return 0;
        }
        *(uint *)(param_1 + 0x2d0) = *param_3;
        return 0;
      }
      if (param_2 == 0x2771) {
        uVar4 = setstropt(param_1 + 0x390,*param_3);
        return uVar4;
      }
      if (param_2 != 0x2774) {
        return 0x30;
      }
      uVar14 = *param_3;
      if (*(int *)(param_1 + 0x48) != 0) {
        Curl_share_lock(param_1,1,2);
        iVar11 = *(int *)(param_1 + 0x3c);
        iVar5 = *(int *)(param_1 + 0x468);
        bVar16 = iVar11 == 3;
        if (bVar16) {
          iVar11 = 0;
        }
        if (bVar16) {
          *(int *)(param_1 + 0x38) = iVar11;
        }
        if (bVar16) {
          *(int *)(param_1 + 0x3c) = iVar11;
        }
        iVar12 = *(int *)(param_1 + 0x48);
        iVar11 = *(int *)(iVar12 + 0x30);
        bVar16 = *(int *)(iVar12 + 0x2c) == iVar5;
        if (bVar16) {
          iVar5 = 0;
        }
        if (bVar16) {
          *(int *)(param_1 + 0x468) = iVar5;
        }
        iVar5 = *(int *)(param_1 + 0x85b0);
        bVar16 = iVar11 == iVar5;
        if (bVar16) {
          iVar5 = 0;
        }
        if (bVar16) {
          *(int *)(param_1 + 0x85b0) = iVar5;
        }
        *(int *)(iVar12 + 4) = *(int *)(iVar12 + 4) + -1;
        Curl_share_unlock(param_1,1);
      }
      *(uint *)(param_1 + 0x48) = uVar14;
      if (uVar14 == 0) {
        return 0;
      }
      Curl_share_lock(param_1,1,2);
      piVar13 = *(int **)(param_1 + 0x48);
      iVar5 = *piVar13;
      bVar16 = iVar5 << 0x1c < 0;
      piVar7 = (int *)(piVar13[1] + 1);
      if (bVar16) {
        iVar5 = 3;
      }
      piVar13[1] = (int)piVar7;
      if (bVar16) {
        piVar7 = piVar13 + 5;
      }
      if (bVar16) {
        *(int *)(param_1 + 0x3c) = iVar5;
      }
      iVar5 = piVar13[0xb];
      if (bVar16) {
        *(int **)(param_1 + 0x38) = piVar7;
      }
      if (iVar5 != 0) {
        Curl_cookie_cleanup(*(undefined4 *)(param_1 + 0x468));
        piVar13 = *(int **)(param_1 + 0x48);
        *(int *)(param_1 + 0x468) = piVar13[0xb];
      }
      if (piVar13[0xc] != 0) {
        iVar5 = piVar13[0xd];
        *(int *)(param_1 + 0x85b0) = piVar13[0xc];
        *(int *)(param_1 + 0x2a8) = iVar5;
      }
      Curl_share_unlock(param_1,1);
      return 0;
    }
    pcVar9 = (char *)*param_3;
    param_1 = param_1 + 0x35c;
    if ((pcVar9 != (char *)0x0) && (*pcVar9 == '\0')) {
      pcVar9 = "deflate, gzip";
    }
    goto LAB_00044576;
  }
  if (param_2 != 0x27b5) {
    if (0x27b5 < param_2) {
      if (param_2 == 0x27ba) {
        uVar4 = setstropt(param_1 + 0x3b0,*param_3);
        return uVar4;
      }
      if (0x27ba < param_2) {
        if (param_2 == 0x27be) {
          uVar4 = setstropt(param_1 + 0x3b8,*param_3);
          return uVar4;
        }
        if (param_2 < 0x27bf) {
          if (param_2 != 0x27bd) {
            return 0x30;
          }
          uVar4 = setstropt(param_1 + 0x3b4,*param_3);
          return uVar4;
        }
        uVar4 = setstropt(param_1 + 0x3c0,*param_3);
        return uVar4;
      }
      if (param_2 == 0x27b8) {
        *(uint *)(param_1 + 0x1e8) = *param_3;
        return 0;
      }
      if (param_2 != 0x27b9) {
        return 0x30;
      }
      uVar4 = setstropt(param_1 + 0x3ac,*param_3);
      return uVar4;
    }
    if (param_2 != 0x2797) {
      if (0x2797 < param_2) {
        if (param_2 == 0x27a5) {
          *(uint *)(param_1 + 0x1d4) = *param_3;
          return 0;
        }
        if (param_2 != 0x27b4) {
          if (param_2 != 0x27a3) {
            return 0x30;
          }
          uVar4 = setstropt(param_1 + 0x364,*param_3);
          return uVar4;
        }
        *(uint *)(param_1 + 0x1dc) = *param_3;
        return 0;
      }
      if (param_2 == 0x2793) {
        *(uint *)(param_1 + 0x1fc) = *param_3;
        return 0;
      }
      if (param_2 != 0x2796) {
        return 0x30;
      }
      uVar4 = setstropt(param_1 + 0x360,*param_3);
      return uVar4;
    }
    uVar14 = *param_3;
    if (uVar14 == 0) {
      return 0;
    }
    iVar5 = Curl_raw_equal(uVar14,"ALL");
    if (iVar5 != 0) {
      Curl_share_lock(param_1,2,2);
      Curl_cookie_clearall(*(undefined4 *)(param_1 + 0x468));
      Curl_share_unlock(param_1,2);
      return 0;
    }
    iVar5 = Curl_raw_equal(uVar14,&DAT_00136790);
    if (iVar5 != 0) {
      Curl_share_lock(param_1,2,2);
      Curl_cookie_clearsess(*(undefined4 *)(param_1 + 0x468));
      Curl_share_unlock(param_1,2);
      return 0;
    }
    iVar5 = Curl_raw_equal(uVar14,"FLUSH");
    if (iVar5 == 0) {
      iVar5 = Curl_raw_equal(uVar14,"RELOAD");
      if (iVar5 != 0) {
        Curl_cookie_loadfiles(param_1);
        return 0;
      }
      if (*(int *)(param_1 + 0x468) == 0) {
        uVar4 = Curl_cookie_init(param_1,0,0,1);
        *(undefined4 *)(param_1 + 0x468) = uVar4;
      }
      iVar5 = (*Curl_cstrdup)(uVar14);
      if ((iVar5 != 0) && (*(int *)(param_1 + 0x468) != 0)) {
        Curl_share_lock(param_1,2,2);
        iVar11 = Curl_raw_nequal("Set-Cookie:",iVar5,0xb);
        if (iVar11 == 0) {
          Curl_cookie_add(param_1,*(undefined4 *)(param_1 + 0x468),0,iVar5,0,0);
        }
        else {
          Curl_cookie_add(param_1,*(undefined4 *)(param_1 + 0x468),1,iVar5 + 0xb,0,0);
        }
        Curl_share_unlock(param_1,2);
        (*Curl_cfree)(iVar5);
        return 0;
      }
      (*Curl_cfree)(iVar5);
      return 0x1b;
    }
    Curl_flush_cookies(param_1,0);
    return 0;
  }
  __src = (void *)*param_3;
  if (__src != (void *)0x0) {
    psVar1 = (size_t *)(param_1 + 0x198);
    if (*(int *)(param_1 + 0x19c) != -1 || *psVar1 != 0xffffffff) {
      if (*(int *)(param_1 + 0x19c) == 0) {
        setstropt(param_1 + 0x3f4,0);
        sVar6 = *psVar1;
        if (sVar6 == 0 && *(int *)(param_1 + 0x19c) == 0) {
          sVar6 = 1;
        }
        __dest = (void *)(*Curl_cmalloc)(sVar6);
        if (__dest != (void *)0x0) {
          if (*psVar1 != 0 || *(int *)(param_1 + 0x19c) != 0) {
            memcpy(__dest,__src,*psVar1);
          }
          uVar4 = 0;
          *(void **)(param_1 + 0x3f4) = __dest;
          goto LAB_00044aa4;
        }
      }
      uVar4 = 0x1b;
      goto LAB_00044aa4;
    }
  }
  uVar4 = setstropt(param_1 + 0x3f4,__src);
LAB_00044aa4:
  *(undefined4 *)(param_1 + 0x278) = 2;
  *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_1 + 0x3f4);
  return uVar4;
}

