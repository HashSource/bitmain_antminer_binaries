
BIO_METHOD * buffer_ctrl(BIO *param_1,int param_2,BIO_METHOD *param_3,BIO *param_4)

{
  BIO_METHOD *pBVar1;
  BIO *bp;
  long lVar2;
  bio_st *bp_00;
  char *pcVar3;
  void *pvVar4;
  char *pcVar5;
  bio_st *pbVar6;
  void *ptr;
  BIO_METHOD *pBVar7;
  undefined1 auStack_24 [4];
  
  pbVar6 = param_1->next_bio;
  if (param_2 == 0xc) {
    lVar2 = BIO_int_ctrl(param_4,0x75,(long)pbVar6->method,0);
    if (lVar2 == 0) {
      return (BIO_METHOD *)0x0;
    }
    lVar2 = BIO_int_ctrl(param_4,0x75,(long)pbVar6->callback,1);
    if (lVar2 != 0) {
      return (BIO_METHOD *)0x1;
    }
    return (BIO_METHOD *)0x0;
  }
  if (param_2 < 0xd) {
    if (param_2 == 3) {
      return (BIO_METHOD *)pbVar6->retry_reason;
    }
    if (3 < param_2) {
      if (param_2 != 10) {
        if (param_2 != 0xb) goto LAB_00109d34;
        bp_00 = param_1->prev_bio;
        if (bp_00 == (bio_st *)0x0) {
          return (BIO_METHOD *)0x0;
        }
        if (0 < pbVar6->retry_reason) {
          while( true ) {
            BIO_clear_flags(param_1,0xf);
            if (pbVar6->retry_reason < 1) {
              bp = param_1->prev_bio;
              pbVar6->retry_reason = 0;
              pbVar6->num = 0;
              pBVar1 = (BIO_METHOD *)BIO_ctrl(bp,0xb,(long)param_3,param_4);
              return pBVar1;
            }
            pBVar1 = (BIO_METHOD *)
                     BIO_write(param_1->prev_bio,(void *)(pbVar6->flags + pbVar6->num),
                               pbVar6->retry_reason);
            BIO_copy_next_retry(param_1);
            if ((int)pBVar1 < 1) break;
            pbVar6->num = (int)&pBVar1->type + pbVar6->num;
            pbVar6->retry_reason = pbVar6->retry_reason - (int)pBVar1;
          }
          return pBVar1;
        }
        goto LAB_00109ea0;
      }
      pBVar1 = (BIO_METHOD *)pbVar6->init;
      goto joined_r0x00109ed2;
    }
    if (param_2 != 1) {
      if (param_2 == 2) {
        if (0 < pbVar6->init) {
          return (BIO_METHOD *)0x0;
        }
        bp_00 = param_1->prev_bio;
        goto LAB_00109ea0;
      }
      goto LAB_00109d34;
    }
    bp_00 = param_1->prev_bio;
    pbVar6->shutdown = 0;
    pbVar6->init = 0;
    pbVar6->num = 0;
    pbVar6->retry_reason = 0;
  }
  else {
    if (param_2 == 0x65) {
      if (param_1->prev_bio == (bio_st *)0x0) {
        return (BIO_METHOD *)0x0;
      }
      BIO_clear_flags(param_1,0xf);
      pBVar1 = (BIO_METHOD *)BIO_ctrl(param_1->prev_bio,0x65,(long)param_3,param_4);
      BIO_copy_next_retry(param_1);
      return pBVar1;
    }
    if (0x65 < param_2) {
      if (param_2 != 0x75) {
        if (param_2 == 0x7a) {
          if ((int)pbVar6->method < (int)param_3) {
            pcVar3 = (char *)CRYPTO_malloc((int)param_3,"crypto/bio/bf_buff.c",0x124);
            if (pcVar3 == (char *)0x0) goto LAB_00109fa6;
            CRYPTO_free(pbVar6->cb_arg);
            pbVar6->cb_arg = pcVar3;
          }
          else {
            pcVar3 = pbVar6->cb_arg;
          }
          pbVar6->init = (int)param_3;
          pbVar6->shutdown = 0;
          memcpy(pcVar3,param_4,(size_t)param_3);
          return (BIO_METHOD *)0x1;
        }
        if (param_2 == 0x74) {
          if (pbVar6->init < 1) {
            return (BIO_METHOD *)0x0;
          }
          pBVar1 = (BIO_METHOD *)0x0;
          pcVar3 = pbVar6->cb_arg + pbVar6->shutdown;
          do {
            pcVar5 = pcVar3 + 1;
            if (*pcVar3 == '\n') {
              pBVar1 = (BIO_METHOD *)((int)&pBVar1->type + 1);
            }
            pcVar3 = pcVar5;
          } while (pcVar5 != pbVar6->cb_arg + pbVar6->init + pbVar6->shutdown);
          return pBVar1;
        }
LAB_00109d34:
        if (param_1->prev_bio == (BIO *)0x0) {
          return (BIO_METHOD *)0x0;
        }
        pBVar1 = (BIO_METHOD *)BIO_ctrl(param_1->prev_bio,param_2,(long)param_3,param_4);
        return pBVar1;
      }
      pBVar1 = param_3;
      pBVar7 = param_3;
      if (param_4 != (BIO *)0x0) {
        if (param_4->method == (BIO_METHOD *)0x0) {
          pBVar7 = (BIO_METHOD *)pbVar6->callback;
        }
        else {
          pBVar1 = pbVar6->method;
        }
      }
      ptr = (void *)pbVar6->flags;
      pvVar4 = ptr;
      if (((int)pBVar1 < 0x1001) || (pBVar1 == pbVar6->method)) {
        if ((int)pBVar7 < 0x1001) {
          return (BIO_METHOD *)0x1;
        }
        pcVar3 = pbVar6->cb_arg;
        if (pBVar7 == (BIO_METHOD *)pbVar6->callback) goto LAB_00109e52;
LAB_00109f7a:
        pvVar4 = CRYPTO_malloc((int)param_3,"crypto/bio/bf_buff.c",0x146);
        if (pvVar4 == (void *)0x0) {
          if (pbVar6->cb_arg != pcVar3) {
            CRYPTO_free(pcVar3);
          }
LAB_00109fa6:
          ERR_put_error(0x20,0x72,0x41,"crypto/bio/bf_buff.c",0x197);
          return (BIO_METHOD *)0x0;
        }
      }
      else {
        pcVar3 = (char *)CRYPTO_malloc((int)param_3,"crypto/bio/bf_buff.c",0x141);
        if (pcVar3 == (char *)0x0) goto LAB_00109fa6;
        if ((0x1000 < (int)pBVar7) && (pBVar7 != (BIO_METHOD *)pbVar6->callback)) goto LAB_00109f7a;
      }
      if (pbVar6->cb_arg == pcVar3) {
        ptr = (void *)pbVar6->flags;
      }
      else {
        CRYPTO_free(pbVar6->cb_arg);
        ptr = (void *)pbVar6->flags;
        pbVar6->cb_arg = pcVar3;
        pbVar6->method = pBVar1;
        pbVar6->shutdown = 0;
        pbVar6->init = 0;
      }
LAB_00109e52:
      if (pvVar4 == ptr) {
        return (BIO_METHOD *)0x1;
      }
      CRYPTO_free(ptr);
      pbVar6->flags = (int)pvVar4;
      pbVar6->callback = (_func_745 *)pBVar7;
      pbVar6->num = 0;
      pbVar6->retry_reason = 0;
      return (BIO_METHOD *)0x1;
    }
    if (param_2 != 0xd) {
      if (param_2 == 0x1d) {
        buffer_read(param_1,auStack_24,0);
        pBVar1 = (BIO_METHOD *)pbVar6->init;
        if ((int)param_3 <= pbVar6->init) {
          pBVar1 = param_3;
        }
        memcpy(param_4,pbVar6->cb_arg + pbVar6->shutdown,(size_t)pBVar1);
        return pBVar1;
      }
      goto LAB_00109d34;
    }
    pBVar1 = (BIO_METHOD *)pbVar6->retry_reason;
joined_r0x00109ed2:
    if (pBVar1 != (BIO_METHOD *)0x0) {
      return pBVar1;
    }
    bp_00 = param_1->prev_bio;
  }
  if (bp_00 == (bio_st *)0x0) {
    return (BIO_METHOD *)0x0;
  }
LAB_00109ea0:
  pBVar1 = (BIO_METHOD *)BIO_ctrl(bp_00,param_2,(long)param_3,param_4);
  return pBVar1;
}

