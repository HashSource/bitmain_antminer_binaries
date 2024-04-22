
uchar * b64_write(BIO *param_1,uchar *param_2,uchar *param_3)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  int *outl;
  int iVar5;
  uchar *local_30;
  
  outl = (int *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  if (outl[4] != 1) {
    outl[4] = 1;
    *outl = 0;
    outl[1] = 0;
    outl[2] = 0;
    EVP_EncodeInit((EVP_ENCODE_CTX *)(outl + 7));
  }
  if (0x5dd < outl[1]) {
    OpenSSLDie(DAT_0012bdbc,0x17a,DAT_0012bdcc);
  }
  iVar5 = *outl;
  if (0x5de < iVar5) {
    OpenSSLDie(DAT_0012bdbc,0x17b,DAT_0012bdc8);
    iVar5 = *outl;
  }
  iVar1 = outl[1];
  if (iVar5 < iVar1) {
    OpenSSLDie(DAT_0012bdbc,0x17c,DAT_0012bdc4);
    iVar5 = *outl;
    iVar1 = outl[1];
  }
  iVar5 = iVar5 - iVar1;
  if (iVar5 < 1) {
LAB_0012bb30:
    local_30 = (uchar *)0x0;
    puVar3 = param_2;
    if (param_2 != (uchar *)0x0) {
      puVar3 = param_3;
    }
    outl[1] = 0;
    *outl = 0;
    if ((param_2 != (uchar *)0x0 && param_3 != (uchar *)0x0) && -1 < (int)puVar3) {
      local_30 = (uchar *)0x0;
      do {
        puVar3 = param_3;
        if (0x3ff < (int)param_3) {
          puVar3 = (uchar *)0x400;
        }
        iVar5 = BIO_test_flags(param_1,-1);
        if (iVar5 << 0x17 < 0) {
          iVar5 = outl[2];
          if (iVar5 < 1) {
            if ((int)puVar3 < 3) {
              memcpy((void *)((int)outl + 0x65a),param_2,(size_t)puVar3);
              outl[2] = (int)puVar3;
              return puVar3 + (int)local_30;
            }
            puVar3 = (uchar *)(((int)puVar3 / 3) * 3);
            iVar5 = EVP_EncodeBlock((uchar *)(outl + 0x1f),param_2,(int)puVar3);
            *outl = iVar5;
            if (0x5de < iVar5) {
              OpenSSLDie(DAT_0012bdbc,0x1b7,DAT_0012bdc8);
              iVar5 = *outl;
            }
            if (iVar5 < outl[1]) {
              OpenSSLDie(DAT_0012bdbc,0x1b8,DAT_0012bdc4);
              iVar5 = *outl;
            }
            local_30 = local_30 + (int)puVar3;
          }
          else {
            if (3 < iVar5) {
              OpenSSLDie(DAT_0012bdbc,0x196,DAT_0012bdd0);
              iVar5 = outl[2];
            }
            puVar3 = (uchar *)(3 - iVar5);
            if ((int)param_3 <= (int)(uchar *)(3 - iVar5)) {
              puVar3 = param_3;
            }
            memcpy((void *)((int)outl + iVar5 + 0x65a),param_2,(size_t)puVar3);
            puVar2 = puVar3 + outl[2];
            local_30 = local_30 + (int)puVar3;
            outl[2] = (int)puVar2;
            if ((int)puVar2 < 3) {
              return local_30;
            }
            iVar5 = EVP_EncodeBlock((uchar *)(outl + 0x1f),(uchar *)((int)outl + 0x65a),(int)puVar2)
            ;
            *outl = iVar5;
            if (0x5de < iVar5) {
              OpenSSLDie(DAT_0012bdbc,0x1a5,DAT_0012bdc8);
              iVar5 = *outl;
            }
            if (iVar5 < outl[1]) {
              OpenSSLDie(DAT_0012bdbc,0x1a6,DAT_0012bdc4);
              iVar5 = *outl;
            }
            outl[2] = 0;
          }
        }
        else {
          EVP_EncodeUpdate((EVP_ENCODE_CTX *)(outl + 7),(uchar *)(outl + 0x1f),outl,param_2,
                           (int)puVar3);
          iVar5 = *outl;
          if (0x5de < iVar5) {
            OpenSSLDie(DAT_0012bdbc,0x1bf,DAT_0012bdc8);
            iVar5 = *outl;
          }
          if (iVar5 < outl[1]) {
            OpenSSLDie(DAT_0012bdbc,0x1c0,DAT_0012bdc4);
            iVar5 = *outl;
          }
          local_30 = local_30 + (int)puVar3;
        }
        iVar1 = 0;
        param_2 = param_2 + (int)puVar3;
        outl[1] = 0;
        if (0 < iVar5) {
          do {
            puVar2 = (uchar *)BIO_write(param_1->next_bio,(void *)((int)outl + iVar1 + 0x7c),iVar5);
            if ((int)puVar2 < 1) {
              if (local_30 != (uchar *)0x0) {
                puVar2 = local_30;
              }
              BIO_copy_next_retry(param_1);
              return puVar2;
            }
            if (iVar5 < (int)puVar2) {
              OpenSSLDie(DAT_0012bdbc,0x1ce,DAT_0012bdb8);
              puVar4 = puVar2 + outl[1];
              outl[1] = (int)puVar4;
              if ((int)puVar4 < 0x5df) goto LAB_0012bbee;
LAB_0012bc2e:
              OpenSSLDie(DAT_0012bdbc,0x1d1,DAT_0012bdc0);
              if (*outl < outl[1]) goto LAB_0012bc42;
            }
            else {
              puVar4 = puVar2 + outl[1];
              outl[1] = (int)puVar4;
              if (0x5de < (int)puVar4) goto LAB_0012bc2e;
LAB_0012bbee:
              if (*outl < (int)puVar4) {
LAB_0012bc42:
                OpenSSLDie(DAT_0012bdbc,0x1d2,DAT_0012bdc4);
              }
            }
            if (iVar5 - (int)puVar2 < 1) break;
            iVar1 = outl[1];
            iVar5 = iVar5 - (int)puVar2;
          } while( true );
        }
        param_3 = param_3 + -(int)puVar3;
        *outl = 0;
        outl[1] = 0;
      } while (0 < (int)param_3);
    }
  }
  else {
    while (local_30 = (uchar *)BIO_write(param_1->next_bio,(void *)((int)outl + iVar1 + 0x7c),iVar5)
          , 0 < (int)local_30) {
      if (iVar5 < (int)local_30) {
        OpenSSLDie(DAT_0012bdbc,0x184,DAT_0012bdb8);
        puVar3 = local_30 + outl[1];
        outl[1] = (int)puVar3;
        if ((int)puVar3 < 0x5df) goto LAB_0012bacc;
LAB_0012bb0c:
        OpenSSLDie(DAT_0012bdbc,0x186,DAT_0012bdc0);
        if (*outl < outl[1]) goto LAB_0012bb20;
      }
      else {
        puVar3 = local_30 + outl[1];
        outl[1] = (int)puVar3;
        if (0x5de < (int)puVar3) goto LAB_0012bb0c;
LAB_0012bacc:
        if (*outl < (int)puVar3) {
LAB_0012bb20:
          OpenSSLDie(DAT_0012bdbc,0x187,DAT_0012bdc4);
        }
      }
      if (iVar5 - (int)local_30 < 1) goto LAB_0012bb30;
      iVar1 = outl[1];
      iVar5 = iVar5 - (int)local_30;
    }
    BIO_copy_next_retry(param_1);
  }
  return local_30;
}

