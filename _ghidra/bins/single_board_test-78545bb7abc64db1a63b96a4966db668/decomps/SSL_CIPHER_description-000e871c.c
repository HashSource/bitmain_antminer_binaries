
char * SSL_CIPHER_description(SSL_CIPHER *param_1,char *buf,int size)

{
  undefined4 uVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  
  if (buf == (char *)0x0) {
    size = 0x80;
    buf = (char *)CRYPTO_malloc(0x80,"ssl/ssl_ciph.c",0x66d);
    if (buf == (char *)0x0) {
      ERR_put_error(0x14,0x272,0x41,"ssl/ssl_ciph.c",0x66e);
      return (char *)0x0;
    }
  }
  else if (size < 0x80) {
    return (char *)0x0;
  }
  uVar6 = param_1->algorithm_auth;
  uVar7 = param_1->algorithm_enc;
  uVar3 = param_1->algorithm_mac;
  uVar5 = param_1->algorithm_ssl;
  uVar1 = ssl_protocol_to_string(param_1->algo_strength);
  if (uVar6 == 8) {
    pcVar9 = "PSK";
  }
  else if (uVar6 < 9) {
    if (uVar6 == 1) {
      pcVar9 = "RSA";
    }
    else if (uVar6 == 0) {
      pcVar9 = "any";
    }
    else if (uVar6 == 2) {
      pcVar9 = "DH";
    }
    else {
      if (uVar6 != 4) goto LAB_000e894e;
      pcVar9 = "ECDH";
    }
  }
  else if (uVar6 == 0x40) {
    pcVar9 = "RSAPSK";
  }
  else if (uVar6 < 0x41) {
    if (uVar6 == 0x10) {
      pcVar9 = "GOST";
    }
    else if (uVar6 == 0x20) {
      pcVar9 = "SRP";
    }
    else {
LAB_000e894e:
      pcVar9 = "unknown";
    }
  }
  else if (uVar6 == 0x80) {
    pcVar9 = "ECDHEPSK";
  }
  else {
    if (uVar6 != 0x100) goto LAB_000e894e;
    pcVar9 = "DHEPSK";
  }
  if (uVar7 == 8) {
    pcVar8 = "ECDSA";
  }
  else if (uVar7 < 9) {
    if (uVar7 == 1) {
      pcVar8 = "RSA";
    }
    else if (uVar7 == 0) {
      pcVar8 = "any";
    }
    else if (uVar7 == 2) {
      pcVar8 = "DSS";
    }
    else {
      if (uVar7 != 4) goto LAB_000e88fe;
      pcVar8 = "None";
    }
  }
  else if (uVar7 == 0x20) {
    pcVar8 = "GOST01";
  }
  else if (uVar7 < 0x21) {
    if (uVar7 == 0x10) {
      pcVar8 = "PSK";
    }
    else {
LAB_000e88fe:
      pcVar8 = "unknown";
    }
  }
  else if (uVar7 == 0x40) {
    pcVar8 = "SRP";
  }
  else {
    if (uVar7 != 0xa0) goto LAB_000e88fe;
    pcVar8 = "GOST12";
  }
  if (uVar3 == 0x400) {
LAB_000e89e8:
    pcVar4 = "GOST89(256)";
  }
  else if (uVar3 < 0x401) {
    if (uVar3 == 0x10) {
      pcVar4 = "IDEA(128)";
    }
    else if (uVar3 < 0x11) {
      if (uVar3 == 2) {
        pcVar4 = "3DES(168)";
      }
      else if (uVar3 < 3) {
        if (uVar3 == 1) {
          pcVar4 = "DES(56)";
        }
        else {
LAB_000e8a62:
          pcVar4 = "unknown";
        }
      }
      else if (uVar3 == 4) {
        pcVar4 = "RC4(128)";
      }
      else {
        if (uVar3 != 8) goto LAB_000e8a62;
        pcVar4 = "RC2(128)";
      }
    }
    else if (uVar3 == 0x80) {
      pcVar4 = "AES(256)";
    }
    else if (uVar3 < 0x81) {
      if (uVar3 == 0x20) {
        pcVar4 = "None";
      }
      else {
        if (uVar3 != 0x40) goto LAB_000e8a62;
        pcVar4 = "AES(128)";
      }
    }
    else if (uVar3 == 0x100) {
      pcVar4 = "Camellia(128)";
    }
    else {
      if (uVar3 != 0x200) goto LAB_000e8a62;
      pcVar4 = "Camellia(256)";
    }
  }
  else if (uVar3 == 0x10000) {
    pcVar4 = "AESCCM8(128)";
  }
  else if (uVar3 < 0x10001) {
    if (uVar3 == 0x2000) {
      pcVar4 = "AESGCM(256)";
    }
    else if (uVar3 < 0x2001) {
      if (uVar3 == 0x800) {
        pcVar4 = "SEED(128)";
      }
      else {
        if (uVar3 != 0x1000) goto LAB_000e8a62;
        pcVar4 = "AESGCM(128)";
      }
    }
    else if (uVar3 == 0x4000) {
      pcVar4 = "AESCCM(128)";
    }
    else {
      if (uVar3 != 0x8000) goto LAB_000e8a62;
      pcVar4 = "AESCCM(256)";
    }
  }
  else if (uVar3 == 0x80000) {
    pcVar4 = "CHACHA20/POLY1305(256)";
  }
  else if (uVar3 < 0x80001) {
    if (uVar3 != 0x20000) {
      if (uVar3 == 0x40000) goto LAB_000e89e8;
      goto LAB_000e8a62;
    }
    pcVar4 = "AESCCM8(256)";
  }
  else if (uVar3 == 0x100000) {
    pcVar4 = "ARIAGCM(128)";
  }
  else {
    if (uVar3 != 0x200000) goto LAB_000e8a62;
    pcVar4 = "ARIAGCM(256)";
  }
  if (uVar5 == 0x10) {
    pcVar2 = "SHA256";
    goto LAB_000e88ae;
  }
  if (uVar5 < 0x11) {
    if (uVar5 == 2) {
      pcVar2 = "SHA1";
      goto LAB_000e88ae;
    }
    if (uVar5 < 3) {
      if (uVar5 == 1) {
        pcVar2 = "MD5";
        goto LAB_000e88ae;
      }
    }
    else {
      if (uVar5 == 4) {
        pcVar2 = "GOST94";
        goto LAB_000e88ae;
      }
      if (uVar5 == 8) goto LAB_000e8a3a;
    }
  }
  else {
    if (uVar5 == 0x80) {
LAB_000e8a18:
      pcVar2 = "GOST2012";
      goto LAB_000e88ae;
    }
    if (uVar5 < 0x81) {
      if (uVar5 == 0x20) {
        pcVar2 = "SHA384";
        goto LAB_000e88ae;
      }
      if (uVar5 == 0x40) {
        pcVar2 = "AEAD";
        goto LAB_000e88ae;
      }
    }
    else {
      if (uVar5 == 0x100) {
LAB_000e8a3a:
        pcVar2 = "GOST89";
        goto LAB_000e88ae;
      }
      if (uVar5 == 0x200) goto LAB_000e8a18;
    }
  }
  pcVar2 = "unknown";
LAB_000e88ae:
  BIO_snprintf(buf,size,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s\n",param_1->name,uVar1,pcVar9,
               pcVar8,pcVar4,pcVar2);
  return buf;
}

