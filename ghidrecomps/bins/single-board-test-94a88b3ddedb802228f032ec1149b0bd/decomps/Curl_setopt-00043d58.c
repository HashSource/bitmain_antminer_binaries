
undefined4 Curl_setopt(int param_1,uint param_2,char **param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  void *__dest;
  int *piVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  undefined4 unaff_r4;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  if (param_2 == 0x2717) {
    uVar2 = setstropt(param_1 + 900,*param_3);
    return uVar2;
  }
  if (param_2 < 0x2718) {
    if (param_2 == 0x72) {
      pcVar10 = *param_3;
      *(char **)(param_1 + 0x2e0) = pcVar10;
      *(int *)(param_1 + 0x2e4) = (int)pcVar10 >> 0x1f;
      return 0;
    }
    if (param_2 < 0x73) {
      if (param_2 == 0x3c) {
        pcVar10 = *param_3;
        iVar3 = *(int *)(param_1 + 0x19c);
        iVar7 = (int)pcVar10 >> 0x1f;
        bVar13 = *(char **)(param_1 + 0x198) < pcVar10;
        if (((int)((iVar3 - iVar7) - (uint)bVar13) < 0 !=
             (SBORROW4(iVar3,iVar7) != SBORROW4(iVar3 - iVar7,(uint)bVar13))) &&
           (*(int *)(param_1 + 0x18c) == *(int *)(param_1 + 0x3f4))) {
          setstropt(param_1 + 0x3f4,0);
          *(undefined4 *)(param_1 + 0x18c) = 0;
        }
        *(char **)(param_1 + 0x198) = pcVar10;
        *(int *)(param_1 + 0x19c) = iVar7;
        return 0;
      }
      if (param_2 < 0x3d) {
        if (param_2 == 0x2b) {
          pcVar10 = *param_3;
          if (pcVar10 != (char *)0x0) {
            pcVar10 = (char *)0x1;
          }
          *(char *)(param_1 + 0x2ff) = (char)pcVar10;
          if (pcVar10 == (char *)0x0) {
            *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) & 0xffffffef;
            return 0;
          }
          *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) | 0x10;
          return 0;
        }
        if (param_2 < 0x2c) {
          if (param_2 == 0x15) {
            pcVar10 = *param_3;
            *(char **)(param_1 + 0x238) = pcVar10;
            *(int *)(param_1 + 0x23c) = (int)pcVar10 >> 0x1f;
            return 0;
          }
          if (param_2 < 0x16) {
            if (param_2 == 0xe) {
              pcVar10 = *param_3;
              *(char **)(param_1 + 0x218) = pcVar10;
              *(int *)(param_1 + 0x21c) = (int)pcVar10 >> 0x1f;
              return 0;
            }
            if (param_2 < 0xf) {
              if (param_2 == 3) {
                *(char **)(param_1 + 0x170) = *param_3;
                return 0;
              }
              if (param_2 == 0xd) {
                *(int *)(param_1 + 0x200) = (int)*param_3 * 1000;
                return 0;
              }
            }
            else {
              if (param_2 == 0x13) {
                *(char **)(param_1 + 0x220) = *param_3;
                return 0;
              }
              if (param_2 == 0x14) {
                *(char **)(param_1 + 0x224) = *param_3;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x21) {
              *(char **)(param_1 + 0x270) = *param_3;
              return 0;
            }
            if (param_2 < 0x22) {
              if (param_2 == 0x1b) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x24e) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x20) {
                *(char **)(param_1 + 0x280) = *param_3;
                return 0;
              }
            }
            else {
              if (param_2 == 0x29) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x310) = (char)pcVar10;
                return 0;
              }
              if (0x29 < param_2) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x304) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x22) {
                *(char **)(param_1 + 0x274) = *param_3;
                return 0;
              }
            }
          }
        }
        else {
          if (param_2 == 0x32) {
            pcVar10 = *param_3;
            if (pcVar10 != (char *)0x0) {
              pcVar10 = (char *)0x1;
            }
            *(char *)(param_1 + 0x2fc) = (char)pcVar10;
            return 0;
          }
          if (param_2 < 0x33) {
            if (param_2 == 0x2e) {
LAB_0004449a:
              pcVar10 = *param_3;
              if (pcVar10 != (char *)0x0) {
                pcVar10 = (char *)0x1;
              }
              *(char *)(param_1 + 0x309) = (char)pcVar10;
              if (pcVar10 == (char *)0x0) {
                *(undefined4 *)(param_1 + 0x278) = 1;
                return 0;
              }
              *(undefined4 *)(param_1 + 0x278) = 4;
              *(undefined *)(param_1 + 0x307) = 0;
              return 0;
            }
            if (param_2 < 0x2f) {
              if (param_2 == 0x2c) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x307) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x2d) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x300) = (char)pcVar10;
                return 0;
              }
            }
            else {
              if (param_2 == 0x2f) {
                if (*param_3 == (char *)0x0) {
                  *(undefined4 *)(param_1 + 0x278) = 1;
                  return 0;
                }
                *(undefined4 *)(param_1 + 0x278) = 2;
                *(undefined *)(param_1 + 0x307) = 0;
                return 0;
              }
              if (param_2 == 0x30) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x2fd) = (char)pcVar10;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x35) {
              pcVar10 = *param_3;
              if (pcVar10 != (char *)0x0) {
                pcVar10 = (char *)0x1;
              }
              *(char *)(param_1 + 0x2fb) = (char)pcVar10;
              return 0;
            }
            if (param_2 < 0x36) {
              if (param_2 == 0x33) {
                *(char **)(param_1 + 0x30c) = *param_3;
                return 0;
              }
              if (param_2 == 0x34) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x301) = (char)pcVar10;
                return 0;
              }
            }
            else {
              if (param_2 == 0x3a) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x306) = (char)pcVar10;
                return 0;
              }
              if (0x3a < param_2) {
                *(char **)(param_1 + 0x15c) = *param_3;
                return 0;
              }
              if (param_2 == 0x36) goto LAB_0004449a;
            }
          }
        }
      }
      else {
        if (param_2 == 0x5a) {
          uVar2 = Curl_ssl_set_engine_default();
          return uVar2;
        }
        if (param_2 < 0x5b) {
          if (param_2 == 0x4a) {
            pcVar10 = *param_3;
            if (pcVar10 != (char *)0x0) {
              pcVar10 = (char *)0x1;
            }
            *(char *)(param_1 + 0x313) = (char)pcVar10;
            return 0;
          }
          if (param_2 < 0x4b) {
            if (param_2 == 0x44) {
              *(char **)(param_1 + 0x180) = *param_3;
              return 0;
            }
            if (param_2 < 0x45) {
              if (param_2 == 0x3d) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x2fa) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x40) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x288) = (char)pcVar10;
                return 0;
              }
            }
            else {
              if (param_2 == 0x45) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x2f9) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x47) {
                *(char **)(param_1 + 0x438) = *param_3;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x50) {
              if (*param_3 == (char *)0x0) {
                return 0;
              }
              *(undefined4 *)(param_1 + 0x278) = 1;
              *(undefined *)(param_1 + 0x309) = 0;
              *(undefined *)(param_1 + 0x307) = 0;
              return 0;
            }
            if (param_2 < 0x51) {
              if (param_2 == 0x4b) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x312) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x4e) {
                *(int *)(param_1 + 0x204) = (int)*param_3 * 1000;
                return 0;
              }
            }
            else {
              if (param_2 == 0x54) {
                if ((int)*param_3 < 3) {
                  *(char **)(param_1 + 0x27c) = *param_3;
                  return 0;
                }
                return 1;
              }
              if (param_2 == 0x55) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x314) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x51) {
                pcVar10 = *param_3;
                if (pcVar10 == (char *)0x1) {
                  Curl_failf(param_1,DAT_000454d4);
                  return 0x2b;
                }
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x289) = (char)pcVar10;
                return 0;
              }
            }
          }
        }
        else {
          if (param_2 == 0x69) {
            pcVar10 = *param_3;
            if (pcVar10 != (char *)0x0) {
              pcVar10 = (char *)0x1;
            }
            *(char *)(param_1 + 0x303) = (char)pcVar10;
            return 0;
          }
          if (0x69 < param_2) {
            if (param_2 == 0x6e) {
              pcVar10 = *param_3;
              if (pcVar10 == (char *)0x1) {
                *(undefined4 *)(param_1 + 0x2ec) = 1;
                return 0;
              }
              if (pcVar10 == (char *)0x2) {
                *(undefined4 *)(param_1 + 0x2ec) = 2;
                return 0;
              }
              if (pcVar10 != (char *)0x0) {
                return 0x30;
              }
              *(undefined4 *)(param_1 + 0x2ec) = 0;
              return 0;
            }
            if (param_2 < 0x6f) {
              if (param_2 == 0x6a) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x315) = (char)pcVar10;
                return 0;
              }
              if (param_2 != 0x6b) {
                return 0x30;
              }
              pcVar10 = *param_3;
              if (pcVar10 == (char *)0x0) {
                *(undefined4 *)(param_1 + 0x174) = 0;
                return 0;
              }
              *(byte *)(param_1 + 0x862e) = (byte)((uint)((int)pcVar10 << 0x1b) >> 0x1f);
              if ((int)pcVar10 << 0x1b < 0) {
                pcVar10 = (char *)((uint)pcVar10 & 0xffffffef | 2);
              }
              uVar11 = 0;
              do {
                uVar12 = uVar11 & 0xff;
                uVar11 = uVar11 + 1;
                if ((int)((((uint)pcVar10 & 0xfffffffb) >> uVar12) << 0x1f) < 0) {
                  *(uint *)(param_1 + 0x174) = (uint)pcVar10 & 0xfffffffb;
                  return 0;
                }
              } while (uVar11 != 0x1f);
            }
            else {
              if (param_2 == 0x70) {
                *(int *)(param_1 + 0x20c) = (int)*param_3 * 1000;
                return 0;
              }
              if (0x70 < param_2) {
                *(char **)(param_1 + 0x2d8) = *param_3;
                return 0;
              }
              pcVar10 = *param_3;
              if (pcVar10 == (char *)0x0) {
                *(undefined4 *)(param_1 + 0x178) = 0;
                return 0;
              }
              *(byte *)(param_1 + 0x863e) = (byte)((uint)((int)pcVar10 << 0x1b) >> 0x1f);
              if ((int)pcVar10 << 0x1b < 0) {
                pcVar10 = (char *)((uint)pcVar10 & 0xffffffef | 2);
              }
              uVar11 = 0;
              do {
                uVar12 = uVar11 & 0xff;
                uVar11 = uVar11 + 1;
                if ((int)((((uint)pcVar10 & 0xfffffffb) >> uVar12) << 0x1f) < 0) {
                  *(uint *)(param_1 + 0x178) = (uint)pcVar10 & 0xfffffffb;
                  return 0;
                }
              } while (uVar11 != 0x1f);
            }
            return 4;
          }
          if (param_2 == 0x60) {
            pcVar10 = *param_3;
            if (pcVar10 != (char *)0x0) {
              pcVar10 = (char *)0x1;
            }
            *(char *)(param_1 + 0x24d) = (char)pcVar10;
            return 0;
          }
          if (param_2 < 0x61) {
            if (param_2 == 0x5b) {
              pcVar10 = *param_3;
              if (pcVar10 != (char *)0x0) {
                pcVar10 = (char *)0x1;
              }
              *(char *)(param_1 + 0x325) = (char)pcVar10;
              return 0;
            }
            if (param_2 == 0x5c) {
              *(char **)(param_1 + 0x2c8) = *param_3;
              return 0;
            }
          }
          else {
            if (param_2 == 99) {
              pcVar10 = *param_3;
              if (pcVar10 != (char *)0x0) {
                pcVar10 = (char *)0x1;
              }
              *(char *)(param_1 + 0x324) = (char)pcVar10;
              return 0;
            }
            if (param_2 == 0x65) {
              *(char **)(param_1 + 0x2c4) = *param_3;
              return 0;
            }
            if (param_2 == 0x62) {
              pcVar10 = *param_3 + -1;
              *(char **)(param_1 + 0x2cc) = *param_3;
              if ((char *)0x3ffe < pcVar10) {
                unaff_r4 = 0;
              }
              if (pcVar10 < (char *)0x3fff) {
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
        if (*param_3 + -1 < (char *)0xb) {
          uVar2 = *(undefined4 *)(DAT_00044708 + (int)(*param_3 + -1) * 4);
        }
        else {
          uVar2 = 0;
        }
        *(undefined4 *)(param_1 + 0x40c) = uVar2;
        return 0;
      }
      if (param_2 < 0xbe) {
        if (param_2 == 0x9c) {
          *(char **)(param_1 + 0x204) = *param_3;
          return 0;
        }
        if (param_2 < 0x9d) {
          if (param_2 == 0x8a) {
            *(char **)(param_1 + 0x2e8) = *param_3;
            return 0;
          }
          if (param_2 < 0x8b) {
            if (param_2 == 0x81) {
              *(char **)(param_1 + 0x31c) = *param_3;
              return 0;
            }
            if (param_2 < 0x82) {
              if (param_2 == 0x77) {
                *(char **)(param_1 + 0x318) = *param_3;
                return 0;
              }
              if (param_2 == 0x79) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x326) = (char)pcVar10;
                return 0;
              }
            }
            else {
              if (param_2 == 0x88) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x327) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x89) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x328) = (char)pcVar10;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x8d) {
              pcVar10 = *param_3;
              if (pcVar10 != (char *)0x0) {
                pcVar10 = (char *)0x1;
              }
              *(char *)(param_1 + 0x329) = (char)pcVar10;
              return 0;
            }
            if (param_2 < 0x8e) {
              if (param_2 == 0x8b) {
                uVar1 = curlx_sltous(*param_3);
                *(undefined2 *)(param_1 + 0x1a0) = uVar1;
                return 0;
              }
              if (param_2 == 0x8c) {
                uVar2 = curlx_sltosi(*param_3);
                *(undefined4 *)(param_1 + 0x1a4) = uVar2;
                return 0;
              }
            }
            else {
              if (param_2 == 0x9a) {
                *(char **)(param_1 + 800) = *param_3;
                return 0;
              }
              if (0x9a < param_2) {
                *(char **)(param_1 + 0x200) = *param_3;
                return 0;
              }
              if (param_2 == 0x96) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x2b4) = (char)pcVar10;
                return 0;
              }
            }
          }
        }
        else {
          if (param_2 == 0xa6) {
            if (*param_3 == (char *)0x0) {
              *(undefined *)(param_1 + 0x33c) = 0;
              return 0;
            }
            if (*param_3 != (char *)0x1) {
              return 0x30;
            }
            *(undefined *)(param_1 + 0x33c) = 1;
            return 0;
          }
          if (param_2 < 0xa7) {
            if (param_2 == 0x9f) {
              *(char **)(param_1 + 0x334) = *param_3;
              return 0;
            }
            if (param_2 < 0xa0) {
              if (param_2 == 0x9d) {
                *(bool *)(param_1 + 0x330) = *param_3 == (char *)0x0;
                return 0;
              }
              if (param_2 == 0x9e) {
                *(bool *)(param_1 + 0x331) = *param_3 == (char *)0x0;
                return 0;
              }
            }
            else {
              if (param_2 == 0xa0) {
                *(char **)(param_1 + 0x338) = *param_3;
                return 0;
              }
              if (param_2 == 0xa1) {
                uVar11 = curlx_sltosi(*param_3);
                *(uint *)(param_1 + 0x184) = uVar11 & 7;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0xb2) {
              *(char **)(param_1 + 0x210) = *param_3;
              return 0;
            }
            if (param_2 < 0xb3) {
              if (param_2 == 0xab) {
                uVar2 = curlx_sltoui(*param_3);
                *(undefined4 *)(param_1 + 0x3f8) = uVar2;
                return 0;
              }
              if (param_2 == 0xac) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x2b5) = (char)pcVar10;
                return 0;
              }
            }
            else {
              if (param_2 == 0xb6) {
                *(char **)(param_1 + 0x400) = *param_3;
                return 0;
              }
              if (param_2 == 0xbc) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x316) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0xb5) {
                *(char **)(param_1 + 0x3fc) = *param_3;
                return 0;
              }
            }
          }
        }
      }
      else {
        if (param_2 == 0xe2) {
          pcVar10 = *param_3;
          if (pcVar10 != (char *)0x0) {
            pcVar10 = (char *)0x1;
          }
          *(char *)(param_1 + 0x43d) = (char)pcVar10;
          return 0;
        }
        if (param_2 < 0xe3) {
          if (param_2 == 0xd4) {
            *(char **)(param_1 + 0x208) = *param_3;
            return 0;
          }
          if (param_2 < 0xd5) {
            if (param_2 == 0xc5) {
              pcVar10 = *param_3;
              if (pcVar10 != (char *)0x0) {
                pcVar10 = (char *)0x1;
              }
              *(char *)(param_1 + 0x414) = (char)pcVar10;
              return 0;
            }
            if (param_2 < 0xc6) {
              if (param_2 == 0xc1) {
                *(char **)(param_1 + 0x86a0) = *param_3;
                return 0;
              }
              if (param_2 == 0xc2) {
                *(char **)(param_1 + 0x86a0) = *param_3;
                return 0;
              }
            }
            else {
              if (param_2 == 0xcf) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x302) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0xd2) {
                *(char **)(param_1 + 0x428) = *param_3;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0xd7) {
              *(char **)(param_1 + 0x434) = *param_3;
              return 0;
            }
            if (param_2 < 0xd8) {
              if (param_2 == 0xd5) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x42c) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0xd6) {
                *(char **)(param_1 + 0x430) = *param_3;
                return 0;
              }
            }
            else {
              if (param_2 == 0xda) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x408) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0xe1) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x43c) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0xd8) {
                pcVar10 = *param_3;
                *(byte *)(param_1 + 0x32a) = (byte)pcVar10 & 1;
                *(byte *)(param_1 + 0x32b) = (byte)((uint)((int)pcVar10 << 0x1e) >> 0x1f);
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
              iVar3 = Curl_ssl_cert_status_request();
              if (iVar3 == 0) {
                return 4;
              }
              pcVar10 = *param_3;
              if (pcVar10 != (char *)0x0) {
                pcVar10 = (char *)0x1;
              }
              *(char *)(param_1 + 0x28a) = (char)pcVar10;
              return 0;
            }
            if (param_2 < 0xe9) {
              if (param_2 == 0xe3) {
                *(char **)(param_1 + 0x440) = *param_3;
                return 0;
              }
              if (param_2 == 0xe5) {
                *(byte *)(param_1 + 0x24c) = (byte)*param_3 & 1;
                return 0;
              }
            }
            else {
              if (param_2 == 0xea) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x43e) = (char)pcVar10;
                return 0;
              }
              if (param_2 < 0xea) {
                iVar3 = Curl_ssl_false_start();
                if (iVar3 == 0) {
                  return 4;
                }
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x2b6) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0xed) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x43f) = (char)pcVar10;
                return 0;
              }
            }
          }
          else {
            if (param_2 == 0x2712) {
              if (*(char *)(param_1 + 0x454) != '\0') {
                (**DAT_000454d0)(*(undefined4 *)(param_1 + 0x450));
                *(undefined4 *)(param_1 + 0x450) = 0;
                *(undefined *)(param_1 + 0x454) = 0;
              }
              uVar2 = setstropt(param_1 + 0x38c,*param_3);
              *(undefined4 *)(param_1 + 0x450) = *(undefined4 *)(param_1 + 0x38c);
              return uVar2;
            }
            if (param_2 < 0x2713) {
              if (param_2 == 0xf2) {
                pcVar10 = *param_3;
                if (pcVar10 != (char *)0x0) {
                  pcVar10 = (char *)0x1;
                }
                *(char *)(param_1 + 0x214) = (char)pcVar10;
                return 0;
              }
              if (param_2 == 0x2711) {
                *(char **)(param_1 + 0x160) = *param_3;
                return 0;
              }
            }
            else {
              if (param_2 == 0x2715) {
                uVar2 = setstropt_userpwd(*param_3,param_1 + 0x3b4,param_1 + 0x3b8);
                return uVar2;
              }
              if (0x2715 < param_2) {
                uVar2 = setstropt_userpwd(*param_3,param_1 + 0x3c0,param_1 + 0x3c4);
                return uVar2;
              }
              if (param_2 == 0x2714) {
                uVar2 = setstropt(param_1 + 0x380,*param_3);
                return uVar2;
              }
            }
          }
        }
      }
    }
    return 0x30;
  }
  if (param_2 == 0x27c0) {
    uVar2 = setstropt(param_1 + 0x3c4,*param_3);
    return uVar2;
  }
  if (0x27c0 < param_2) {
    if (0x2801 < param_2) {
      if (param_2 == 0x4ec7) {
        *(char **)(param_1 + 400) = *param_3;
        return 0;
      }
      if (0x4ec7 < param_2) {
        if (param_2 == 0x4efb) {
          pcVar10 = *param_3;
          *(char **)(param_1 + 0x1c4) = pcVar10;
          if (pcVar10 == (char *)0x0) {
            *(undefined *)(param_1 + 0x4a0) = 0;
            return 0;
          }
          *(undefined *)(param_1 + 0x4a0) = 1;
          return 0;
        }
        if (0x4efb < param_2) {
          if (param_2 == 0x75a5) {
            puVar6 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
            uVar2 = puVar6[1];
            *(undefined4 *)(param_1 + 0x2e0) = *puVar6;
            *(undefined4 *)(param_1 + 0x2e4) = uVar2;
            return 0;
          }
          if (0x75a5 < param_2) {
            if (param_2 == 0x75c1) {
              puVar6 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
              uVar2 = puVar6[1];
              *(undefined4 *)(param_1 + 0x228) = *puVar6;
              *(undefined4 *)(param_1 + 0x22c) = uVar2;
              return 0;
            }
            if (param_2 != 0x75c2) {
              if (param_2 != 0x75a8) {
                return 0x30;
              }
              puVar5 = (uint *)((int)param_3 + 7U & 0xfffffff8);
              iVar3 = *(int *)(param_1 + 0x19c);
              uVar11 = *puVar5;
              uVar12 = puVar5[1];
              bVar13 = *(uint *)(param_1 + 0x198) < uVar11;
              if (((int)((iVar3 - uVar12) - (uint)bVar13) < 0 !=
                   (SBORROW4(iVar3,uVar12) != SBORROW4(iVar3 - uVar12,(uint)bVar13))) &&
                 (*(int *)(param_1 + 0x18c) == *(int *)(param_1 + 0x3f4))) {
                setstropt(param_1 + 0x3f4,0);
                *(undefined4 *)(param_1 + 0x18c) = 0;
              }
              *(uint *)(param_1 + 0x198) = uVar11;
              *(uint *)(param_1 + 0x19c) = uVar12;
              return 0;
            }
            puVar6 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
            uVar2 = puVar6[1];
            *(undefined4 *)(param_1 + 0x230) = *puVar6;
            *(undefined4 *)(param_1 + 0x234) = uVar2;
            return 0;
          }
          if (param_2 == 0x75a3) {
            puVar6 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
            uVar2 = puVar6[1];
            *(undefined4 *)(param_1 + 0x218) = *puVar6;
            *(undefined4 *)(param_1 + 0x21c) = uVar2;
            return 0;
          }
          if (param_2 != 0x75a4) {
            return 0x30;
          }
          puVar6 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
          uVar2 = puVar6[1];
          *(undefined4 *)(param_1 + 0x238) = *puVar6;
          *(undefined4 *)(param_1 + 0x23c) = uVar2;
          return 0;
        }
        if (param_2 == 0x4ee7) {
          *(char **)(param_1 + 0x41c) = *param_3;
          return 0;
        }
        if (0x4ee7 < param_2) {
          if (param_2 == 0x4ee8) {
            *(char **)(param_1 + 0x420) = *param_3;
            return 0;
          }
          if (param_2 != 0x4ef0) {
            return 0x30;
          }
          *(char **)(param_1 + 0x1e0) = *param_3;
          return 0;
        }
        if (param_2 == 0x4ee4) {
          *(char **)(param_1 + 0x1b0) = *param_3;
          return 0;
        }
        if (param_2 != 0x4ee6) {
          return 0x30;
        }
        *(char **)(param_1 + 0x418) = *param_3;
        return 0;
      }
      if (param_2 == 0x4e8c) {
        *(char **)(param_1 + 0x2ac) = *param_3;
        return 0;
      }
      if (0x4e8c < param_2) {
        if (param_2 == 0x4eaf) {
          *(char **)(param_1 + 0x1f0) = *param_3;
          return 0;
        }
        if (0x4eaf < param_2) {
          if (param_2 == 0x4eb4) {
            *(char **)(param_1 + 0x1d0) = *param_3;
            return 0;
          }
          if (param_2 != 0x4ec3) {
            if (param_2 != 0x4eb0) {
              return 0x30;
            }
            *(char **)(param_1 + 500) = *param_3;
            return 0;
          }
          *(char **)(param_1 + 0x1d8) = *param_3;
          return 0;
        }
        if (param_2 == 0x4ea2) {
          *(char **)(param_1 + 0x1cc) = *param_3;
          return 0;
        }
        if (param_2 != 0x4eae) {
          return 0x30;
        }
        *(char **)(param_1 + 0x1ec) = *param_3;
        return 0;
      }
      if (param_2 == 0x4e58) {
        pcVar10 = *param_3;
        *(char **)(param_1 + 0x1c0) = pcVar10;
        if (pcVar10 == (char *)0x0) {
          *(undefined *)(param_1 + 0x4a0) = 0;
          return 0;
        }
        *(undefined *)(param_1 + 0x4a0) = 1;
        return 0;
      }
      if (0x4e58 < param_2) {
        if (param_2 == 0x4e6f) {
          *(char **)(param_1 + 0x1ac) = *param_3;
          return 0;
        }
        if (param_2 != 0x4e7e) {
          return 0x30;
        }
        *(char **)(param_1 + 0x1c8) = *param_3;
        return 0;
      }
      if (param_2 == 0x4e2b) {
        pcVar10 = *param_3;
        *(char **)(param_1 + 0x1a8) = pcVar10;
        uVar2 = DAT_000454e0;
        if (pcVar10 == (char *)0x0) {
          *(undefined4 *)(param_1 + 0x1bc) = 0;
          *(undefined4 *)(param_1 + 0x1a8) = uVar2;
          return 0;
        }
        *(undefined4 *)(param_1 + 0x1bc) = 1;
        return 0;
      }
      if (param_2 != 0x4e2c) {
        return 0x30;
      }
      pcVar10 = *param_3;
      *(char **)(param_1 + 0x1b4) = pcVar10;
      uVar2 = DAT_000454e4;
      if (pcVar10 == (char *)0x0) {
        *(undefined4 *)(param_1 + 0x1b8) = 0;
        *(undefined4 *)(param_1 + 0x1b4) = uVar2;
        return 0;
      }
      *(undefined4 *)(param_1 + 0x1b8) = 1;
      return 0;
    }
    if (0x27ff < param_2) {
      return 4;
    }
    if (param_2 == 0x27de) {
      iVar3 = curl_strnequal(*param_3,DAT_00044c10,3);
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x2c0) = 0;
        return 0;
      }
      *(undefined4 *)(param_1 + 0x2c0) = 1;
      return 0;
    }
    if (param_2 < 0x27df) {
      if (param_2 == 0x27d0) {
        uVar2 = setstropt(param_1 + 0x3d4,*param_3);
        return uVar2;
      }
      if (0x27d0 < param_2) {
        if (param_2 == 0x27da) {
          *(char **)(param_1 + 0x424) = *param_3;
          return 0;
        }
        if (param_2 < 0x27db) {
          if (param_2 == 0x27d3) {
            *(char **)(param_1 + 0x16c) = *param_3;
            return 0;
          }
          if (param_2 != 0x27d9) {
            return 0x30;
          }
          *(char **)(param_1 + 0x86f0) = *param_3;
          return 0;
        }
        if (param_2 == 0x27dc) {
          uVar2 = setstropt(param_1 + 0x3e0,*param_3);
          if (*(int *)(param_1 + 0x3e0) == 0) {
            return uVar2;
          }
          if (*(int *)(param_1 + 0x2c0) == 0) {
            *(undefined4 *)(param_1 + 0x2c0) = 1;
            return uVar2;
          }
          return uVar2;
        }
        if (param_2 < 0x27dd) {
          pcVar10 = *param_3;
          *(char **)(param_1 + 0x26c) = pcVar10;
          *(char **)(param_1 + 0x464) = pcVar10;
          return 0;
        }
        uVar2 = setstropt(param_1 + 0x3e4,*param_3);
        if (*(int *)(param_1 + 0x3e0) != 0) {
          if (*(int *)(param_1 + 0x2c0) == 0) {
            *(undefined4 *)(param_1 + 0x2c0) = 1;
            return uVar2;
          }
          return uVar2;
        }
        return uVar2;
      }
      if (param_2 == 0x27cb) {
        *(char **)(param_1 + 0x404) = *param_3;
        return 0;
      }
      if (0x27cb < param_2) {
        if (param_2 == 0x27ce) {
          uVar2 = setstropt(param_1 + 0x3cc,*param_3);
          return uVar2;
        }
        if (param_2 != 0x27cf) {
          return 0x30;
        }
        uVar2 = setstropt(param_1 + 0x3d0,*param_3);
        return uVar2;
      }
      if (param_2 == 0x27c1) {
        uVar2 = setstropt(param_1 + 0x3c8,*param_3);
        return uVar2;
      }
      if (param_2 != 0x27ca) {
        return 0x30;
      }
      uVar2 = setstropt(param_1 + 0x3d8,*param_3);
      return uVar2;
    }
    if (param_2 == 0x27ee) {
      uVar2 = Curl_set_dns_local_ip4(param_1,*param_3);
      return uVar2;
    }
    if (param_2 < 0x27ef) {
      if (param_2 == 0x27e9) {
        uVar2 = setstropt(param_1 + 0x3dc,*param_3);
        return uVar2;
      }
      if (0x27e9 < param_2) {
        if (param_2 == 0x27ec) {
          uVar2 = setstropt(param_1 + 1000,*param_3);
          return uVar2;
        }
        if (param_2 != 0x27ed) {
          return 0x30;
        }
        uVar2 = Curl_set_dns_interface(param_1,*param_3);
        return uVar2;
      }
      if (param_2 == 0x27e1) {
        *(char **)(param_1 + 0x1e4) = *param_3;
        return 0;
      }
      if (param_2 != 0x27e3) {
        return 0x30;
      }
      uVar2 = Curl_set_dns_servers(param_1,*param_3);
      return uVar2;
    }
    if (param_2 == 0x27f4) {
      *(char **)(param_1 + 0x244) = *param_3;
      return 0;
    }
    if (param_2 < 0x27f5) {
      if (param_2 == 0x27ef) {
        uVar2 = Curl_set_dns_local_ip6(param_1,*param_3);
        return uVar2;
      }
      if (param_2 != 0x27f0) {
        return 0x30;
      }
      uVar2 = setstropt(param_1 + 0x3bc,*param_3);
      return uVar2;
    }
    if (param_2 != 0x27f7) {
      if (param_2 == 0x27fe) {
        uVar2 = setstropt(param_1 + 0x354,*param_3);
        return uVar2;
      }
      if (param_2 != 0x27f6) {
        return 0x30;
      }
      uVar2 = setstropt(param_1 + 0x398,*param_3);
      return uVar2;
    }
    param_1 = param_1 + 0x3ec;
    pcVar10 = *param_3;
