
int dtls1_get_record(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  uint local_28;
  int local_24;
  
LAB_000d8e9a:
  iVar7 = dtls1_process_buffered_records(param_1);
  do {
    if (iVar7 == 0) {
      return -1;
    }
    iVar7 = dtls1_retrieve_buffered_record(param_1,param_1[0x3ce] + 0x24);
    if (iVar7 != 0) {
      return 1;
    }
    if ((param_1[0x196] == 0xf1) && (0xc < param_1[0x3bf])) {
      uVar9 = param_1[0x240];
      if (param_1[0x3bf] - 0xd < uVar9) {
LAB_000d8ed0:
        iVar7 = ssl3_read_n(param_1,uVar9,uVar9,1,1,&local_28);
        if ((0 < iVar7) && (local_28 == uVar9)) goto LAB_000d9008;
LAB_000d8ef0:
        iVar7 = ossl_statem_in_error(param_1);
        if (iVar7 != 0) {
          return -1;
        }
      }
      else {
LAB_000d9008:
        param_1[0x196] = 0xf0;
        iVar7 = dtls1_get_bitmap(param_1,param_1 + 0x23e,&local_24);
        if (iVar7 == 0) break;
        iVar8 = dtls1_record_replay_check(param_1,iVar7);
        if (iVar8 != 0) {
          if (param_1[0x240] == 0) {
            param_1[0x246] = 1;
            goto LAB_000d8e9a;
          }
          if (local_24 == 0) {
            iVar7 = dtls1_process_record(param_1,iVar7);
            if (iVar7 != 0) {
              return 1;
            }
            goto LAB_000d8ef0;
          }
          iVar7 = SSL_in_init(param_1);
          if (((iVar7 != 0) || (iVar7 = ossl_statem_get_in_handshake(param_1), iVar7 != 0)) &&
             (iVar7 = dtls1_buffer_record(param_1,param_1[0x3ce] + 0x1c,param_1 + 0x248), iVar7 < 0)
             ) {
            return -1;
          }
        }
      }
    }
    else {
      iVar7 = ssl3_read_n(param_1,0xd,param_1[0x19b],0,1,&local_28);
      if (iVar7 < 1) {
        return iVar7;
      }
      if (param_1[0x3bf] != 0xd) {
        param_1[0x3bf] = 0;
        goto LAB_000d8e9a;
      }
      param_1[0x196] = 0xf1;
      pbVar10 = (byte *)param_1[0x3be];
      if ((code *)param_1[0x21] != (code *)0x0) {
        (*(code *)param_1[0x21])(0,0,0x100,pbVar10,0xd,param_1,param_1[0x22]);
      }
      bVar1 = *pbVar10;
      param_1[0x23f] = (uint)bVar1;
      bVar2 = pbVar10[2];
      bVar5 = pbVar10[1];
      param_1[0x247] = (uint)CONCAT11(pbVar10[3],pbVar10[4]);
      *(undefined4 *)((int)param_1 + 0xf22) = *(undefined4 *)(pbVar10 + 5);
      *(undefined2 *)((int)param_1 + 0xf26) = *(undefined2 *)(pbVar10 + 9);
      bVar3 = pbVar10[0xb];
      bVar4 = pbVar10[0xc];
      param_1[0x246] = 0;
      uVar9 = (uint)CONCAT11(bVar3,bVar4);
      param_1[0x240] = uVar9;
      if (bVar1 == 0x15 || param_1[0x140] != 0) {
        if ((((uint)CONCAT11(bVar5,bVar2) ^ *param_1) & 0xff00) == 0) goto LAB_000d8fd0;
      }
      else if ((uint)CONCAT11(bVar5,bVar2) == *param_1) {
LAB_000d8fd0:
        if ((uVar9 < 0x4541) &&
           (((param_1[0x11d] == 0 ||
             (cVar6 = *(char *)(param_1[0x11d] + 0x1ec), 3 < (byte)(cVar6 - 1U))) ||
            (uVar9 <= (0x200 << (uint)(byte)(cVar6 - 1)) + 0x140U)))) {
          if (param_1[0x3bf] - 0xd < uVar9) goto LAB_000d8ed0;
          goto LAB_000d9008;
        }
      }
    }
    param_1[0x240] = 0;
    param_1[0x3bf] = 0;
    param_1[0x246] = 1;
    iVar7 = dtls1_process_buffered_records(param_1);
  } while( true );
  param_1[0x240] = 0;
  param_1[0x3bf] = 0;
  goto LAB_000d8e9a;
}

