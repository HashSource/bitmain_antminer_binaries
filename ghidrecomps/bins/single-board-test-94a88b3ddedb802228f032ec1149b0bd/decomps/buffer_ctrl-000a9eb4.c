
size_t buffer_ctrl(BIO *param_1,int param_2,size_t param_3,BIO *param_4)

{
  BIO *pBVar1;
  size_t sVar2;
  void *pvVar3;
  long lVar4;
  char *pcVar5;
  size_t *psVar7;
  size_t sVar8;
  void *pvVar9;
  char *pcVar6;
  
  psVar7 = (size_t *)param_1->ptr;
  if (param_2 == 0xc) {
    lVar4 = BIO_int_ctrl(param_4,0x75,*psVar7,0);
    if (lVar4 == 0) {
      return 0;
    }
    lVar4 = BIO_int_ctrl(param_4,0x75,psVar7[1],1);
    if (lVar4 == 0) {
      return 0;
    }
    return 1;
  }
  if (param_2 < 0xd) {
    if (param_2 == 3) {
      return psVar7[6];
    }
    if (param_2 < 4) {
      if (param_2 == 1) {
        pBVar1 = param_1->next_bio;
        psVar7[4] = 0;
        psVar7[3] = 0;
        psVar7[7] = 0;
        psVar7[6] = 0;
        if (pBVar1 == (bio_st *)0x0) {
          return 0;
        }
        goto LAB_000a9eea;
      }
    }
    else {
      if (param_2 == 10) {
        sVar2 = psVar7[3];
        goto joined_r0x000aa018;
      }
      if (param_2 == 0xb) {
        pBVar1 = param_1->next_bio;
        if (pBVar1 == (bio_st *)0x0) {
          return 0;
        }
        if (0 < (int)psVar7[6]) {
          while( true ) {
            BIO_clear_flags(param_1,0xf);
            if ((int)psVar7[6] < 1) {
              pBVar1 = param_1->next_bio;
              psVar7[6] = 0;
              psVar7[7] = 0;
              sVar2 = BIO_ctrl(pBVar1,0xb,param_3,param_4);
              return sVar2;
            }
            sVar2 = BIO_write(param_1->next_bio,(void *)(psVar7[5] + psVar7[7]),psVar7[6]);
            BIO_copy_next_retry(param_1);
            if ((int)sVar2 < 1) break;
            psVar7[7] = sVar2 + psVar7[7];
            psVar7[6] = psVar7[6] - sVar2;
          }
          return sVar2;
        }
        goto LAB_000a9eea;
      }
    }
  }
  else {
    if (param_2 == 0x74) {
      if (0 < (int)psVar7[3]) {
        sVar2 = 0;
        pcVar6 = (char *)(psVar7[2] + psVar7[4]);
        do {
          pcVar5 = pcVar6 + 1;
          if (*pcVar6 == '\n') {
            sVar2 = sVar2 + 1;
          }
          pcVar6 = pcVar5;
        } while (pcVar5 != (char *)(psVar7[2] + psVar7[4]) + psVar7[3]);
        return sVar2;
      }
      return 0;
    }
    if (param_2 < 0x75) {
      if (param_2 == 0xd) {
        sVar2 = psVar7[6];
joined_r0x000aa018:
        if (sVar2 != 0) {
          return sVar2;
        }
        pBVar1 = param_1->next_bio;
        if (pBVar1 == (bio_st *)0x0) {
          return 0;
        }
        goto LAB_000a9eea;
      }
      if (param_2 == 0x65) {
        if (param_1->next_bio == (bio_st *)0x0) {
          return 0;
        }
        BIO_clear_flags(param_1,0xf);
        sVar2 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
        BIO_copy_next_retry(param_1);
        return sVar2;
      }
    }
    else {
      if (param_2 == 0x75) {
        sVar2 = param_3;
        sVar8 = param_3;
        if (param_4 != (BIO *)0x0) {
          if (param_4->method == (BIO_METHOD *)0x0) {
            sVar2 = psVar7[1];
          }
          else {
            sVar8 = *psVar7;
          }
        }
        pvVar3 = (void *)psVar7[2];
        pvVar9 = (void *)psVar7[5];
        if ((((int)sVar8 < 0x1001) || (*psVar7 == sVar8)) ||
           (pvVar3 = CRYPTO_malloc(param_3,DAT_000aa0f4,0x171), pvVar3 != (void *)0x0)) {
          if ((((int)sVar2 < 0x1001) || (psVar7[1] == sVar2)) ||
             (pvVar9 = CRYPTO_malloc(param_3,DAT_000aa0f4,0x176), pvVar9 != (void *)0x0)) {
            if ((void *)psVar7[2] != pvVar3) {
              CRYPTO_free((void *)psVar7[2]);
              psVar7[2] = (size_t)pvVar3;
              *psVar7 = sVar8;
              psVar7[4] = 0;
              psVar7[3] = 0;
            }
            if ((void *)psVar7[5] == pvVar9) {
              return 1;
            }
            CRYPTO_free((void *)psVar7[5]);
            psVar7[5] = (size_t)pvVar9;
            psVar7[1] = sVar2;
            psVar7[7] = 0;
            psVar7[6] = 0;
            return 1;
          }
          if ((void *)psVar7[2] != pvVar3) {
            CRYPTO_free(pvVar3);
          }
        }
LAB_000aa0d4:
        ERR_put_error(0x20,0x72,0x41,DAT_000aa0f4,0x1c1);
        return 0;
      }
      if (param_2 == 0x7a) {
        if ((int)*psVar7 < (int)param_3) {
          pvVar3 = CRYPTO_malloc(param_3,DAT_000aa0f4,0x153);
          if (pvVar3 == (void *)0x0) goto LAB_000aa0d4;
          if ((void *)psVar7[2] != (void *)0x0) {
            CRYPTO_free((void *)psVar7[2]);
          }
          psVar7[2] = (size_t)pvVar3;
        }
        psVar7[3] = param_3;
        psVar7[4] = 0;
        memcpy((void *)psVar7[2],param_4,param_3);
        return 1;
      }
    }
  }
  pBVar1 = param_1->next_bio;
  if (pBVar1 == (bio_st *)0x0) {
    return 0;
  }
LAB_000a9eea:
  sVar2 = BIO_ctrl(pBVar1,param_2,param_3,param_4);
  return sVar2;
}

