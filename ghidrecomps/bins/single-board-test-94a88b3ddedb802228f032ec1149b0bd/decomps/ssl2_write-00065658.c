
uint ssl2_write(SSL *param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uchar *puVar6;
  EVP_MD *md;
  uint uVar7;
  int iVar8;
  int extraout_r1;
  size_t extraout_r1_00;
  uint uVar9;
  uchar *puVar10;
  size_t sVar11;
  ssl2_state_st *psVar12;
  uchar *__src;
  size_t sVar13;
  int iVar14;
  
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    uVar2 = (*param_1->handshake_func)(param_1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (uVar2 == 0) {
      ERR_put_error(0x14,0x7f,0xe5,DAT_0006590c,0x199);
      return 0xffffffff;
    }
  }
  if ((param_1->error == 0) || (ssl2_write_error(param_1), param_1->error == 0)) {
    piVar3 = __errno_location();
    *piVar3 = 0;
    param_1->rwstate = 1;
    if (0 < (int)param_3) {
      psVar12 = param_1->s2;
      uVar2 = psVar12->wnum;
      psVar12->wnum = 0;
      param_3 = param_3 - uVar2;
      do {
        __src = (uchar *)(param_2 + uVar2);
        if (psVar12->wpend_len == 0) {
          uVar4 = param_3;
          if (psVar12->clear_text == 0) {
            md = EVP_MD_CTX_md(param_1->write_hash);
            iVar8 = EVP_MD_size(md);
            psVar12 = param_1->s2;
            if (-1 < iVar8) {
              if (psVar12->clear_text != 0) {
                iVar5 = iVar8 + 3;
                uVar9 = 0x7fff - iVar8;
                goto LAB_0006572c;
              }
              uVar9 = EVP_CIPHER_CTX_block_size(param_1->enc_read_ctx);
              psVar12 = param_1->s2;
              uVar7 = iVar8 + param_3;
              sVar11 = psVar12->escape;
              if (uVar7 < 0x4000) {
                if ((1 < uVar9) || (sVar11 != 0)) goto LAB_00065848;
                iVar5 = iVar8 + 3;
                psVar12->three_byte_header = 0;
                uVar9 = 0x7fff - iVar8;
              }
              else if (sVar11 == 0) {
                uVar4 = 0x7fff;
                if (uVar7 < 0x7fff) {
                  uVar4 = uVar7;
                }
                __aeabi_uidivmod(uVar4,uVar9);
                uVar9 = 0x7fff - iVar8;
                iVar5 = iVar8 + 3;
                psVar12->three_byte_header = 0;
                uVar4 = (uVar4 - extraout_r1) - iVar8;
              }
              else {
LAB_00065848:
                __aeabi_uidivmod(uVar7,uVar9);
                sVar13 = extraout_r1_00;
                if (extraout_r1_00 != 0) {
                  sVar13 = uVar9 - extraout_r1_00;
                }
                iVar14 = iVar8 + sVar13;
                if (sVar11 == 0) {
                  sVar11 = sVar13;
                  if (sVar13 != 0) {
                    sVar11 = 1;
                  }
                  iVar5 = iVar8 + 3;
                  uVar9 = 0x7fff - iVar14;
                  psVar12->three_byte_header = sVar11;
                  sVar11 = sVar13;
                  iVar8 = iVar14;
                }
                else {
                  iVar5 = iVar8 + 3;
                  psVar12->three_byte_header = 1;
                  uVar9 = 0x7fff - iVar14;
                  sVar11 = sVar13;
                  iVar8 = iVar14;
                }
              }
              goto LAB_0006573c;
            }
          }
          else {
            uVar9 = 0x7fff;
            iVar5 = 3;
            iVar8 = 0;
LAB_0006572c:
            uVar4 = 0x7fff;
            if (param_3 < 0x7fff) {
              uVar4 = param_3;
            }
            psVar12->three_byte_header = 0;
            sVar11 = 0;
LAB_0006573c:
            psVar12->wlength = uVar4;
            psVar12->padding = sVar11;
            puVar6 = psVar12->wbuf + iVar5;
            psVar12->wact_data = puVar6;
            psVar12->mac_data = psVar12->wbuf + 3;
            if (uVar4 <= uVar9) {
              memcpy(puVar6,__src,uVar4);
              if (sVar11 != 0) {
                memset(param_1->s2->wact_data + uVar4,0,sVar11);
              }
              psVar12 = param_1->s2;
              if (psVar12->clear_text == 0) {
                psVar12->wact_data_length = sVar11 + uVar4;
                ssl2_mac(param_1,psVar12->mac_data,1);
                param_1->s2->wlength = param_1->s2->wlength + iVar8;
                iVar8 = ssl2_enc(param_1,1);
                if (iVar8 < 1) {
                  psVar12 = param_1->s2;
                  goto LAB_00065878;
                }
                psVar12 = param_1->s2;
              }
              uVar9 = psVar12->wlength;
              psVar12->wpend_len = uVar9;
              if (psVar12->three_byte_header == 0) {
                puVar10 = psVar12->mac_data;
                puVar10[-2] = (byte)(uVar9 >> 8) | 0x80;
                puVar6 = puVar10 + -2;
                puVar10[-1] = (uchar)param_1->s2->wlength;
                psVar12 = param_1->s2;
                psVar12->wpend_len = psVar12->wpend_len + 2;
              }
              else {
                puVar10 = psVar12->mac_data;
                bVar1 = (byte)((uVar9 << 0x12) >> 0x18);
                puVar10[-3] = bVar1 >> 2;
                puVar6 = puVar10 + -3;
                psVar12 = param_1->s2;
                if (psVar12->escape != 0) {
                  puVar10[-3] = bVar1 >> 2 | 0x40;
                  psVar12 = param_1->s2;
                }
                puVar10[-2] = (uchar)psVar12->wlength;
                puVar10[-1] = (uchar)param_1->s2->padding;
                psVar12 = param_1->s2;
                psVar12->wpend_len = psVar12->wpend_len + 3;
              }
              psVar12->wpend_buf = __src;
              psVar12->write_ptr = puVar6;
              psVar12->wpend_tot = param_3;
              psVar12->wpend_ret = uVar4;
              psVar12->wpend_off = 0;
              psVar12->write_sequence = psVar12->write_sequence + 1;
              uVar4 = write_pending(param_1,__src,param_3);
              goto LAB_000656f4;
            }
          }
LAB_00065878:
          uVar4 = 0xffffffff;
LAB_0006587c:
          psVar12->wnum = uVar2;
          return uVar4;
        }
        uVar4 = write_pending(param_1,__src,param_3);
LAB_000656f4:
        if ((int)uVar4 < 1) {
          psVar12 = param_1->s2;
          goto LAB_0006587c;
        }
        if ((param_3 == uVar4) || ((int)(param_1->options << 0x1f) < 0)) {
          return uVar4 + uVar2;
        }
        psVar12 = param_1->s2;
        param_3 = param_3 - uVar4;
        uVar2 = uVar2 + uVar4;
      } while( true );
    }
  }
  else {
    param_3 = 0xffffffff;
  }
  return param_3;
}

