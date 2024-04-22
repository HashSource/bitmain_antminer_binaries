
byte * ssl3_get_certificate_request(int *param_1)

{
  byte *pbVar1;
  _STACK *st;
  X509_NAME *data;
  void *pvVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint len;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *__src;
  byte *pbVar10;
  int local_30;
  byte *local_2c [2];
  
  pbVar1 = (byte *)(**(code **)(param_1[2] + 0x30))
                             (param_1,0x1150,0x1151,0xffffffff,param_1[0x42],&local_30);
  if (local_30 == 0) {
    return pbVar1;
  }
  iVar3 = param_1[0x16];
  *(undefined4 *)(iVar3 + 0x358) = 0;
  if (*(int *)(iVar3 + 0x340) == 0xe) {
    *(undefined4 *)(iVar3 + 0x354) = 1;
    if ((*(int *)(iVar3 + 0x178) != 0) && (iVar3 = ssl3_digest_cached_records(param_1), iVar3 == 0))
    goto LAB_0006664e;
LAB_00066782:
    pbVar1 = (byte *)0x1;
  }
  else {
    if (*(int *)(iVar3 + 0x340) == 0xd) {
      if ((*param_1 < 0x301) || (-1 < *(int *)(*(int *)(iVar3 + 0x344) + 0x10) << 0x1d)) {
        pbVar9 = (byte *)param_1[0x10];
        st = sk_new(DAT_00066914);
        if (st != (_STACK *)0x0) {
          iVar3 = param_1[0x26];
          __src = pbVar9 + 1;
          uVar6 = (uint)*pbVar9;
          if (*(void **)(iVar3 + 0x11c) != (void *)0x0) {
            CRYPTO_free(*(void **)(iVar3 + 0x11c));
            iVar3 = param_1[0x26];
            *(undefined4 *)(iVar3 + 0x11c) = 0;
          }
          if (uVar6 < 10) {
            uVar8 = uVar6;
            if (uVar6 != 0) goto LAB_000666aa;
          }
          else {
            uVar8 = 9;
            pvVar2 = CRYPTO_malloc(uVar6,DAT_00066910,0x82d);
            iVar5 = param_1[0x26];
            *(void **)(iVar3 + 0x11c) = pvVar2;
            memcpy(*(void **)(iVar5 + 0x11c),__src,uVar6);
            *(uint *)(param_1[0x26] + 0x120) = uVar6;
LAB_000666aa:
            uVar6 = 0;
            pbVar4 = pbVar9;
            do {
              pbVar4 = pbVar4 + 1;
              iVar3 = param_1[0x16] + uVar6;
              uVar6 = uVar6 + 1;
              *(byte *)(iVar3 + 0x360) = *pbVar4;
            } while (uVar6 < uVar8);
          }
          pbVar4 = __src + *pbVar9;
          if (*(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1e < 0) {
            pbVar10 = pbVar4 + 2;
            uVar6 = (uint)CONCAT11(__src[*pbVar9],pbVar4[1]);
            if (pbVar1 < pbVar10 + (uVar6 - (int)pbVar9) + 2) {
              ssl3_send_alert(param_1,2,0x32);
              ERR_put_error(0x14,0x87,0x92,DAT_00066910,0x83e);
              goto LAB_000667b8;
            }
            iVar3 = param_1[0x26];
            *(undefined4 *)(iVar3 + 0x44) = 0;
            *(undefined4 *)(iVar3 + 0x54) = 0;
            *(undefined4 *)(iVar3 + 0x60) = 0;
            *(undefined4 *)(iVar3 + 0x70) = 0;
            *(undefined4 *)(iVar3 + 0x7c) = 0;
            *(undefined4 *)(iVar3 + 0x8c) = 0;
            *(undefined4 *)(iVar3 + 0x98) = 0;
            *(undefined4 *)(iVar3 + 0xa8) = 0;
            *(undefined4 *)(iVar3 + 0xb4) = 0;
            *(undefined4 *)(iVar3 + 0xc4) = 0;
            *(undefined4 *)(iVar3 + 0xd0) = 0;
            *(undefined4 *)(iVar3 + 0xe0) = 0;
            *(undefined4 *)(iVar3 + 0xec) = 0;
            *(undefined4 *)(iVar3 + 0xfc) = 0;
            *(undefined4 *)(iVar3 + 0x108) = 0;
            *(undefined4 *)(iVar3 + 0x118) = 0;
            if (((int)(uVar6 << 0x1f) < 0) ||
               (iVar3 = tls1_save_sigalgs(param_1,pbVar10,uVar6), iVar3 == 0)) {
              ssl3_send_alert(param_1,2,0x32);
              ERR_put_error(0x14,0x87,0x168,DAT_00066910,0x849);
              goto LAB_000667b8;
            }
            iVar3 = tls1_process_sigalgs(param_1);
            pbVar4 = pbVar10 + uVar6;
            if (iVar3 == 0) {
              ssl3_send_alert(param_1,2,0x50);
              iVar3 = 0x84e;
LAB_0006675a:
              ERR_put_error(0x14,0x87,0x41,DAT_00066910,iVar3);
              goto LAB_000667b8;
            }
          }
          uVar6 = (uint)CONCAT11(*pbVar4,pbVar4[1]);
          if (pbVar4 + uVar6 + (2 - (int)pbVar9) != pbVar1) {
            ssl3_send_alert(param_1,2,0x32);
            ERR_put_error(0x14,0x87,0x9f,DAT_00066910,0x861);
LAB_000667b8:
            param_1[0xd] = 5;
            sk_pop_free(st,DAT_00066918);
            return (byte *)0x0;
          }
          if (uVar6 != 0) {
            pbVar1 = pbVar4 + 4;
            len = (uint)CONCAT11(pbVar4[2],pbVar4[3]);
            for (uVar7 = len + 2; uVar7 <= uVar6; uVar7 = uVar7 + len + 2) {
              local_2c[0] = pbVar1;
              data = d2i_X509_NAME((X509_NAME **)0x0,local_2c,len);
              pbVar9 = pbVar1 + len;
              if (data == (X509_NAME *)0x0) {
                if (param_1[0x40] << 2 < 0) goto LAB_0006682c;
                ssl3_send_alert(param_1,2,0x32);
                ERR_put_error(0x14,0x87,0xd,DAT_00066960,0x877);
                goto LAB_000667b8;
              }
              pbVar1 = pbVar9 + 2;
              if (pbVar9 != local_2c[0]) {
                ssl3_send_alert(param_1,2,0x32);
                ERR_put_error(0x14,0x87,0x83,DAT_00066910,0x87f);
                goto LAB_000667b8;
              }
              iVar3 = sk_push(st,data);
              if (iVar3 == 0) {
                iVar3 = 0x883;
                goto LAB_0006675a;
              }
              if (uVar6 <= uVar7) goto LAB_00066830;
              len = (uint)CONCAT11(*pbVar9,pbVar9[1]);
            }
            if (-1 < param_1[0x40] << 2) {
              ssl3_send_alert(param_1,2,0x32);
              ERR_put_error(0x14,0x87,0x84,DAT_00066960,0x86b);
              goto LAB_000667b8;
            }
LAB_0006682c:
            ERR_clear_error();
          }
LAB_00066830:
          iVar3 = param_1[0x16];
          *(uint *)(iVar3 + 0x35c) = uVar8;
          *(undefined4 *)(iVar3 + 0x358) = 1;
          if (*(_STACK **)(iVar3 + 0x36c) != (_STACK *)0x0) {
            sk_pop_free(*(_STACK **)(iVar3 + 0x36c),DAT_00066918);
            iVar3 = param_1[0x16];
          }
          *(_STACK **)(iVar3 + 0x36c) = st;
          goto LAB_00066782;
        }
        ERR_put_error(0x14,0x87,0x41,DAT_00066910,0x821);
      }
      else {
        ssl3_send_alert(param_1,2,10);
        ERR_put_error(0x14,0x87,0xe8,DAT_00066910,0x819);
      }
    }
    else {
      ssl3_send_alert(param_1,2,10);
      ERR_put_error(0x14,0x87,0x106,DAT_00066910,0x810);
    }
LAB_0006664e:
    pbVar1 = (byte *)0x0;
    param_1[0xd] = 5;
  }
  return pbVar1;
}

