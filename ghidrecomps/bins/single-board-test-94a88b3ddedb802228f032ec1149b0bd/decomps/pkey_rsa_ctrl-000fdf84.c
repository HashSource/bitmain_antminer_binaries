
void pkey_rsa_ctrl(int param_1,int param_2,EVP_MD *param_3,EVP_MD *param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  EVP_MD *pEVar4;
  EVP_MD *extraout_r1;
  EVP_MD *pEVar5;
  int iVar6;
  EVP_MD **ppEVar7;
  bool bVar8;
  
  ppEVar7 = *(EVP_MD ***)(param_1 + 0x14);
  if (param_2 == 0x1002) {
LAB_000fe0a2:
    if (ppEVar7[4] == (EVP_MD *)0x6) {
      if (param_2 == 0x1007) {
        param_4->type = (int)ppEVar7[7];
      }
      else if ((int)((int)&param_3->type + 2) < 0 == SCARRY4((int)param_3,2)) {
        ppEVar7[7] = param_3;
      }
    }
    else {
      ERR_put_error(4,0x8f,0x92,DAT_000fe23c,0x20f);
    }
    return;
  }
  if (param_2 < 0x1003) {
    if (param_2 == 7) {
      return;
    }
    if (param_2 < 8) {
      if (param_2 == 2) {
        ERR_put_error(4,0x8f,0x94,DAT_000fe23c,0x275);
        return;
      }
      if (2 < param_2) {
        return;
      }
      if (param_2 != 1) {
        return;
      }
      if (param_4 != (EVP_MD *)0x0) {
        if (ppEVar7[4] == (EVP_MD *)0x3) {
LAB_000fe1bc:
          ERR_put_error(4,0x8c,0x8d,DAT_000fe23c,0x1dc);
          return;
        }
        if (ppEVar7[4] == (EVP_MD *)0x5) {
          iVar6 = EVP_MD_type(param_4);
          iVar6 = RSA_X931_hash_id(iVar6);
          if (iVar6 == -1) {
LAB_000fe1a6:
            ERR_put_error(4,0x8c,0x8e,DAT_000fe23c,0x1e2);
            return;
          }
        }
      }
      ppEVar7[5] = param_4;
      return;
    }
    if (param_2 != 0xd) {
      if (param_2 < 0xe) {
        return;
      }
      if (param_2 != 0x1001) {
        return;
      }
      if ((undefined *)((int)&param_3[-1].md_ctrl + 3) < (undefined *)0x6) {
        pEVar5 = ppEVar7[5];
        if (pEVar5 != (EVP_MD *)0x0) {
          if (param_3 == (EVP_MD *)0x3) goto LAB_000fe1bc;
          if (param_3 == (EVP_MD *)0x5) {
            iVar6 = EVP_MD_type(pEVar5);
            iVar6 = RSA_X931_hash_id(iVar6);
            if (iVar6 == -1) goto LAB_000fe1a6;
            goto LAB_000fe01a;
          }
        }
        if (param_3 == (EVP_MD *)0x6) {
          uVar1 = *(uint *)(param_1 + 0x10) & 0x18;
        }
        else {
          if (param_3 != (EVP_MD *)0x4) goto LAB_000fe01a;
          uVar1 = *(uint *)(param_1 + 0x10) & 0x300;
        }
        if (uVar1 != 0) {
          if (pEVar5 == (EVP_MD *)0x0) {
            pEVar5 = EVP_sha1();
            ppEVar7[5] = pEVar5;
          }
LAB_000fe01a:
          ppEVar7[4] = param_3;
          return;
        }
      }
      ERR_put_error(4,0x8f,0x90,DAT_000fe23c,0x205);
      return;
    }
    goto LAB_000fe09a;
  }
  if (param_2 == 0x1007) goto LAB_000fe0a2;
  if (param_2 < 0x1008) {
    if (param_2 == 0x1004) {
      if (param_4 == (EVP_MD *)0x0) {
        return;
      }
      BN_free((BIGNUM *)ppEVar7[1]);
      ppEVar7[1] = param_4;
      return;
    }
    if (param_2 < 0x1004) {
      if ((int)param_3 < 0x100) {
        ERR_put_error(4,0x8f,0x91,DAT_000fe23c,0x21d);
        return;
      }
      *ppEVar7 = param_3;
      return;
    }
    if (param_2 != 0x1005) {
      if (param_2 != 0x1006) {
        return;
      }
      param_4->type = (int)ppEVar7[4];
      return;
    }
LAB_000fe164:
    if (((uint)ppEVar7[4] & 0xfffffffd) != 4) {
      ERR_put_error(4,0x8f,0x9c,DAT_000fe23c,0x244);
      return;
    }
    if (param_2 != 0x1008) {
      ppEVar7[6] = param_4;
      return;
    }
    if (ppEVar7[6] != (EVP_MD *)0x0) {
      param_4->type = (int)ppEVar7[6];
      return;
    }
  }
  else {
    if (param_2 == 0x100a) {
      if (ppEVar7[4] == (EVP_MD *)0x4) {
        pEVar5 = (EVP_MD *)0x4;
        if (ppEVar7[9] != (EVP_MD *)0x0) {
          CRYPTO_free(ppEVar7[9]);
          pEVar5 = extraout_r1;
        }
        bVar8 = param_4 == (EVP_MD *)0x0;
        pEVar4 = param_4;
        if (!bVar8) {
          pEVar4 = param_3;
        }
        bVar2 = (int)pEVar4 < 0;
        bVar3 = param_3 != (EVP_MD *)0x0;
        if ((bVar8 || !bVar3) || bVar2) {
          pEVar5 = (EVP_MD *)0x0;
        }
        if ((!bVar8 && bVar3) && !bVar2) {
          pEVar5 = (EVP_MD *)0x1;
        }
        if ((!bVar8 && bVar3) && !bVar2) {
          ppEVar7[9] = param_4;
        }
        if ((!bVar8 && bVar3) && !bVar2) {
          ppEVar7[10] = param_3;
        }
        if ((bVar8 || !bVar3) || bVar2) {
          ppEVar7[9] = pEVar5;
        }
        if ((!bVar8 && bVar3) && !bVar2) {
          return;
        }
        ppEVar7[10] = pEVar5;
        return;
      }
      iVar6 = 0x252;
      goto LAB_000fe0c0;
    }
    if (param_2 < 0x100b) {
      if (param_2 == 0x1008) goto LAB_000fe164;
      if (param_2 != 0x1009) {
        return;
      }
    }
    else if (param_2 != 0x100b) {
      if (param_2 != 0x100c) {
        return;
      }
      if (ppEVar7[4] == (EVP_MD *)0x4) {
        param_4->type = (int)ppEVar7[9];
        return;
      }
      iVar6 = 0x262;
      goto LAB_000fe0c0;
    }
    if (ppEVar7[4] != (EVP_MD *)0x4) {
      iVar6 = 0x22d;
LAB_000fe0c0:
      ERR_put_error(4,0x8f,0x8d,DAT_000fe23c,iVar6);
      return;
    }
    if (param_2 != 0x100b) {
      ppEVar7[5] = param_4;
      return;
    }
  }
LAB_000fe09a:
  param_4->type = (int)ppEVar7[5];
  return;
}

