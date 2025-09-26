
int pkey_rsa_ctrl(undefined4 *param_1,int param_2,int param_3,EVP_MD *param_4)

{
  uint uVar1;
  int extraout_r0;
  int iVar2;
  int iVar3;
  EVP_MD *pEVar4;
  int extraout_r3;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  
  piVar5 = (int *)param_1[5];
  if (param_2 != 0x1002) {
    if (param_2 < 0x1003) {
      if (param_2 == 7) {
        return 1;
      }
      if (param_2 < 8) {
        if (4 < param_2) {
          if (param_2 != 5) {
            return -2;
          }
          return 1;
        }
        if (param_2 < 3) {
          if (param_2 == 1) {
            iVar3 = check_padding_md(param_4,piVar5[5]);
            if (iVar3 == 0) {
              return 0;
            }
            if (piVar5[9] != -1) {
              iVar3 = EVP_MD_type((EVP_MD *)piVar5[6]);
              iVar2 = EVP_MD_type(param_4);
              if (iVar3 == iVar2) {
                return 1;
              }
              ERR_put_error(4,0x8f,0x91,"crypto/rsa/rsa_pmeth.c",0x1fa);
              return 0;
            }
            piVar5[6] = (int)param_4;
            return 1;
          }
          if (param_2 != 2) {
            return -2;
          }
          goto LAB_0015c11a;
        }
      }
      else {
        if (param_2 == 0xb) {
          return 1;
        }
        if (0xb < param_2) {
          if (param_2 != 0xd) {
            if (param_2 != 0x1001) {
              return -2;
            }
            if (param_3 - 1U < 6) {
              iVar3 = check_padding_md(piVar5[6],param_3);
              if (iVar3 == 0) {
                return 0;
              }
              if (param_3 == 6) {
                uVar1 = param_1[4] & 0x18;
              }
              else {
                if (*(int *)*param_1 == 0x390) goto LAB_0015c35e;
                if (param_3 != 4) goto LAB_0015c100;
                uVar1 = param_1[4] & 0x300;
              }
              if (uVar1 != 0) {
                if (piVar5[6] == 0) {
                  pEVar4 = EVP_sha1();
                  piVar5[6] = (int)pEVar4;
                }
LAB_0015c100:
                piVar5[5] = param_3;
                return 1;
              }
            }
LAB_0015c35e:
            ERR_put_error(4,0x8f,0x90,"crypto/rsa/rsa_pmeth.c",0x1ac);
            return -2;
          }
          goto LAB_0015c20a;
        }
        if (param_2 < 9) {
          return -2;
        }
      }
      if (*(int *)*param_1 != 0x390) {
        return 1;
      }
LAB_0015c11a:
      ERR_put_error(4,0x8f,0x94,"crypto/rsa/rsa_pmeth.c",0x244);
      return -2;
    }
    if (param_2 != 0x1008) {
      if (0x1008 < param_2) {
        if (param_2 != 0x100b) {
          if (0x100b < param_2) {
            if (param_2 != 0x100c) {
              if (param_2 != 0x100d) {
                return -2;
              }
              if (param_3 - 2U < 4) {
                piVar5[2] = param_3;
                return 1;
              }
              ERR_put_error(4,0x8f,0xa5,"crypto/rsa/rsa_pmeth.c",0x1e2);
              return -2;
            }
            if (piVar5[5] == 4) {
              iVar3 = piVar5[0xc];
              param_4->type = piVar5[0xb];
              return iVar3;
            }
            iVar3 = 0x22c;
            goto LAB_0015c380;
          }
          if (param_2 != 0x1009) {
            if (param_2 != 0x100a) {
              return -2;
            }
            if (piVar5[5] == 4) {
              CRYPTO_free((void *)piVar5[0xb]);
              bVar6 = (int)param_4 < 0;
              bVar7 = param_4 == (EVP_MD *)0x0;
              if (!bVar7) {
                bVar6 = param_3 < 0;
              }
              bVar8 = param_3 != 0;
              iVar3 = extraout_r3;
              if ((bVar7 || !bVar8) || bVar6) {
                iVar3 = 0;
              }
              if ((!bVar7 && bVar8) && !bVar6) {
                piVar5[0xb] = (int)param_4;
              }
              iVar2 = extraout_r0;
              if ((!bVar7 && bVar8) && !bVar6) {
                iVar2 = 1;
              }
              if ((!bVar7 && bVar8) && !bVar6) {
                piVar5[0xc] = param_3;
              }
              if ((bVar7 || !bVar8) || bVar6) {
                iVar2 = 1;
              }
              if ((bVar7 || !bVar8) || bVar6) {
                piVar5[0xb] = iVar3;
              }
              if ((bVar7 || !bVar8) || bVar6) {
                piVar5[0xc] = iVar3;
                return iVar2;
              }
              return iVar2;
            }
            iVar3 = 0x21d;
            goto LAB_0015c380;
          }
        }
        if (piVar5[5] != 4) {
          iVar3 = 0x1eb;
LAB_0015c380:
          ERR_put_error(4,0x8f,0x8d,"crypto/rsa/rsa_pmeth.c",iVar3);
          return -2;
        }
        if (param_2 != 0x100b) {
          piVar5[6] = (int)param_4;
          return 1;
        }
        goto LAB_0015c20a;
      }
      if (param_2 != 0x1005) {
        if (param_2 < 0x1006) {
          if (param_2 == 0x1003) {
            if (0x1ff < param_3) {
              *piVar5 = param_3;
              return 1;
            }
            ERR_put_error(4,0x8f,0x78,"crypto/rsa/rsa_pmeth.c",0x1d1);
            return -2;
          }
          if (param_2 != 0x1004) {
            return -2;
          }
          if (((param_4 != (EVP_MD *)0x0) && (iVar3 = BN_is_odd(param_4), iVar3 != 0)) &&
             (iVar3 = BN_is_one(param_4), iVar3 == 0)) {
            BN_free((BIGNUM *)piVar5[1]);
            piVar5[1] = (int)param_4;
            return 1;
          }
          ERR_put_error(4,0x8f,0x65,"crypto/rsa/rsa_pmeth.c",0x1d9);
          return -2;
        }
        if (param_2 == 0x1006) {
          param_4->type = piVar5[5];
          return 1;
        }
        if (param_2 != 0x1007) {
          return -2;
        }
        goto LAB_0015c196;
      }
    }
    if ((piVar5[5] & 0xfffffffdU) != 4) {
      ERR_put_error(4,0x8f,0x9c,"crypto/rsa/rsa_pmeth.c",0x208);
      return -2;
    }
    if (param_2 != 0x1008) {
      if (piVar5[9] == -1) {
        piVar5[7] = (int)param_4;
        return 1;
      }
      iVar3 = EVP_MD_type((EVP_MD *)piVar5[7]);
      iVar2 = EVP_MD_type(param_4);
      if (iVar3 == iVar2) {
        return 1;
      }
      ERR_put_error(4,0x8f,0x98,"crypto/rsa/rsa_pmeth.c",0x214);
      return 0;
    }
    if (piVar5[7] != 0) {
      param_4->type = piVar5[7];
      return 1;
    }
LAB_0015c20a:
    param_4->type = piVar5[6];
    return 1;
  }
LAB_0015c196:
  if (piVar5[5] != 6) {
    ERR_put_error(4,0x8f,0x92,"crypto/rsa/rsa_pmeth.c",0x1b6);
    return -2;
  }
  if (param_2 == 0x1007) {
    param_4->type = piVar5[8];
    return 1;
  }
  if (param_3 + 3 < 0 != SCARRY4(param_3,3)) {
    return -2;
  }
  iVar3 = piVar5[9];
  if (iVar3 != -1) {
    if (param_3 == -2) {
      if (param_1[4] == 0x10) {
        ERR_put_error(4,0x8f,0x92,"crypto/rsa/rsa_pmeth.c",0x1c1);
        return -2;
      }
    }
    else if (param_3 == -1) {
      iVar2 = EVP_MD_size((EVP_MD *)piVar5[6]);
      if (iVar2 < iVar3) goto LAB_0015c1cc;
    }
    else if ((-1 < param_3) && (param_3 < iVar3)) {
LAB_0015c1cc:
      ERR_put_error(4,0x8f,0xa4,"crypto/rsa/rsa_pmeth.c",0x1c7);
      return 0;
    }
  }
  piVar5[8] = param_3;
  return 1;
}

