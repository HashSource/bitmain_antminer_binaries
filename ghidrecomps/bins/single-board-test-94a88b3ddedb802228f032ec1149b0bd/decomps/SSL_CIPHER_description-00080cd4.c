
char * SSL_CIPHER_description(SSL_CIPHER *param_1,char *buf,int size)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  bool bVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  int local_30;
  
  uVar3 = param_1->algo_strength & 2;
  uVar2 = param_1->algorithm_mkey;
  uVar5 = param_1->algorithm_auth;
  uVar4 = param_1->algorithm_enc;
  uVar12 = param_1->algorithm_ssl;
  if ((param_1->algo_strength & 8) == 0) {
    if (uVar4 == 1) {
      local_30 = 8;
    }
    else {
      local_30 = 7;
    }
    iVar8 = 0x400;
    bVar10 = false;
  }
  else {
    bVar10 = true;
    iVar8 = 0x200;
    local_30 = 5;
  }
  uVar7 = DAT_00080fd4;
  if (uVar3 == 0) {
    uVar7 = DAT_00081038;
  }
  uVar1 = DAT_00081044;
  if ((((uVar12 & 1) == 0) && (uVar1 = DAT_0008103c, (uVar12 & 2) == 0)) &&
     (uVar1 = DAT_00080fd8, (uVar12 & 4) != 0)) {
    uVar1 = DAT_00081048;
  }
  uVar9 = DAT_00081040;
  if (uVar2 != 0x20) {
    if (uVar2 < 0x21) {
      uVar9 = DAT_00081068;
      if (uVar2 != 4) {
        if (uVar2 < 5) {
          if (uVar2 == 1) {
            uVar9 = DAT_00081018;
            if ((uVar3 != 0) && (uVar9 = DAT_00081060, iVar8 == 0x200)) {
              uVar9 = DAT_00081020;
            }
          }
          else {
            uVar9 = DAT_0008104c;
            if (uVar2 != 2) goto LAB_00080d60;
          }
        }
        else if (uVar2 == 8) {
          uVar9 = DAT_00080ffc;
          if ((uVar3 != 0) && (uVar9 = DAT_00081058, iVar8 == 0x200)) {
            uVar9 = DAT_00081004;
          }
        }
        else {
          uVar9 = DAT_0008101c;
          if (uVar2 != 0x10) goto LAB_00080d60;
        }
      }
    }
    else {
      uVar9 = DAT_00080fe8;
      if (uVar2 != 0x100) {
        if (uVar2 < 0x101) {
          uVar9 = DAT_0008105c;
          if ((uVar2 != 0x40) && (uVar9 = DAT_00080ff0, uVar2 != 0x80)) {
LAB_00080d60:
            uVar9 = DAT_00080fd8;
          }
        }
        else {
          uVar9 = DAT_00081064;
          if ((uVar2 != 0x200) && (uVar9 = DAT_00080fec, uVar2 != 0x400)) goto LAB_00080d60;
        }
      }
    }
  }
  uVar6 = DAT_0008101c;
  if (uVar5 != 0x20) {
    if (uVar5 < 0x21) {
      uVar6 = DAT_00081000;
      if (uVar5 != 4) {
        if (uVar5 < 5) {
          uVar6 = DAT_00081018;
          if ((uVar5 != 1) && (uVar6 = DAT_00081014, uVar5 != 2)) {
LAB_00080d82:
            uVar6 = DAT_00080fd8;
          }
        }
        else {
          uVar6 = DAT_00080ffc;
          if ((uVar5 != 8) && (uVar6 = DAT_00080ff0, uVar5 != 0x10)) goto LAB_00080d82;
        }
      }
    }
    else {
      uVar6 = DAT_00081010;
      if (uVar5 != 0x100) {
        if (uVar5 < 0x101) {
          uVar6 = DAT_00081008;
          if ((uVar5 != 0x40) && (uVar6 = DAT_00080fe8, uVar5 != 0x80)) goto LAB_00080d82;
        }
        else {
          uVar6 = DAT_0008100c;
          if ((uVar5 != 0x200) && (uVar6 = DAT_00080fec, uVar5 != 0x400)) goto LAB_00080d82;
        }
      }
    }
  }
  uVar11 = DAT_0008106c;
  if (uVar4 == 0x40) goto LAB_00080da6;
  if (uVar4 < 0x41) {
    if (uVar4 == 4) {
      if (uVar3 == 0) {
        uVar11 = DAT_000810a8;
        if ((param_1->algorithm2 & 2) != 0) {
          uVar11 = DAT_000810ac;
        }
      }
      else {
        uVar11 = DAT_00081028;
        if (local_30 == 5) {
          uVar11 = DAT_0008102c;
        }
      }
      goto LAB_00080da6;
    }
    if (uVar4 < 5) {
      if (uVar4 == 1) {
        if (uVar3 == 0) {
          bVar10 = false;
        }
        uVar11 = DAT_00081030;
        if (bVar10) {
          uVar11 = DAT_00081034;
        }
        goto LAB_00080da6;
      }
      uVar11 = DAT_0008107c;
      if (uVar4 == 2) goto LAB_00080da6;
    }
    else {
      uVar11 = DAT_00081080;
      if ((uVar4 == 0x10) || (uVar11 = DAT_00081000, uVar4 == 0x20)) goto LAB_00080da6;
      if (uVar4 == 8) {
        uVar11 = DAT_0008108c;
        if ((uVar3 != 0) && (uVar11 = DAT_00080ff4, local_30 == 5)) {
          uVar11 = DAT_00080ff8;
        }
        goto LAB_00080da6;
      }
    }
  }
  else {
    uVar11 = DAT_00081088;
    if (uVar4 == 0x400) goto LAB_00080da6;
    if (uVar4 < 0x401) {
      uVar11 = DAT_00081078;
      if (((uVar4 == 0x100) || (uVar11 = DAT_00081074, uVar4 == 0x200)) ||
         (uVar11 = DAT_00081050, uVar4 == 0x80)) goto LAB_00080da6;
    }
    else {
      uVar11 = DAT_00081084;
      if (((uVar4 == 0x1000) || (uVar11 = DAT_00081070, uVar4 == 0x2000)) ||
         (uVar11 = DAT_00081054, uVar4 == 0x800)) goto LAB_00080da6;
    }
  }
  uVar11 = DAT_00080fd8;
LAB_00080da6:
  uVar2 = param_1->algorithm_mac - 1;
  uVar13 = DAT_00080fd8;
  if (uVar2 < 0x40) {
    uVar13 = *(undefined4 *)(DAT_00080fdc + uVar2 * 4 + 0xff8);
  }
  if (buf == (char *)0x0) {
    buf = (char *)CRYPTO_malloc(0x80,DAT_00081024,0x741);
    if (buf == (char *)0x0) {
      return DAT_000810b0;
    }
    size = 0x80;
  }
  else if (size < 0x80) {
    return DAT_00080fe4;
  }
  BIO_snprintf(buf,size,DAT_00080fe0,param_1->name,uVar1,uVar9,uVar6,uVar11,uVar13,uVar7);
  return buf;
}

