
char * SSL_CIPHER_description(SSL_CIPHER *param_1,char *buf,int size)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  bool bVar10;
  char *pcVar11;
  uint uVar12;
  char *pcVar13;
  int local_30;
  
  uVar2 = param_1->algo_strength & 2;
  uVar1 = param_1->algorithm_mkey;
  uVar4 = param_1->algorithm_auth;
  uVar3 = param_1->algorithm_enc;
  uVar12 = param_1->algorithm_ssl;
  if ((param_1->algo_strength & 8) == 0) {
    if (uVar3 == 1) {
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
  pcVar6 = " export";
  if (uVar2 == 0) {
    pcVar6 = "";
  }
  if ((uVar12 & 1) == 0) {
    if ((uVar12 & 2) == 0) {
      pcVar7 = "unknown";
      if ((uVar12 & 4) != 0) {
        pcVar7 = "TLSv1.2";
      }
      goto LAB_00080d44;
    }
    pcVar7 = "SSLv3";
    if (uVar1 != 0x20) goto LAB_00080d48;
LAB_00080d2a:
    pcVar9 = "ECDH/RSA";
  }
  else {
    pcVar7 = "SSLv2";
LAB_00080d44:
    if (uVar1 == 0x20) goto LAB_00080d2a;
LAB_00080d48:
    if (uVar1 < 0x21) {
      if (uVar1 == 4) {
        pcVar9 = "DH/DSS";
      }
      else if (uVar1 < 5) {
        if (uVar1 == 1) {
          if (uVar2 == 0) {
            pcVar9 = "RSA";
          }
          else if (iVar8 == 0x200) {
            pcVar9 = "RSA(512)";
          }
          else {
            pcVar9 = "RSA(1024)";
          }
        }
        else {
          if (uVar1 != 2) goto LAB_00080d60;
          pcVar9 = "DH/RSA";
        }
      }
      else if (uVar1 == 8) {
        if (uVar2 == 0) {
          pcVar9 = "DH";
        }
        else if (iVar8 == 0x200) {
          pcVar9 = "DH(512)";
        }
        else {
          pcVar9 = "DH(1024)";
        }
      }
      else {
        if (uVar1 != 0x10) goto LAB_00080d60;
        pcVar9 = "KRB5";
      }
    }
    else if (uVar1 == 0x100) {
      pcVar9 = "PSK";
    }
    else if (uVar1 < 0x101) {
      if (uVar1 == 0x40) {
        pcVar9 = "ECDH/ECDSA";
      }
      else if (uVar1 == 0x80) {
        pcVar9 = "ECDH";
      }
      else {
LAB_00080d60:
        pcVar9 = "unknown";
      }
    }
    else if (uVar1 == 0x200) {
      pcVar9 = "GOST";
    }
    else {
      if (uVar1 != 0x400) goto LAB_00080d60;
      pcVar9 = "SRP";
    }
  }
  if (uVar4 == 0x20) {
    pcVar5 = "KRB5";
  }
  else if (uVar4 < 0x21) {
    if (uVar4 == 4) {
      pcVar5 = "None";
    }
    else if (uVar4 < 5) {
      if (uVar4 == 1) {
        pcVar5 = "RSA";
      }
      else if (uVar4 == 2) {
        pcVar5 = "DSS";
      }
      else {
LAB_00080d82:
        pcVar5 = "unknown";
      }
    }
    else if (uVar4 == 8) {
      pcVar5 = "DH";
    }
    else {
      if (uVar4 != 0x10) goto LAB_00080d82;
      pcVar5 = "ECDH";
    }
  }
  else if (uVar4 == 0x100) {
    pcVar5 = "GOST94";
  }
  else if (uVar4 < 0x101) {
    if (uVar4 == 0x40) {
      pcVar5 = "ECDSA";
    }
    else {
      if (uVar4 != 0x80) goto LAB_00080d82;
      pcVar5 = "PSK";
    }
  }
  else if (uVar4 == 0x200) {
    pcVar5 = "GOST01";
  }
  else {
    if (uVar4 != 0x400) goto LAB_00080d82;
    pcVar5 = "SRP";
  }
  if (uVar3 == 0x40) {
    pcVar11 = "AES(128)";
    goto LAB_00080da6;
  }
  if (uVar3 < 0x41) {
    if (uVar3 == 4) {
      if (uVar2 == 0) {
        if ((param_1->algorithm2 & 2) == 0) {
          pcVar11 = "RC4(128)";
        }
        else {
          pcVar11 = "RC4(64)";
        }
      }
      else if (local_30 == 5) {
        pcVar11 = "RC4(40)";
      }
      else {
        pcVar11 = "RC4(56)";
      }
      goto LAB_00080da6;
    }
    if (uVar3 < 5) {
      if (uVar3 == 1) {
        if (uVar2 == 0) {
          bVar10 = false;
        }
        if (bVar10) {
          pcVar11 = "DES(40)";
        }
        else {
          pcVar11 = "DES(56)";
        }
        goto LAB_00080da6;
      }
      if (uVar3 == 2) {
        pcVar11 = "3DES(168)";
        goto LAB_00080da6;
      }
    }
    else {
      if (uVar3 == 0x10) {
        pcVar11 = "IDEA(128)";
        goto LAB_00080da6;
      }
      if (uVar3 == 0x20) {
        pcVar11 = "None";
        goto LAB_00080da6;
      }
      if (uVar3 == 8) {
        if (uVar2 == 0) {
          pcVar11 = "RC2(128)";
        }
        else if (local_30 == 5) {
          pcVar11 = "RC2(40)";
        }
        else {
          pcVar11 = "RC2(56)";
        }
        goto LAB_00080da6;
      }
    }
  }
  else {
    if (uVar3 == 0x400) {
      pcVar11 = "GOST89(256)";
      goto LAB_00080da6;
    }
    if (uVar3 < 0x401) {
      if (uVar3 == 0x100) {
        pcVar11 = "Camellia(128)";
        goto LAB_00080da6;
      }
      if (uVar3 == 0x200) {
        pcVar11 = "Camellia(256)";
        goto LAB_00080da6;
      }
      if (uVar3 == 0x80) {
        pcVar11 = "AES(256)";
        goto LAB_00080da6;
      }
    }
    else {
      if (uVar3 == 0x1000) {
        pcVar11 = "AESGCM(128)";
        goto LAB_00080da6;
      }
      if (uVar3 == 0x2000) {
        pcVar11 = "AESGCM(256)";
        goto LAB_00080da6;
      }
      if (uVar3 == 0x800) {
        pcVar11 = "SEED(128)";
        goto LAB_00080da6;
      }
    }
  }
  pcVar11 = "unknown";
LAB_00080da6:
  uVar1 = param_1->algorithm_mac - 1;
  if (uVar1 < 0x40) {
    pcVar13 = *(char **)(CSWTCH_91 + uVar1 * 4);
  }
  else {
    pcVar13 = "unknown";
  }
  if (buf == (char *)0x0) {
    buf = (char *)CRYPTO_malloc(0x80,"ssl_ciph.c",0x741);
    if (buf == (char *)0x0) {
      return "OPENSSL_malloc Error";
    }
    size = 0x80;
  }
  else if (size < 0x80) {
    return "Buffer too small";
  }
  BIO_snprintf(buf,size,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s\n",param_1->name,pcVar7,pcVar9
               ,pcVar5,pcVar11,pcVar13,pcVar6);
  return buf;
}