LAB_00044576:
    uVar2 = setstropt(param_1,pcVar10);
    return uVar2;
  }
  if (param_2 == 0x2763) {
    uVar2 = setstropt(param_1 + 0x39c,*param_3);
    return uVar2;
  }
  if (param_2 < 0x2764) {
    if (param_2 == 0x272d) {
      *(char **)(param_1 + 0x168) = *param_3;
      return 0;
    }
    if (0x272d < param_2) {
      if (param_2 == 0x274e) {
        uVar2 = setstropt(param_1 + 0x358,*param_3);
        return uVar2;
      }
      if (0x274e < param_2) {
        if (param_2 == 0x2756) {
          *(char **)(param_1 + 0x268) = *param_3;
          return 0;
        }
        if (0x2756 < param_2) {
          if (param_2 == 0x275d) {
            uVar2 = setstropt(param_1 + 0x3a0,*param_3);
            return uVar2;
          }
          if (param_2 != 0x2762) {
            if (param_2 != 0x275c) {
              return 0x30;
            }
            uVar2 = setstropt(param_1 + 0x3a4,*param_3);
            return uVar2;
          }
          uVar2 = setstropt(param_1 + 0x34c,*param_3);
          iVar3 = Curl_cookie_init(param_1,0,*(undefined4 *)(param_1 + 0x468),
                                   *(undefined *)(param_1 + 0x24d));
          if (iVar3 == 0) {
            uVar2 = 0x1b;
          }
          *(int *)(param_1 + 0x468) = iVar3;
          return uVar2;
        }
        if (param_2 == 0x274f) {
          uVar2 = setstropt(param_1 + 0x378,*param_3);
          iVar3 = *(int *)(param_1 + 0x378);
          if (iVar3 != 0) {
            iVar3 = 1;
          }
          *(char *)(param_1 + 0x311) = (char)iVar3;
          return uVar2;
        }
        if (param_2 != 0x2751) {
          return 0x30;
        }
        uVar2 = setstropt(param_1 + 0x394,*param_3);
        return uVar2;
      }
      if (param_2 == 0x2735) {
        pcVar10 = *param_3;
        *(char **)(param_1 + 0x150) = pcVar10;
        if (pcVar10 != (char *)0x0) {
          return 0;
        }
        *(undefined4 *)(param_1 + 0x150) = *DAT_00044704;
        return 0;
      }
      if (0x2735 < param_2) {
        if (param_2 == 0x2737) {
          *(char **)(param_1 + 0x254) = *param_3;
          return 0;
        }
        if (param_2 != 0x2749) {
          return 0x30;
        }
        *(char **)(param_1 + 0x1f8) = *param_3;
        return 0;
      }
      if (param_2 != 0x272f) {
        if (param_2 != 0x2734) {
          return 0x30;
        }
        uVar2 = setstropt(param_1 + 0x350,*param_3);
        return uVar2;
      }
      if (*param_3 == (char *)0x0) {
        return 0;
      }
      iVar3 = curl_slist_append(*(undefined4 *)(param_1 + 0x460));
      if (iVar3 == 0) {
        curl_slist_free_all(*(undefined4 *)(param_1 + 0x460));
        *(undefined4 *)(param_1 + 0x460) = 0;
        return 0x1b;
      }
      *(int *)(param_1 + 0x460) = iVar3;
      return 0;
    }
    if (param_2 == 0x2722) {
      uVar2 = setstropt(param_1 + 0x3a8,*param_3);
      return uVar2;
    }
    if (0x2722 < param_2) {
      if (param_2 == 0x2728) {
        pcVar10 = *param_3;
        *(undefined *)(param_1 + 0x307) = 0;
        *(undefined4 *)(param_1 + 0x278) = 3;
        *(char **)(param_1 + 0x248) = pcVar10;
        return 0;
      }
      if (0x2728 < param_2) {
        if (param_2 == 0x272a) {
          uVar2 = setstropt(param_1 + 0x370,*param_3);
          return uVar2;
        }
        if (0x2729 < param_2) {
          if (param_2 != 0x272c) {
            return 0x30;
          }
          *(char **)(param_1 + 0x250) = *param_3;
          return 0;
        }
        uVar2 = setstropt(param_1 + 0x340,*param_3);
        return uVar2;
      }
      if (param_2 == 0x2726) {
        uVar2 = setstropt(param_1 + 0x348,*param_3);
        return uVar2;
      }
      if (param_2 != 0x2727) {
        return 0x30;
      }
      *(char **)(param_1 + 0x240) = *param_3;
      return 0;
    }
    if (param_2 == 0x271f) {
      *(char **)(param_1 + 0x18c) = *param_3;
      setstropt(param_1 + 0x3f4);
      *(undefined4 *)(param_1 + 0x278) = 2;
      return 0;
    }
    if (0x271f < param_2) {
      if (param_2 == 0x2720) {
        if (*(char *)(param_1 + 0x45c) != '\0') {
          (**DAT_000454d0)(*(undefined4 *)(param_1 + 0x458));
          *(undefined4 *)(param_1 + 0x458) = 0;
          *(undefined *)(param_1 + 0x45c) = 0;
        }
        uVar2 = setstropt(param_1 + 0x388,*param_3);
        *(undefined4 *)(param_1 + 0x458) = *(undefined4 *)(param_1 + 0x388);
        return uVar2;
      }
      if (param_2 != 0x2721) {
        return 0x30;
      }
      uVar2 = setstropt(param_1 + 0x368,*param_3);
      iVar3 = *(int *)(param_1 + 0x368);
      if (iVar3 != 0) {
        iVar3 = 1;
      }
      *(char *)(param_1 + 0x2fe) = (char)iVar3;
      return uVar2;
    }
    if (param_2 == 0x2719) {
      *(char **)(param_1 + 0x164) = *param_3;
      return 0;
    }
    if (param_2 != 0x271a) {
      return 0x30;
    }
    *(char **)(param_1 + 0x158) = *param_3;
    return 0;
  }
  if (param_2 == 0x2786) {
    uVar2 = setstropt(param_1 + 0x37c,*param_3);
    return uVar2;
  }
  if (param_2 < 0x2787) {
    if (param_2 == 0x276f) {
      *(char **)(param_1 + 0x154) = *param_3;
      return 0;
    }
    if (param_2 < 0x2770) {
      if (param_2 == 0x2768) {
        uVar2 = setstropt(param_1 + 0x374,*param_3);
        return uVar2;
      }
      if (0x2768 < param_2) {
        if (param_2 != 0x2769) {
          if (param_2 != 0x276d) {
            return 0x30;
          }
          *(char **)(param_1 + 600) = *param_3;
          return 0;
        }
        if (*param_3 == (char *)0x0) {
          return 0;
        }
        if (**param_3 == '\0') {
          return 0;
        }
        uVar2 = Curl_ssl_set_engine();
        return uVar2;
      }
      if (param_2 == 0x2766) {
        uVar2 = setstropt(param_1 + 0x344,*param_3);
        return uVar2;
      }
      if (param_2 != 0x2767) {
        return 0x30;
      }
      uVar2 = setstropt(param_1 + 0x36c,*param_3);
      return uVar2;
    }
    if (param_2 != 0x2776) {
      if (0x2776 < param_2) {
        if (param_2 == 0x2778) {
          *(char **)(param_1 + 0x2d4) = *param_3;
          return 0;
        }
        if (0x2777 < param_2) {
          if (param_2 != 0x277d) {
            return 0x30;
          }
          *(char **)(param_1 + 0x2b0) = *param_3;
          return 0;
        }
        *(char **)(param_1 + 0x2d0) = *param_3;
        return 0;
      }
      if (param_2 == 0x2771) {
        uVar2 = setstropt(param_1 + 0x390,*param_3);
        return uVar2;
      }
      if (param_2 != 0x2774) {
        return 0x30;
      }
      pcVar10 = *param_3;
      if (*(int *)(param_1 + 0x48) != 0) {
        Curl_share_lock(param_1,1,2);
        iVar7 = *(int *)(param_1 + 0x3c);
        iVar3 = *(int *)(param_1 + 0x468);
        bVar13 = iVar7 == 3;
        if (bVar13) {
          iVar7 = 0;
        }
        if (bVar13) {
          *(int *)(param_1 + 0x38) = iVar7;
        }
        if (bVar13) {
          *(int *)(param_1 + 0x3c) = iVar7;
        }
        iVar8 = *(int *)(param_1 + 0x48);
        iVar7 = *(int *)(iVar8 + 0x30);
        bVar13 = *(int *)(iVar8 + 0x2c) == iVar3;
        if (bVar13) {
          iVar3 = 0;
        }
        if (bVar13) {
          *(int *)(param_1 + 0x468) = iVar3;
        }
        iVar3 = *(int *)(param_1 + 0x85b0);
        bVar13 = iVar7 == iVar3;
        if (bVar13) {
          iVar3 = 0;
        }
        if (bVar13) {
          *(int *)(param_1 + 0x85b0) = iVar3;
        }
        *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + -1;
        Curl_share_unlock(param_1,1);
      }
      *(char **)(param_1 + 0x48) = pcVar10;
      if (pcVar10 == (char *)0x0) {
        return 0;
      }
      Curl_share_lock(param_1,1,2);
      piVar9 = *(int **)(param_1 + 0x48);
      iVar3 = *piVar9;
      bVar13 = iVar3 << 0x1c < 0;
      piVar4 = (int *)(piVar9[1] + 1);
      if (bVar13) {
        iVar3 = 3;
      }
      piVar9[1] = (int)piVar4;
      if (bVar13) {
        piVar4 = piVar9 + 5;
      }
      if (bVar13) {
        *(int *)(param_1 + 0x3c) = iVar3;
      }
      iVar3 = piVar9[0xb];
      if (bVar13) {
        *(int **)(param_1 + 0x38) = piVar4;
      }
      if (iVar3 != 0) {
        Curl_cookie_cleanup(*(undefined4 *)(param_1 + 0x468));
        piVar9 = *(int **)(param_1 + 0x48);
        *(int *)(param_1 + 0x468) = piVar9[0xb];
      }
      if (piVar9[0xc] != 0) {
        iVar3 = piVar9[0xd];
        *(int *)(param_1 + 0x85b0) = piVar9[0xc];
        *(int *)(param_1 + 0x2a8) = iVar3;
      }
      Curl_share_unlock(param_1,1);
      return 0;
    }
    pcVar10 = *param_3;
    param_1 = param_1 + 0x35c;
    if ((pcVar10 != (char *)0x0) && (*pcVar10 == '\0')) {
      pcVar10 = DAT_00044700;
    }
    goto LAB_00044576;
  }
  if (param_2 != 0x27b5) {
    if (0x27b5 < param_2) {
      if (param_2 == 0x27ba) {
        uVar2 = setstropt(param_1 + 0x3b0,*param_3);
        return uVar2;
      }
      if (0x27ba < param_2) {
        if (param_2 == 0x27be) {
          uVar2 = setstropt(param_1 + 0x3b8,*param_3);
          return uVar2;
        }
        if (param_2 < 0x27bf) {
          if (param_2 != 0x27bd) {
            return 0x30;
          }
          uVar2 = setstropt(param_1 + 0x3b4,*param_3);
          return uVar2;
        }
        uVar2 = setstropt(param_1 + 0x3c0,*param_3);
        return uVar2;
      }
      if (param_2 == 0x27b8) {
        *(char **)(param_1 + 0x1e8) = *param_3;
        return 0;
      }
      if (param_2 != 0x27b9) {
        return 0x30;
      }
      uVar2 = setstropt(param_1 + 0x3ac,*param_3);
      return uVar2;
    }
    if (param_2 != 0x2797) {
      if (0x2797 < param_2) {
        if (param_2 == 0x27a5) {
          *(char **)(param_1 + 0x1d4) = *param_3;
          return 0;
        }
        if (param_2 != 0x27b4) {
          if (param_2 != 0x27a3) {
            return 0x30;
          }
          uVar2 = setstropt(param_1 + 0x364,*param_3);
          return uVar2;
        }
        *(char **)(param_1 + 0x1dc) = *param_3;
        return 0;
      }
      if (param_2 == 0x2793) {
        *(char **)(param_1 + 0x1fc) = *param_3;
        return 0;
      }
      if (param_2 != 0x2796) {
        return 0x30;
      }
      uVar2 = setstropt(param_1 + 0x360,*param_3);
      return uVar2;
    }
    pcVar10 = *param_3;
    if (pcVar10 == (char *)0x0) {
      return 0;
    }
    iVar3 = Curl_raw_equal(pcVar10,DAT_000446fc);
    if (iVar3 != 0) {
      Curl_share_lock(param_1,2,2);
      Curl_cookie_clearall(*(undefined4 *)(param_1 + 0x468));
      Curl_share_unlock(param_1,2);
      return 0;
    }
    iVar3 = Curl_raw_equal(pcVar10,DAT_000454cc);
    if (iVar3 != 0) {
      Curl_share_lock(param_1,2,2);
      Curl_cookie_clearsess(*(undefined4 *)(param_1 + 0x468));
      Curl_share_unlock(param_1,2);
      return 0;
    }
    iVar3 = Curl_raw_equal(pcVar10,DAT_000454dc);
    if (iVar3 == 0) {
      iVar3 = Curl_raw_equal(pcVar10,DAT_000455c0);
      if (iVar3 != 0) {
        Curl_cookie_loadfiles(param_1);
        return 0;
      }
      if (*(int *)(param_1 + 0x468) == 0) {
        uVar2 = Curl_cookie_init(param_1,0,0,1);
        *(undefined4 *)(param_1 + 0x468) = uVar2;
      }
      iVar3 = (**DAT_000455c4)(pcVar10);
      if ((iVar3 != 0) && (*(int *)(param_1 + 0x468) != 0)) {
        Curl_share_lock(param_1,2,2);
        iVar7 = Curl_raw_nequal(DAT_000455c8,iVar3,0xb);
        if (iVar7 == 0) {
          Curl_cookie_add(param_1,*(undefined4 *)(param_1 + 0x468),0,iVar3,0,0);
        }
        else {
          Curl_cookie_add(param_1,*(undefined4 *)(param_1 + 0x468),1,iVar3 + 0xb,0,0);
        }
        Curl_share_unlock(param_1,2);
        (**DAT_000455cc)(iVar3);
        return 0;
      }
      (**DAT_000455cc)(iVar3);
      return 0x1b;
    }
    Curl_flush_cookies(param_1,0);
    return 0;
  }
  pcVar10 = *param_3;
  if (pcVar10 != (char *)0x0) {
    puVar5 = (uint *)(param_1 + 0x198);
    if (*(int *)(param_1 + 0x19c) != -1 || *puVar5 != 0xffffffff) {
      if (*(int *)(param_1 + 0x19c) == 0) {
        setstropt(param_1 + 0x3f4,0);
        uVar11 = *puVar5;
        if ((uVar11 | *(uint *)(param_1 + 0x19c)) == 0) {
          uVar11 = 1;
        }
        __dest = (void *)(**DAT_000454d8)(uVar11);
        if (__dest != (void *)0x0) {
          if ((*puVar5 | *(uint *)(param_1 + 0x19c)) != 0) {
            memcpy(__dest,pcVar10,*puVar5);
          }
          uVar2 = 0;
          *(void **)(param_1 + 0x3f4) = __dest;
          goto LAB_00044aa4;
        }
      }
      uVar2 = 0x1b;
      goto LAB_00044aa4;
    }
  }
  uVar2 = setstropt(param_1 + 0x3f4,pcVar10);
LAB_00044aa4:
  *(undefined4 *)(param_1 + 0x278) = 2;
  *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_1 + 0x3f4);
  return uVar2;
}

