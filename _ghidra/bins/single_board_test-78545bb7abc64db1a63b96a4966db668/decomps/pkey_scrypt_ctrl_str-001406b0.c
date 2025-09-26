
/* WARNING: Type propagation algorithm not settling */

undefined4 pkey_scrypt_ctrl_str(int param_1,char *param_2,byte *param_3)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  longlong lVar11;
  
  if (param_3 == (byte *)0x0) {
    ERR_put_error(0x34,0x68,0x66,"crypto/kdf/scrypt.c",0xb7);
    return 0;
  }
  iVar4 = strcmp(param_2,"pass");
  if (iVar4 == 0) {
    uVar5 = EVP_PKEY_CTX_str2ctrl(param_1,0x1008,param_3);
    return uVar5;
  }
  iVar4 = strcmp(param_2,"hexpass");
  if (iVar4 == 0) {
    uVar5 = 0x1008;
LAB_00140880:
    uVar5 = EVP_PKEY_CTX_hex2ctrl(param_1,uVar5,param_3);
    return uVar5;
  }
  iVar4 = strcmp(param_2,"salt");
  if (iVar4 == 0) {
    uVar5 = EVP_PKEY_CTX_str2ctrl(param_1,0x1009,param_3);
    return uVar5;
  }
  iVar4 = strcmp(param_2,"hexsalt");
  if (iVar4 == 0) {
    uVar5 = 0x1009;
    goto LAB_00140880;
  }
  cVar1 = *param_2;
  if (cVar1 == 'N') {
    if (param_2[1] == '\0') {
      if (*param_3 == 0) {
        return 0;
      }
      uVar6 = *param_3 - 0x30;
      if ((uVar6 & 0xff) < 10) {
        uVar7 = (int)uVar6 >> 0x1f;
        while( true ) {
          lVar3 = CONCAT44(uVar7,uVar6);
          param_3 = param_3 + 1;
          uVar9 = *param_3 - 0x30;
          uVar8 = (int)uVar9 >> 0x1f;
          if (*param_3 == 0) {
            if (uVar7 == 0 && uVar6 < 2) {
              return 0;
            }
            if (((uVar7 - 1) + (uint)(uVar6 != 0) & uVar7) != 0 || (uVar6 - 1 & uVar6) != 0) {
              return 0;
            }
            iVar4 = *(int *)(param_1 + 0x14);
            *(uint *)(iVar4 + 0x10) = uVar6;
            *(uint *)(iVar4 + 0x14) = uVar7;
            return 1;
          }
          if (9 < (uVar9 & 0xff)) break;
          uVar2 = uVar6 * 10;
          iVar4 = ((uVar7 << 2 | uVar6 >> 0x1e) + uVar7 + (uint)CARRY4(uVar6 * 4,uVar6)) * 2 +
                  (uint)CARRY4(uVar6 * 5,uVar6 * 5);
          uVar6 = uVar2 + uVar9;
          uVar7 = iVar4 + uVar8 + CARRY4(uVar2,uVar9);
          bVar10 = uVar8 <= uVar7;
          if (uVar7 == uVar8) {
            bVar10 = uVar9 <= uVar6;
          }
          if ((!bVar10) || (lVar11 = __aeabi_uldivmod(uVar2,iVar4,10,0), lVar11 != lVar3)) break;
        }
      }
      goto LAB_00140848;
    }
  }
  else if (cVar1 == 'r') {
    if (param_2[1] == '\0') {
      if (*param_3 == 0) {
        return 0;
      }
      uVar6 = *param_3 - 0x30;
      if ((uVar6 & 0xff) < 10) {
        uVar7 = (int)uVar6 >> 0x1f;
        while( true ) {
          lVar3 = CONCAT44(uVar7,uVar6);
          param_3 = param_3 + 1;
          uVar9 = *param_3 - 0x30;
          uVar8 = (int)uVar9 >> 0x1f;
          if (*param_3 == 0) {
            if (uVar6 == 0 && uVar7 == 0) {
              return 0;
            }
            iVar4 = *(int *)(param_1 + 0x14);
            *(uint *)(iVar4 + 0x18) = uVar6;
            *(uint *)(iVar4 + 0x1c) = uVar7;
            return 1;
          }
          if (9 < (uVar9 & 0xff)) break;
          uVar2 = uVar6 * 10;
          iVar4 = ((uVar7 << 2 | uVar6 >> 0x1e) + uVar7 + (uint)CARRY4(uVar6 * 4,uVar6)) * 2 +
                  (uint)CARRY4(uVar6 * 5,uVar6 * 5);
          uVar6 = uVar2 + uVar9;
          uVar7 = iVar4 + uVar8 + CARRY4(uVar2,uVar9);
          bVar10 = uVar8 <= uVar7;
          if (uVar7 == uVar8) {
            bVar10 = uVar9 <= uVar6;
          }
          if ((!bVar10) || (lVar11 = __aeabi_uldivmod(uVar2,iVar4,10,0), lVar11 != lVar3)) break;
        }
      }
      goto LAB_00140848;
    }
  }
  else if ((cVar1 == 'p') && (param_2[1] == '\0')) {
    if (*param_3 == 0) {
      return 0;
    }
    uVar6 = *param_3 - 0x30;
    if ((uVar6 & 0xff) < 10) {
      uVar7 = (int)uVar6 >> 0x1f;
      while( true ) {
        lVar3 = CONCAT44(uVar7,uVar6);
        param_3 = param_3 + 1;
        uVar9 = *param_3 - 0x30;
        uVar8 = (int)uVar9 >> 0x1f;
        if (*param_3 == 0) {
          if (uVar6 == 0 && uVar7 == 0) {
            return 0;
          }
          iVar4 = *(int *)(param_1 + 0x14);
          *(uint *)(iVar4 + 0x20) = uVar6;
          *(uint *)(iVar4 + 0x24) = uVar7;
          return 1;
        }
        if (9 < (uVar9 & 0xff)) break;
        uVar2 = uVar6 * 10;
        iVar4 = ((uVar7 << 2 | uVar6 >> 0x1e) + uVar7 + (uint)CARRY4(uVar6 * 4,uVar6)) * 2 +
                (uint)CARRY4(uVar6 * 5,uVar6 * 5);
        uVar6 = uVar2 + uVar9;
        uVar7 = iVar4 + uVar8 + CARRY4(uVar2,uVar9);
        bVar10 = uVar8 <= uVar7;
        if (uVar7 == uVar8) {
          bVar10 = uVar9 <= uVar6;
        }
        if ((!bVar10) || (lVar11 = __aeabi_uldivmod(uVar2,iVar4,10,0), lVar11 != lVar3)) break;
      }
    }
    goto LAB_00140848;
  }
  iVar4 = strcmp(param_2,"maxmem_bytes");
  if (iVar4 != 0) {
    ERR_put_error(0x34,0x68,0x67,"crypto/kdf/scrypt.c",0xd4);
    return 0xfffffffe;
  }
  if (*param_3 == 0) {
    return 0;
  }
  uVar6 = *param_3 - 0x30;
  if ((uVar6 & 0xff) < 10) {
    uVar7 = (int)uVar6 >> 0x1f;
    while( true ) {
      lVar3 = CONCAT44(uVar7,uVar6);
      param_3 = param_3 + 1;
      uVar8 = *param_3 - 0x30;
      uVar9 = (int)uVar8 >> 0x1f;
      if (*param_3 == 0) {
        if (uVar6 != 0 || uVar7 != 0) {
          iVar4 = *(int *)(param_1 + 0x14);
          *(uint *)(iVar4 + 0x28) = uVar6;
          *(uint *)(iVar4 + 0x2c) = uVar7;
          return 1;
        }
        return 0;
      }
      if (9 < (uVar8 & 0xff)) break;
      uVar2 = uVar6 * 10;
      iVar4 = ((uVar7 << 2 | uVar6 >> 0x1e) + uVar7 + (uint)CARRY4(uVar6 * 4,uVar6)) * 2 +
              (uint)CARRY4(uVar6 * 5,uVar6 * 5);
      uVar6 = uVar2 + uVar8;
      uVar7 = iVar4 + uVar9 + CARRY4(uVar2,uVar8);
      bVar10 = uVar9 <= uVar7;
      if (uVar7 == uVar9) {
        bVar10 = uVar8 <= uVar6;
      }
      if ((!bVar10) || (lVar11 = __aeabi_uldivmod(uVar2,iVar4,10,0), lVar11 != lVar3)) break;
    }
  }
LAB_00140848:
  ERR_put_error(0x34,0x69,0x6c,"crypto/kdf/scrypt.c",0xad);
  return 0;
}

