
undefined4
tls1_process_ticket(SSL *param_1,int param_2,int param_3,undefined *param_4,undefined4 *param_5)

{
  undefined *puVar1;
  undefined uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  
  *param_5 = 0;
  param_1->tlsext_ocsp_resplen = 0;
  uVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if ((uVar3 & 0x4000) == 0) {
    uVar4 = 0;
    if (0x300 < param_1->version) {
      if (param_4 == (undefined *)0x0) {
        uVar4 = 0;
      }
      else {
        puVar6 = (undefined *)(param_2 + param_3);
        if ((puVar6 < param_4) &&
           ((-1 < *(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c ||
            (puVar6 = puVar6 + *(byte *)(param_2 + param_3) + 1, puVar6 < param_4)))) {
          puVar7 = puVar6 + CONCAT11(*puVar6,puVar6[1]) + 2;
          if ((puVar7 < param_4) &&
             (puVar7 + (byte)puVar6[CONCAT11(*puVar6,puVar6[1]) + 2] + 1 <= param_4)) {
            puVar6 = puVar7 + (byte)puVar6[CONCAT11(*puVar6,puVar6[1]) + 2] + 1 + 2;
            if (param_4 <= puVar6) {
              return 0;
            }
            do {
              puVar7 = puVar6 + 4;
              if (param_4 < puVar7) {
                return 0;
              }
              uVar2 = *puVar6;
              puVar1 = puVar6 + 1;
              uVar3 = (uint)CONCAT11(puVar6[2],puVar6[3]);
              puVar6 = puVar7 + uVar3;
              if (param_4 < puVar6) {
                return 0;
              }
            } while (CONCAT11(uVar2,*puVar1) != 0x23);
            if (uVar3 == 0) {
              param_1->tlsext_ocsp_resplen = 1;
              return 1;
            }
            if (param_1->tls_session_ticket_ext_cb_arg != (void *)0x0) {
              return 2;
            }
            iVar5 = tls_decrypt_ticket(param_1,puVar7,uVar3,param_2,param_3,param_5);
            if (iVar5 == 3) {
              return 3;
            }
            if (iVar5 == 4) {
              param_1->tlsext_ocsp_resplen = 1;
              return 3;
            }
            if (iVar5 == 2) {
              param_1->tlsext_ocsp_resplen = 1;
              return 2;
            }
          }
        }
        uVar4 = 0xffffffff;
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

