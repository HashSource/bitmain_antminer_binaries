
int tls12_do_shared_sigalgs(int param_1,char *param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  EVP_MD *pEVar2;
  uint uVar3;
  char *pcVar4;
  int local_2c;
  
  iVar1 = DAT_000703a8;
  if (param_3 == 0) {
    local_2c = 0;
  }
  else {
    local_2c = 0;
    pcVar4 = param_2;
    do {
      switch(*pcVar4) {
      case '\x01':
        pEVar2 = EVP_md5();
        break;
      case '\x02':
        pEVar2 = EVP_sha1();
        break;
      case '\x03':
        pEVar2 = EVP_sha224();
        break;
      case '\x04':
        pEVar2 = EVP_sha256();
        break;
      case '\x05':
        pEVar2 = EVP_sha384();
        break;
      case '\x06':
        pEVar2 = EVP_sha512();
        break;
      default:
        goto switchD_00070304_caseD_6;
      }
      if (pEVar2 != (EVP_MD *)0x0) {
        uVar3 = (uint)(byte)(pcVar4[1] - 1);
        if (((uVar3 < 3) && (*(int *)(iVar1 + uVar3 * 4) != -1)) && (param_5 != 0)) {
          uVar3 = 0;
          do {
            if ((*(char *)(param_4 + uVar3) == *pcVar4) &&
               (*(char *)(param_4 + uVar3 + 1) == pcVar4[1])) {
              local_2c = local_2c + 1;
              if (param_1 != 0) {
                *(char *)(param_1 + 0xd) = *pcVar4;
                *(char *)(param_1 + 0xc) = pcVar4[1];
                tls1_lookup_sigalg(param_1,param_1 + 4,param_1 + 8,pcVar4);
                param_1 = param_1 + 0x10;
              }
              break;
            }
            uVar3 = uVar3 + 2;
          } while (uVar3 < param_5);
        }
      }
switchD_00070304_caseD_6:
      pcVar4 = pcVar4 + 2;
    } while ((uint)((int)pcVar4 - (int)param_2) < param_3);
  }
  return local_2c;
}

