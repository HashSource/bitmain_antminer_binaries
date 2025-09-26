
void pkey_rsa_ctrl(int param_1,int param_2,EVP_MD *param_3,EVP_MD *param_4)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  int iVar4;
  EVP_MD *pEVar5;
  undefined4 *puVar6;
  bool bVar7;
  bool bVar8;
  
  puVar6 = *(undefined4 **)(param_1 + 0x14);
  if (param_2 == 0x1002) {
LAB_00199342:
    if (puVar6[4] == 6) {
      if (param_2 == 0x1007) {
        param_4->type = puVar6[7];
      }
      else if ((int)((int)&param_3->type + 2) < 0 == SCARRY4((int)param_3,2)) {
        puVar6[7] = param_3;
      }
    }
    else {
      ERR_put_error(4,0x8f,0x92,"rsa_pmeth.c",0x20f);
    }
    return;
  }
  if (param_2 < 0x1003) {
    if (param_2 == 7) {
      return;
    }
    if (param_2 < 8) {
      if (param_2 == 2) {
        ERR_put_error(4,0x8f,0x94,"rsa_pmeth.c",0x275);
        return;
      }
      if (2 < param_2) {
        return;
      }
      if (param_2 != 1) {
        return;
      }
      if (param_4 != (EVP_MD *)0x0) {
        if (puVar6[4] == 3) {
LAB_0019945c:
          ERR_put_error(4,0x8c,0x8d,"rsa_pmeth.c",0x1dc);
          return;
        }
        if (puVar6[4] == 5) {
          iVar4 = EVP_MD_type(param_4);
          iVar4 = RSA_X931_hash_id(iVar4);
          if (iVar4 == -1) {
LAB_00199446:
            ERR_put_error(4,0x8c,0x8e,"rsa_pmeth.c",0x1e2);
            return;
          }
        }
      }
      puVar6[5] = param_4;
      return;
    }
    if (param_2 != 0xd) {
      if (param_2 < 0xe) {
        return;
      }
      if (param_2 != 0x1001) {
        return;
      }
      if ((undefined1 *)((int)&param_3[-1].md_ctrl + 3) <= &DAT_00000005) {
        pEVar5 = (EVP_MD *)puVar6[5];
        if (pEVar5 != (EVP_MD *)0x0) {
          if (param_3 == (EVP_MD *)0x3) goto LAB_0019945c;
          if (param_3 == (EVP_MD *)&DAT_00000005) {
            iVar4 = EVP_MD_type(pEVar5);
            iVar4 = RSA_X931_hash_id(iVar4);
            if (iVar4 == -1) goto LAB_00199446;
            goto LAB_001992ba;
          }
        }
        if (param_3 == (EVP_MD *)&DAT_00000006) {
          uVar1 = *(uint *)(param_1 + 0x10) & 0x18;
        }
        else {
          if (param_3 != (EVP_MD *)0x4) goto LAB_001992ba;
          uVar1 = *(uint *)(param_1 + 0x10) & 0x300;
        }
        if (uVar1 != 0) {
          if (pEVar5 == (EVP_MD *)0x0) {
            pEVar5 = EVP_sha1();
            puVar6[5] = pEVar5;
          }
LAB_001992ba:
          puVar6[4] = param_3;
          return;
        }
      }
      ERR_put_error(4,0x8f,0x90,"rsa_pmeth.c",0x205);
      return;
    }
    goto LAB_0019933a;
  }
  if (param_2 == 0x1007) goto LAB_00199342;
  if (param_2 < 0x1008) {
    if (param_2 == 0x1004) {
      if (param_4 == (EVP_MD *)0x0) {
        return;
      }
      BN_free((BIGNUM *)puVar6[1]);
      puVar6[1] = param_4;
      return;
    }
    if (param_2 < 0x1004) {
      if ((int)param_3 < 0x100) {
        ERR_put_error(4,0x8f,0x91,"rsa_pmeth.c",0x21d);
        return;
      }
      *puVar6 = param_3;
      return;
    }
    if (param_2 != 0x1005) {
      if (param_2 != 0x1006) {
        return;
      }
      param_4->type = puVar6[4];
      return;
    }
LAB_00199404:
    if ((puVar6[4] & 0xfffffffd) != 4) {
      ERR_put_error(4,0x8f,0x9c,"rsa_pmeth.c",0x244);
      return;
    }
    if (param_2 != 0x1008) {
      puVar6[6] = param_4;
      return;
    }
    if (puVar6[6] != 0) {
      param_4->type = puVar6[6];
      return;
    }
  }
  else {
    if (param_2 == 0x100a) {
      if (puVar6[4] == 4) {
        uVar3 = 4;
        if ((void *)puVar6[9] != (void *)0x0) {
          CRYPTO_free((void *)puVar6[9]);
          uVar3 = extraout_r1;
        }
        bVar7 = param_4 == (EVP_MD *)0x0;
        pEVar5 = param_4;
        if (!bVar7) {
          pEVar5 = param_3;
        }
        bVar2 = (int)pEVar5 < 0;
        bVar8 = param_3 != (EVP_MD *)0x0;
        if ((bVar7 || !bVar8) || bVar2) {
          uVar3 = 0;
        }
        if ((!bVar7 && bVar8) && !bVar2) {
          uVar3 = 1;
        }
        if ((!bVar7 && bVar8) && !bVar2) {
          puVar6[9] = param_4;
        }
        if ((!bVar7 && bVar8) && !bVar2) {
          puVar6[10] = param_3;
        }
        if ((bVar7 || !bVar8) || bVar2) {
          puVar6[9] = uVar3;
        }
        if ((!bVar7 && bVar8) && !bVar2) {
          return;
        }
        puVar6[10] = uVar3;
        return;
      }
      iVar4 = 0x252;
      goto LAB_00199360;
    }
    if (param_2 < 0x100b) {
      if (param_2 == 0x1008) goto LAB_00199404;
      if (param_2 != 0x1009) {
        return;
      }
    }
    else if (param_2 != 0x100b) {
      if (param_2 != 0x100c) {
        return;
      }
      if (puVar6[4] == 4) {
        param_4->type = puVar6[9];
        return;
      }
      iVar4 = 0x262;
      goto LAB_00199360;
    }
    if (puVar6[4] != 4) {
      iVar4 = 0x22d;
LAB_00199360:
      ERR_put_error(4,0x8f,0x8d,"rsa_pmeth.c",iVar4);
      return;
    }
    if (param_2 != 0x100b) {
      puVar6[5] = param_4;
      return;
    }
  }
LAB_0019933a:
  param_4->type = puVar6[5];
  return;
}

