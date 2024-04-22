
size_t ssl2_read_internal(SSL *param_1,void *param_2,size_t param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  EVP_MD *md;
  int iVar3;
  int extraout_r1;
  uchar *puVar4;
  byte *pbVar5;
  ssl2_state_st *psVar6;
  size_t sVar7;
  uchar *puVar8;
  bool bVar9;
  undefined auStack_3c [24];
  
  do {
    uVar1 = SSL_state(param_1);
    if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
      sVar7 = (*param_1->handshake_func)(param_1);
      if ((int)sVar7 < 0) {
        return sVar7;
      }
      if (sVar7 == 0) {
        ERR_put_error(0x14,0xec,0xe5,DAT_00065640,0x8e);
        return 0xffffffff;
      }
    }
    piVar2 = __errno_location();
    *piVar2 = 0;
    param_1->rwstate = 1;
    if ((int)param_3 < 1) {
      return param_3;
    }
    psVar6 = param_1->s2;
    sVar7 = psVar6->ract_data_length;
    if (sVar7 != 0) {
      if ((int)param_3 <= (int)sVar7) {
        sVar7 = param_3;
      }
      memcpy(param_2,psVar6->ract_data,sVar7);
      if (param_4 != 0) {
        return sVar7;
      }
      psVar6 = param_1->s2;
      iVar3 = psVar6->ract_data_length - sVar7;
      psVar6->ract_data = psVar6->ract_data + sVar7;
      psVar6->ract_data_length = iVar3;
      if (iVar3 != 0) {
        return sVar7;
      }
      param_1->rstate = 0xf0;
      return sVar7;
    }
    if (param_1->rstate == 0xf0) {
      if (param_1->max_cert_list == 0) {
        sVar7 = read_n(param_1,2,0x8001);
        if ((int)sVar7 < 1) {
          return sVar7;
        }
        pbVar5 = param_1->packet;
      }
      else {
        sVar7 = read_n(param_1,5,0x8001,0);
        if ((int)sVar7 < 1) {
          return sVar7;
        }
        pbVar5 = param_1->packet;
        param_1->max_cert_list = 0;
        if ((-1 < (char)*pbVar5) || (pbVar5[2] != 4 && pbVar5[2] != 1)) {
          ERR_put_error(0x14,0xec,0xaf,DAT_00065640,0xb8);
          return 0xffffffff;
        }
      }
      psVar6 = param_1->s2;
      param_1->rstate = 0xf1;
      psVar6->escape = 0;
      uVar1 = (uint)CONCAT11(*pbVar5,pbVar5[1]);
      psVar6->rlength = uVar1;
      bVar9 = (char)*pbVar5 < '\0';
      if (!bVar9) {
        uVar1 = uVar1 & 0x3fff;
        psVar6->three_byte_header = 1;
      }
      if (bVar9) {
        uVar1 = uVar1 & 0x7fff;
        psVar6->three_byte_header = 0;
      }
      else {
        psVar6->rlength = uVar1;
        pbVar5 = (byte *)(uint)*pbVar5;
      }
      if (bVar9) {
        psVar6->rlength = uVar1;
      }
      else {
        pbVar5 = (byte *)((uint)((int)pbVar5 << 0x19) >> 0x1f);
      }
      if (!bVar9) {
        psVar6->escape = (int)pbVar5;
      }
    }
    else if (param_1->rstate != 0xf1) {
      ERR_put_error(0x14,0xec,0x7e,DAT_00065640,0x127);
      return 0xffffffff;
    }
    uVar1 = psVar6->three_byte_header;
    iVar3 = psVar6->rlength + 2 + uVar1;
    if ((int)param_1->packet_length < iVar3) {
      iVar3 = iVar3 - param_1->packet_length;
      sVar7 = read_n(param_1,iVar3,iVar3,1);
      if ((int)sVar7 < 1) {
        return sVar7;
      }
      psVar6 = param_1->s2;
      uVar1 = psVar6->three_byte_header;
    }
    puVar4 = param_1->packet;
    param_1->rstate = 0xf0;
    puVar8 = puVar4 + 2;
    if (uVar1 != 0) {
      uVar1 = (uint)puVar4[2];
      puVar8 = puVar4 + 3;
    }
    psVar6->padding = uVar1;
    if (psVar6->clear_text == 0) {
      md = EVP_MD_CTX_md(param_1->read_hash);
      uVar1 = EVP_MD_size(md);
      if ((int)uVar1 < 0) {
        return 0xffffffff;
      }
      if (0x14 < (int)uVar1) {
        OpenSSLDie(DAT_00065640,0xf3,DAT_00065644);
      }
      psVar6 = param_1->s2;
      psVar6->mac_data = puVar8;
      psVar6->ract_data = puVar8 + uVar1;
      if (psVar6->rlength < psVar6->padding + uVar1) {
        ERR_put_error(0x14,0xec,0x11b,DAT_00065640,0xf7);
        return 0xffffffff;
      }
    }
    else {
      psVar6->mac_data = puVar8;
      psVar6->ract_data = puVar8;
      if (uVar1 != 0) {
        ERR_put_error(0x14,0xec,0x11b,DAT_00065640,0xec);
        return 0xffffffff;
      }
      uVar1 = 0;
    }
    psVar6->ract_data_length = psVar6->rlength;
    if ((psVar6->clear_text == 0) && (uVar1 <= psVar6->rlength)) {
      iVar3 = ssl2_enc(param_1,0);
      if (iVar3 == 0) {
        ERR_put_error(0x14,0xec,0x93,DAT_00065640,0x104);
        return 0xffffffff;
      }
      param_1->s2->ract_data_length = param_1->s2->ract_data_length - uVar1;
      ssl2_mac(param_1,auStack_3c,0);
      psVar6 = param_1->s2;
      psVar6->ract_data_length = psVar6->ract_data_length - psVar6->padding;
      iVar3 = CRYPTO_memcmp(auStack_3c,psVar6->mac_data,uVar1);
      if (iVar3 != 0) {
LAB_00065610:
        ERR_put_error(0x14,0xec,0x71,DAT_00065640,0x10d);
        return 0xffffffff;
      }
      uVar1 = param_1->s2->rlength;
      iVar3 = EVP_CIPHER_CTX_block_size(param_1->enc_read_ctx);
      __aeabi_uidivmod(uVar1,iVar3);
      if (extraout_r1 != 0) goto LAB_00065610;
      psVar6 = param_1->s2;
    }
    psVar6->read_sequence = psVar6->read_sequence + 1;
  } while( true );
}

