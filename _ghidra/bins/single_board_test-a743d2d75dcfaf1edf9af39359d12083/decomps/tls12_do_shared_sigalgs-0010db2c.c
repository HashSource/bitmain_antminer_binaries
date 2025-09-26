
int tls12_do_shared_sigalgs(int param_1,char *param_2,uint param_3,int param_4,uint param_5)

{
  EVP_MD *pEVar1;
  uint uVar2;
  char *pcVar3;
  int local_2c;
  
  if (param_3 == 0) {
    local_2c = 0;
  }
  else {
    local_2c = 0;
    pcVar3 = param_2;
    do {
      switch(*pcVar3) {
      case '\x01':
        pEVar1 = EVP_md5();
        break;
      case '\x02':
        pEVar1 = EVP_sha1();
        break;
      case '\x03':
        pEVar1 = EVP_sha224();
        break;
      case '\x04':
        pEVar1 = EVP_sha256();
        break;
      case '\x05':
        pEVar1 = EVP_sha384();
        break;
      case '\x06':
        pEVar1 = EVP_sha512();
        break;
      default:
        goto switchD_0010db54_default;
      }
      if (pEVar1 != (EVP_MD *)0x0) {
        uVar2 = (uint)(byte)(pcVar3[1] - 1);
        if (((uVar2 < 3) && (*(int *)(&CSWTCH_132 + uVar2 * 4) != -1)) && (param_5 != 0)) {
          uVar2 = 0;
          do {
            if ((*(char *)(param_4 + uVar2) == *pcVar3) &&
               (*(char *)(param_4 + uVar2 + 1) == pcVar3[1])) {
              local_2c = local_2c + 1;
              if (param_1 != 0) {
                *(char *)(param_1 + 0xd) = *pcVar3;
                *(char *)(param_1 + 0xc) = pcVar3[1];
                tls1_lookup_sigalg(param_1,param_1 + 4,param_1 + 8,pcVar3);
                param_1 = param_1 + 0x10;
              }
              break;
            }
            uVar2 = uVar2 + 2;
          } while (uVar2 < param_5);
        }
      }
switchD_0010db54_default:
      pcVar3 = pcVar3 + 2;
    } while ((uint)((int)pcVar3 - (int)param_2) < param_3);
  }
  return local_2c;
}

