
undefined4 ossl_statem_server_write_transition(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  if (*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) {
    switch(*(undefined4 *)(param_1 + 0x40)) {
    case 0:
    case 0x15:
    case 0x1a:
      goto switchD_00101166_caseD_0;
    case 1:
switchD_00101166_caseD_1:
      if (*(int *)(param_1 + 0x44) == 0x13) {
        *(undefined4 *)(param_1 + 0x40) = 0x13;
        *(undefined4 *)(param_1 + 0x44) = 0;
        return 1;
      }
      iVar2 = tls_setup_handshake(param_1);
      if (iVar2 == 0) {
        return 0;
      }
switchD_00101166_caseD_0:
      return 2;
    default:
switchD_00101166_caseD_2:
      ossl_statem_fatal(param_1,0x50,0x25c,0x44,"ssl/statem/statem_srvr.c",0x22e);
      return 0;
    case 0x13:
      break;
    case 0x14:
      if ((*(int *)(*(int *)(param_1 + 0x80) + 0x104) == 0) &&
         (iVar2 = SSL_get_options(param_1), iVar2 << 0x12 < 0)) {
        *(undefined4 *)(param_1 + 0x40) = 0x15;
        return 1;
      }
switchD_00101166_caseD_14:
      if (((*(int *)(param_1 + 0x5ec) != 0) || (*(int *)(*(int *)(param_1 + 0x7c) + 0x180) == 0)) ||
         (*(int *)(*(int *)(param_1 + 0x7c) + 0x204) == 0)) goto switchD_00101212_caseD_14;
      break;
    case 0x16:
switchD_00101166_caseD_16:
      if (*(int *)(param_1 + 0x8c) != 0) {
LAB_0010130a:
        if (*(int *)(param_1 + 0x55c) == 0) {
switchD_00101166_caseD_21:
          *(undefined4 *)(param_1 + 0x40) = 0x23;
          return 1;
        }
LAB_00101312:
        *(undefined4 *)(param_1 + 0x40) = 0x21;
        return 1;
      }
      iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
      if ((*(uint *)(iVar2 + 0x14) & 0x54) == 0) goto LAB_00101330;
      goto LAB_001012ac;
    case 0x17:
switchD_00101166_caseD_17:
      if (*(int *)(param_1 + 0x548) != 0) {
        *(undefined4 *)(param_1 + 0x40) = 0x22;
        return 1;
      }
    case 0x22:
switchD_00101166_caseD_22:
      iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
LAB_001012ac:
      uVar4 = *(uint *)(iVar2 + 0x10);
      if (((uVar4 & 6) != 0) ||
         ((((uVar4 & 0x48) != 0 && (*(int *)(*(int *)(param_1 + 0x404) + 0x104) != 0)) ||
          ((uVar4 & 0x1a0) != 0)))) {
        *(undefined4 *)(param_1 + 0x40) = 0x18;
        return 1;
      }
    case 0x18:
switchD_00101166_caseD_18:
      iVar2 = send_certificate_request(param_1);
      if (iVar2 != 0) {
LAB_001012c8:
        *(undefined4 *)(param_1 + 0x40) = 0x19;
        return 1;
      }
switchD_00101166_caseD_19:
      *(undefined4 *)(param_1 + 0x40) = 0x1a;
      return 1;
    case 0x19:
      goto switchD_00101166_caseD_19;
    case 0x20:
switchD_00101166_caseD_20:
      if (*(int *)(param_1 + 0x8c) == 0) goto LAB_0010130a;
      break;
    case 0x21:
      goto switchD_00101166_caseD_21;
    case 0x23:
      goto switchD_00101166_caseD_23;
    case 0x24:
switchD_00101166_caseD_24:
      if (*(int *)(param_1 + 0x8c) != 0) {
        return 2;
      }
    }
    goto switchD_00101166_caseD_13;
  }
  iVar3 = **(int **)(param_1 + 4);
  iVar2 = iVar3 + -0x10000;
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  if (iVar3 < 0x304) {
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    switch(*(undefined4 *)(param_1 + 0x40)) {
    case 0:
    case 0x15:
    case 0x1a:
      goto switchD_00101166_caseD_0;
    case 1:
      goto switchD_00101166_caseD_1;
    default:
      goto switchD_00101166_caseD_2;
    case 0x13:
      goto switchD_00101166_caseD_13;
    case 0x14:
      goto switchD_00101166_caseD_14;
    case 0x16:
      goto switchD_00101166_caseD_16;
    case 0x17:
      goto switchD_00101166_caseD_17;
    case 0x18:
      goto switchD_00101166_caseD_18;
    case 0x19:
      goto switchD_00101166_caseD_19;
    case 0x20:
      goto switchD_00101166_caseD_20;
    case 0x21:
      goto switchD_00101166_caseD_21;
    case 0x22:
      goto switchD_00101166_caseD_22;
    case 0x23:
      goto switchD_00101166_caseD_23;
    case 0x24:
      goto switchD_00101166_caseD_24;
    }
  }
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 1:
    if (*(int *)(param_1 + 0x5f0) != -1) {
      *(undefined4 *)(param_1 + 0x40) = 0x2a;
      return 1;
    }
    if (*(int *)(param_1 + 0x5f4) != 3) {
      return 2;
    }
    goto LAB_001012c8;
  default:
    ossl_statem_fatal(param_1,0x50,600,0x44,"ssl/statem/statem_srvr.c",0x1ab);
    uVar1 = 0;
    break;
  case 0x14:
switchD_00101212_caseD_14:
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x16;
    break;
  case 0x16:
    iVar2 = *(int *)(param_1 + 0x44c);
    if ((*(uint *)(param_1 + 0x4ec) & 0x100000) == 0) goto LAB_00101408;
    if (iVar2 != 2) goto switchD_00101166_caseD_21;
    goto LAB_0010140c;
  case 0x17:
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x28;
    break;
  case 0x19:
    if (*(int *)(param_1 + 0x5f4) == 3) {
      *(undefined4 *)(param_1 + 0x5f4) = 4;
      *(undefined4 *)(param_1 + 0x40) = 1;
      return 1;
    }
    goto LAB_00101330;
  case 0x20:
    iVar2 = *(int *)(param_1 + 0x5f4);
    bVar5 = iVar2 == 4;
    if (bVar5) {
      iVar2 = 2;
    }
    if (bVar5) {
      *(int *)(param_1 + 0x5f4) = iVar2;
    }
    else if (*(int *)(param_1 + 0x55c) == 0) goto switchD_00101166_caseD_13;
    if (*(uint *)(param_1 + 0xf70) < *(uint *)(param_1 + 0xf6c)) goto LAB_00101312;
  case 0x2a:
  case 0x2c:
switchD_00101166_caseD_13:
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x40) = 1;
    break;
  case 0x21:
    if ((*(int *)(param_1 + 0x8c) == 0) && (*(uint *)(param_1 + 0xf70) < *(uint *)(param_1 + 0xf6c))
       ) {
      return 1;
    }
    goto switchD_00101166_caseD_13;
  case 0x23:
    iVar2 = *(int *)(param_1 + 0x44c);
LAB_00101408:
    if (iVar2 == 1) goto switchD_00101212_caseD_24;
LAB_0010140c:
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x25;
    break;
  case 0x24:
switchD_00101212_caseD_24:
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x2e;
    break;
  case 0x25:
    if (*(int *)(param_1 + 0x8c) != 0) goto switchD_00101166_caseD_23;
    iVar2 = send_certificate_request();
    if (iVar2 != 0) goto LAB_001012c8;
LAB_00101330:
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x17;
    break;
  case 0x28:
switchD_00101166_caseD_23:
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x24;
    break;
  case 0x2e:
    goto switchD_00101166_caseD_0;
  }
  return uVar1;
}

