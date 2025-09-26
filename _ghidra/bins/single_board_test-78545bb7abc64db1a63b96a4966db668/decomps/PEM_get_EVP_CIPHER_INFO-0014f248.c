
int PEM_get_EVP_CIPHER_INFO(char *header,EVP_CIPHER_INFO *cipher)

{
  int iVar1;
  size_t sVar2;
  EVP_CIPHER *cipher_00;
  int iVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  byte *pbVar7;
  char *pcVar8;
  uchar *__s;
  char *pcVar9;
  byte *pbVar10;
  byte *pbVar11;
  
  __s = cipher->iv;
  cipher->cipher = (EVP_CIPHER *)0x0;
  cipher->iv[0] = '\0';
  cipher->iv[1] = '\0';
  cipher->iv[2] = '\0';
  cipher->iv[3] = '\0';
  cipher->iv[4] = '\0';
  cipher->iv[5] = '\0';
  cipher->iv[6] = '\0';
  cipher->iv[7] = '\0';
  cipher->iv[8] = '\0';
  cipher->iv[9] = '\0';
  cipher->iv[10] = '\0';
  cipher->iv[0xb] = '\0';
  cipher->iv[0xc] = '\0';
  cipher->iv[0xd] = '\0';
  cipher->iv[0xe] = '\0';
  cipher->iv[0xf] = '\0';
  if ((header == (char *)0x0) || (*header == '\n' || *header == '\0')) {
    return 1;
  }
  iVar1 = strncmp(header,"Proc-Type:",10);
  if (iVar1 == 0) {
    cVar5 = header[10];
    if (cVar5 == ' ' || cVar5 == '\t') {
      pcVar9 = header + 0xb;
      do {
        pcVar8 = pcVar9;
        cVar5 = *pcVar8;
        pcVar9 = pcVar8 + 1;
      } while (cVar5 == '\t' || cVar5 == ' ');
    }
    else {
      pcVar8 = header + 10;
    }
    if ((cVar5 == '4') && (pcVar8[1] == ',')) {
      pcVar9 = pcVar8 + 2;
      if (pcVar8[2] == ' ' || pcVar8[2] == '\t') {
        pcVar8 = pcVar8 + 3;
        do {
          pcVar9 = pcVar8;
          pcVar8 = pcVar9 + 1;
        } while (*pcVar9 == ' ' || *pcVar9 == '\t');
      }
      iVar1 = strncmp(pcVar9,"ENCRYPTED",9);
      if (iVar1 == 0) {
        pbVar10 = (byte *)(pcVar9 + 9);
        sVar2 = strspn((char *)pbVar10," \t\r\n");
        if (sVar2 != 0) {
          bVar6 = pcVar9[9];
          if (bVar6 == 0x20 || (bVar6 & 0xfb) == 9) {
            pbVar11 = (byte *)(pcVar9 + 10);
            do {
              pbVar10 = pbVar11;
              bVar6 = *pbVar10;
              pbVar11 = pbVar10 + 1;
            } while (bVar6 == 0x20 || (bVar6 & 0xfb) == 9);
          }
          if (bVar6 != 10) {
            ERR_put_error(9,0x6b,0x70,"crypto/pem/pem_lib.c",0x203);
            return 0;
          }
          iVar1 = strncmp((char *)(pbVar10 + 1),"DEK-Info:",9);
          if (iVar1 != 0) {
            ERR_put_error(9,0x6b,0x69,"crypto/pem/pem_lib.c",0x20c);
            return 0;
          }
          bVar6 = pbVar10[10];
          pbVar11 = pbVar10 + 10;
          if (bVar6 == 0x20 || bVar6 == 9) {
            pbVar10 = pbVar10 + 0xb;
            do {
              pbVar11 = pbVar10;
              bVar6 = *pbVar11;
              pbVar10 = pbVar11 + 1;
            } while (bVar6 == 9 || bVar6 == 0x20);
          }
          if (bVar6 == 0) {
            *pbVar11 = 0;
            cipher_00 = EVP_get_cipherbyname((char *)pbVar11);
            cipher->cipher = cipher_00;
            *pbVar11 = 0;
          }
          else {
            pbVar10 = pbVar11;
            if (bVar6 == 0x2c || (bVar6 == 9 || bVar6 == 0x20)) {
LAB_0014f3d6:
              *pbVar10 = 0;
              cipher_00 = EVP_get_cipherbyname((char *)pbVar11);
              cipher->cipher = cipher_00;
              *pbVar10 = bVar6;
              pbVar11 = pbVar10;
            }
            else {
              do {
                pbVar10 = pbVar10 + 1;
                bVar6 = *pbVar10;
                if (bVar6 == 0) goto LAB_0014f3d6;
              } while (bVar6 != 0x2c && (bVar6 != 9 && bVar6 != 0x20));
              *pbVar10 = 0;
              cipher_00 = EVP_get_cipherbyname((char *)pbVar11);
              cipher->cipher = cipher_00;
              *pbVar10 = bVar6;
              pbVar11 = pbVar10;
              if (bVar6 == 9 || bVar6 == 0x20) {
                do {
                  pbVar11 = pbVar10 + 1;
                  pbVar10 = pbVar11;
                } while (*pbVar11 == 0x20 || *pbVar11 == 9);
              }
            }
          }
          if (cipher_00 == (EVP_CIPHER *)0x0) {
            ERR_put_error(9,0x6b,0x72,"crypto/pem/pem_lib.c",0x21f);
            return 0;
          }
          iVar1 = EVP_CIPHER_iv_length(cipher_00);
          if (iVar1 < 1) {
            if ((iVar1 == 0) && (*pbVar11 == 0x2c)) {
              ERR_put_error(9,0x6b,0x82,"crypto/pem/pem_lib.c",0x227);
              return 0;
            }
          }
          else {
            if (*pbVar11 != 0x2c) {
              ERR_put_error(9,0x6b,0x81,"crypto/pem/pem_lib.c",0x224);
              return 0;
            }
            pbVar11 = pbVar11 + 1;
          }
          sVar2 = EVP_CIPHER_iv_length(cipher_00);
          if (0 < (int)sVar2) {
            memset(__s,0,sVar2);
          }
          if ((int)(sVar2 * 2) < 1) {
            return 1;
          }
          pbVar10 = pbVar11;
          do {
            pbVar7 = pbVar10 + 1;
            iVar4 = OPENSSL_hexchar2int(*pbVar10);
            iVar1 = (int)pbVar10 - (int)pbVar11 >> 1;
            if (iVar4 < 0) {
              ERR_put_error(9,0x65,0x67,"crypto/pem/pem_lib.c",0x23d);
              return 0;
            }
            if (((int)pbVar10 - (int)pbVar11 & 1U) == 0) {
              iVar3 = 4;
            }
            else {
              iVar3 = 0;
            }
            __s[iVar1] = (byte)(iVar4 << iVar3) | __s[iVar1];
            pbVar10 = pbVar7;
          } while (pbVar7 != pbVar11 + sVar2 * 2);
          return 1;
        }
      }
      ERR_put_error(9,0x6b,0x6a,"crypto/pem/pem_lib.c",0x1fd);
    }
  }
  else {
    ERR_put_error(9,0x6b,0x6b,"crypto/pem/pem_lib.c",0x1f0);
  }
  return 0;
}

