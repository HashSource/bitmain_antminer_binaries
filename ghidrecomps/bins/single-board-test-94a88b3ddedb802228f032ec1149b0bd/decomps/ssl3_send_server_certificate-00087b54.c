
undefined4 ssl3_send_server_certificate(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x34) == 0x2140) {
    iVar2 = ssl_get_server_send_pkey();
    if ((iVar2 == 0) &&
       ((iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), *(int *)(iVar3 + 0x10) != 0x20 ||
        (*(int *)(iVar3 + 0xc) << 0x1b < 0)))) {
      iVar2 = 0xcec;
    }
    else {
      iVar3 = ssl3_output_cert_chain(param_1,iVar2);
      iVar2 = 0xcf3;
      if (iVar3 != 0) {
        *(undefined4 *)(param_1 + 0x34) = 0x2141;
        goto LAB_00087b62;
      }
    }
    ERR_put_error(0x14,0x9a,0x44,DAT_00087bbc,iVar2);
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
  else {
LAB_00087b62:
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x44))(param_1);
  }
  return uVar1;
}

